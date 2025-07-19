#include "Game.h"
#include"../../../Framework/Input/Input.h"

/**
 * @brief
 * @param
*/
void Game::Init(void)
{
	// �T�E���h������
	m_pGameSound->Init();
	// �V�[���}�l�[�W��������
	scenemanager.Init();
}

/**
 * @brief �Q�[���̃��[�v����
 * ��ȃQ�[�������͂����ɏ���
*/
void Game::Update(void)
{
	// �Q�[���I���t���O�������Ă��Ȃ��ꍇ
	if (!scenemanager.GetIsQuit())
	{
		// �C�x���g�����܂ł̓��[�v��������
		scenemanager.Update();
	}
	// �Q�[���I���t���O����������
	else
	{
		// �u�I�����܂����H�v��\������
		PostMessage(Window::GetInstance().GetHandleWindow(), WM_CLOSE, 0, 0);
		// �Q�[���I���t���O�����Z�b�g
		scenemanager.SetIsQuit(false);
	}
}

void Game::Draw(void)
{
	scenemanager.Draw();
}

void Game::Uninit(void)
{
	scenemanager.Uninit();
	m_pGameSound->Uninit();	// �T�E���h�I��
	CoUninitialize();		// ���s���ɃQ�[���𗎂Ƃ��ƃT�E���h�̉�������ꂸ�Ƀ��������[�N���N�����̂ł�����COM���C�u�������I��
}
