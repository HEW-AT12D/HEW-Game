#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"


/**
 * @brief ゲームシーン
 * 
 * シーンの派生全部テンプレートでよくないか？。。。
*/
class GameScene :public IScene
{
public:
	GameScene();
	~GameScene();
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	ObjectManager objectmanager;
};


