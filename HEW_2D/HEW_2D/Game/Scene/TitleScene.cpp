#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/SoundGun/SoundGun.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"


/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
 * 
 * ステージは、縦２０マス＊横４０マス
*/
void TitleScene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();
	

	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	// TODO:1218ここまで オブジェクトの管理をenumから変更→tagと名前にしたい
	
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	//擬音（どおん）
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");	// 名前要変更
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/Gion.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetPosition(Vector3(500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	
	// マガジン
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

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
	// 入力管理
	// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetJump(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}


	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
	
	// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
	if (Input::GetInstance().GetKeyPress(VK_F))
	{
		Vector3 p_pos = objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->GetPosition();
		//Suction(gion_pos, p_pos);
		if (gion_pos.x - p_pos.x <= 300 && gion_pos.x - p_pos.x >= 0)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
		{
			//ここに、近づくスピードを書く
			gion_pos.x -= 14;
			std::cout << "吸い込んでます" << std::endl;
			objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetPosition(gion_pos);
		}
		std::cout << "擬音座標：" << gion_pos.x << std::endl;
	}
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える


	//----------------当たり判定-----------------------
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObject<GameObject>(OBJECT, "Ground");
	ColliderPlayer_Ground(playerShared, groundShared);
	Collider_toGround(objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine"), objectmanager.GetGameObject<GameObject>(OBJECT, "Ground"));

	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
