#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"

class ResultScene :public IScene
{
public:
	ResultScene(D3D11& _D3d11) :IScene(_D3d11) {};
	~ResultScene() {
		Uninit();
	};

	void Init(void) override;		//! 初期化
	void Update(void) override;		//! 更新
	void Draw(void) override;		//! 描画
	void Uninit(void) override;		//! 終了
	void ChangeFRAME(void) override;
private:
	
};
