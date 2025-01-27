#include "Player.h"
#include "../../../Framework/Input/Input.h"


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
		Animation(JUMP);
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
	// 左移動しようとしている場合
	if (MoveLeft)
	{
		m_Direction.x -= 1.0f;	// 左向きの方向ベクトルを加算
		// ジャンプ中はジャンプモーション優先
		if (Jumping)
		{
			Animation(JUMP);
		}
		else {
			Animation(RUN);
		}
		MoveLeft = false;
	}
	// 右移動しようとしている場合
	if (MoveRight)
	{
		m_Direction.x += 1.0f;	// 右向きの方向ベクトルを加算
		// ジャンプ中はジャンプモーション優先
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
		m_Number.y = 0;			// 2025/01/23 赤根: なぜか二枚目のほうに設定されるけど違和感はマシになったので一旦これで置いとく
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
}

/**
 * @brief 解放処理
*/
void Player::Uninit(void)
{
	for (auto& mag : m_Magazines) {
		// マガジンを全て開放
		mag->Uninit();
		// 所有権を捨てる
		mag.reset();
	}
	// マガジンのコンテナを空にする
	m_Magazines.clear();
	// 擬音銃の解放
	m_Soundgun->Uninit();
	// 所有権を捨てる
	m_Soundgun.reset();
	// プレイヤーの解放
	this->GameObject::Uninit();
}


/**
 * @brief アニメーション関数
 * @param どのアニメーションを再生するかの列挙型
 * 接地したときに左右移動キー押さないと通常時に戻らないのでそこも直す
 * TODO:2025/01/21 左向きに移動したときの処理がまだ！！！！！！！！！！！！！！
*/
void Player::Animation(STATE _Anim_Name)
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
		// ↓は画像内ので今のところ実装予定なし
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
void Player::SetChild(std::shared_ptr<GameObject> _child)
{
	// 設定する子オブジェクトがマガジンであれば(キャストできれば)
	if (auto casted = std::dynamic_pointer_cast<Magazine>(_child))
	{
		// マガジンの座標とスケールを変更する(ここをマガジン数によって変えたい)
		// どうする？
		// →マガジンの大きさをUI向きに変更→マガジン一個の大きさ分だけ右にずらして座標を設定すればいける？→いけた！

		// 大きさを代入
		casted->SetScale(Vector3(75.0f, 75.0f, 0.0f));
		// 一個目のマガジン追加の場合、座標を直接設定
		if (m_Magazines.empty())
		{
			// 座標設定
			casted->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));
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
		_child->SetParent(std::dynamic_pointer_cast<Player>(shared_from_this()));
	}
	// 擬音銃なら
	else if (auto casted = std::dynamic_pointer_cast<SoundGun>(_child))
	{
		// 子オブジェクトに設定
		m_Soundgun = casted;
		m_pChildren.push_back(casted);
	}
	else
	{
		// 子オブジェクトに追加
		m_pChildren.push_back(_child);
	}
}


/**
 * @brief 擬音吸い込み関数
 * 
 * 
 * シーンで判定した擬音との当たり判定を使って当たった擬音の座標を移動させる
 * 
 * →その擬音をマガジンに組み込む処理を追加する
 * @param _gion_pos
 * @param _p_pos
*/
void Player::Suction(std::weak_ptr<GameObject> _gion_pos)
{
	Vector3 gion_pos = _gion_pos.lock()->GetPosition();
	if (gion_pos.x - transform.GetPosition().x <= 200)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
	{
		//ここに、近づくスピードを書く
		gion_pos.x -= 10;
		_gion_pos.lock()->SetPosition(gion_pos);
		std::cout << "吸い込んでます" << std::endl;
	}
}


void Player::Reverse(std::weak_ptr<GameObject>_gion)
{
	// 発射する擬音の座標を取得
	Vector3 gion_pos = _gion.lock()->GetPosition();

	if (Input::GetInstance().GetKeyRelease(VK_W))
	{
		// 擬音の座標をプレイヤーの少し右に設定
		IsShot = true;
		gion_pos.y = transform.GetPosition().y;
		gion_pos.x = transform.GetPosition().x + 100;
		_gion.lock()->SetPosition(gion_pos);
	}

	if (IsShot)
	{
		if (gion_pos.x <= 700)
		{
			gion_pos.x += 10;
			_gion.lock()->SetPosition(gion_pos);
		}
		else {
			IsShot = false;
		}
	}
}

