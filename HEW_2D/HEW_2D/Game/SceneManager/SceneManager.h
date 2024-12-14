#pragma once
#include "../../Framework/Scene/IScene.h"


//! TODO:scenemanager��titlescene��resultscene���C���N���[�h����ƁA���ꂼ��ŃC���N���[�h����Ă���objectmanager��IScene���Փ˂��Ă��܂�
//! ��scenemanager.cpp�ł̂�titlescene��resultscene���C���N���[�h���ĉ���
//! TODO:�V�[����vector�Ŏ��ׂ��Hmap�Ŏ��ׂ��H
//! 
//! �g���Ă��Ȃ��V�[���̓��[�h�����A���݃V�[���������X�V�A�`�悷��悤�ɂ�����
//! �V�[���J�ڂ̎��ɑO�V�[����������ĐV�����V�[�����������A�Ƃ�������ɂ�����
//!						��
//! �X�e�[�W�I���V�[���͂����ƕێ����Ă����A�I�����ꂽ�X�e�[�W�����𖈉񐶐������
//! �Ƃ����������肽��
//! 

enum SceneName {
	TITLE,
	STAGESELECT,
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

	/**
	 * @brief �V�[�������֐�
	 * @tparam T �����������V�[���̌^
	 * @param _name �L�[�i�V�[���̖��O�i�^�O�j�j
	*/
	template <typename T>
	void CreateScene(SceneName _name)
	{
		// �^�O��ݒ肵�ăV�[����ǉ�
		Scenes.emplace(_name, std::make_unique<T>());
	}

private:
	std::unordered_map<SceneName, std::unique_ptr<IScene>> Scenes;	//! �V�[���z��
	SceneName CurrentScene;
};

