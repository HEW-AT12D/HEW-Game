#pragma once
#include "../../Framework/Scene/IScene.h"
/**
 * @brief タイトルシーンクラス
 * 
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
*/
class TitleScene :public IScene
{
public:
	TitleScene() = default;
	TitleScene(D3D11& _D3d11) :IScene(_D3d11) {
		objectmanager.AddObject<GameObject>(OBJECT);
	};
	~TitleScene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	//Sound sound;
};


