#include "Stage2Scene.h"
#include "../../Framework/Input/Input.h"



void Stage2Scene::Init(void) {
	// プレイヤー
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/GameObject/バネ.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	std::cout << "Stage2SceneInit" << std::endl;
}

void Stage2Scene::Update(void) {
	Input::GetInstance().Update();

	//ゲームセレクト画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
}

void Stage2Scene::Draw(void) {
	objectmanager.Draw();
}

void Stage2Scene::Uninit(void) {
	objectmanager.Uninit();
}