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

	// オブジェクト追加		


	// 背景
	objectmanager.AddObject<GameObject>(OBJECT);
	objectmanager.

	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void){

}

void TitleScene::Draw(void){

}

void TitleScene::Uninit(void){

}
