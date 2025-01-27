#include "StageSelectScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/SceneManager/SceneManager.h"



void StageSelectScene::Init(void) {
	// プレイヤー
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	std::cout << "STAGESELECTSceneInit" << std::endl;
}

void StageSelectScene::Update(void) {
	Input::GetInstance().Update();

	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		GetChangeScene();
		SetChangeScene(GAME);
	}
}

void StageSelectScene::Draw(void) {
	objectmanager.Draw();
}

void StageSelectScene::Uninit(void) {
	objectmanager.Uninit();
}

