#pragma once
#include "../../Framework/Scene/IScene.h"

/**
 * @brief タイトルシーンクラス
 * 
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
 * 
 * オブジェクトをコンストラクタで代入しておき、シーンの初期化処理内でオブジェクトを初期化する
*/
class TitleScene :public IScene
{
public:
	TitleScene() = default;
	TitleScene(D3D11& _D3d11) :IScene(_D3d11) {
		//-----------------------
		//-----オブジェクト追加-----
		//-----------------------
		
		// 背景
		objectmanager.AddObject<GameObject>(OBJECT);
		// タイトル
		objectmanager.AddObject<GameObject>(OBJECT);
		// UI1(ボタン)
		objectmanager.AddObject<GameObject>(OBJECT);
		// UI2(ボタン)
		objectmanager.AddObject<GameObject>(OBJECT);
		// プレイヤー
		objectmanager.AddObject<Player>(PLAYER);
		

	};
	~TitleScene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	//Sound sound;
};


