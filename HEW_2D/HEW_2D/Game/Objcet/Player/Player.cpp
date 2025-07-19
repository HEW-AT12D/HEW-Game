#include "Player.h"
#include "../../../Framework/Input/Input.h"
#include "../../../Framework/Component/Collider/BoxCollider2D/Collider.h"

/**
 * @brief 更新
*/
void Player::Update(void)
{
	// 方向ベクトル初期化
	m_Direction = { 0.0f };

	// 方向ベクトルを合成
	// ジャンプした場合
	if (Jump && !Jumping)
	{
		// ジャンプ中でなければ
		// ジャンプ処理
		Jumping = true;					// ジャンプ中に設定(これステートでもいいかも)
		m_Velocity.y += m_JumpPower;	// 速度のY成分にジャンプ力を代入
		m_Direction.y += 1.0f;			// 上向きの方向ベクトルを加算
		Jump = false;
		Animation(JUMP);
	}
	// 下降している場合(ジャンプ中でベクトルのY成分が負(-)の時)
	if (Jumping && m_Velocity.y < 0.0f)
	{
		if (isFacingLeft) { Animation(LEFTJUMP); }
		else {
			Animation(JUMP);
		}
		// 地面に足がついた場合は方向ベクトルをリセット
		if (OnGround)
		{
			// 着地フラグを立てて
			Jumping = false;
			// 通常時アニメーションへ変更
			Animation(RUN);
		}
		else
		{
			// そうでない場合(下降中の場合)
			m_Direction.y -= 1.0f;	// 下向きの方向ベクトルを加算
		}
	}
	
	// 押し続けている間は吸い込み処理
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTriggerPress()) {
		// 吸い込み中の処理
		IsSuction = true;	// 吸い込み中フラグを立てる
		m_Soundgun->SetIsSuction(true);	// 吸い込み処理を実行
	}
	else {
		IsSuction = false;	// 吸い込み中フラグを下ろす
		m_Soundgun->SetIsSuction(false);	// 吸い込み処理を実行
	}

	// 発射処理
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger()) {
		// 発射処理
		IsShot = true;	// 発射中フラグを立てる
		this->Shot();
		IsShot = false;
	}
	this->UpdateMove();
	this->UpdateCurrentMag();	// 現在のマガジンをセット
	this->UpdateCrossHair();	// クロスヘアの更新

	if (MoveLeft)
	{
		isFacingLeft = true; // ← 左向きフラグをON
		m_Direction.x -= 1.0f;
		if (Jumping)
		{
			Animation(LEFTJUMP);
		}
		else {
			Animation(LEFTRUN);
		}
		MoveLeft = false;
	}

	if (MoveRight)
	{
		isFacingLeft = false; // ← 右向きフラグをOFF
		m_Direction.x += 1.0f;
		if (Jumping)
		{
			Animation(JUMP);
		}
		else {
			Animation(RUN);
		}
		MoveRight = false;
	}

	// 正規化(長さを１に揃える)
	if (m_Direction.Length() > 0.0f)
	{
		m_Direction.Normalize();
	}
	else
	{
		m_Direction = { 0.0f, 0.0f, 0.0f };  // 明示的に方向ベクトルをリセット
	}

	// X成分の移動速度を方向ベクトルと移動速度から計算
	m_Velocity.x = m_Direction.x * m_MoveSpeed;


	// 地面の上にいない場合、重力分速度を減算
	if (!OnGround)
	{
		Jumping = true;
		m_Velocity.y -= 0.5f;	// 重力加速度実装の場合ここを変更
	}
	else {
		// 接地していればジャンプ中ではない
		Jumping = false;
		// 通常時アニメーションへ変更(立ち止まってる時にアニメーションはしたくないので、一番自然な状態の画像に設定)
		if (isFacingLeft)
		{
			m_Number.y = 3; // 左向き立ち絵
		}
		else {
			m_Number.y = 0;
		}
	}

	// 移動処理
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// 方向ベクトルとX成分の移動速度を掛けた値の分だけ毎フレーム進む
	// 新しい座標を代入
	transform.SetPosition(newpos);
}


/**
 * @brief 描画
 * 吸い込みエフェクト、子オブジェクトとして設定したUIのマガジンも描画する
*/
void Player::Draw(void)
{
	// まず自身の描画
	this->GameObject::Draw();

	// TODO:(完了)アニメーションの違和感を取る
	// TODO:アタッチされたオブジェクトの描画
	// TODO:ジャンプの先行入力取れてしまうのを直す

	// 擬音銃の吸い込み時の竜巻を描画したいが、今回竜巻はUIにしていて、オブジェクトとして登録してしまうと当たり判定を取ってしまうのでここで擬音銃の描画まで行う
	// 擬音銃を持っていれば
	if (m_Soundgun)
	{
		// スケール反転（X軸のみ反転）
		Vector3 gunScale = m_Soundgun->GetScale();
		gunScale.x = isFacingLeft ? -abs(gunScale.x) : abs(gunScale.x);
		m_Soundgun->SetScale(gunScale);

		// プレイヤーの左右に銃を移動
		Vector3 gunPos = transform.GetPosition();
		float offset = transform.GetScale().x / 2 + m_Soundgun->GetScale().x / 2;
		gunPos.x += isFacingLeft ? -offset : offset;
		m_Soundgun->SetPosition(gunPos);
	}
}

/**
 ** @brief 解放処理
**/
void Player::Uninit(void)
{
	// マガジンのコンテナを空にする
	m_Magazines.clear();

	// プレイヤーの解放
	this->GameObject::Uninit();
}


/**
 * @brief アニメーション関数
 * @param どのアニメーションを再生するかの列挙型
 * 接地したときに左右移動キー押さないと通常時に戻らないのでそこも直す
 * TODO:2025/01/21 左向きに移動したときの処理がまだ！！！！！！！！！！！！！！
*/
void Player::Animation(ANIMATIONSTATE _Anim_Name)
{
	// 一番初めはアニメーション加算なのでCountUpをtrueに設定
	static bool CountUp = true;
	static bool CountDown = false;
	// ディレイ用フレームカウント変数
	static int framecount = 0;

	// UV番号最大値で割る→余りがあればまだ加算できる
	// 余りなし→アニメーション最終フレームなので減算開始
	// →行いたいアニメーションの種類だけ引数で送る→関数内で計算して加算中か減算中かを判断させればいい
	switch (_Anim_Name)
	{
	case NORMAL:
		// 通常時は何もしない(小刻みな縦揺れアニメーションとかあればここに書く)
		break;
	case RUN:
		// 通常移動時
		this->m_Number.y = 0;	// 一番上の段を使う

		// フレーム数加算
		framecount++;
		if (framecount == 3)
		{
			// 加算中は
			if (CountUp)
			{
				// アニメーション番号加算(アニメーションごとに分割数が違う場合はswitchで条件分けしてここに分割数を入れればおｋ)
				m_Number.x += 1;
				// アニメーション番号余りなし→アニメーション最終フレームなので減算開始
				if (m_Number.x % m_Split.x == 0)
				{
					CountDown = true;
					CountUp = false;
				}
			}
			// 減算中は
			if (CountDown)
			{
				// アニメーション番号加算
				m_Number.x -= 1;
				// アニメーション番号が0より小さい→アニメーションの開始フレームなので番号を0に戻して加算開始
				if (m_Number.x < 0)
				{
					m_Number.x = 0;
					CountUp = true;
					CountDown = false;
				}
			}
			framecount = 0;
		}
		break;
	case LEFTRUN:
		this->m_Number.y = 3;	// 3番上の段を使う

		// フレーム数加算
		framecount++;
		if (framecount == 3)
		{
			// 加算中は
			if (CountUp)
			{
				// アニメーション番号加算(アニメーションごとに分割数が違う場合はswitchで条件分けしてここに分割数を入れればおｋ)
				m_Number.x += 1;
				// アニメーション番号余りなし→アニメーション最終フレームなので減算開始
				if (m_Number.x % m_Split.x == 0)
				{
					CountDown = true;
					CountUp = false;
				}
			}
			// 減算中は
			if (CountDown)
			{
				// アニメーション番号加算
				m_Number.x -= 1;
				// アニメーション番号が0より小さい→アニメーションの開始フレームなので番号を0に戻して加算開始
				if (m_Number.x < 0)
				{
					m_Number.x = 0;
					CountUp = true;
					CountDown = false;
				}
			}
			framecount = 0;
		}
		break;

	case JUMP:
		// ここがややこしい
		// ・ジャンプしたとき→ジャンプ中ではなくジャンプフラグが立った時
		// ・上昇中のとき→ジャンプ中でベクトルのY成分が正(+)の時
		// ・下降中のとき→ジャンプ中でベクトルのY成分が負(-)の時
		// ・着地したとき→ジャンプ中で下向きのベクトルが0になった時(プレイヤーが地面に接触したとき)

		// ジャンプ時
		// ・ジャンプしたとき→ジャンプ中ではなくジャンプフラグが立った時
		if (!Jumping && Jump)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・上昇中のとき→ジャンプ中でベクトルのY成分が正(+)の時
		if (Jumping && m_Velocity.y > 0.0f)
		{
			// 別画像がないので同じものを使う
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・下降中のとき→ジャンプ中でベクトルのY成分が負(-)の時
		if (Jumping && m_Velocity.y < 0.0f)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}
		// ・着地したとき→ジャンプ中で下向きのベクトルが0になった時(プレイヤーが地面に接触したとき)
		if (Jumping && m_Velocity.y == 0)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}

		break;
	case LEFTJUMP:
		if (!Jumping && Jump)
		{
			this->m_Number.y = 4;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・上昇中のとき→ジャンプ中でベクトルのY成分が正(+)の時
		if (Jumping && m_Velocity.y > 0.0f)
		{
			// 別画像がないので同じものを使う
			this->m_Number.y = 4;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・下降中のとき→ジャンプ中でベクトルのY成分が負(-)の時
		if (Jumping && m_Velocity.y < 0.0f)
		{
			this->m_Number.y = 4;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}
		// ・着地したとき→ジャンプ中で下向きのベクトルが0になった時(プレイヤーが地面に接触したとき)
		if (Jumping && m_Velocity.y == 0)
		{
			this->m_Number.y = 4;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}
		break;
		// ↓は画像がないので今のところ実装予定なし
	case DAMAGED:
		break;
	case ATTACKED:
		break;
	default:
		break;
	}
}


/**
 * @brief 子オブジェクトをセット
 * @param _child 子オブジェクトのポインタ
 *
 * 〇マガジン取得の流れ
 * 　・マガジンを拾う→タグをUIに変更→大きさと座標を変更、としたい
*/
void Player::SetChild(GameObject* _child)
{
	// 設定する子オブジェクトがマガジンであれば(キャストできれば)
	if (auto casted = dynamic_cast<Magazine*>(_child))
	{
		// マガジンの座標とスケールを変更する(ここをマガジン数によって変えたい)
		// どうする？
		// →マガジンの大きさをUI向きに変更→マガジン一個の大きさ分だけ右にずらして座標を設定すればいける？→いけた！

		// 大きさを代入
		casted->SetScale(Vector3(120.0f, 120.0f, 0.0f));
		// 一個目は「ドォン」を入れるマガジンなので、座標を直接設定
		if (m_Magazines.empty())
		{
			// 座標設定
			casted->SetPosition(Vector3(810.0f, 450.0f, 0.0f));
			// このマガジンだけ大きさを変える
			casted->SetScale(Vector3(300.0f, 300.0f, 0.0f));
		}
		// 二個目のマガジン(擬音銃に装填する用のマガジン)を追加する場合
		else if (m_Magazines.size() == 1)
		{
			// 座標設定
			casted->SetPosition(Vector3(-900.0f, 500.0f, 0.0f));
		}
		// 既にマガジンを一個以上所持している場合は
		else
		{
			// マガジン数を計算
			size_t magcnt = m_Magazines.size();

			// 描画したい座標を計算
			Vector3 newMagPos;
			// X座標はいちばん後ろのマガジンの座標から 追加するマガジンの大きさ / 2した値 を足した座標に表示する
			newMagPos.x = m_Magazines.back()->GetPosition().x + casted->GetScale().x;
			// Y座標も同じように設定
			newMagPos.y = m_Magazines.back()->GetPosition().y;
			// 座標を代入
			casted->SetPosition(newMagPos);
		}

		// プレイヤーのマガジンに追加して
		m_Magazines.push_back(casted);
		// 子オブジェクトとしても設定
		m_pChildren.push_back(casted);

		// プレイヤーをマガジンの親として設定する
		// shared_from_thisだけだとGameObject型になるので、Player型にキャストしてから渡す
		_child->SetParent(dynamic_cast<Player*>(this));
	}
	// 擬音銃なら
	else if (auto casted = dynamic_cast<SoundGun*>(_child))
	{
		// 子オブジェクトに設定
		m_Soundgun = casted;
		m_pChildren.push_back(casted);

		// 座標をプレイヤーの少し右に調整(これ座標変換できるようにしたい)
		Vector3 newpos = transform.GetPosition();
		newpos.x += transform.GetScale().x / 2 + casted->GetScale().x / 2;	// 擬音銃とプレイヤーの大きさのそれぞれ半分を足した値を加算して座標を設定
		casted->SetPosition(newpos);

	}
	// クロスヘアの場合
	else if (auto casted = dynamic_cast<CrossHair*>(_child))
	{
		// 子オブジェクトに設定
		m_pCrossHair = casted;
		m_pChildren.push_back(casted);
	}
	else
	{
		// 子オブジェクトに追加
		m_pChildren.push_back(_child);
	}
	// 子オブジェクト側にもこのオブジェクトを親として設定
	_child->SetParent(this);
}

/**
 * @brief プレイヤーの周囲にある擬音を取得する関数
 * @param _onomatopoeias シーンから受け取ったプレイヤー周辺の擬音
 * @return 近くにある擬音のペア(タグと名前、ポインタ)
 *
 * →プレイヤーの周囲にある擬音を取得する
 * →その中から、吸い込める擬音を探す
*/
std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> Player::StartSuction(std::vector<std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>> _onomatopoeias)
{
	std::pair closest = ColliderFan_Gion(this, _onomatopoeias);
	if (closest.second) {
		IsSuction = true;
	}
	return closest;
}

/**
 * @brief 吸い込む擬音を探す関数
 *
 * シーンから受け取ったプレイヤー周辺の擬音から、吸い込める擬音を探す
 *
 * →その擬音をマガジンに組み込む処理を追加する
 *  →プレイヤーと当たるまで吸い込んだら、マガジンに追加
 * @param _gion_pos
 * @param _p_pos
*/
bool Player::Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> _onomatopoeia)
{
	// 擬音銃が存在しない場合は何もしない
	if (!m_Soundgun) return false;


	// フラグを立てて擬音銃の吸い込み処理を実行
	m_Soundgun->SetIsSuction(true);

	// 擬音銃の吸い込みの結果を返す
	if (m_Soundgun->Suction(_onomatopoeia)) {
		// 音がドォンならカウント加算
		if (_onomatopoeia.first.first == Tag::Doon) {
			BombCount++;
		}
		return true;	// 吸い込み成功
	}
	return false;	// 吸い込み失敗
}


/**
 * @brief 擬音銃のエイムの座標を基準に擬音を発射
 * @param _gion
 *
 * やること
 * →クロスヘアを擬音銃の子オブジェクトに設定→入力を取って操作可能にする→プレイヤーの発射関数でそのクロスヘア情報とマガジンに入ってる擬音情報を使えるようにする
 *
 * やりたいこと→使う擬音(マガジン)を決める→エイム操作(これはいつでもできるようにする)→発射
*/
void Player::Shot(void)
{
	//発射
	if (IsShot)
	{
		if (!m_Magazines[UsingMagIdx]->GetBulletPointer()) { return; }
		//==========================================
		//=======１月２６日現状======================
		//Playerの０度～１８０度までしか判定をとれていない
		//１８０度を超えると＋に変換される（例：２４０度で入力すると、１２０度で発射される）
		//==============================================================================

		Vector3 vertex;			// 
		float hypotenuse;		// 斜辺の二乗
		float root_hypotenuse;	// 平方根の計算をした斜辺
		float Radians;			// 角度
		float Degrees;			// 度
		float M_PI;				// 円周率

		//-----------式案----------//
		//Playerを中心にして,照準を合わせている場所をGetPosで取って,//
		//エイムして取ったポジションから、垂直に降ろして三点取る//

		//斜辺^2 = エイムして取ったX座標のポジション ^ 2 - (エイムして取ったポジションから、垂直に降ろしたX座標 - PlayerのX座標) ^ 2//
		//cosθ = (エイムして取ったポジションから、垂直に降ろしたX座標 - PlayerのX座標) / 斜辺

		Vector3 p_aim = m_pCrossHair->GetPosition();				// クロスヘア座標
		Vector3 p_player = this->transform.GetPosition();		// プレイヤー座標
		Vector3 p_gion = m_Magazines[UsingMagIdx]->GetBulletPointer()->GetPosition();		// 発射する擬音の座標
		vertex.x = p_aim.x - p_player.x;			// 照準とPlayerのX座標の差（底辺）
		vertex.y = p_aim.y - p_player.y;			// 照準とPlayerのY座標差  （高さ）
		hypotenuse = (vertex.y * vertex.y) + (vertex.x * vertex.x); //斜辺の計算（底辺の二乗＋高さの二乗＝斜辺の二乗）
		root_hypotenuse = std::sqrt(hypotenuse);	// 斜辺の平方根の計算(ここでベクトルの長さが求まる)

		// ベクトルを正規化
		Vector3 normalized_vector;
		normalized_vector.x = vertex.x / root_hypotenuse;
		normalized_vector.y = vertex.y / root_hypotenuse;

		// 銃の向きを設定(↑で計算して正規化した方向ベクトルを使用)
		m_Soundgun->SetDirection(normalized_vector);

		// 擬音の発射関数には減速力とかは気にしなくていい→0に設定する→まっすぐ飛んでいく
		// 使うマガジンの情報を受け取って擬音銃で発射
		m_Soundgun->Shot(m_Magazines[UsingMagIdx]);

		// 発射フラグをリセット
		IsShot = false;
		//m_Magazines[UsingMagIdx].reset();
	}
}

/**
 * @brief マガジンカーソルの設定
 * @param _cursor マガジンカーソルのポインタ
 *
 * マガジンカーソルを設定する
 * マガジンカーソルの座標と大きさを設定して、子オブジェクトに追加する
*/
void Player::SetMagCursor(GameObject* _cursor)
{
	// マガジンカーソルを設定
	if (_cursor)
	{
		m_pMagCursor = _cursor;
		// マガジンカーソルを子オブジェクトに追加
		m_pChildren.push_back(_cursor);
	}
}

/**
 * @brief プレイヤーの移動更新
 * 入力に合わせてプレイヤーの移動フラグを更新する
 * 右スティックの入力でジャンプ、左スティックの入力で左右移動を行う
*/
void Player::UpdateMove(void)
{
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();
	// 入力管理
	// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		this->MoveRight = true;
	}
	else {
		this->MoveRight = false;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		this->MoveLeft = true;
	}
	else {
		this->MoveLeft = false;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		this->Jump = true;
	}
	else {
		this->Jump = false;
	}
}

/**
 * @brief 現在のマガジンを更新
 * R1でマガジンカーソルを右に移動、L1で左に移動
 * マガジンカーソルの座標を更新する
*/
void Player::UpdateCurrentMag(void)
{
	// カーソルの座標取得
	Vector3 p_frame = m_pMagCursor->GetPosition();

	// R1でマガジンカーソル右移動
	if (Input::GetInstance().GetKeyTrigger(VK_P) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		// ドォン用マガジンを除く一番最後のマガジンを選択していなければ
		if (this->UsingMagIdx != m_Magazines.size() - 1)
		{
			// マガジン選択番号を１増やしてカーソルを右に移動
			this->UsingMagIdx += 1;
			p_frame.x += 120.0f;
		}
		// 一番最後のマガジンを選択している場合
		else
		{
			// マガジン選択番号を１(ドォン用マガジンを除く一番最初)に戻してカーソルを初期位置に移動
			this->UsingMagIdx = 1;
			p_frame.x = -900.0f;
		}
		// 座標を設定
		m_pMagCursor->SetPosition(p_frame);
		// SE再生
		m_pSound->Play(SE_CLICK);
	}
	// L1でマガジンカーソル左移動
	if (Input::GetInstance().GetKeyTrigger(VK_O) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_LEFT_SHOULDER))
	{
		// ドォン用マガジンを除く一番最初のマガジンを選択していなければ
		if (this->UsingMagIdx != 1)
		{
			m_pSound->Play(SE_CLICK);
			// マガジン選択番号を１減らして
			this->UsingMagIdx -= 1;
			// カーソルを左に移動
			p_frame.x -= 120.0f;
		}
		// 一番最初のマガジンを選択している場合
		else
		{
			// マガジン選択番号を(ドォン用マガジンを除く)一番後ろにして
			this->UsingMagIdx = m_Magazines.size() - 1;
			// カーソルを一番後ろの位置に移動
			p_frame.x = -900.0f + m_pMagCursor->GetScale().x * (m_Magazines.size() - 2);	// 初期位置 + カーソルの大きさ * マガジン数(ドォン入れないので-2)
		}
		// マガジンアウトラインの座標を設定
		m_pMagCursor->SetPosition(p_frame);
		// SE再生
		m_pSound->Play(SE_CLICK);
	}
}

/**
 * @brief クロスヘアの更新
 * 右スティックの入力に合わせてクロスヘアの座標を更新する
 * 画面外に出ないように制限をかける
*/
void Player::UpdateCrossHair(void)
{
	// クロスヘアの座標をプレイヤーの座標に合わせる
	if (!m_pCrossHair) return; // クロスヘアが設定されていない場合は何もしない

	Vector2 input = Input::GetInstance().GetRightAnalogStick(); // 右スティックの入力を取得

	// スティックの入力に合わせてクロスヘアの座標を移動
	if (input != Vector2{ 0.0f }) {

		Vector3 crosshairvelocity = m_pCrossHair->GetVelocity();
		Vector3 newPos = m_pCrossHair->GetPosition() + Vector3(input.x, input.y, 0.0f) * crosshairvelocity;

		// クロスヘアの座標を画面内に調整
		// X座標の制限
		if(newPos.x < 0 - 1920.0f / 2){
			newPos.x = 0 - 1920.0f / 2; // 左端
		}
		else if(newPos.x > 1920.0f / 2){
			newPos.x = 1920.0f / 2; // 右端
		}
		// Y座標の制限
		if(newPos.y < 0 - 1080.0f / 2){
			newPos.y = 0 - 1080.0f / 2; // 下端
		}
		else if(newPos.y > 1080.0f / 2){
			newPos.y = 1080.0f / 2; // 上端
		}
		m_pCrossHair->SetPosition(newPos);
	}
}

/**
 * @brief 選択しているマガジン内の擬音の情報を返す関数
 * @return 装填されている擬音
*/
IOnomatopoeia* Player::GetLoadedBullet(void)
{
	// 装填中のマガジンに入ってる擬音を返す
	return m_Magazines[UsingMagIdx]->GetBulletPointer();
}

/**
 * @brief プレイヤーが持っているマガジンのコンテナを返す関数
 * @return マガジンのコンテナ
*/
std::vector<Magazine*>& Player::GetMagazines(void)
{
	return m_Magazines;
}

/**
 * @brief 選択してるマガジンを返す関数
 * @return 選択中のマガジン
*/
Magazine* Player::GetUsingMag(void)
{
	return m_Magazines[UsingMagIdx];
}


// 射撃状態のゲッター、セッター
bool Player::GetIsShot(void)
{
	return IsShot;
}

void Player::SetIsShot(bool _flg)
{
	IsShot = _flg;
}

// 吸い込み状態のゲッターセッター
bool Player::GetIsSuction(void)
{
	return IsSuction;
}

void Player::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
	m_Soundgun->SetIsSuction(_flg);	// 擬音銃の吸い込み状態も更新
}

// 選択されているマガジン番号のセッターゲッター
void Player::SetMagIdx(int _num)
{
	this->UsingMagIdx = _num;
}


int Player::GetMagIdx(void)
{
	return this->UsingMagIdx;
}

// マガジン数のゲッター
size_t Player::GetMagCount(void)
{
	return m_Magazines.size();
}
