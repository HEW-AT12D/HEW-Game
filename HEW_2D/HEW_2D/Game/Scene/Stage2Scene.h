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
class Stage2Scene :public IScene
{
public:
	Stage2Scene(D3D11& _D3d11) :IScene(_D3d11) {
		// �I�u�W�F�N�g�̒ǉ��̓V�[���̏������ōs��
		// �T�E���h�Ƃ����̃V�[���̂ݑ��݂�����̂�����΂��̏��������s��
		ChangeScene = false;
		m_Frame = FRAME1;
	};
	~Stage2Scene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;
	void ChangeFRAME(void)override;
	void Frame1(void);
	void Frame2(void);
	void Frame3(void);
	void Frame4(void);
	void (Stage2Scene::*Array[5])() = {&Stage2Scene::Frame1,&Stage2Scene::Frame2,&Stage2Scene::Frame3,&Stage2Scene::Frame4 };
	
	Sound sound;
	FRAME nowFRAME;
private:
};
