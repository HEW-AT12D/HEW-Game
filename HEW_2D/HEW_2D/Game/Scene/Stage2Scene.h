#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../../Framework/Sound/sound.h"
/**
 * @brief タイトルシーンクラス
 *
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
 *
 * オブジェクトをコンストラクタで代入しておき、シーンの初期化処理内でオブジェクトを初期化する
*/
class Stage2Scene :public IScene
{
public:
	Stage2Scene(D3D11& _D3d11) :IScene(_D3d11) {
		// オブジェクトの追加はシーンの初期化で行う
		// サウンドとかこのシーンのみ存在するものがあればその初期化を行う
		ChangeScene = false;
		m_Frame = FRAME1;
	};
	~Stage2Scene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;
	void ChangeFRAME(void)override;
	void Frame1(void);
	void Frame2(void);
	void Frame3(void);
	void Frame4(void);
	void (Stage2Scene::*Array[5])() = {&Stage2Scene::Frame1,&Stage2Scene::Frame2,&Stage2Scene::Frame3,&Stage2Scene::Frame4 };
	
	Sound sound;
	FRAME nowFRAME;
private:
};
