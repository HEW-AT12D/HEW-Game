#include "ResultScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include <Xinput.h>

void ResultScene::Init(void) {
	// オブジェクト追加
	//背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->SetScale(Vector3(1960.0f, 1080.0f, 0.0f));

	objectmanager.AddObject<GameObject>(OBJECT, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->Init(L"Game/Asset/UI/TitleCursol.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(Vector3(-250.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetScale(Vector3(300.0f, 300.0f, 0.0f));

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE1");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->Init(L"Game/Asset/UI/BacktoTitleButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));
	Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
	Button2.x = 1;
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE2");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->Init(L"Game/Asset/UI/EndButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	

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
	

	if(Input::GetInstance().GetKeyPress(VK_DOWN)){
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();
		cursol_pos.y = -400.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(cursol_pos);
		Int2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->GetUV();
		Button1.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetUV(Button1);
		Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
		Button2.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);
	}

	if (Input::GetInstance().GetKeyPress(VK_UP)) {
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();
		cursol_pos.y = -200.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(cursol_pos);
		Int2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->GetUV();
		Button1.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetUV(Button1);
		Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
		Button2.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);
	}
	Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();

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

	//// スティック入力値を取得
	//Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// 右スティック入力
	//Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// 左スティック入力

	//auto playerResult = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result");
	//auto groundResult = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result");
	////playerResult.lock()->Update();
	///*if (!BoxCollider2(playerResult.lock(), groundResult.lock(), playerResult.lock()))
	//{
	//	playerResult.lock()->SetOnGround(false);
	//}*/

	//// 入力管理
	//	// 右移動
	//if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetMoveRight(true);
	//	//sound.Play(SOUND_LABEL_BGM000);
	//	//デバック用
	//	//std::cout << "Playerの座標移動ができています" << std::endl;
	//}
	//// 左移動
	//if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetMoveLeft(true);

	//	//デバック用
	//	//std::cout << "Playerの座標移動ができています" << std::endl;
	//}
	//// ジャンプ
	//if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetJump(true);
	//	//デバック用
	//	//std::cout << "Playerの座標移動ができています" << std::endl;
	//}

	//// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
	//	// プレイヤー発の扇型と当たってる擬音を探す→(一番近くの)当たってる擬音を吸い込む
	//if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	//{
	//	// 吸い込める擬音を探す
	//	// そのフレーム内のタグが擬音のもの全て取得→それとプレイヤーから出る扇型の当たり判定を取得
	//	//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
	//	auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);

	//	//バイブレーションスタート
	//	Input::GetInstance().SetVibration(0.5f, 1.0f);

	//	// 擬音が0ではなければ
	//	if (!onomatopoeias.empty())
	//	{

	//		// 扇形との当たり判定を取得
	//		auto HitOnomatopoeia = ColliderFan_Gion(playerResult.lock(), onomatopoeias);

	//		// ポインタに値が入っていれば(扇形範囲内に当たった擬音があれば)
	//		if (HitOnomatopoeia.second)
	//		{
	//			// 擬音の吸い込み実行
	//			playerResult.lock()->SetIsSuction(true);			// プレイヤーの状態を吸い込み中に設定

	//			// 吸い込み処理が終わったら
	//			if (playerResult.lock()->Suction(HitOnomatopoeia.second))
	//			{

	//				// 吸い込み処理が終わった時に擬音のタグをUIに変更、射撃するときにタグを擬音に変更する処理がまだ
	//				objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);
	//				/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
	//				gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
	//			}
	//		}
	//		// 擬音が0(吸い込み中に扇型範囲から擬音がいなくなった場合)
	//		else
	//		{
	//			// プレイヤーの状態を変更
	//			playerResult.lock()->SetIsSuction(false);		// 「非」吸い込み中に設定
	//		}
	//	}
	//	// 擬音が0(フレーム内の擬音がない場合)
	//	else
	//	{
	//		// プレイヤーの状態を変更
	//		playerResult.lock()->SetIsSuction(false);		// 「非」吸い込み中に設定
	//	}
	//}
	//else {
	//	Input::GetInstance().SetVibration(0.0f, 0.0f); //バイブレーション初期化
	//}

	//if (Input::GetInstance().GetKeyTrigger(VK_RETURN) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_Y))
	//{
	//	//ここでTITLEに戻る
	//	m_RequestNext = TITLE;
	//	SetChangeScene(true);
	//}

}


void ResultScene::Draw(void) {
	objectmanager.Draw();
}


void ResultScene::Uninit(void) {

}

void ResultScene::ChangeFRAME(void) {
	std::cout << "ChangeFRAME関数" << std::endl;
}