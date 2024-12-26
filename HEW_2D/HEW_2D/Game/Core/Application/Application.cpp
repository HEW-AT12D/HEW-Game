#include "../../EntryPoint/main.h"
#include "../../../Framework/Input/Input.h"
#include "Application.h"

using namespace SimpleMath;

/**
 * @brief �A�v���S�̂Ƃ��Ă̏���������
 * 
 * �E�B���h�E��������DirectX���������Q�[��������
 * �̗���Ői�߂�
*/
void Application::Init(void)
{
	//HWND hWnd;						// �E�B���h�E�n���h������p�ϐ�
	//Window::GetInstance().Init();	// �E�B���h�E������
	//hWnd = Window::GetInstance().GetHandleWindow();		// �E�B���h�E�n���h���擾
	//d3d11.Init(hWnd);				// �E�B���h�E�����g����DirectX��������
	m_Game.Init();					// �Q�[��������
	
	//player.Init(L"asset/char01.png", 3, 4);				//�v���C���[��������
	//player.SetPosition(Vector3(100.0f, 0.0f, 0.0f));	//�ʒu��ݒ�
	//player.SetScale(Vector3(200.0f, 300.0f, 0.0f));		//�傫����ݒ�
	//player.SetRotation(Vector3(0.0f, 0.0f, 0.0f));		//�p�x��ݒ�
	//player.SetColor(Vector4(1.0f, 1.0f, 1.0f, 0.5f));	//�p�x��ݒ�

	//background.Init(L"asset/back_img_01.png");	//�w�i��������
	//background.SetPos(0.0f, 0.0f, 0.0f);		//�ʒu��ݒ�
	//background.SetSize(640.0f, 480.0f, 0.0f);	//�傫����ݒ�
	//background.SetAngle(0.0f);					//�p�x��ݒ�

}

/**
 * @brief �A�v���P�[�V�������s
 * ���������C���̃��[�v�ƂȂ�
*/
void Application::Run(void)
{
	// FPS�v���p�ϐ�
	int fpsCounter = 0;
	long long oldTick = GetTickCount64(); // �O��v�����̎���
	long long nowTick = oldTick; // ����v�����̎���

	// FPS�Œ�p�ϐ�
	LARGE_INTEGER liWork; // work�����ϐ��͍�Ɨp�ϐ�
	long long frequency;// �ǂꂭ�炢�ׂ������Ԃ��J�E���g�ł��邩
	QueryPerformanceFrequency(&liWork);
	frequency = liWork.QuadPart;
	// ���ԁi�P�ʁF�J�E���g�j�擾
	QueryPerformanceCounter(&liWork);
	long long oldCount = liWork.QuadPart;// �O��v�����̎���
	long long nowCount = oldCount;// ����v�����̎���


	//! �I��(WM_QUIT)���b�Z�[�W���Ȃ��Ԃ̓��[�v��������
	//! ����d���[�v�Ɍ����邪�AMessageLoop()�̓��b�Z�[�W��WM_QUIT�ȊO�̏ꍇtrue��Ԃ��̂ő��v(����ȊO�̃��b�Z�[�W�̓E�B���h�E�v���V�[�W���ɑ����Ă����܂�)
	while (Window::GetInstance().MessageLoop())
	{
		QueryPerformanceCounter(&liWork);// ���ݎ��Ԃ��擾
		nowCount = liWork.QuadPart;

		// 1/60�b���o�߂������H
		if (nowCount >= oldCount + frequency / 60) {
			// �Q�[�����[�v���s
			m_Game.Update();
			m_Game.Draw();
			fpsCounter++; // �Q�[�����������s������{�P����
			oldCount = nowCount;
		}
	}
	//! �I������
	Uninit();
}

//void Application::Draw(void)
//{
//	d3d11.StartRender();	// �`��J�n
//	background.Draw();		// �w�i��`��
//	player.Draw();			// �v���C���[��`��
//	d3d11.FinishRender();	// �`��I��
//}

void Application::Uninit(void)
{
	//player.Uninit();		// �v���C���[���I��
	//background.Uninit();	// �v���C���[���I��
	Window::GetInstance().Uninit();	// �E�B���h�E���I��
	m_Game.Uninit();		// �Q�[�����I��
	m_D3d11.Release();		// DirectX���I��
}
