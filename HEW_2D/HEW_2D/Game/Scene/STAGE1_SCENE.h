#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../../Framework/Sound/sound.h"

/**
 * @brief �^�C�g���V�[���N���X
 *
 * �T�E���h�A�w�i�Ȃǂ̃Q�[���I�u�W�F�N�g��z��iarray�j�Ŏ���
 *
 * �I�u�W�F�N�g���R���X�g���N�^�ő�����Ă����A�V�[���̏������������ŃI�u�W�F�N�g������������
*/
class STAGE1_SCENE :public IScene
{
public:
	STAGE1_SCENE(D3D11& _D3d11) :IScene(_D3d11) {
		// �I�u�W�F�N�g�̒ǉ��̓V�[���̏������ōs��
		// �T�E���h�Ƃ����̃V�[���̂ݑ��݂�����̂�����΂��̏��������s��

	};
	~STAGE1_SCENE() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	Sound sound;
};
