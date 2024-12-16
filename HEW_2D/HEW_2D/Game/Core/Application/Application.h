#pragma once
#include "../../../Framework/D3D11/D3D11.h"
#include "../../../Framework/Window/Window.h"
#include "../Game/Game.h"


/**
 * @brief �Q�[�����̂��̂��Ǘ�����N���X�iApplication�N���X?�j
 * 
 * ����Ƃ��ẮA
 * �@window�̏�����������
 * �AHWND�i�E�B���h�E�̏�񎝂��Ă�A�h���X�ւ̃|�C���^�݂����Ȃ��́j���g����DirectX�̏�����������
 * �B�Q�[���̒��g�̏�����������
 * �Ƃ�������Ői�ށB���ʂɍl����ΏI�������͂��̋t�̏��ԂȂ͂�
*/
class Application {
private:
	D3D11 d3d11;				// DirectX11�Ǘ��N���X
	Window window;				// �E�B���h�E�N���X
	Game game;					// �Q�[���N���X

public:
	Application() :game(d3d11) {};
	~Application();


	void Init(void);		// ������
	void Run(void);			// ���[�v
	void Uninit(void);		// �I��
};
