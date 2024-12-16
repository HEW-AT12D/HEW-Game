#pragma once
#include "../../Framework/Scene/IScene.h"
/**
 * @brief �^�C�g���V�[���N���X
 * 
 * �T�E���h�A�w�i�Ȃǂ̃Q�[���I�u�W�F�N�g��z��iarray�j�Ŏ���
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


