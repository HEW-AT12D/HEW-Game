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
	// プレイヤー
	objectmanager.AddObject<GameObject>(PLAYER, "Player");
	objectmanager.GetGameObject(IMAGE, "Player")->Init(L"Game/Asset/Character/Player.png");
	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void) {
	objectmanager.Update();
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
