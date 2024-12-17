#pragma once
#include "../../Framework/Scene/IScene.h"

/**
 * @brief �^�C�g���V�[���N���X
 * 
 * �T�E���h�A�w�i�Ȃǂ̃Q�[���I�u�W�F�N�g��z��iarray�j�Ŏ���
 * 
 * �I�u�W�F�N�g���R���X�g���N�^�ő�����Ă����A�V�[���̏������������ŃI�u�W�F�N�g������������
*/
class TitleScene :public IScene
{
public:
	TitleScene() = default;
	TitleScene(D3D11& _D3d11) :IScene(_D3d11) {
		//-----------------------
		//-----�I�u�W�F�N�g�ǉ�-----
		//-----------------------
		
		// �w�i
		objectmanager.AddObject<GameObject>(OBJECT);
		// �^�C�g��
		objectmanager.AddObject<GameObject>(OBJECT);
		// UI1(�{�^��)
		objectmanager.AddObject<GameObject>(OBJECT);
		// UI2(�{�^��)
		objectmanager.AddObject<GameObject>(OBJECT);
		// �v���C���[
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


