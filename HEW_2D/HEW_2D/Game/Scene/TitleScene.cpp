#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"


/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
 * 
 * ステージは、縦２０マス＊横４０マス
*/
void TitleScene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();
	

	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	// TODO:1218ここまで オブジェクトの管理をenumから変更→tagと名前にしたい
	
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	//擬音（どおん）
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/Gion.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->SetPosition(Vector3(500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	
	// マガジン(二個持った状態でスタート、落ちてるのは一個だけ)
	// 一個目
	objectmanager.AddObject<Magazine>(UI, "Magazine1");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 二個目
	objectmanager.AddObject<Magazine>(UI, "Magazine2");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 二つは子オブジェクトに設定してUIに変更しておく
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second);
	
	// 変更するべきこと→取得したマガジンをしっかり自身の所有オブジェクトとして設定する
	// →
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->Set
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	// 三個目
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}



void TitleScene::Update(void)
{
	
	// 入力情報の更新
	Input::GetInstance().Update();
	// 入力管理
	// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}


	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
	
	// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
	if (Input::GetInstance().GetKeyPress(VK_F))
	{
		Vector3 p_pos = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->GetPosition();
		//Suction(gion_pos, p_pos);
		if (gion_pos.x - p_pos.x <= 300 && gion_pos.x - p_pos.x >= 0)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
		{
			//ここに、近づくスピードを書く
			gion_pos.x -= 14;
			std::cout << "吸い込んでます" << std::endl;
			objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->SetPosition(gion_pos);
		}
		std::cout << "擬音座標：" << gion_pos.x << std::endl;
	}
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える


	//----------------当たり判定-----------------------
	auto playerShared = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground");
	ColliderPlayer_Ground(playerShared, groundShared);


	// ここでマガジンがUIになっていなければ当たり判定を取りたい
	if (m_MagCount >= 1)
	{
		// １つのシーンに落ちてるマガジン数は一個なので、シーンの持つマガジンカウントが１ならまだ当たっていない
		// →判定チェックする

		auto magShared = objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine3");

		// マガジンと地面
		Collider_toGround(std::weak_ptr<Magazine>(magShared.second), groundShared);
		// プレイヤーとマガジンが当たったら
		if (Collider_Player_to_Magazine(playerShared, objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")))
		{
			// マガジンのタグを変更
			objectmanager.ChangeTag(magShared.first.first, magShared.first.second, UI);
			// プレイヤーの子オブジェクトに設定
			playerShared.lock()->SetChild(magShared.second);
			magShared.second->SetScale(Vector3(75.0f, 75.0f, 0.0f));
			magShared.second->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));
			m_MagCount = 0;
		}

	}

	// マガジンとの当たり判定を毎フレーム取る→マガジンを取得したらその判定チェックはしなくておｋ
	//objectmanager.Collider_Player_to_Object();		// ここで当たったらマガジン数を１つ減らす

	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
