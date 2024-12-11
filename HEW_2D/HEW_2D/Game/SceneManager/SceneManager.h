#pragma once
#include "../../pch.h"
#include "../../Framework/Scene/IScene.h"


//! TODO:scenemanager��titlescene��resultscene���C���N���[�h����ƁA���ꂼ��ŃC���N���[�h����Ă���objectmanager��IScene���Փ˂��Ă��܂�
//! ��scenemanager.cpp�ł̂�titlescene��resultscene���C���N���[�h���ĉ���

enum SceneName {
	TITLE,
	GAME,
	RESULT,

	SCENE_MAX
};

/**
 * @brief �V�[���Ǘ��N���X
 * 
 * �^�C�g���A�Q�[���A���U���g�̂R�����Ȃ̂ō����array���g�p
 * �������ŃV�[�������ׂĔz��Ɋi�[
 * �V�[���؂�ւ��֐����K�v
 * 
 * �C�x���g�����ŃV�[���؂�ւ�
 * ��map�ŕێ����Ă����A�V�[���J�ڂŃV�[�������
*/
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init(void);		//! ������
	void Update(void);		//! �X�V
	void Draw(void);		//! �`��
	void Uninit(void);		//! �I��

	void ChangeScene(SceneName scene);	//! �V�[���؂�ւ�

private:
	std::vector<std::unique_ptr<IScene>> scenes;
	SceneName scenename;
};

