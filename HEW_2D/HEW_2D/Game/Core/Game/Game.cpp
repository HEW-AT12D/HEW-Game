#include "Game.h"
#include"../../../Framework/Input/Input.h"

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
	if(Input::GetInstance().GetKeyTrigger(VK_RETURN)){ 
		scenemanager.ChangeScene(STAGESELECT); 
	}
	
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
