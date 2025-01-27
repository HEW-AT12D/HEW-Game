#include "Re_TitleScene.h"
#include "../../Framework/Input/Input.h"



void Re_TitleScene :: Init(void) {
	// プレイヤー
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/GameObject/バネ.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	std::cout << "Re_TitleSceneInit" << std::endl;
}

void Re_TitleScene::Update(void) {
	Input::GetInstance().Update();

	//ゲームセレクト画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
}

void Re_TitleScene::Draw(void) {
	objectmanager.Draw();
}

void Re_TitleScene::Uninit(void) {
	objectmanager.Uninit();
}