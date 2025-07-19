#pragma once
#include "../../Game/ObjectManager/ObjectManager.h"
#include "../Sound/sound.h"


enum FRAME {
	FRAME1,
	FRAME2,
	FRAME3,
	FRAME4,

	FRAME_MAX
};

enum SceneName {
	TITLE,			// �^�C�g��
	STAGESELECT,	// �X�e�[�W�I��
	TEST,
	STAGE1,			// �X�e�[�W2
	STAGE2,			// �X�e�[�W2
	RESULT,			// ���U���g
	QUIT,			// �Q�[���I��

	SCENE_MAX
};


/**
 * @brief �V�[���̒��ۃN���X
 *
 * �S�ẴV�[����������p������̂Ń|�����[�t�B�Y���ŃV�[�����Ǘ��ł���
 *
 * �����ɃI�u�W�F�N�g�}�l�[�W���u���Ƃ��ׂ��H
 *
 * �V�[�����̃I�u�W�F�N�g�}�l�[�W�����I�u�W�F�N�g��������d3d�̎Q�Ƃ�n��
 */
class IScene
{
public:
	IScene(D3D11& _D3d11, Sound& _sound) : SoundRef(_sound), objectmanager(_D3d11, SoundRef) {
		m_Frame = FRAME1;
		m_MagCount = 1;
	};

	virtual ~IScene() {};

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void ChangeFRAME(void);

	virtual void SetChangeScene(bool _Flg);
	virtual bool GetChangeScene(void);

	virtual SceneName GetRequestScene(void);		// ���ɑJ�ڂ������V�[�����擾����֐�

protected:
	Sound& SoundRef;	// �T�E���h�N���X�̎Q��
	ObjectManager objectmanager;	// �I�u�W�F�N�g�}�l�[�W��
	SceneName m_RequestNext;		// ���ɑJ�ڂ������V�[��
	FRAME m_Frame;					// ���݃t���[��
	bool ChangeScene = false;		// �V�[���؂�ւ��t���O
	bool ChangeFrame = false;		// �t���[���؂�ւ��t���O
	int m_MagCount;					// �}�K�W����
};
