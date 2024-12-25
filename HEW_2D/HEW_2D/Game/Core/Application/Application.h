#pragma once
#include "../../../Framework/D3D11/D3D11.h"
#include "../../../Framework/Window/Window.h"
#include "../Game/Game.h"


/**
 * @brief �Q�[�����̂��̂��Ǘ�����N���X�iApplication�N���X?�j
 * 
 * ����Ƃ��ẮA
 * �@window�̏�����������
 * �AHWND�i�E�B���h�E�̏�񎝂��Ă�A�h���X�ւ̃|�C���^�݂����Ȃ��́j���g���ăR���X�g���N�^��DirectX�̏�����������
 * �B�Q�[���̒��g�̏�����������
 * �Ƃ�������Ői�ށB���ʂɍl����ΏI�������͂��̋t�̏��ԂȂ͂�
 * 
 * Input��Window�N���X�̓V���O���g���Ƃ��Đ݌v
*/
class Application {
private:
	D3D11 m_D3d11;			// DirectX11�Ǘ��N���X
	//Window window;		// �E�B���h�E�N���X
	Game m_Game;			// �Q�[���N���X
public:
	//! �����o�ϐ��͐錾�������ɏ���������遨���d3d11�̃R���X�g���N�^���Ăяo���A���̂��Ƃ�game�N���X�̃R���X�g���N�^���Ă�
	Application() :m_D3d11(), m_Game(m_D3d11) {};
	~Application() {};


	void Init(void);		// ������
	void Run(void);			// ���[�v
	void Uninit(void);		// �I��
};
