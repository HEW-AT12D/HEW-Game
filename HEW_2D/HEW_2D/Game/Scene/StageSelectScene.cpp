#include "StageSelectScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/SceneManager/SceneManager.h"



void StageSelectScene::Init(void) {
	// プレイヤー
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(-300.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	objectmanager.AddObject<GameObject>(UI, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	objectmanager.AddObject<GameObject>(UI, "STAGE1");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->Init(L"Game/Asset/UI/STAGE1.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetScale(Vector3(330.0f, 130.0f, 0.0f));

	objectmanager.AddObject<GameObject>(UI, "STAGE2");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->Init(L"Game/Asset/UI/STAGE2.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->SetPosition(Vector3(0.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->SetScale(Vector3(330.0f, 130.0f, 0.0f));

	
	std::cout << "STAGE1_SCENEInit" << std::endl;
}

void StageSelectScene::Update(void) {
	Input::GetInstance().Update();

	//ゲーム画面に遷移
	// シーン遷移（デバック用

	Vector3 Cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->GetPosition();
	if (Cursol_pos.y == 0)
	{
		if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			SetChangeScene(GAME);
		}
	}

	if (Cursol_pos.y == -300)
	{
		if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			SetChangeScene(TEST);
		}
	}
	

	if (Input::GetInstance().GetKeyTrigger(VK_DOWN))
	{
		Cursol_pos.y = -300.0f;
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursol_pos);
	}else 
	if (Input::GetInstance().GetKeyTrigger(VK_UP))
	{
		Vector3 Cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->GetPosition();
		Cursol_pos.y = 0.0f;
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursol_pos);
	}

	
}

void StageSelectScene::Draw(void) {
	objectmanager.Draw();
}

void StageSelectScene::Uninit(void) {
	objectmanager.Uninit();
}

