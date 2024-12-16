#pragma once
#include "../../EntryPoint/main.h"
#include "../../../Framework/SceneManager/SceneManager.h"


/**
 * @brief �Q�[���N���X
 * �A�v���P�[�V�����N���X���ێ�����Q�[���N���X
 * �����̃N���X��؂�ւ���Α��̃Q�[���ł����̊O���̃N���X�͎g���܂킹��
*/
class Game
{
public:
	Game() = default;
	Game(D3D11& _D3d11) :scenemanager(_D3d11){}
	~Game();

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	SceneManager scenemanager;	// �V�[���Ǘ��N���X
};

Game::Game()
{
}

Game::~Game()
{
}