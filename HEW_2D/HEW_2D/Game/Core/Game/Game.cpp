#include "Game.h"


/**
 * @brief
 * @param
*/
void Game::Init(void)
{
	scenemanager.Init();
}


/**
 * @brief �Q�[���̃��[�v����
 * ��ȃQ�[�������͂����ɏ���
*/
void Game::Update(void)
{
	// �C�x���g�����܂ł̓��[�v��������
	scenemanager.Update();

}

void Game::Draw(void)
{
	scenemanager.Draw();
}

void Game::Uninit(void)
{
	scenemanager.Uninit();
}
