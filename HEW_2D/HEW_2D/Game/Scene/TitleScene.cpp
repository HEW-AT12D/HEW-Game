#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include"../../Game/Objcet/SoundGun/SoundGun.h"
#include"../../Framework/Component/Collider/Collider.h"
#include"../../Framework/Component/Gravity/Gravity.h"



/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
*/

bool isMoving = false;//移動中かどうかのフラグ
Vector3 targetPosition;                // 目標位置
const float moveSpeed = 10.0f;          // 1フレームあたりの移動速度

void TitleScene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();
	

	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	// TODO:1218ここまで オブジェクトの管理をenumから変更→tagと名前にしたい
	
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background1");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// プレイヤー
	objectmanager.AddObject<GameObject>(PLAYER, "Player");
	objectmanager.GetGameObject(PLAYER, "Player")->Init(L"Game/Asset/Character/Character_sprit.png",2,1);
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(Vector3(0.0f, 100.0f, 0.0f));
	objectmanager.GetGameObject(PLAYER, "Player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));


	//擬音（どおん）
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");
	objectmanager.GetGameObject(OBJECT, "Gion")->Init(L"Game/Asset/Gion/Gion.png");
	objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(Vector3(300.0f, -100.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Gion")->SetScale(Vector3(120.0f, 60.0f, 0.0f));
	

	//足場
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObject(OBJECT, "Ground")->Init(L"Game/Asset/BackGround/ground.png");
	objectmanager.GetGameObject(OBJECT, "Ground")->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Ground")->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//吸い込み画像
	objectmanager.AddObject<GameObject>(OBJECT, "Saikuron");
	objectmanager.GetGameObject(OBJECT, "Saikuron")->Init(L"Game/Asset/BackGround/saikuron.png");
	objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(Vector3(100.0f, -100.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Saikuron")->SetScale(Vector3(200.0f, 100.0f, 0.0f));

	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
	
}


void TitleScene::Update(void)
{
	
	// 入力情報の更新
	Input::GetInstance().Update();
	Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
	Vector3 s_pos = objectmanager.GetGameObject(OBJECT, "Saikuron")->GetPosition();
	//pos.y -= 1.0f;
	
	std::cout << "PlayerY座標：" << pos.y << std::endl;
	
	
	if (ColliderPlayer_Ground(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Ground")))
	{
		//std::cout << "衝突しました" << std::endl;
		if (Input::GetInstance().GetKeyPress(VK_Q))
		{
			Jump(objectmanager.GetGameObject(PLAYER, "Player"), pos);
		}
	}
	else {
		//Playerの重力加速度
		Gravity(objectmanager.GetGameObject(PLAYER, "Player"), pos);
	}
	// 入力管理
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		pos.x += 5.0f;
		s_pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);
		objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(s_pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
	/*	objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}

	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		pos.x -= 5.0f;
		s_pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);
		objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(s_pos);
	}


	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
	
	//吸い込み処理
	//SPACE押す→扇型と擬音の当たり判定が作動する→(trueなら)Playerと擬音の当たり判定作動
	if (Input::GetInstance().GetKeyPress(VK_SPACE))
	{
		Vector3 p_pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();
		

		//Playerと擬音の当たり判定がtrueになったことを表すif文
		if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
		{
			std::cout << "Playerと擬音の当たり判定がtrueになりました" << std::endl;
		}else if (ColliderFan_Gion(objectmanager.GetGameObject(OBJECT, "Saikuron"), objectmanager.GetGameObject(OBJECT, "Gion")))
		{
			//ここに、近づくスピードを書く
			gion_pos.x -= 14;
			std::cout << "吸い込んでます" << std::endl;
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(gion_pos);

			//Playerに当たったら保存する処理をここに書く
			/*if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
			{
				std::cout << "Playerと擬音が衝突しています" << std::endl;
			}*/

		}
		std::cout << "擬音座標：" << gion_pos.x << std::endl;
	}


	//!擬音の発射
	//! Player と Gion の当たり判定
	if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
	{
		std::cout << "Playerと擬音の当たり判定がtrueになりました" << std::endl;

		// Xキーが押されたら移動を開始
		if (Input::GetInstance().GetKeyPress(VK_X) && !isMoving)
		{
			// Gion の現在位置を取得
			Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();

			// 目標位置を設定（X方向に300.0f移動）
			targetPosition = gion_pos;
			targetPosition.x += 500.0f;

			// 移動フラグを有効化
			isMoving = true;
		}
	}

	
	// Gion が移動中の場合
	if (isMoving)
	{
		// Gion の現在位置を取得
		Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();

		// 目標位置との差を計算
		Vector3 direction = targetPosition - gion_pos;

		// 現在位置が目標位置に近いかどうかを判定
		float distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
		if (distance <= moveSpeed)
		{
			// 目標位置に到達した場合、位置を目標に揃える
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(targetPosition);
			isMoving = false; // 移動を停止
		}
		else
		{
			// 正規化して方向ベクトルを計算
			direction.x /= distance;
			direction.y /= distance;
			direction.z /= distance;

			// 1フレーム分の移動量を計算
			gion_pos.x += direction.x * moveSpeed;
			gion_pos.y += direction.y * moveSpeed;
			gion_pos.z += direction.z * moveSpeed;

			// Gion の位置を更新
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(gion_pos);
		}
	}
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える


	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
