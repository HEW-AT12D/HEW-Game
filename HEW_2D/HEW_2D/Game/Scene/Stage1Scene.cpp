#include "Stage1Scene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../Objcet/Camera/Camera.h"


/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
 * 
 * ステージは、縦２０マス＊横４０マス
*/
void Stage1Scene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();

	// BGM再生
	Sound::GetInstance().Play(BGM_INGAME);
	

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

	// 擬音銃(設計的には銃を別画像で用意してプレイヤーに持たせる方が良かったが、)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(260.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

	//擬音（ポヨン）
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// 名前要変更
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Wiin.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	
	// マガジン(二個持った状態でスタート、落ちてるのは一個だけ)
	// 1個目(ドォン専用)
	objectmanager.AddObject<Magazine>(UI, "SpecialMagazine");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 2個目
	objectmanager.AddObject<Magazine>(UI, "Magazine1");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 3個目
	objectmanager.AddObject<Magazine>(UI, "Magazine2");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 3つは子オブジェクトに設定してUIに変更しておく
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "SpecialMagazine").second);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	// 3個目(フィールドに落ちてるマガジン)
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 地面
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	// 地面2
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(700.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// スライム
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// クロスヘア
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(30.0f, 30.0f, 0.0f));
	// クロスヘアをプレイヤーの子オブジェクトとして設定
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//マガジンの外枠(初期位置は一番左上のマガジン)
	objectmanager.AddObject<GameObject>(UI, "Frame");    // 名前要変更
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

	//// カメラ
	//objectmanager.AddObject<Camera>(CAMERA, "Camera");    // 名前要変更
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->Init(L"Game/Asset/UI/BlackImage.png");
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	std::cout << "GameSceneInit" << std::endl;
	//// UI1(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(ボタン)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// プレイヤー
	//objectmanager.AddObject<Player>(PLAYER);
}



void Stage1Scene::Update(void)
{

	// 入力情報の更新
	Input::GetInstance().Update();
	// スティック入力値を取得
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// 右スティック入力
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// 左スティック入力

	// シーン更新に必要な情報を取得
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");		// プレイヤー
	auto grounds = objectmanager.GetObjects<GameObject>(GROUND);						// 地面(配列)
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");	// 地面1(個別)
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");	// 地面2
	auto onopatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);			// 擬音(配列)
	auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");		// 擬音(個別)
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");			// 敵(個別)
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");	// クロスヘア


	// 入力管理
	// 右移動
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		//sound.Play(SOUND_LABEL_BGM000);
		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// 左移動
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}
	// ジャンプ
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonPress(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

		//デバック用
		std::cout << "Playerの座標移動ができています" << std::endl;
	}


	//ゲーム画面に遷移
	// シーン遷移（デバック用
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		SetChangeScene(true);
	}


	//----------------当たり判定-----------------------

	ColliderPlayer_Ground(playerShared.second, grounds);			// プレイヤーと地面
	Collider_Objects_Objects(onopatopoeias,grounds);		// 擬音と地面
	//ColliderPlayer_Ground(playerShared, groundShared2);


	// クロスヘアの入力取得(本来はプレイヤーのフラグを立てて、プレイヤーの更新の中でクロスヘアを動かすべき)
	if (Input::GetInstance().GetKeyPress(VK_UP) || RightStickInput.y > 0.1f)
	{
		crosshairShared.lock()->SetMoveUp(true);
	}
	else {
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



	////擬音の吸収→247行目の吸い込み処理に変更、改良
	//if (Input::GetInstance().GetKeyPress(VK_F))
	//{
	//	if (ColliderFan_Gion(playerShared, gionShared))
	//	{
	//		//この下二つを一つにまとめてもいいかも？
	//		playerShared.lock()->Suction(gionShared, playerShared);
	//		//擬音の吸い込み時の回転・サイズ変更
	//		gionShared.lock()->Onomatopeia_ObjectMave(gionShared);
	//	}
	//}

	// マガジンに擬音が入っていればエイムの位置に発射
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger())
	{
		// マガジンに擬音が装填されているかチェック
		if (playerShared.second->GetLoadedBullet())
		{
			playerShared.second->SetIsShot(true);


			//--------------------------------------
			//			擬音のタグ変更処理
			//--------------------------------------

			// ここオブジェクトマネージャから擬音の情報持ってきたほうが良いかも？

			// ここで擬音のタグをUIから擬音に変更
			// →擬音のポインタだけわかってるのにキーの特定がスムーズにできないのでやっぱり管理方法変えたほうがいい(登録されてるタグを毎フレーム確認して同期させるとか)

			// ここでは持ってきた擬音がキャストできた型によってその擬音のタグを変えるようにする
			auto bullet = playerShared.second->GetLoadedBullet();

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
			// SE再生
			Sound::GetInstance().Play(SE_SHOT);
		}
	}


	//playerShared.lock()->Shot(gionShared);


	// ----------------吸い込み処理→ここはプレイヤーの処理に移す-------------------------
	// プレイヤー発の扇型と当たってる擬音を探す→(一番近くの)当たってる擬音を吸い込む
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	{
		// 吸い込める擬音がなくても演出だけ行う
		// SE再生
		Sound::GetInstance().Play(SE_SUCTION);
		// 

		// 吸い込める擬音を探す
		// そのフレーム内のタグが擬音のもの全て取得→それとプレイヤーから出る扇型の当たり判定を取得
		//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
		auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);

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
					// 吸い込み処理が終わった時に擬音のタグをUIに変更して
					objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);

					//// マガジン番号を次へ移行
					//playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() + 1);
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
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える

	/////////////////////////////////////////////////////
	// ここでマガジンがUIになっていなければ当たり判定を取る
	/////////////////////////////////////////////////////
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

			// サウンド再生
			Sound::GetInstance().Play(SE_GETMAGAZINE);
		}

	}

	/////////////////////////////////
	// カーソル移動して擬音の選択
	/////////////////////////////////
	
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

	// マガジンとの当たり判定を毎フレーム取る→マガジンを取得したらその判定チェックはしなくておｋ
	//objectmanager.Collider_Player_to_Object();		// ここで当たったらマガジン数を１つ減らす

	objectmanager.Update();
	
}

void Stage1Scene::Draw(void) {
	objectmanager.Draw();
}

void Stage1Scene::Uninit(void) {
	// BGM停止
	Sound::GetInstance().Stop(BGM_INGAME);
	objectmanager.Uninit();
}
