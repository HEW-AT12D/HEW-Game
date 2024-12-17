#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"


TitleScene(D3D11& _D3d11) :IScene(_D3d11) {

}




/**
 * @brief タイトル初期化
*/
void TitleScene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();

	// オブジェクト追加		objectmanager.AddObject<GameObject>(OBJECT);

	// 背景
	objectmanager.AddObject<GameObject>(OBJECT);

	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void){

}

void TitleScene::Draw(void){

}

void TitleScene::Uninit(void){

}
