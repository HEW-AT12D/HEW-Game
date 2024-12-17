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
	objectmanager.AddObject<GameObject>(OBJECT);
	// タイトル
	objectmanager.AddObject<GameObject>(OBJECT);
	// UI1(ボタン)
	objectmanager.AddObject<GameObject>(OBJECT);
	// UI2(ボタン)
	objectmanager.AddObject<GameObject>(OBJECT);
	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void) {

}

void TitleScene::Draw(void) {

}

void TitleScene::Uninit(void) {

}
