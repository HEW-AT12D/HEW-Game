#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"


/**
 * @brief ゲームシーン
 * 
 * シーンの派生全部テンプレートでよくないか？。。。→ポリモーフィズムで管理できないからNG!
*/
class GameScene :public IScene
{
public:
	GameScene(D3D11& _D3d11, Sound& _sound) :IScene(_D3d11, _sound) {};
	~GameScene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:

};

