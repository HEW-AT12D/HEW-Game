#include "Stage2Scene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"


/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
 *
 * ステージは、縦２０マス＊横４０マス
*/

void Stage2Scene::Frame1() {
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	//チュートリアル看板(吸引編)
	objectmanager.AddObject<GameObject>(BACKGROUND, "board1");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->Init(L"Game/Asset/GameObject/board.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->SetScale(Vector3(500.0f, 500.0f, 0.0f));

	// プレイヤー(看板用)
	objectmanager.AddObject<GameObject>(BACKGROUND, "Playerboard");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->SetPosition(Vector3(-500.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// スライム(看板用)
	objectmanager.AddObject<GameObject>(ENEMY, "Slimeboard");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->SetPosition(Vector3(-350.0f, -180.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->SetScale(Vector3(60.0f, 30.0f, 0.0f));

	//銃のエフェクト(看板用)
	objectmanager.AddObject<GameObject>(UI, "SoundGunboard");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->SetPosition(Vector3(-430.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->SetScale(Vector3(70.0f, 60.0f, 0.0f));

	// ポヨンを付与するためのオブジェクト
	objectmanager.AddObject<GameObject>(OBJECT, "baneboard");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetPosition(Vector3(-350.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetScale(Vector3(50.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));

	//ポヨン(看板用)
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "Poyonboard");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetScale(Vector3(150.0f, 75.0f, 0.0f));

	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Completion_Player_Sprite.png", 2, 6);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// 擬音銃(設計的には銃を別画像で用意してプレイヤーに持たせる方が良かったが、)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

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
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second); //ドーン

	// 変更するべきこと→取得したマガジンをしっかり自身の所有オブジェクトとして設定する
	// →
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->Set
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	


	// 三個目
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	

	// バネ
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(0.0f, -415.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


	// 地面2
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(600.0f, -40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(900.0f, 130.0f, 0.0f));

	// 地面3
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(400.0f, 40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));



	//擬音（ビリビリ）
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(450.0f, 60.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));

	// クロスヘア
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
	// クロスヘアをプレイヤーの子オブジェクトとして設定
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//enemy擬音
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));


	//サンダーエフェクト
	objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

	//マガジンの外枠
	objectmanager.AddObject<GameObject>(UI, "Frame");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

	//ゴール
	objectmanager.AddObject<GameObject>(OBJECT, "door");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->Init(L"Game/Asset/GameObject/door.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetPosition(Vector3(850.0f, -370.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetScale(Vector3(100.0f, 150.0f, 0.0f));

	std::vector<std::shared_ptr<GameObject>> objects = {
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock(),//地面１
	};

	//擬音（ドーン）
	objectmanager.AddObject<Poyon>(Doon, "Gion2");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->SetPosition(Vector3(800.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

}

void Stage2Scene::Frame2() {
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2.lock()->GetPosition();
	pos.x = -700.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2.lock()->SetPosition(pos);
	
	/*objectmanager.AddObject<GameObject>(OBJECT, "FRAME2bane");
    objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->SetScale(Vector3(200.0f, 250.0f, 0.0f));*/

	//enemy擬音
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "FRAME2Poyon");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//パタパタの箱
	objectmanager.AddObject<PataPata>(GROUND, "FRAME2Box");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetPosition(Vector3(200.0f,-400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Groundの一番右
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground1");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->SetPosition(Vector3(500.0f, -100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Groundの真ん中
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground2"); // 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetPosition(Vector3(-180.0f, 100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Groundの一番左
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground3");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//擬音（ドーン）
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "FRAME2Gion2");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->SetScale(Vector3(150.0f, 100.0f, 0.0f));

	//宝箱
	objectmanager.AddObject<GameObject>(OBJECT, "FRAME2treasure");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->Init(L"Game/Asset/GameObject/takarabako.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->SetScale(Vector3(150.0f, 100.0f, 0.0f));
}

void Stage2Scene::Frame3() {
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(-700.0f, 200.0f, 0.0f));

	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2.lock()->GetPosition();
	pos.x = -900.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2.lock()->SetPosition(pos);

	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetScale(Vector3(300.0f, 30.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetPosition(Vector3(-180.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetPosition(Vector3(850.0f, 150.0f, 0.0f));

	//パタパタ擬音
	objectmanager.AddObject<PataPata>(ONOMATOPOEIA, "FRAME3patapata");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->Init(L"Game/Asset/Onomatopoeia/pata.png");
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->SetPosition(Vector3(-500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//ビリビリエフェクト
	objectmanager.AddObject<BiriBiri>(UI, "FRAME3biribiriefect");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->SetPosition(Vector3(550.0f, -460.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->SetScale(Vector3(400.0f, 800.0f, 0.0f));

	//ビリビリ擬音
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//パタパタBOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box1");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->SetPosition(Vector3(-330.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//パタパタBOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box2");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->SetPosition(Vector3(50.0f, -410.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Groundの一番右
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground1");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->SetPosition(Vector3(750.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//ビリビリの床
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground2");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->SetPosition(Vector3(550.0f, -450.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->SetScale(Vector3(200.0f, 50.0f, 0.0f));

	// バネ
	objectmanager.AddObject<GameObject>(OBJECT, "baneFRAME3");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->Init(L"Game/Asset/GameObject/bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->SetPosition(Vector3(300.0f, -420.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/SlimeRight.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));
}

void Stage2Scene::Frame4() {

}

void Stage2Scene::Init(void) {
	// BGM再生
	Sound::GetInstance().Play(BGM_INGAME);


	// オブジェクトマネージャ初期化
	objectmanager.Init();
	Frame1();
	//sound.Init();


	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	// TODO:1218ここまで オブジェクトの管理をenumから変更→tagと名前にしたい


	

	std::cout << "TitleSceneInit" << std::endl;

	std::cout << "GameSceneInit" << std::endl;

	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}

int count = 0; // お情けグローバル変数

void Stage2Scene::Update(void)
{
	Input::GetInstance().Update();
	// スティック入力値を取得
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// 右スティック入力
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// 左スティック入力

	//sound.Play(SOUND_LABEL_BGM000);


	// 入力情報の更新
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	auto grounds = objectmanager.GetObjects<GameObject>(GROUND);	// 地面(配列)
	auto under_ground = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");
	auto enemygion = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");
	auto enemygion2 = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon");
	auto baneShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane");
	auto poyonShared = objectmanager.GetGameObjectPtr<GameObject>(Doon, "Gion2");
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");
	auto BoxShared = objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box");
	auto Ground2FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2");
	auto Ground3FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3");
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto PataPataFRAME3 = objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata");
	auto Ground1FRAME3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1");
	auto PataPatagion = objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata");
	auto efectThunder = objectmanager.GetGameObjectPtr<GameObject>(UI, "FRAME3biribiriefect");
	auto BriBriFRAME3 = objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri");
	auto Ground2FRAME3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2");
	auto baneFRAME3 = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3");
	auto FRAME3Box1 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Box1");
	auto FRAME3Box2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Box2");
	auto gionShared = objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion");
	auto treasureBox = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
	auto GOOL = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door");
	auto Ground1FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1");
	auto Frame_Red = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame");
	auto Magazine1 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1"); //ドーン
	auto Magazine2 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2"); //もともとあるやつ
	auto Magazine3 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine3"); //落ちてるやつ

	Vector3 pos = playerShared.second->GetPosition();
	Vector3 p_enemy = enemyShared.lock()->GetPosition();


	switch (m_Frame)
	{
	case FRAME1:
		

		break;
	case FRAME2:
		objectmanager.DeleteObject(Doon, "Gion2");
		/*if (ColliderPlayer_Ground(playerShared2.lock(), Ground1FRAME2)) {
			playerShared2.lock()->SetOnGround(true);
			std::cout << "OnGroundの状態：" << playerShared.second->GetOnGround() << std::endl;
		}*/
		

		BoxCollider2(playerShared2.lock(), BoxShared.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground1FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground2FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground3FRAME2.lock(), playerShared2.lock());

		BoxShared.lock()->Action(BoxShared.lock(),playerShared.second);
		
		//std::cout << "OnGroundの状態：" << playerShared.second->GetOnGround() << std::endl;

		//スライムジャンプ
		if (Collider_toEnemy(enemyShared, groundShared))
		{
			//スライムジャンプフラグ
			if (enemygion2.lock())
			{
				if (enemygion2.lock()->Get_gion() == false)
				{

					Vector3 Slim_Position = enemygion2.lock()->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion2.lock()->SetPosition(Slim_Position);
				}
			}
			enemyShared.lock()->SetJump(true);
		}
		else if (enemygion2.lock()) {
			enemyShared.lock()->SetOnGround(false);
			enemygion2.lock()->Fade_in_out();
		}

		//enemygion2がemptyでないかチェック
		if (enemygion2.lock())
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion2.lock(), baneShared.lock()))
			{
				enemygion2.lock()->Set_gion(true);
				Vector3 _p_poyon = baneShared.lock()->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneShared.lock()->GetRotation();  //ポヨンの回転
				enemygion2.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2.lock()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion2.lock()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion2.lock()->Get_Onomatope())
			{
				enemygion2.lock()->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneShared.lock()))
				{
					enemygion2.lock()->Action(playerShared.second); //当たっていればAction関数実行
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}


		//enemygion2がemptyでないかチェック
		if (gionShared.lock())
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(gionShared.lock(), treasureBox.lock()))
			{
				gionShared.lock()->Set_gion(true);
				Vector3 _p_poyon = treasureBox.lock()->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = treasureBox.lock()->GetRotation();  //ポヨンの回転
				gionShared.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				gionShared.lock()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				gionShared.lock()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (gionShared.lock()->Get_Onomatope())
			{
				gionShared.lock()->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(gionShared.lock(), treasureBox.lock()))
				{
					//gionShared.lock()->Action(playerShared.second); //当たっていればAction関数実行
					treasureBox.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}

		// フレーム遷移処理
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				m_Frame = FRAME3;
				//playerShared.second->SetOnGround(false);
				Frame3();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");
				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1のポヨン
				objectmanager.DeleteObject(GROUND, "FRAME2Ground1");
			}
		}
		objectmanager.Update(); //Playerの物理挙動

		break;
	case FRAME3:
		objectmanager.DeleteObject(OBJECT, "bane");

		BoxCollider2(playerShared2.lock(), BoxShared.lock(),playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground3FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground2FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground1FRAME3.lock(), playerShared2.lock());

		if (PataPataFRAME3.lock())
		{
			if (BoxCollider(PataPataFRAME3.lock(), BoxShared.lock()))
			{
				Vector3 PaPata_Position = PataPataFRAME3.lock()->GetPosition();
				Vector3 Box_pos = BoxShared.lock()->GetPosition();
				PaPata_Position = Box_pos;
				PaPata_Position.y = PaPata_Position.y + 100;
				PataPataFRAME3.lock()->SetPosition(PaPata_Position);
			}
			BoxShared.lock()->Action(BoxShared.lock(), playerShared.second);
		}

		//ビリビリ
		if (BriBriFRAME3.lock())
		{
			if (BoxCollider(BriBriFRAME3.lock(), efectThunder.lock()))
			{
				efectThunder.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				//_p_biribiri.x = _p_biribiri.x - 250;
				//_p_biribiri.y = _p_biribiri.y + 80;
				//_r_biribiri.z = _r_biribiri.z - 15;
				BriBriFRAME3.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				//
				//gionShared.lock()->SetPosition(_p_biribiri); //ポヨンの画像の座標をバネにくっつける
				//gionShared.lock()->SetRotation(_r_biribiri); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else {
				efectThunder.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //ビリビリのエフェクトを色で消えた感じにしてる
			}

			//BriBriFRAME3.lock()->Fade_in_out();
			//二回目の回収をするまではずっとtrue
			if (BriBriFRAME3.lock()->Get_Onomatope())
			{
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, Ground2FRAME3.lock()))
				{
					playerShared.second->SetOnGround(true);
					BriBriFRAME3.lock()->Action(playerShared.second); //当たっていればAction関数実行
				}
				else {
					Vector3 r_player = playerShared.second->GetRotation();
					r_player.z = 0;
					playerShared.second->SetRotation(r_player);
				}
			}
		}
		else {
			std::cout << "enemygionがemptyです" << std::endl;
		}
		if (BriBriFRAME3.lock())
		{
			efectThunder.lock()->Animation(EFECT, efectThunder);
		}

		//enemygion2がemptyでないかチェック
		if (enemygion2.lock())
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion2.lock(), baneFRAME3.lock()))
			{
				enemygion2.lock()->Set_gion(true);
				Vector3 _p_poyon = baneFRAME3.lock()->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneFRAME3.lock()->GetRotation();  //ポヨンの回転
				enemygion2.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2.lock()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion2.lock()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion2.lock()->Get_Onomatope())
			{
				enemygion2.lock()->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneFRAME3.lock()))
				{
					enemygion2.lock()->Action(playerShared.second); //当たっていればAction関数実行
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}

		////enemygionがemptyでないかチェック
		//if (PataPataFRAME3.lock())
		//{
		//	//パタパタの画像とバネの画像が当たっているか
		//	if (BoxCollider(PataPataFRAME3.lock(), FRAME3Box2.lock()))
		//	{

		//		PataPataFRAME3.lock()->Set_gion(true);
		//		Vector3 _p_poyon = FRAME3Box2.lock()->GetPosition(); //ポヨンの座標
		//		Vector3 _r_poyon = FRAME3Box2.lock()->GetRotation();  //ポヨンの回転
		//		PataPataFRAME3.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
		//		_p_poyon.x = _p_poyon.x + 30;
		//		_p_poyon.y = _p_poyon.y + 20;
		//		_r_poyon.z = _r_poyon.z - 15;
		//		PataPataFRAME3.lock()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
		//		PataPataFRAME3.lock()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
		//		std::cout << "当りました" << std::endl;
		//	}
		//	else
		//	{
		//		//std::cout << "当たっていません" << std::endl;
		//	}

		//	//二回目の回収をするまではずっとtrue
		//	if (PataPataFRAME3.lock()->Get_Onomatope())
		//	{
		//		PataPataFRAME3.lock()->Fade_in_out();
		//		//Playerと付与したオブジェクトが当たっているか
		//		if (BoxCollider(playerShared.second, FRAME3Box2.lock()))
		//		{
		//			PataPataFRAME3.lock()->Action(PataPataFRAME3.lock(),playerShared.second); //当たっていればAction関数実行
		//		}
		//	}
		/*}
		else {
			std::cout << "enemygionがemptyです" << std::endl;
		}*/

		// フレーム遷移処理
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				//m_Frame = FRAME_MAX;
				playerShared.second->SetOnGround(false);
				//Frame4();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");
				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1のポヨン
				Sound::GetInstance().Stop(BGM_INGAME);
				//ここでTITLEに戻る
				m_RequestNext = RESULT;
				SetChangeScene(true);
			}
		}
		objectmanager.Update(); 
		break;
	case FRAME4:
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}

	//FRAME1～FRAME3までの地面の当たり判定
	if (!BoxCollider2(playerShared2.lock(), under_ground.lock(), playerShared2.lock()))
	{
		playerShared.second->SetOnGround(false);
	}

	// マガジンに擬音が入っていればエイムの位置に発射
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger())
	{
		//poyonShared.lock()->Set_Onomatope(true); //擬音が発射中かのフラグ
		// マガジンに擬音が装填されているかチェック
		if (playerShared.second->GetLoadedBullet())
		{
			//if (BoxCollider(Frame_Red.lock(), Magazine1.lock())) //ドーン専用
			//{
			//	playerShared.second->UseMagNumber = 0;
			//}
			//else if (BoxCollider(Frame_Red.lock(), Magazine2.lock()))
			//{
			//	playerShared.second->UseMagNumber = 1;
			//}
			playerShared.second->SetIsShot(true);


			//--------------------------------------
			//			擬音のタグ変更処理
			//--------------------------------------

			// ここオブジェクトマネージャから擬音の情報持ってきたほうが良いかも？

			// ここで擬音のタグをUIから擬音に変更
			// →擬音のポインタだけわかってるのにキーの特定がスムーズにできないのでやっぱり管理方法変えたほうがいい(登録されてるタグを毎フレーム確認して同期させるとか)

			// ここでは持ってきた擬音がキャストできた型によってその擬音のタグを変えるようにする
			auto bullet = playerShared.second->GetLoadedBullet();

			switch (m_Frame)
			{
			case FRAME1:
				// 擬音が"パタパタ"の場合
				if (dynamic_cast<PataPata*>(bullet))
				{
					objectmanager.ChangeTag(UI, "PataPata", ONOMATOPOEIA);
				}
				// "ビリビリ"の場合
				else if (dynamic_cast<BiriBiri*>(bullet))
				{
					objectmanager.ChangeTag(UI, "BiriBiri", ONOMATOPOEIA);
				}
				// "ポヨン"の場合
				else if (dynamic_cast<Poyon*>(bullet))
				{
					objectmanager.ChangeTag(UI, "Poyon", ONOMATOPOEIA);
				}
				// それ以外(不明な型)の場合
				else
				{
					throw std::runtime_error("擬音をキャストできませんでした");
				}
				break;
			case FRAME2:
				// 擬音が"パタパタ"の場合
				if (dynamic_cast<PataPata*>(bullet))
				{
					objectmanager.ChangeTag(UI, "PataPata", ONOMATOPOEIA);
				}
				// "ビリビリ"の場合
				else if (dynamic_cast<BiriBiri*>(bullet))
				{
					objectmanager.ChangeTag(UI, "Gion", ONOMATOPOEIA);
				}
				// "ポヨン"の場合
				else if (dynamic_cast<Poyon*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME2Poyon", ONOMATOPOEIA);
				}
				// それ以外(不明な型)の場合
				else
				{
					throw std::runtime_error("擬音をキャストできませんでした");
				}
				break;
			case FRAME3:
				// 擬音が"パタパタ"の場合
				if (dynamic_cast<PataPata*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME3patapata", ONOMATOPOEIA);
				}
				// "ビリビリ"の場合
				else if (dynamic_cast<BiriBiri*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME3biribiri", ONOMATOPOEIA);
				}
				// "ポヨン"の場合
				else if (dynamic_cast<Poyon*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME2Poyon", ONOMATOPOEIA);
				}
				// それ以外(不明な型)の場合
				else
				{
					throw std::runtime_error("擬音をキャストできませんでした");
				}
				break;
			case FRAME4:
				break;
			case FRAME_MAX:
				break;
			default:
				break;
			}
			
			// SE再生
			Sound::GetInstance().Play(SE_SHOT);
			playerShared2.lock()->SetMagNumber(1); //0番目の配列

		}
	}

	// R1でマガジンカーソル右移動
	if (Input::GetInstance().GetKeyTrigger(VK_P) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		// カーソルの座標取得
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();

		// ドォン用マガジンを除く一番最後のマガジンを選択していなければ
		if (playerShared.second->GetMagNumber() != playerShared.second->GetMagCount() - 1)
		{
			// マガジン選択番号を１増やして
			playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() + 1);
			// カーソルを右に移動
			p_frame.x += 120.0f;
		}
		// 一番最後のマガジンを選択している場合
		else
		{
			// マガジン選択番号を１(ドォン用マガジンを除く一番最初)に戻して
			playerShared.second->SetMagNumber(1);
			// カーソルを初期位置に移動
			p_frame.x = -900.0f;
		}
		// 座標を設定
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		// SE再生
		Sound::GetInstance().Play(SE_CLICK);
	}
	// L1でマガジンカーソル左移動
	if (Input::GetInstance().GetKeyTrigger(VK_O) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_LEFT_SHOULDER))
	{
		// カーソルの座標取得
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();

		// ドォン用マガジンを除く一番最初のマガジンを選択していなければ
		if (playerShared.second->GetMagNumber() != 1)
		{
			Sound::GetInstance().Play(SE_CLICK);
			// マガジン選択番号を１減らして
			playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() - 1);
			// カーソルを左に移動
			p_frame.x -= 120.0f;
		}
		// 一番最初のマガジンを選択している場合
		else
		{
			// マガジン選択用カーソルを取得
			auto magcursor = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock();
			// マガジン選択番号を(ドォン用マガジンを除く)一番後ろにして
			playerShared.second->SetMagNumber(playerShared.second->GetMagCount() - 1);
			// カーソルを一番後ろの位置に移動
			p_frame.x = -900.0f + magcursor->GetScale().x * (playerShared.second->GetMagCount() - 2);	// 初期位置 + カーソルの大きさ * マガジン数(ドォン入れないので-2)
		}
		// 座標を設定
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		// SE再生
		Sound::GetInstance().Play(SE_CLICK);
	}


	// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
		// プレイヤー発の扇型と当たってる擬音を探す→(一番近くの)当たってる擬音を吸い込む
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	{
		// 吸い込める擬音を探す
		// そのフレーム内のタグが擬音のもの全て取得→それとプレイヤーから出る扇型の当たり判定を取得
		//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
		auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);
		auto Doononomatopeia = objectmanager.GetGameObjectPair2<IOnomatopoeia>(Doon, "Gion2");

		//バイブレーションスタート
		Input::GetInstance().SetVibration(0.5f, 1.0f);

		// 擬音が0ではなければ
		if (!onomatopoeias.empty())
		{

			// 扇形との当たり判定を取得
			auto HitOnomatopoeia = ColliderFan_Gion(playerShared.second, onomatopoeias);

			// ポインタに値が入っていれば(扇形範囲内に当たった擬音があれば)
			if (HitOnomatopoeia.second)
			{
				// 擬音の吸い込み実行
				playerShared.second->SetIsSuction(true);			// プレイヤーの状態を吸い込み中に設定

				// 吸い込み処理が終わったら
				if (playerShared.second->Suction(HitOnomatopoeia.second))
				{
					
					// 吸い込み処理が終わった時に擬音のタグをUIに変更、射撃するときにタグを擬音に変更する処理がまだ
					objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);
					/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
				}
			}
			// 擬音が0(吸い込み中に扇型範囲から擬音がいなくなった場合)
			else
			{
				// プレイヤーの状態を変更
				playerShared.second->SetIsSuction(false);		// 「非」吸い込み中に設定
				if (m_Frame == FRAME1)
				{
					count = 1; //チュートリアルの画像切り替えカウント
					objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				}
			}
		}
		// 擬音が0(フレーム内の擬音がない場合)
		else
		{
			// プレイヤーの状態を変更
			playerShared.second->SetIsSuction(false);		// 「非」吸い込み中に設定
		}


		// Doon専用
		if (!Doononomatopeia.empty())
		{
			// 扇形との当たり判定を取得
			auto HitDoon = ColliderFan_Gion(playerShared.second, Doononomatopeia);

			// ポインタに値が入っていれば(扇形範囲内に当たった擬音があれば)
			if (HitDoon.second)
			{
				// 擬音の吸い込み実行
				playerShared.second->SetIsSuction(true);			// プレイヤーの状態を吸い込み中に設定

				// 吸い込み処理が終わったら
				if (playerShared.second->Suction(HitDoon.second))
				{
					playerShared.second->m_Magazines.resize(2); //最低限１コ確保
					if (HitDoon.second == poyonShared.lock())
					{
						poyonShared.lock()->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
						poyonShared.lock()->SetScale(Vector3(300.0f, 150.0f, 0.0f));
					}
					playerShared.second->m_Magazines[0] = std::static_pointer_cast<Magazine>(poyonShared.lock()); //キャストして配列の０番目に格納
					// 吸い込み処理が終わった時に擬音のタグをUIに変更、射撃するときにタグを擬音に変更する処理がまだ
					objectmanager.ChangeTag(HitDoon.first.first, HitDoon.first.second, UI);
					/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
				}
			}
			// 擬音が0(吸い込み中に扇型範囲から擬音がいなくなった場合)
			else
			{
				// プレイヤーの状態を変更
				playerShared.second->SetIsSuction(false);		// 「非」吸い込み中に設定

			}
		}
		// 擬音が0(フレーム内の擬音がない場合)
		else
		{
			// プレイヤーの状態を変更
			playerShared.second->SetIsSuction(false);		// 「非」吸い込み中に設定
		}
	}
	else {
		Input::GetInstance().SetVibration(0.0f, 0.0f); //バイブレーション初期化
	}
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える

	// 入力管理
		// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		//sound.Play(SOUND_LABEL_BGM000);
		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);
		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}

	// クロスヘアの入力取得(本来はプレイヤーのフラグを立てて、プレイヤーの更新の中でクロスヘアを動かすべき)XINPUT_GAMEPAD_RIGHT_THUMB
	if (Input::GetInstance().GetKeyPress(VK_UP) || RightStickInput.y > 0.1f)
	{
		crosshairShared.lock()->SetMoveUp(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveUp(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_DOWN) || RightStickInput.y < -0.1f)
	{
		crosshairShared.lock()->SetMoveDown(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveDown(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_RIGHT) || RightStickInput.x > 0.1f)
	{
		crosshairShared.lock()->SetMoveRight(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveRight(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_LEFT) || RightStickInput.x < -0.1f)
	{
		crosshairShared.lock()->SetMoveLeft(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveLeft(false);
	}


	if (m_Frame == FRAME1)
	{
		Vector3 poyon_rotation = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->GetRotation();
		Vector3 poyon_posiiton = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->GetPosition();

		if (count == 0)
		{
			poyon_rotation.z += 5.0f;
		}
		else if(count == 1){
			poyon_rotation.z = 0.0f;
			objectmanager.DeleteObject(ENEMY, "Slimeboard");
			objectmanager.DeleteObject(UI, "SoundGunboard");
		}
		objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetRotation(poyon_rotation);

		std::cout << playerShared2.lock()->m_Magazines.size() << std::endl; //マガジン数のデバック
		// シーン更新に必要な情報を取得
		auto grounds2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
		auto effectShared = objectmanager.GetGameObjectPtr<GameObject>(UI, "Thunder_Effect");
		auto groundShared3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3");

		 BoxCollider2(playerShared2.lock(), groundShared2.lock(),playerShared2.lock());
		
		effectShared.lock()->Animation(EFECT, effectShared);

		////擬音の選択
		//if (Input::GetInstance().GetKeyTrigger(VK_P))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();
		//	p_frame.x = p_frame.x + 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		//}
		//if (Input::GetInstance().GetKeyTrigger(VK_O))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();
		//	p_frame.x = p_frame.x - 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		//}


		//ゲーム画面に遷移
		// シーン遷移（デバック用
		/*if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			this->ChangeScene = true;
			SetChangeScene(this->ChangeScene);
		}*/


		
		//ColliderPlayer_Ground(playerShared.second, grounds2);



		//スライムジャンプ
		if (Collider_toEnemy(enemyShared, groundShared))
		{
			//スライムジャンプフラグ
			if (enemygion.lock())
			{
				if (enemygion.lock()->Get_gion() == false)
				{

					Vector3 Slim_Position = enemygion.lock()->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion.lock()->SetPosition(Slim_Position);
				}
				else {
					Vector3 pos_bane = baneShared.lock()->GetPosition();
					baneShared.lock()->SetPosition(pos_bane);
				}

			}
			enemyShared.lock()->SetJump(true);
		}
		else if (enemygion.lock()) {
			enemyShared.lock()->SetOnGround(false);
			enemygion.lock()->Fade_in_out();
		}

		if (enemygion.lock() != nullptr)
		{
			Vector4 poyon_color = enemygion.lock()->GetColor(); //エラー：吸収する瞬間にenemygion自体が削除されるのでエラーが出る
			Vector3 p_poyon = p_enemy;
			p_poyon.x = p_poyon.x + 50;
			p_poyon.y = p_poyon.y + 150;
		}

		Vector3 enemy_Rotation = enemyShared.lock()->GetRotation();


		if (p_enemy.x <= -300)
		{
			enemyShared.lock()->cb.matrixWorld = DirectX::XMMatrixScaling(-1.0f, 1.0f, 1.0f);
		}
		//std::cout << p_enemy.x << std::endl;

		Vector3 _p_biribiri = effectShared.lock()->GetPosition(); //ポヨンの座標
		Vector3 _r_biribiri = effectShared.lock()->GetRotation();  //ポヨンの回転

		//enemygionがemptyでないかチェック
		if (enemygion.lock())
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion.lock(), baneShared.lock()))
			{

				enemygion.lock()->Set_gion(true);
				Vector3 _p_poyon = baneShared.lock()->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneShared.lock()->GetRotation();  //ポヨンの回転
				enemygion.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion.lock()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion.lock()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion.lock()->Get_Onomatope())
			{
				enemygion.lock()->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneShared.lock()))
				{
					enemygion.lock()->Action(playerShared.second); //当たっていればAction関数実行
					Sound::GetInstance().Play(SE_POYON);
				}
			}
		}
		else {
			std::cout << "enemygionがemptyです" << std::endl;
		}

		//ビリビリ
		if (gionShared.lock())
		{
			if (BoxCollider(gionShared.lock(), effectShared.lock()))
			{
				effectShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				//_p_biribiri.x = _p_biribiri.x - 250;
				//_p_biribiri.y = _p_biribiri.y + 80;
				//_r_biribiri.z = _r_biribiri.z - 15;
				gionShared.lock()->Set_Onomatope(true); //当たってたらフラグをtrue
				//
				//gionShared.lock()->SetPosition(_p_biribiri); //ポヨンの画像の座標をバネにくっつける
				//gionShared.lock()->SetRotation(_r_biribiri); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else {
				effectShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //ビリビリのエフェクトを色で消えた感じにしてる
			}

			gionShared.lock()->Fade_in_out();
			//二回目の回収をするまではずっとtrue
			if (gionShared.lock()->Get_Onomatope())
			{
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, groundShared3.lock()))
				{
					playerShared.second->SetOnGround(true);
					gionShared.lock()->Action(playerShared.second); //当たっていればAction関数実行
					Sound::GetInstance().Play(SE_BIRIBIRI);
				}
				else {
					Vector3 r_player = playerShared.second->GetRotation();
					r_player.z = 0;
					playerShared.second->SetRotation(r_player);
				}
			}
		}
		else {
			playerShared2.lock()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		}


		// ここでマガジンがUIになっていなければ当たり判定を取りたい
		if (m_MagCount >= 1)
		{
			// １つのシーンに落ちてるマガジン数は一個なので、シーンの持つマガジンカウントが１ならまだ当たっていない
			// →判定チェックする

			auto magShared = objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine3");

			// マガジンと地面
			Collider_toGround(std::weak_ptr<Magazine>(magShared.second), groundShared);
			// プレイヤーとマガジンが当たったら
			if (Collider_Player_to_Magazine(playerShared.second, objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")))
			{
				// マガジンのタグを変更
				objectmanager.ChangeTag(magShared.first.first, magShared.first.second, UI);
				// プレイヤーの子オブジェクトに設定
				playerShared.second->SetChild(magShared.second);
				/*magShared.second->SetScale(Vector3(75.0f, 75.0f, 0.0f));
				magShared.second->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));*/
				m_MagCount = 0;
			}

		}
		/////////////////////////////////
		// カーソル移動して擬音の選択
		/////////////////////////////////

		
		// マガジンとの当たり判定を毎フレーム取る→マガジンを取得したらその判定チェックはしなくておｋ
		//objectmanager.Collider_Player_to_Object();		// ここで当たったらマガジン数を１つ減らす


		// フレーム遷移処理
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				m_Frame = FRAME2;
				//playerShared.second->SetOnGround(false);
				Frame2();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");

				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1のポヨン
				objectmanager.DeleteObject(BACKGROUND, "board1");
				objectmanager.DeleteObject(BACKGROUND, "Playerboard");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyonboard");
				objectmanager.DeleteObject(ENEMY, "Slimeboard");
				objectmanager.DeleteObject(UI, "SoundGunboard");
				objectmanager.DeleteObject(OBJECT, "baneboard");
			}
		}
		objectmanager.Update();
	}
}

void Stage2Scene::Draw(void) {
	switch (m_Frame)
	{
	case FRAME1:
		break;
	case FRAME2:
		break;
	case FRAME3:
		break;
	case FRAME4:
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}
	objectmanager.Draw();
}

void Stage2Scene::Uninit(void) {
	objectmanager.Uninit();
	//sound.Uninit();
}

void Stage2Scene::ChangeFRAME(void) {
	auto playerSharde = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	Vector3 pos = playerSharde.second->GetPosition();
}