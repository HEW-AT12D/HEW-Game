#include "SoundGun.h"
#include "Magazine.h"

/**
 * @brief 更新
*/
void SoundGun::Update(void)
{
	// アニメーションカウントを増やすかの判定
	static bool countup = true;
	// 吸い込み中ならアニメーションを動かす
	if (IsSuction)
	{
		if (countup)
		{
			m_Number.y++;
			// アニメーションが最後まで行った場合
			if (m_Number.y == m_Split.y)
			{
				countup = false;
			}
		}
		else
		{
			m_Number.y--;
			// アニメーションが最初まで戻った場合
			if (m_Number.y == 0)
			{
				countup = true;
			}
		}
	}

	// 親オブジェクトと座標を同期(これは基底クラスでやるべき)
	// ここではとりあえず擬音銃の座標を同期させる
	Vector3 newpos = m_pParent->GetPosition();
	newpos.x += transform.GetScale().x / 2 + m_pParent->GetScale().x / 2;	// 擬音銃とプレイヤーの大きさのそれぞれ半分を足した値を加算して座標を設定
	transform.SetPosition(newpos);
}

/**
 * @brief 描画
 * 吸い込み中のみ描画を行う 
*/
void SoundGun::Draw(void)
{
	// 吸い込み中なら
	if (IsSuction)
	{
		this->GameObject::Draw();
	}
}

/**
 * @brief 吸い込み状態のセッター
 * @param _flg 吸い込み状態にするかどうか
*/
void SoundGun::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
}

/**
 * @brief 吸い込み状態のゲッター
 * @return 吸い込み中かどうか
*/
bool SoundGun::GetIsSuction(void)
{
	return IsSuction;
}

/**
 * @brief 吸い込み関数
 * @param _gion_pos
 * @param _p_pos
*/
bool SoundGun::Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> _onomatopoeia)
{
	// 親オブジェクト(プレイヤー)が存在しなければ終了
	if (!m_pParent) { return false; }

	// プレイヤー取得
	Vector3 player_pos = m_pParent->GetPosition();

	// プレイヤーの前方ベクトル取得
	Vector3 forward = m_pParent->GetDirection(); // 例: {0, 0, 1} など
	forward.Normalize();
	// オフセット距離(プレイヤーと擬音銃)の計算
	Vector3 offset = XMVectorAbs(player_pos - this->transform.GetPosition());
	// 吸い込みの中心 = プレイヤー位置 + 正面方向 * オフセット距離
	Vector3 suction_center = player_pos + forward * offset;

	// 吸い込む擬音の情報
	Vector3 onomat_pos = _onomatopoeia.second->GetPosition();		// 座標
	Vector3 onomat_rot = _onomatopoeia.second->GetRotation();		// 角度
	Vector3 onomat_scale = _onomatopoeia.second->GetScale();		// サイズ

	// Playerと擬音の距離が一定に来たら、擬音が徐々に近づく
	// 擬音 → 吸い込み中心 への方向ベクトルを計算
	Vector3 dir = suction_center - onomat_pos;
	dir.Normalize();
	// 移動速度をかけて位置を更新
	onomat_pos += dir * 10.0f;	// 10.0fは吸い込み速度
	_onomatopoeia.second->SetPosition(onomat_pos);
	std::cout << "吸い込んでます" << std::endl;

	// 擬音の回転・縮小
	onomat_rot.z += 40;
	_onomatopoeia.second->SetRotation(onomat_rot);	// 角度の再設定

	// 吸い込み中は毎フレーム縮小される
	if (onomat_scale.y >= 0.0f)
	{
		// サイズを変更して再設定
		onomat_scale.x -= 8.0f;
		onomat_scale.y -= 4.0f;

		_onomatopoeia.second->SetScale(onomat_scale);
	}

	// プレイヤーの座標に当たったら(限りなく近づいたら)
	if ((onomat_pos - m_pParent->GetPosition()).Length() <= 100.0f)
	{
		// 親オブジェクトのマガジンに格納
		auto player = dynamic_cast<Player*>(m_pParent);
		// ここの関数にはGameObject型で持ってきてるのでIOnomatopoeia型にキャスト

		// 擬音の座標を現在選択しているマガジンの座標に変更
		// →今選択してるマガジンに既に擬音がある場合、次のマガジンに装填、を繰り返し、全部装填されている場合、座標は寄せるが回転、吸い込み処理は行わない
		if (!_onomatopoeia.second) return false;

		// マガジンのポインタを取得
		std::vector<Magazine*> mags = player->GetMagazines();

		// 擬音の種類によってマガジンUIの形にSRTと色を設定
		if (_onomatopoeia.first.first == Tag::Doon) {
			// 一個目のドォンならSRTをドォン用マガジンに合わせて装填
			if (!mags[0]) {
				_onomatopoeia.second->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
				_onomatopoeia.second->SetScale(Vector3(300.0f, 150.0f, 0.0f));
				_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
			}
			// 二個目以降は座標変更して透明度0にする
			else {
				_onomatopoeia.second->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
				_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));
			}
			mags[0]->SetOnomatopoeia(_onomatopoeia.second);	// マガジンに擬音をセット
		}
		else {
			_onomatopoeia.second->SetRotation(player->GetUsingMag()->GetRotation());
			_onomatopoeia.second->SetScale(player->GetUsingMag()->GetScale());			// 大きさを設定
			_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));				// 色の初期化

			// 現在選択中のマガジンに擬音がなければすべての空きを探して装填
			if (!mags[player->GetMagIdx()]->GetBulletPointer()) {
				_onomatopoeia.second->SetPosition(mags[player->GetMagIdx()]->GetPosition());	// 現在選択中のマガジンの座標に合わせる
				mags[player->GetMagIdx()]->SetOnomatopoeia(_onomatopoeia.second);
			}
			else {
				for (size_t idx = 1; idx < player->GetMagCount(); idx++)
				{
					// マガジン内が空なら擬音をセットしてループを抜ける
					if (!mags[idx]->GetBulletPointer()) {
						_onomatopoeia.second->SetPosition(mags[player->GetMagIdx()]->GetPosition());	// 現在選択中のマガジンの座標に合わせる
						mags[idx]->SetOnomatopoeia(_onomatopoeia.second);
						break;
					}
				}
			}
		}		

		// プレイヤーと擬音銃の吸い込み状態を解除
		this->IsSuction = false;
		player->SetIsSuction(false);

		// 吸い込み完了の結果を返す
		return true;
	}
	return false;
}


/**
 * @brief 擬音発射関数
 * @param _mag マガジン情報
 * 
 * 流れ
 * 発射→マガジンの弾の所有権を銃に渡す（選択されているマガジン番号の中にある弾の所有権を渡す）→その弾を銃が発射
*/
void SoundGun::Shot(Magazine* _mag)
{
	// 引数のマガジンの中にある擬音のサイズなどを設定
	auto gion = _mag->ReleaseBullet();

	Vector3 gion_Rot = gion->GetRotation();		// 擬音の回転情報
	Vector3 gion_Scale = gion->GetScale();		// 擬音のサイズ情報
	Vector3 gion_Pos = transform.GetPosition();	// 擬音の座標(これは擬音銃の少し右に出現させるので銃基準でいじる)
	Vector3 gion_dir = m_Direction;				// 発射する向き(銃の向いている方向に発射する)

	// 擬音の座標を設定
	if (m_Direction.x > 0.0f) { gion_Pos.x += 5.0f; }		// 右向きなら擬音銃の少し右
	if (m_Direction.x < 0.0f) { gion_Pos.x -= 5.0f; }		// 左向きなら擬音銃の少し左

	// 擬音のサイズ設定
	gion_Scale.y = 120.0f;
	gion_Scale.x = 240.0f;

	gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);
	gion->SetDirection(gion_dir);

	// AddForceで代入するための速度用変数
	Vector3 velocity;
	velocity.x = m_ShotPower;
	velocity.y = m_ShotPower;
	// →Playerの発射関数にやること書いてる
	// 擬音に力を加えてまっすぐ飛ばしたい
	gion->AddForce(velocity);
}
