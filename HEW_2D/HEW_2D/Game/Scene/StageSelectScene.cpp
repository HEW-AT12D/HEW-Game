#include "StageSelectScene.h"



void StageSelectScene::Init(void) {
	// ÉvÉåÉCÉÑÅ[
	objectmanager.AddObject<GameObject>(ENEMY, "player");
	objectmanager.GetGameObject<Character>(ENEMY, "player").lock()->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObject<Character>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<Character>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	std::cout << "STAGESELECTSceneInit" << std::endl;
}

void StageSelectScene::Update(void) {

}

void StageSelectScene::Draw(void) {
	objectmanager.Draw();
}

void StageSelectScene::Uninit(void) {

}

