#include "TestScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/SoundGun/SoundGun.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"


/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
*/



void TestScene::Init(void) {
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
	objectmanager.AddObject<Poyon>(OBJECT, "Gion");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/Gion.png");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));


	// マガジン
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1200.0f, 120.0f, 0.0f));

	// 地面2
	objectmanager.AddObject<GameObject>(OBJECT, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->SetPosition(Vector3(700.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(OBJECT, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	//50音
	objectmanager.AddObject<GameObject>(OBJECT, "Moji");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->Init(L"Game/Asset/GameObject/Moji.png", 12, 5);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetScale(Vector3(300.0f, 300.0f, 0.0f));

	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}



void TestScene::Update(void)
{

	// 入力情報の更新
	Input::GetInstance().Update();


	auto playerShared = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2");
	auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime");
	Vector3 player_angre = playerShared.lock()->GetRotation();

	// 入力管理
	// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE))
	{
		if (Collider_toGround(playerShared, groundShared))
		{
			objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

			/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
			pos.x -= 5.0f;
			objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

			Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
			objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

			//デバック用
			std::cout << "Playerの座標移動ができています" << std::endl;
		}

	}

	//50音の切り替え(確認用)
	if (Input::GetInstance().GetKeyRelease(VK_N))
	{
		Int2 moji = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->GetUV();
		moji.y++;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetUV(moji);
		if (moji.y >= 5)
		{
			moji.y = 0;
			moji.x++;
			objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetUV(moji);
		}
	}


	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}


	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える


	//----------------当たり判定-----------------------

	//---------------ここは変えるべき↓--------------//
	if (Collider_toGround(playerShared, groundShared2))
	{
		Collider_toGround(playerShared, groundShared2);//付与するGround
	}
	else if (Collider_toGround(playerShared, groundShared))//PlayerとGroundの当たり判定
	{
		Collider_toGround(playerShared, groundShared);
	}
	//----------------------------------------------//

	Collider_toGround(enemyShared, groundShared);//EnemyとGroundの当たり判定
	Collider_toGround(objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine"), objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground"));//マガジンとGroundの当たり判定

	//付与予定のGroundとの当たり判定
	if (Collider_toGround(gionShared, groundShared2))
	{

		//擬音のチェックフラグ
		//gionShared.lock()->Collider_check = true;
		if (Collider_toGround(playerShared, groundShared2))
		{
			//gionShared.lock()->BriBri_check = true;
			//gionShared.lock()->Action(playerShared);

			gionShared.lock()->Action();

		}
		else {
			//まだ付与されていないPlayerとGroundが衝突している
			Collider_toGround(playerShared, groundShared);
			playerShared.lock()->SetRotation(player_angre);
		}

	}
	//Playerと付与されたGroundが衝突しているのか


	//gionShared.lock()->Action(playerShared);//オブジェクトが付与される

	//------------↑もっといい書き方あるはず↑------------------------

	// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
	if (Input::GetInstance().GetKeyPress(VK_F))
	{
		//ここに位置を生当たり判定追加してもいいかも
		if (ColliderFan_Gion(playerShared, gionShared))
		{
			playerShared.lock()->Suction(gionShared);

			//擬音のデータをここに格納している？
			//playerShared.lock()->magazine.push_back(gionShared.lock());
		}
	}

	//-----------------吐き出しの処理--------------------//
	if (Input::GetInstance().GetKeyPress(VK_R))
	{
		//吐き出しの処理
		playerShared.lock()->Reverse(gionShared);
	}
	

	//Enemyの動作
	Vector3 slime_pos = objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->GetPosition();
	std::cout << "スライムの座標：" << slime_pos.y << std::endl;
	objectmanager.Update();

}

void TestScene::Draw(void) {
	objectmanager.Draw();
}

void TestScene::Uninit(void) {
	objectmanager.Uninit();
}
