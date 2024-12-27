#include "StageSelectScene.h"



void StageSelectScene::Init(void) {
	// ƒvƒŒƒCƒ„[
	objectmanager.AddObject<GameObject>(ENEMY, "player");
	objectmanager.GetGameObject(ENEMY, "player")->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObject(ENEMY, "player")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(ENEMY, "player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	std::cout << "STAGESELECTSceneInit" << std::endl;
}

void StageSelectScene::Update(void) {

}

void StageSelectScene::Draw(void) {
	objectmanager.Draw();
}

void StageSelectScene::Uninit(void) {

}

