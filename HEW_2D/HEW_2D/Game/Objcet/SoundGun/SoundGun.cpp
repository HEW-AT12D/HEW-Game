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

// 吸い込み状態のゲッターセッター
void SoundGun::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
}


bool SoundGun::GetIsSuction(void)
{
	return IsSuction;
}


/**
 * @brief 吸い込み関数
 * @param _gion_pos
 * @param _p_pos
*/
bool SoundGun::Suction(IOnomatopoeia* _gion)
{
	// 親オブジェクト(プレイヤー)が存在していて、
	if (m_pParent)
	{
		// 吸い込む擬音の情報
		Vector3 gion_pos = _gion->GetPosition();		// 座標
		Vector3 gion_rot = _gion->GetRotation();		// 角度
		Vector3 gion_scale = _gion->GetScale();		// サイズ

		/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
		//ここに、近づくスピードを書く
		gion_pos.x -= 10;
		_gion->SetPosition(gion_pos);
		std::cout << "吸い込んでます" << std::endl;


		// 擬音の回転、縮小
		gion_rot.z += 40;
		_gion->SetRotation(gion_rot);	// 角度の再設定

		// 吸い込み中は毎フレーム縮小される
		if (gion_scale.y >= 0.0f)
		{
			// サイズを変更して再設定
			gion_scale.x -= 8.0f;
			gion_scale.y -= 4.0f;

			_gion->SetScale(gion_scale);
		}

		// プレイヤーの座標に当たったら(限りなく近づいたら)
		if (gion_pos.x - m_pParent->GetPosition().x <= 100.0f)
		{
			
			if (m_pParent->m_Tag == Tag(Doon))
			{
				return false;
			}
			// 親オブジェクトのマガジンに格納
			auto player = dynamic_cast<Player*>(m_pParent);
			// ここの関数にはGameObject型で持ってきてるのでIOnomatopoeia型にキャスト
			//auto onomatopoeia = std::dynamic_pointer_cast<IOnomatopoeia>(_gion.lock());

			//// 擬音の座標を現在選択しているマガジンの座標に変更
			//// →今選択してるマガジンに既に擬音がある場合、次のマガジンに装填、を繰り返し、全部装填されている場合、座標は寄せるが回転、吸い込み処理は行わない
			////onomatopoeia->SetPosition(player->GetUsingMag()->GetPosition());	// 座標を設定
			//onomatopoeia->SetRotation(player->GetUsingMag()->GetRotation());	// 角度を設定
			auto gionShared = _gion;
			if (!gionShared) return false;  // weak_ptr が無効

			auto onomatopoeia = dynamic_cast<IOnomatopoeia*>(gionShared);
			if (!onomatopoeia) return false; // キャスト失敗

			// 安全に呼び出せる
			onomatopoeia->SetRotation(player->GetUsingMag()->GetRotation());
			onomatopoeia->SetScale(player->GetUsingMag()->GetScale());
			onomatopoeia->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
			player->GetUsingMag()->SetOnomatopoeia(onomatopoeia);


			onomatopoeia->SetScale(player->GetUsingMag()->GetScale());			// 大きさを設定
			onomatopoeia->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));				// 色の初期化
			player->GetUsingMag()->SetOnomatopoeia(onomatopoeia);				// マガジンに装填
			//// 0番目の要素が存在するかチェック
			// if (!player->m_Magazines.empty())
			//{
			//	if (player->m_pChildren[0] == 0)
			//	{
			//		// 1番目に追加する際に特定の位置に設定
			//		onomatopoeia->SetPosition(player->GetUsingMag()->GetPosition());	// 座標を設定
			//	}
			//	else if (player->m_pChildren.size()>1&&player->m_pChildren[1])
			//	{
			//		// 1番目に追加する際に特定の位置に設定
			//		onomatopoeia->SetPosition(Vector3(-500.0f, 250.0f, 0.0f));
			//	}
			//	else if (player->m_Magazines.size() == 2)
			//	{
			//		// 2番目に追加する際にさらに別の位置に設定
			//		onomatopoeia->SetPosition(player->GetUsingMag()->GetPosition());	// 座標を設定
			//	}
			//	else if (player->m_Magazines.size() == 3)
			//	{
			//		// 2番目に追加する際にさらに別の位置に設定
			//		onomatopoeia->SetPosition(Vector3(-500.0f, 250.0f, 0.0f));
			//	}
			//}
			/*if (_gion.lock()->m_Tag== Tag(Doon))
			{
				_gion.lock()->SetPosition(Vector3(900.0f, 500.0f, 0.0f));
			}*/
			// プレイヤーと擬音銃の吸い込み状態を解除
			this->IsSuction = false;
			player->SetIsSuction(false);

			// 吸い込み完了の結果を返す
			return true;
		}
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

	//gion_Rot.z = 0;		// 吸い込みで

	// 擬音の座標を設定
	gion_Pos.x += 5.0f;		// 擬音銃の少し右

	// 擬音のサイズ設定
	gion_Scale.y = 120.0f;
	gion_Scale.x = 240.0f;

	// 各情報を代入
	/*gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);*/


	gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);
	gion->SetDirection(gion_dir);

	// AddForceで代入するための速度用変数
	Vector3 velocity;
	velocity.x = m_ShotPower;
	velocity.y = m_ShotPower;
	// TODO:2025/01/27 ここで下方向のベクトルを無くしておけば下に落ちることはないはず！
	// →Playerの発射関数にやること書いてる
	// 擬音に力を加えてまっすぐ飛ばしたい
	gion->AddForce(velocity);
}
