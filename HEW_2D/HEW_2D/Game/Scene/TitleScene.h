#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"
#include "../../Framework/Sound/sound.h"

/**
 * @brief タイトルシーンクラス
 * 
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
*/
class TitleScene :public IScene
{
public:
	TitleScene();
	~TitleScene();
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	//Sound sound;
	ObjectManager objectmanager;
};



