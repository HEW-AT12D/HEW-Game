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
	game.Init();					// �Q�[��������
	
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

void Application::Run(void)
{
	//! MSG�F�E�B���h�E�̃C�x���g�����ʂ��郁�b�Z�[�W��ێ����邽�߂̍\����
	MSG msg = {};

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
	// �Q�[�����[�v
	while (1)
	{
		// �V���Ƀ��b�Z�[�W�������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// �E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// �uWM_QUIT�v���b�Z�[�W���󂯎�����烋�[�v�𔲂���
			if (msg.message == WM_QUIT) {
				break;
			}
		}
		else
		{
			QueryPerformanceCounter(&liWork);// ���ݎ��Ԃ��擾
			nowCount = liWork.QuadPart;
			// 1/60�b���o�߂������H
			if (nowCount >= oldCount + frequency / 60) {



				//! �Q�[������
				game.Update();

				//// �J�����X�V
				//camera.Update();

				//// ���͏����X�V
				//input.Update();

				//// �e�X�g�v���[���X�V
				////plane.Update();
				////cube.Update();
				////model.Update();
				////ball.Update();
				//
				//// �I�u�W�F�N�g�X�V
				//for (auto& o : Objects) {
				//	o->Update();
				//}

				//// �`��O����
				//Renderer::Begin();

				//! �`��
				game.Draw();

				//// �J�����Z�b�g
				//camera.Draw();

				//// �e�X�g�v���[���`��
				//
				////plane.Draw();
				////cube.Draw();
				////model.Draw();
				////ball.Draw();

				//// �I�u�W�F�N�g�`��
				//for (auto& o : Objects) {
				//	o->Draw();
				//}

				//// �`��㏈��
				//Renderer::End();


				fpsCounter++; // �Q�[�����������s������{�P����
				oldCount = nowCount;
			}


		}
	}

	//Vector3 pos = player.GetPosition();
	//pos.x += 1.0f;

	//if (Input::GetInstance().GetKeyPress(VK_W)) { pos.y += 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_A)) { pos.x -= 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_S)) { pos.y -= 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_D)) { pos.x += 1.0f; }

	//// I�L�[�Ńt���X�N���[����
	//if (Input::GetInstance().GetKeyTrigger(VK_I)) {
	//	d3d11.GetSwapChain()->SetFullscreenState(TRUE, NULL);
	//}
	//// K�L�[�Ńt���X�N���[������
	//if (Input::GetInstance().GetKeyTrigger(VK_K)) {
	//	d3d11.GetSwapChain()->SetFullscreenState(FALSE, NULL);
	//}

	//player.SetPos(pos.x, pos.y, pos.z);
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
	d3d11.Release();		// DirectX���I��
}
