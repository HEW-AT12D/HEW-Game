#pragma once
#include "../../../Game/SceneManager/SceneManager.h"
#include "../../../Framework/D3D11/D3D11.h"
#include"../../../Game/Scene/Stage1Scene.h"
#include "../../../Framework/Sound/sound.h"

/**
 * @brief �Q�[���N���X
 * �A�v���P�[�V�����N���X���ێ�����Q�[���N���X
 * �����̃N���X��؂�ւ���Α��̃Q�[���ł����̊O���̃N���X�͎g���܂킹��
*/
class Game
{
public:
	// �R���X�g���N�^(�����ŃT�E���h�}�l�[�W���[����)
	Game(D3D11& _D3d11) :m_pGameSound(std::make_unique<Sound>()), scenemanager(_D3d11, *m_pGameSound) {};
	~Game() {};

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	std::unique_ptr<Sound> m_pGameSound;	// �Q�[���S�̂̃T�E���h�Ǘ��N���X(�Q�[�����ƂɎg�����͈Ⴄ�̂ł����ɔz�u)
	SceneManager scenemanager;				// �V�[���Ǘ��N���X
};
