#include "TitleScene.h"
#include "../../Framework/Input/Input.h"



void TitleScene::Init(void) {
	// プレイヤー
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/GameObject/バネ.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	objectmanager.AddObject<GameObject>(UI, "rogo");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "rogo").lock()->Init(L"Game/Asset/UI/rogo.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "rogo").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "rogo").lock()->SetScale(Vector3(1300.0f, 800.0f, 0.0f));

	std::cout << "TitleSceneInit" << std::endl;
}

void TitleScene::Update(void) {
	Input::GetInstance().Update();

	//ゲームセレクト画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}