#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"

class ResultScene :public IScene
{
public:
	ResultScene(D3D11& _D3d11) :IScene(_D3d11) {};
	~ResultScene() {};
	
	void Init(void) override;		//! ������
	void Update(void) override;		//! �X�V
	void Draw(void) override;		//! �`��
	void Uninit(void) override;		//! �I��

private:
	
};
