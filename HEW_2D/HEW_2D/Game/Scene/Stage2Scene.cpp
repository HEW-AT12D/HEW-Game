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
 * シーンごとに初期化は最初の一度のみ
 * ステージは、縦２０マス＊横４０マス
*/

void Stage2Scene::Frame1() {
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background")->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background")->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	//チュートリアル看板(吸引編)
	objectmanager.AddObject<GameObject>(BACKGROUND, "board1");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1")->Init(L"Game/Asset/GameObject/board.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1")->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1")->SetScale(Vector3(500.0f, 500.0f, 0.0f));

	// プレイヤー(看板用)
	objectmanager.AddObject<GameObject>(BACKGROUND, "Playerboard");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard")->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard")->SetPosition(Vector3(-500.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard")->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// スライム(看板用)
	objectmanager.AddObject<GameObject>(ENEMY, "Slimeboard");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard")->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard")->SetPosition(Vector3(-350.0f, -180.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard")->SetScale(Vector3(60.0f, 30.0f, 0.0f));

	//銃のエフェクト(看板用)
	objectmanager.AddObject<GameObject>(UI, "SoundGunboard");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard")->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard")->SetPosition(Vector3(-430.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard")->SetScale(Vector3(70.0f, 60.0f, 0.0f));

	// ポヨンを付与するためのオブジェクト
	objectmanager.AddObject<GameObject>(OBJECT, "baneboard");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard")->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard")->SetPosition(Vector3(-350.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard")->SetScale(Vector3(50.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard")->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));

	//ポヨン(看板用)
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "Poyonboard");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->SetScale(Vector3(150.0f, 75.0f, 0.0f));

	// プレイヤー
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->Init(L"Game/Asset/Character/Completion_Player_Sprite.png", 2, 6);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// 擬音銃(設計的には銃を別画像で用意してプレイヤーに持たせる方が良かったが、)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun")->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun")->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun")->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

	// マガジン(二個持った状態でスタート、落ちてるのは一個だけ)
	// 一個目
	objectmanager.AddObject<Magazine>(UI, "Magazine1");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1")->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1")->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 二個目
	objectmanager.AddObject<Magazine>(UI, "Magazine2");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2")->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2")->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 二つは子オブジェクトに設定してUIに変更しておく
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second); //ドーン

	// 変更するべきこと→取得したマガジンをしっかり自身の所有オブジェクトとして設定する
	// →
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->Set
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	// 三個目
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// バネ
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane")->Init(L"Game/Asset/GameObject/Bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane")->SetPosition(Vector3(0.0f, -415.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground")->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground")->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground")->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


	// 地面2
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2")->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2")->SetPosition(Vector3(600.0f, -40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2")->SetScale(Vector3(900.0f, 130.0f, 0.0f));

	// 地面3
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3")->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3")->SetPosition(Vector3(400.0f, 40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3")->SetScale(Vector3(300.0f, 50.0f, 0.0f));



	//擬音（ビリビリ）
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion")->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion")->SetPosition(Vector3(450.0f, 60.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion")->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->SetScale(Vector3(80.0f, 40.0f, 0.0f));

	// クロスヘア
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair")->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair")->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair")->SetScale(Vector3(100.0f, 100.0f, 0.0f));
	// クロスヘアをプレイヤーの子オブジェクトとして設定
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//enemy擬音
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon")->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon")->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon")->SetScale(Vector3(240.0f, 120.0f, 0.0f));


	//サンダーエフェクト
	objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect")->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect")->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect")->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect")->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

	//マガジンの外枠
	objectmanager.AddObject<GameObject>(UI, "Frame");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->SetScale(Vector3(120.0f, 80.0f, 0.0f));

	//ゴール
	objectmanager.AddObject<GameObject>(OBJECT, "door");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door")->Init(L"Game/Asset/GameObject/door.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door")->SetPosition(Vector3(850.0f, -370.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door")->SetScale(Vector3(100.0f, 150.0f, 0.0f));

	std::vector<GameObject*> objects = {
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground"),//地面１
	};

	//擬音（ドーン）
	objectmanager.AddObject<Poyon>(Doon, "Gion2");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2")->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2")->SetPosition(Vector3(800.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2")->SetScale(Vector3(240.0f, 120.0f, 0.0f));

}

void Stage2Scene::Frame2() {
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2->GetPosition();
	pos.x = -700.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2->SetPosition(pos);
	
	/*objectmanager.AddObject<GameObject>(OBJECT, "FRAME2bane");
    objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane")()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane")()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane")()->SetScale(Vector3(200.0f, 250.0f, 0.0f));*/

	//enemy擬音
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "FRAME2Poyon");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon")->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon")->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon")->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//パタパタの箱
	objectmanager.AddObject<PataPata>(GROUND, "FRAME2Box");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box")->SetPosition(Vector3(200.0f,-400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Groundの一番右
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground1");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1")->SetPosition(Vector3(500.0f, -100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1")->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Groundの真ん中
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground2"); // 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2")->SetPosition(Vector3(-180.0f, 100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2")->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Groundの一番左
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground3");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3")->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3")->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//擬音（ドーン）
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "FRAME2Gion2");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2")->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2")->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2")->SetScale(Vector3(150.0f, 100.0f, 0.0f));

	//宝箱
	objectmanager.AddObject<GameObject>(OBJECT, "FRAME2treasure");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure")->Init(L"Game/Asset/GameObject/takarabako.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure")->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure")->SetScale(Vector3(150.0f, 100.0f, 0.0f));
}

void Stage2Scene::Frame3() {
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(-700.0f, 200.0f, 0.0f));

	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2->GetPosition();
	pos.x = -900.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2->SetPosition(pos);

	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box")->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box")->SetScale(Vector3(300.0f, 30.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2")->SetPosition(Vector3(-180.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door")->SetPosition(Vector3(850.0f, 150.0f, 0.0f));

	//パタパタ擬音
	objectmanager.AddObject<PataPata>(ONOMATOPOEIA, "FRAME3patapata");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata")->Init(L"Game/Asset/Onomatopoeia/pata.png");
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata")->SetPosition(Vector3(-500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata")->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//ビリビリエフェクト
	objectmanager.AddObject<BiriBiri>(UI, "FRAME3biribiriefect");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect")->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect")->SetPosition(Vector3(550.0f, -460.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect")->SetScale(Vector3(400.0f, 800.0f, 0.0f));

	//ビリビリ擬音
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri");	// 名前要変更
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri")->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri")->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri")->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//パタパタBOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box1");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1")->SetPosition(Vector3(-330.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//パタパタBOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box2");	// 名前要変更
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2")->SetPosition(Vector3(50.0f, -410.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Groundの一番右
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground1");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1")->SetPosition(Vector3(750.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1")->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//ビリビリの床
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground2");	// 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2")->SetPosition(Vector3(550.0f, -450.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2")->SetScale(Vector3(200.0f, 50.0f, 0.0f));

	// バネ
	objectmanager.AddObject<GameObject>(OBJECT, "baneFRAME3");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3")->Init(L"Game/Asset/GameObject/bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3")->SetPosition(Vector3(300.0f, -420.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->Init(L"Game/Asset/GameObject/SlimeRight.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime")->SetScale(Vector3(80.0f, 40.0f, 0.0f));
}

void Stage2Scene::Frame4() {
	/* Playerポジション */
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2->GetPosition();
	pos.x = -900.0f; pos.y = 0.0f; pos.z = 0.0f;
	playerShared2->SetPosition(pos);

	/* ゴールポジション */
	auto goalShared = objectmanager.GetGameObjectPtr<GameObject >(OBJECT, "door");
	Vector3 goal_pos = goalShared->GetPosition();
	goal_pos.y = -370.0f;
	goalShared->SetPosition(goal_pos);

	// 左側の地面
	objectmanager.AddObject<GameObject>(GROUND, "ground1");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground1")->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground1")->SetPosition(Vector3(-750.0f, -100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground1")->SetScale(Vector3(650.0f, 50.0f, 0.0f));

	// 右側の壁
	objectmanager.AddObject<GameObject>(GROUND, "ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground2")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground2")->SetPosition(Vector3(600.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground2")->SetScale(Vector3(50.0f, 300.0f, 0.0f));

	// 下のブロック
	objectmanager.AddObject<GameObject>(GROUND, "ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground3")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground3")->SetPosition(Vector3(-450.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "ground3")->SetScale(Vector3(50.0f, 200.0f, 0.0f));

	// パタパタ箱
	objectmanager.AddObject<PataPata>(GROUND, "ground4");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "ground4")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "ground4")->SetPosition(Vector3(-450.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "ground4")->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// バネ入れてる箱
	objectmanager.AddObject<PataPata>(OBJECT, "obj1");
	objectmanager.GetGameObjectPtr<PataPata>(OBJECT, "obj1")->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(OBJECT, "obj1")->SetPosition(Vector3(350.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(OBJECT, "obj1")->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "enemy1");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "enemy1")->Init(L"Game/Asset/GameObject/Slime.png", 2, 1);
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "enemy1")->SetPosition(Vector3(-500.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "enemy1")->SetScale(Vector3(80.0f, 40.0f, 0.0f));

	// ドォン
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "Doon");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Doon")->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Doon")->SetPosition(Vector3(-830.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Doon")->SetScale(Vector3(200.0f, 150.0f, 0.0f));
	// ビリビリ
	// ビリビリエフェクト
	// ビリビリ床
}

void Stage2Scene::Init(void) {
	// サウンド初期化
	sound.Init();
	// BGM再生
	sound.Play(BGM_INGAME);
	// オブジェクトマネージャ初期化
	objectmanager.Init();

	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	Frame1();

	std::cout << "TitleSceneInit" << std::endl;
	std::cout << "GameSceneInit" << std::endl;
}
int count = 0; // お情けグローバル変数

void Stage2Scene::Update(void)
{
	Input::GetInstance().Update();
	// スティック入力値を取得
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// 右スティック入力
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// 左スティック入力


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
	Vector3 p_enemy = enemyShared->GetPosition();


	switch (m_Frame)
	{
	case FRAME1:
		

		break;
	case FRAME2:

		/*if (ColliderPlayer_Ground(playerShared2(), Ground1FRAME2)) {
			playerShared2()->SetOnGround(true);
			std::cout << "OnGroundの状態：" << playerShared.second->GetOnGround() << std::endl;
		}*/
		

		BoxCollider2(playerShared2, BoxShared, playerShared2);
		BoxCollider2(playerShared2, Ground1FRAME2, playerShared2);
		BoxCollider2(playerShared2, Ground2FRAME2, playerShared2);
		BoxCollider2(playerShared2, Ground3FRAME2, playerShared2);

		BoxShared->Action(BoxShared, playerShared.second);
		
		//std::cout << "OnGroundの状態：" << playerShared.second->GetOnGround() << std::endl;

		//スライムジャンプ
		if (Collider_toEnemy(enemyShared, groundShared))
		{
			//スライムジャンプフラグ
			if (enemygion2)
			{
				if (enemygion2->Get_gion() == false)
				{

					Vector3 Slim_Position = enemygion2->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion2->SetPosition(Slim_Position);
				}
			}
			enemyShared->SetJump(true);
		}
		else if (enemygion2) {
			enemyShared->SetOnGround(false);
			enemygion2->Fade_in_out();
		}

		//enemygion2がemptyでないかチェック
		if (enemygion2)
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion2, baneShared))
			{
				enemygion2->Set_gion(true);
				Vector3 _p_poyon = baneShared->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneShared->GetRotation();  //ポヨンの回転
				enemygion2->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion2->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion2->Get_Onomatope())
			{
				enemygion2->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneShared))
				{
					enemygion2->Action(playerShared.second); //当たっていればAction関数実行
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}


		//enemygion2がemptyでないかチェック
		if (gionShared)
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(gionShared, treasureBox))
			{
				gionShared->Set_gion(true);
				Vector3 _p_poyon = treasureBox->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = treasureBox->GetRotation();  //ポヨンの回転
				gionShared->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				gionShared->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				gionShared->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (gionShared->Get_Onomatope())
			{
				gionShared->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(gionShared, treasureBox))
				{
					//gionShared()->Action(playerShared.second); //当たっていればAction関数実行
					treasureBox->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}

		// フレーム遷移処理
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2, GOOL))
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
				objectmanager.DeleteObject(ONOMATOPOEIA, "FRAME2Gion2");
				objectmanager.DeleteObject(OBJECT, "FRAME2treasure");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon");
			}
		}
		objectmanager.Update(); //Playerの物理挙動

		break;
	case FRAME3:
		objectmanager.DeleteObject(OBJECT, "bane");

		BoxCollider2(playerShared2, BoxShared, playerShared.second);
		BoxCollider2(playerShared2, Ground3FRAME2, playerShared2);
		BoxCollider2(playerShared2, Ground2FRAME2, playerShared2);
		BoxCollider2(playerShared2, Ground1FRAME3, playerShared2);

		if (PataPataFRAME3)
		{
			if (BoxCollider(PataPataFRAME3, BoxShared))
			{
				Vector3 PaPata_Position = PataPataFRAME3->GetPosition();
				Vector3 Box_pos = BoxShared->GetPosition();
				PaPata_Position = Box_pos;
				PaPata_Position.y = PaPata_Position.y + 100;
				PataPataFRAME3->SetPosition(PaPata_Position);
			}
			BoxShared->Action(BoxShared, playerShared.second);
		}

		//ビリビリ
		if (BriBriFRAME3)
		{
			if (BoxCollider(BriBriFRAME3, efectThunder))
			{
				efectThunder->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				//_p_biribiri.x = _p_biribiri.x - 250;
				//_p_biribiri.y = _p_biribiri.y + 80;
				//_r_biribiri.z = _r_biribiri.z - 15;
				BriBriFRAME3->Set_Onomatope(true); //当たってたらフラグをtrue
				//
				//gionShared()->SetPosition(_p_biribiri); //ポヨンの画像の座標をバネにくっつける
				//gionShared()->SetRotation(_r_biribiri); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else {
				efectThunder->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //ビリビリのエフェクトを色で消えた感じにしてる
			}

			//BriBriFRAME3()->Fade_in_out();
			//二回目の回収をするまではずっとtrue
			if (BriBriFRAME3->Get_Onomatope())
			{
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, Ground2FRAME3))
				{
					playerShared.second->SetOnGround(true);
					BriBriFRAME3->Action(playerShared.second); //当たっていればAction関数実行
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
		if (BriBriFRAME3)
		{
			efectThunder->Animation(EFECT, efectThunder);
		}

		//enemygion2がemptyでないかチェック
		if (enemygion2)
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion2, baneFRAME3))
			{
				enemygion2->Set_gion(true);
				Vector3 _p_poyon = baneFRAME3->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneFRAME3->GetRotation();  //ポヨンの回転
				enemygion2->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion2->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion2->Get_Onomatope())
			{
				enemygion2->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneFRAME3))
				{
					enemygion2->Action(playerShared.second); //当たっていればAction関数実行
				}
			}
		}
		else {
			std::cout << "enemygion2がemptyです" << std::endl;
		}

		////enemygionがemptyでないかチェック
		//if (PataPataFRAME3())
		//{
		//	//パタパタの画像とバネの画像が当たっているか
		//	if (BoxCollider(PataPataFRAME3(), FRAME3Box2()))
		//	{

		//		PataPataFRAME3()->Set_gion(true);
		//		Vector3 _p_poyon = FRAME3Box2()->GetPosition(); //ポヨンの座標
		//		Vector3 _r_poyon = FRAME3Box2()->GetRotation();  //ポヨンの回転
		//		PataPataFRAME3()->Set_Onomatope(true); //当たってたらフラグをtrue
		//		_p_poyon.x = _p_poyon.x + 30;
		//		_p_poyon.y = _p_poyon.y + 20;
		//		_r_poyon.z = _r_poyon.z - 15;
		//		PataPataFRAME3()->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
		//		PataPataFRAME3()->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
		//		std::cout << "当りました" << std::endl;
		//	}
		//	else
		//	{
		//		//std::cout << "当たっていません" << std::endl;
		//	}

		//	//二回目の回収をするまではずっとtrue
		//	if (PataPataFRAME3()->Get_Onomatope())
		//	{
		//		PataPataFRAME3()->Fade_in_out();
		//		//Playerと付与したオブジェクトが当たっているか
		//		if (BoxCollider(playerShared.second, FRAME3Box2()))
		//		{
		//			PataPataFRAME3()->Action(PataPataFRAME3(),playerShared.second); //当たっていればAction関数実行
		//		}
		//	}
		/*}
		else {
			std::cout << "enemygionがemptyです" << std::endl;
		}*/

		// フレーム遷移処理
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2, GOOL))
			{
				//m_Frame = FRAME_MAX;
				playerShared.second->SetOnGround(false);
				//Frame4();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");
				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1のポヨン
				objectmanager.DeleteObject(ONOMATOPOEIA, "FRAME3patapata");
				objectmanager.DeleteObject(UI, "FRAME3biribiriefect");
				objectmanager.DeleteObject(ONOMATOPOEIA, "FRAME3biribiri");
				objectmanager.DeleteObject(GROUND, "FRAME3Box1");
				objectmanager.DeleteObject(GROUND, "FRAME3Box2");
				objectmanager.DeleteObject(GROUND, "FRAME3Ground1");
				objectmanager.DeleteObject(GROUND, "FRAME3Ground2");
				objectmanager.DeleteObject(OBJECT, "baneFRAME3");
				objectmanager.DeleteObject(ONOMATOPOEIA, "FRAME2Poyon");
				objectmanager.DeleteObject(GROUND, "FRAME2Box");
				objectmanager.DeleteObject(GROUND, "FRAME2Ground1");
				objectmanager.DeleteObject(GROUND, "FRAME2Ground2");
				objectmanager.DeleteObject(GROUND, "FRAME2Ground3");
				


				sound.Stop(BGM_INGAME);
				//ここでTITLEに戻る
				m_Frame = FRAME4;
			}
		}
		objectmanager.Update(); 
		break;
	case FRAME4:

		/* Playerと地面や壁の当たり判定 */
		BoxCollider2(playerShared2, FRAME4Ground1, playerShared2);
		BoxCollider2(playerShared2, FRAME4Ground2, playerShared2);
		BoxCollider2(playerShared2, FRAME4Ground3, playerShared2);
		BoxCollider2(playerShared2, FRAME4Ground4, playerShared2);

		/* Playerと箱の当たり判定 */
		BoxCollider2(playerShared2, FRAME4Obj1, playerShared2);

		/* 動く箱の処理 */
		if (FRAME4Ground4)
		{
			FRAME4Ground4->Action(FRAME4Ground4, playerShared2, -300.0f);
		}

		//スライムジャン
		if (Collider_toEnemy(FRAME4Enemy1, groundShared))
		{
			//スライムジャンプフラグ
			if (enemygion2)
			{
				if (enemygion2->Get_gion() == false)
				{
					Vector3 Slim_Position = enemygion2->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion2->SetPosition(Slim_Position);
				}
			}
			FRAME4Enemy1->SetJump(true);
		}
		else if (enemygion2) {
			FRAME4Enemy1->SetOnGround(false);
			enemygion2->Fade_in_out();
		}

		/* EnemyUV変化 */
		if (FRAME4Enemy1->m_FacingLeft)
		{
			FRAME4Enemy1->uv = 0;
			FRAME4Enemy1->SetUV(FRAME4Enemy1->uv);
		}
		else {
			FRAME4Enemy1->uv = 1;
			FRAME4Enemy1->SetUV(FRAME4Enemy1->uv);
		}

		objectmanager.Update();
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}

	//FRAME1～FRAME3までの地面の当たり判定
	if (!BoxCollider2(playerShared2, under_ground, playerShared2))
	{
		playerShared.second->SetOnGround(false);
	}

	// マガジンに擬音が入っていればエイムの位置に発射
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger())
	{
		//poyonShared()->Set_Onomatope(true); //擬音が発射中かのフラグ
		// マガジンに擬音が装填されているかチェック
		if (playerShared.second->GetLoadedBullet())
		{
			//if (BoxCollider(Frame_Red(), Magazine1())) //ドーン専用
			//{
			//	playerShared.second->UseMagNumber = 0;
			//}
			//else if (BoxCollider(Frame_Red(), Magazine2()))
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
			sound.Play(SE_SHOT);
			playerShared2->SetMagNumber(1); //0番目の配列
		}
	}

	// R1でマガジンカーソル右移動
	if (Input::GetInstance().GetKeyTrigger(VK_P) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		// カーソルの座標取得
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->GetPosition();

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
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->SetPosition(p_frame);
		// SE再生
		sound.Play(SE_CLICK);
	}
	// L1でマガジンカーソル左移動
	if (Input::GetInstance().GetKeyTrigger(VK_O) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_LEFT_SHOULDER))
	{
		// カーソルの座標取得
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->GetPosition();

		// ドォン用マガジンを除く一番最初のマガジンを選択していなければ
		if (playerShared.second->GetMagNumber() != 1)
		{
			sound.Play(SE_CLICK);
			// マガジン選択番号を１減らして
			playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() - 1);
			// カーソルを左に移動
			p_frame.x -= 120.0f;
		}
		// 一番最初のマガジンを選択している場合
		else
		{
			// マガジン選択用カーソルを取得
			auto magcursor = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame");
			// マガジン選択番号を(ドォン用マガジンを除く)一番後ろにして
			playerShared.second->SetMagNumber(playerShared.second->GetMagCount() - 1);
			// カーソルを一番後ろの位置に移動
			p_frame.x = -900.0f + magcursor->GetScale().x * (playerShared.second->GetMagCount() - 2);	// 初期位置 + カーソルの大きさ * マガジン数(ドォン入れないので-2)
		}
		// 座標を設定
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")->SetPosition(p_frame);
		// SE再生
		sound.Play(SE_CLICK);
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
					/*enemygion()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
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
					objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard")->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
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
					if (HitDoon.second == poyonShared)
					{
						poyonShared->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
						poyonShared->SetScale(Vector3(300.0f, 150.0f, 0.0f));
					}
					playerShared.second->m_Magazines[0] = dynamic_cast<Magazine*>(poyonShared); //キャストして配列の０番目に格納
					// 吸い込み処理が終わった時に擬音のタグをUIに変更、射撃するときにタグを擬音に変更する処理がまだ
					objectmanager.ChangeTag(HitDoon.first.first, HitDoon.first.second, UI);
					/*enemygion()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
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
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->SetMoveRight(true);
		//sound.Play(SOUND_LABEL_BGM000);
		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->SetMoveLeft(true);

		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player")->SetJump(true);
		//デバック用
		//std::cout << "Playerの座標移動ができています" << std::endl;
	}

	// クロスヘアの入力取得(本来はプレイヤーのフラグを立てて、プレイヤーの更新の中でクロスヘアを動かすべき)XINPUT_GAMEPAD_RIGHT_THUMB
	if (Input::GetInstance().GetKeyPress(VK_UP) || RightStickInput.y > 0.1f)
	{
		crosshairShared->SetMoveUp(true);
	}
	else
	{
		crosshairShared->SetMoveUp(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_DOWN) || RightStickInput.y < -0.1f)
	{
		crosshairShared->SetMoveDown(true);
	}
	else
	{
		crosshairShared->SetMoveDown(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_RIGHT) || RightStickInput.x > 0.1f)
	{
		crosshairShared->SetMoveRight(true);
	}
	else
	{
		crosshairShared->SetMoveRight(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_LEFT) || RightStickInput.x < -0.1f)
	{
		crosshairShared->SetMoveLeft(true);
	}
	else
	{
		crosshairShared->SetMoveLeft(false);
	}


	if (m_Frame == FRAME1)
	{
		Vector3 poyon_rotation = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->GetRotation();
		Vector3 poyon_posiiton = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->GetPosition();

		if (count == 0)
		{
			poyon_rotation.z += 5.0f;
		}
		else if(count == 1){
			poyon_rotation.z = 0.0f;
			objectmanager.DeleteObject(ENEMY, "Slimeboard");
			objectmanager.DeleteObject(UI, "SoundGunboard");
		}
		objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard")->SetRotation(poyon_rotation);

		std::cout << playerShared2->m_Magazines.size() << std::endl; //マガジン数のデバック
		// シーン更新に必要な情報を取得
		auto grounds2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
		auto effectShared = objectmanager.GetGameObjectPtr<GameObject>(UI, "Thunder_Effect");
		auto groundShared3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3");

		 BoxCollider2(playerShared2, groundShared2, playerShared2);
		
		effectShared->Animation(EFECT, effectShared);

		////擬音の選択
		//if (Input::GetInstance().GetKeyTrigger(VK_P))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")()->GetPosition();
		//	p_frame.x = p_frame.x + 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")()->SetPosition(p_frame);
		//}
		//if (Input::GetInstance().GetKeyTrigger(VK_O))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")()->GetPosition();
		//	p_frame.x = p_frame.x - 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame")()->SetPosition(p_frame);
		//}


		//ゲーム画面に遷移
		// シーン遷移（デバック用
		/*if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			this->ChangeScene = true;
			SetChangeScene(this->ChangeScene);
		}*/

		//スライムジャンプ
		if (Collider_toEnemy(enemyShared, groundShared))
		{
			//スライムジャンプフラグ
			if (enemygion)
			{
				if (enemygion->Get_gion() == false)
				{

					Vector3 Slim_Position = enemygion->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion->SetPosition(Slim_Position);
				}
				else {
					Vector3 pos_bane = baneShared->GetPosition();
					baneShared->SetPosition(pos_bane);
				}

			}
			enemyShared->SetJump(true);
		}
		else if (enemygion) {
			enemyShared->SetOnGround(false);
			enemygion->Fade_in_out();
		}

		if (enemygion != nullptr)
		{
			Vector4 poyon_color = enemygion->GetColor(); //エラー：吸収する瞬間にenemygion自体が削除されるのでエラーが出る
			Vector3 p_poyon = p_enemy;
			p_poyon.x = p_poyon.x + 50;
			p_poyon.y = p_poyon.y + 150;
		}

		Vector3 enemy_Rotation = enemyShared->GetRotation();


		if (p_enemy.x <= -300)
		{
			enemyShared->cb.matrixWorld = DirectX::XMMatrixScaling(-1.0f, 1.0f, 1.0f);
		}
		//std::cout << p_enemy.x << std::endl;

		Vector3 _p_biribiri = effectShared->GetPosition(); //ポヨンの座標
		Vector3 _r_biribiri = effectShared->GetRotation();  //ポヨンの回転

		//enemygionがemptyでないかチェック
		if (enemygion)
		{
			//ポヨンの画像とバネの画像が当たっているか
			if (BoxCollider(enemygion, baneShared))
			{

				enemygion->Set_gion(true);
				Vector3 _p_poyon = baneShared->GetPosition(); //ポヨンの座標
				Vector3 _r_poyon = baneShared->GetRotation();  //ポヨンの回転
				enemygion->Set_Onomatope(true); //当たってたらフラグをtrue
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion->SetPosition(_p_poyon); //ポヨンの画像の座標をバネにくっつける
				enemygion->SetRotation(_r_poyon); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else
			{
				//std::cout << "当たっていません" << std::endl;
			}

			//二回目の回収をするまではずっとtrue
			if (enemygion->Get_Onomatope())
			{
				enemygion->Fade_in_out();
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, baneShared))
				{
					enemygion->Action(playerShared.second); //当たっていればAction関数実行
					sound.Play(SE_POYON);
				}
			}
		}
		else {
			std::cout << "enemygionがemptyです" << std::endl;
		}

		//ビリビリ
		if (gionShared)
		{
			if (BoxCollider(gionShared, effectShared))
			{
				effectShared->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				//_p_biribiri.x = _p_biribiri.x - 250;
				//_p_biribiri.y = _p_biribiri.y + 80;
				//_r_biribiri.z = _r_biribiri.z - 15;
				gionShared->Set_Onomatope(true); //当たってたらフラグをtrue
				//
				//gionShared()->SetPosition(_p_biribiri); //ポヨンの画像の座標をバネにくっつける
				//gionShared()->SetRotation(_r_biribiri); //ポヨンの画像の回転を更新
				std::cout << "当りました" << std::endl;
			}
			else {
				effectShared->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //ビリビリのエフェクトを色で消えた感じにしてる
			}

			gionShared->Fade_in_out();
			//二回目の回収をするまではずっとtrue
			if (gionShared->Get_Onomatope())
			{
				//Playerと付与したオブジェクトが当たっているか
				if (BoxCollider(playerShared.second, groundShared3))
				{
					playerShared.second->SetOnGround(true);
					gionShared->Action(playerShared.second); //当たっていればAction関数実行
					sound.Play(SE_BIRIBIRI);
				}
				else {
					Vector3 r_player = playerShared.second->GetRotation();
					r_player.z = 0;
					playerShared.second->SetRotation(r_player);
				}
			}
		}
		else {
			playerShared2->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		}


		// ここでマガジンがUIになっていなければ当たり判定を取りたい
		if (m_MagCount >= 1)
		{
			// １つのシーンに落ちてるマガジン数は一個なので、シーンの持つマガジンカウントが１ならまだ当たっていない
			// →判定チェックする

			auto magShared = objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine3");

			// マガジンと地面
			Collider_toGround(magShared.second, groundShared);
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
			if (Collider_to_Object(playerShared2, GOOL))
			{
				m_Frame = FRAME2;
				//playerShared.second->SetOnGround(false);
				Frame2();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");

				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1のポヨン
				objectmanager.DeleteObject(BACKGROUND, "board1");
				objectmanager.DeleteObject(BACKGROUND, "Playerboard");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyonboard");
				objectmanager.DeleteObject(ENEMY, "Slimeboard");
				objectmanager.DeleteObject(UI, "SoundGunboard");
				objectmanager.DeleteObject(OBJECT, "baneboard");
				objectmanager.DeleteObject(Doon, "Gion2");
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
	sound.Stop(BGM_INGAME);
	sound.Uninit();
	objectmanager.Uninit();
}

void Stage2Scene::ChangeFRAME(void) {
	auto playerSharde = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	Vector3 pos = playerSharde.second->GetPosition();
}