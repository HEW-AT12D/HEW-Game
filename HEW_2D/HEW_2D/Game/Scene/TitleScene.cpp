#include "TitleScene.h"
#include "../../Framework/Input/Input.h"



void TitleScene::Init(void) {
	// 背景
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	//タイトルロゴ
	objectmanager.AddObject<Player>(UI, "rogo");
	objectmanager.GetGameObjectPtr<Player>(UI, "rogo").lock()->Init(L"Game/Asset/UI/rogo.png");
	objectmanager.GetGameObjectPtr<Player>(UI, "rogo").lock()->SetPosition(Vector3(-400.0f, 300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(UI, "rogo").lock()->SetScale(Vector3(1400.0f, 900.0f, 0.0f));
	Vector3 r_rotation = objectmanager.GetGameObjectPtr<Player>(UI, "rogo").lock()->GetRotation();
	r_rotation.z = (15);
	objectmanager.GetGameObjectPtr<Player>(UI, "rogo").lock()->SetRotation(r_rotation);

	//startロゴ
	objectmanager.AddObject<GameObject>(UI, "start");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->Init(L"Game/Asset/UI/START.png",2.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->SetPosition(Vector3(500.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	//endロゴ
	objectmanager.AddObject<GameObject>(UI, "end");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->Init(L"Game/Asset/UI/END.png", 2.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	//Titleカーソル
	objectmanager.AddObject<GameObject>(UI, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->Init(L"Game/Asset/UI/TitleCursol.png", 3.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Vector3(300.0f, -170.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetScale(Vector3(300.0f, 450.0f, 0.0f));

	//Titleキャラクター
	//タイトルロゴ
	objectmanager.AddObject<GameObject>(UI, "Chara");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Chara").lock()->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Chara").lock()->SetPosition(Vector3(-400.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Chara").lock()->SetScale(Vector3(800.0f, 900.0f, 0.0f));
	Vector3 c_rotation = objectmanager.GetGameObjectPtr<GameObject>(UI, "rogo").lock()->GetRotation();
	c_rotation.z = (15);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Chara").lock()->SetRotation(c_rotation);

	std::cout << "TitleSceneInit" << std::endl;
}

void TitleScene::Update(void) {
	Input::GetInstance().Update();
	
	auto rogoShared = objectmanager.GetGameObjectPtr<TitleScene>(UI, "rogo");
	if (Input::GetInstance().GetKeyTrigger(VK_M))
	{
	}
	//ゲームセレクト画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		m_RequestNext = STAGESELECT;
	}
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}

//オノマトペのMove関数
void TitleScene::Title_Onomatope_Move(std::weak_ptr<GameObject>_onomatope,float deltaTime)
{
	
}
