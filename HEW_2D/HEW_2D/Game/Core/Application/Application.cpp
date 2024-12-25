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
*/
void Application::Run(void)
{
	// ���C�����[�v���s
	Window::GetInstance().WinMain();
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
	m_D3d11.Release();		// DirectX���I��
}
