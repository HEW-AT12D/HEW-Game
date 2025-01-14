#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include"../../Game/Objcet/SoundGun/SoundGun.h"



/**
 * @brief タイトルシーンの初期化
 *
 * シーンごとに初期化は最初の一度のみ
 * →
*/



void TitleScene::Init(void) {
	// オブジェクトマネージャ初期化
	objectmanager.Init();
	

	//-----------------------
	//-----オブジェクト追加-----
	//-----------------------
	// TODO:1218ここまで オブジェクトの管理をenumから変更→tagと名前にしたい
	
	// 背景
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background1");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// プレイヤー
	objectmanager.AddObject<GameObject>(PLAYER, "Player");
	objectmanager.GetGameObject(PLAYER, "Player")->Init(L"Game/Asset/Character/Character_sprit.png",2,1);
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(PLAYER, "Player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));


	//擬音（どおん）
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");
	objectmanager.GetGameObject(OBJECT, "Gion")->Init(L"Game/Asset/Gion/どぉん.png");
	objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(Vector3(300.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Gion")->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	


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
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
	/*	objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
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
	
	//吸い込み処理
	if (Input::GetInstance().GetKeyPress(VK_SPACE))
	{
		Vector3 p_pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();
		//Suction(gion_pos, p_pos);
		if (gion_pos.x - p_pos.x <= 300&&gion_pos.x-p_pos.x>=0)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
		{
			//ここに、近づくスピードを書く
			gion_pos.x -= 14;
			std::cout << "吸い込んでます" << std::endl;
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(gion_pos);
		}
		std::cout << "擬音座標：" << gion_pos.x << std::endl;
	}
	//連：メモ
	//擬音を回収したときに、オブジェクトをただ移動させるだけじゃなくて、回収したオブジェクトの情報によって表示させるUIを変える


	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
