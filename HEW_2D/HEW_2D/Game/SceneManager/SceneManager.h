#pragma once
#include "../../Framework/Scene/IScene.h"


/**
 * @brief �V�[���Ǘ��N���X
 * �I�u�W�F�N�g�Ǘ��̓^�O�Ɩ��O���g�����A�V�[���̊Ǘ��̓V�[���̖��O(������Œ�`)�݂̂ōs��
 *
 * �V�[���؂�ւ��֐����K�v
*/
class SceneManager
{
public:
	SceneManager() = default;
	/**
	 * @brief �R���X�g���N�^
	 * @param _D3d11 d3d�̎Q��
	 * �^�C�g���V�[���̓Q�[���J�n�����ɕK�v�Ȃ̂ŃR���X�g���N�^�Ő�������
	*/
	SceneManager(D3D11& _D3d11) :D3d11(_D3d11)
	{
		// �V�[���ێ����Ă���R���e�i����ɂ���
		Scenes.clear();
		CurrentScene = {};
		Quit = false;
	};
	~SceneManager() {};

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
		Scenes.emplace(_SceneName, std::make_unique<T>(D3d11));
	}

	/**
	 * @brief �V�[���擾�֐�
	 * @param _SceneName �V�[���̃^�O
	*/
	IScene* GetScene(SceneName& _SceneName);

	/**
	 * @brief �V�[���폜�֐�
	 * @param _SceneName �폜�������V�[���̌^�imap�̃L�[�j
	*/
	void DeleteScene(SceneName _SceneName);

	/**
	 * @brief �Q�[���I�����N�G�X�g�̏�Ԃ�Ԃ�
	 * @return �Q�[���I�����
	*/
	bool GetIsQuit(void);

	/**
	 * @brief �Q�[���I���t���O��ݒ肷��֐�
	 * @param _flg
	*/
	void SetIsQuit(bool _flg);

private:
	D3D11& D3d11;
	std::unordered_map<SceneName, std::unique_ptr<IScene>> Scenes;	//! �V�[���z��
	SceneName CurrentScene;
	bool Quit = false;
};