#pragma once
#include "../../Framework/Scene/IScene.h"


/**
 * @brief �^�C�g���V�[���N���X
 *
 * �T�E���h�A�w�i�Ȃǂ̃Q�[���I�u�W�F�N�g��z��iarray�j�Ŏ���
 *
 * �I�u�W�F�N�g���R���X�g���N�^�ő�����Ă����A�V�[���̏������������ŃI�u�W�F�N�g������������
*/
class Title1Scene :public IScene
{
public:
	Title1Scene(D3D11& _D3d11) :IScene(_D3d11) {
		// �I�u�W�F�N�g�̒ǉ��̓V�[���̏������ōs��
		// �T�E���h�Ƃ����̃V�[���̂ݑ��݂�����̂�����΂��̏��������s��

	};
	~Title1Scene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:

};
