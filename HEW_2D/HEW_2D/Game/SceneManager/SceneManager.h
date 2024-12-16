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
//! -----------------------------------------------------------------------------------------
//!  �I�u�W�F�N�g�ʂɕ`��@�\���������Ă���̂ŃI�u�W�F�N�g�}�l�[�W���[�܂�d3d�̎Q�Ƃ�n������
//! �@���V�[���}�l�[�W���܂ł̓R���X�g���N�^�Ŏ����Ă���ꂽ���I�u�W�F�N�g�}�l�[�W���Ɏ����Ă����Ȃ�
//! �@�@������������̃N���X�ɂ�d3d�̎Q�Ƃ��������ĉ�������i�����ƃX�}�[�g�ɂ����������j
//! �@�@�@�����Ԃ������Renderer�N���X�݂����Ȃ̂�����āA�`�����͑S�Ă��̃N���X�S���Ƃ�����ׂ�
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
	void CreateScene(SceneName _SceneName)
	{
		// �^�O��ݒ肵�ăV�[����ǉ�
		Scenes.emplace(_SceneName, std::make_unique<T>());
	}

	/**
	 * @brief �V�[���폜�֐�
	 * @param _SceneName �폜�������V�[���̌^�imap�̃L�[�j
	*/
	void DeleteScene(SceneName _SceneName);

private:
	std::unordered_map<SceneName, std::unique_ptr<IScene>> Scenes;	//! �V�[���z��
	SceneName CurrentScene;
};

