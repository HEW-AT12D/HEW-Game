#include "ResultScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include <Xinput.h>

void ResultScene::Init(void) {
	// オブジェクト追加
	//背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background")->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background")->SetScale(Vector3(1960.0f, 1080.0f, 0.0f));

	objectmanager.AddObject<GameObject>(OBJECT, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->Init(L"Game/Asset/UI/TitleCursol.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->SetPosition(Vector3(-250.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->SetScale(Vector3(300.0f, 300.0f, 0.0f));

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE1");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->Init(L"Game/Asset/UI/BacktoTitleButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->SetScale(Vector3(500.0f, 400.0f, 0.0f));
	XMINT2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->GetUV();
	Button2.x = 1;
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->SetUV(Button2);

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE2");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->Init(L"Game/Asset/UI/EndButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	objectmanager.AddObject<GameObject>(UI, "CLEAR");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "CLEAR")->Init(L"Game/Asset/UI/CLEAR.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "CLEAR")->SetPosition(Vector3(0.0f, 300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "CLEAR")->SetScale(Vector3(800.0f, 600.0f, 0.0f));

	// プレイヤー
	/*objectmanager.AddObject<Player>(PLAYER, "Player_Result");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetPosition(Vector3(-500.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));*/

	//// 地面
	//objectmanager.AddObject<GameObject>(GROUND, "Ground_Result");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	std::cout << "ResultSceneInit" << std::endl;
}


void ResultScene::Update(void) {
	Input::GetInstance().Update();
	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}

	objectmanager.Update();
	
	/* カーソル移動 */
	if(Input::GetInstance().GetKeyPress(VK_DOWN)){
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->GetPosition();
		cursol_pos.y = -400.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->SetPosition(cursol_pos);
		XMINT2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->GetUV();
		Button1.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->SetUV(Button1);
		XMINT2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->GetUV();
		Button2.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->SetUV(Button2);
	}

	if (Input::GetInstance().GetKeyPress(VK_UP)) {
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->GetPosition();
		cursol_pos.y = -200.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->SetPosition(cursol_pos);
		XMINT2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->GetUV();
		Button1.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2")->SetUV(Button1);
		XMINT2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->GetUV();
		Button2.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1")->SetUV(Button2);
	}
	Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol")->GetPosition();

	/*　シーン遷移　*/
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{

		if (cursol_pos.y == -200.0f)
		{
			m_RequestNext = TITLE;
			SetChangeScene(true);
		}

		if (cursol_pos.y == -400.0f)
		{
			m_RequestNext = QUIT;
			SetChangeScene(true);
		}
	}
}


void ResultScene::Draw(void) {
	objectmanager.Draw();
}


void ResultScene::Uninit(void) {
	objectmanager.Uninit();
}

void ResultScene::ChangeFRAME(void) {
	std::cout << "ChangeFRAME関数" << std::endl;
}