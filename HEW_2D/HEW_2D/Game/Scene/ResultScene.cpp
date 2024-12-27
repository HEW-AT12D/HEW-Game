#include "ResultScene.h"

void ResultScene::Init(void) {
	// オブジェクト追加
	objectmanager.AddObject<GameObject>(OBJECT, "Object1");

	std::cout << "ResultSceneInit" << std::endl;
}


void ResultScene::Update(void) {

}


void ResultScene::Draw(void) {
	objectmanager.Draw();
}


void ResultScene::Uninit(void) {

}