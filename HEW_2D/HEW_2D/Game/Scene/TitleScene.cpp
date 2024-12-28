#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"



/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
*/



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
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(PLAYER, "Player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));


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
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation(Run, num);
		
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

	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
