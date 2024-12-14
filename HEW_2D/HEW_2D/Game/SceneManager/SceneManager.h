#pragma once
#include "../../Framework/Scene/IScene.h"


//! TODO:scenemanager��titlescene��resultscene���C���N���[�h����ƁA���ꂼ��ŃC���N���[�h����Ă���objectmanager��IScene���Փ˂��Ă��܂�
//! ��scenemanager.cpp�ł̂�titlescene��resultscene���C���N���[�h���ĉ���
//! TODO:�V�[����vector�Ŏ��ׂ��Hmap�Ŏ��ׂ��H
//! 
//! �g���Ă��Ȃ��V�[���̓��[�h�����A���݃V�[���������X�V�A�`�悷��悤�ɂ�����
//! �V�[���J�ڂ̎��ɑO�V�[����������ĐV�����V�[�����������A�Ƃ�������ɂ�����

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

	template <typename T>
	void CreateScene(SceneName _name)
	{
		// �^�O��ݒ肵�ăV�[����ǉ�
		Scenes.emplace(_name, std::make_unique<T>());
	}

private:
	std::map<std::string, std::unique_ptr<IScene>> Scenes;	//! �V�[���z��
	SceneName CurrentScene;
};

