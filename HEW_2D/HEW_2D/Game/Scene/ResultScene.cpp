#include "ResultScene.h"

void ResultScene::Init(void) {
	// オブジェクト追加
	objectmanager.AddObject<GameObject>(
		std::make_pair(Tag::OBJECT, "Object1")
	);
}


void ResultScene::Update(void) {

}


void ResultScene::Draw(void) {

}


void ResultScene::Uninit(void) {

}