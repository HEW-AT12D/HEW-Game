#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"



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
	objectmanager.GetGameObject(BACKGROUND, "Background1")->Init(L"Game/Asset/BackGround/back_img_01.png");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// プレイヤー
	objectmanager.AddObject<GameObject>(PLAYER, "Player");
	objectmanager.GetGameObject(PLAYER, "Player")->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(PLAYER, "Player")->SetScale(Vector3(50.0f, 50.0f, 0.0f));


	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void) {
	objectmanager.Update();
	Vector3 vector3 = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
	vector3.x += 5.0f;
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(vector3);
	std::cout << "Playerの座標移動ができています" << std::endl;
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
