#include "ResultScene.h"

void ResultScene::Init(void) {
	// �I�u�W�F�N�g�ǉ�
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