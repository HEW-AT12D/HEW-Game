#pragma once
#include "../../Framework/Input/input.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/SceneManager/SceneManager.h"
#include "../../Framework/Window/Window.h"


/**
 * @brief �Q�[�����̂��̂��Ǘ�����N���X�iApplication�N���X?�j
 * 
 * ����Ƃ��ẮA
 * �@window�̏�����������
 * �AHWND�i�E�B���h�E�̏�񎝂��Ă�A�h���X�ւ̃|�C���^�݂����Ȃ��́j���g����DirectX�̏�����������
 * �B�Q�[���̒��g�̏�����������
 * �Ƃ�������Ői�ށB���ʂɍl����ΏI�������͂��̋t�̏��ԂȂ͂�
*/
class Game {
private:
	SceneManager scenemanager;	// �V�[���Ǘ��N���X
	D3D11 d3d11;				// DirectX11�Ǘ��N���X
	Input input;				// ���͊Ǘ��N���X
	Window window;				// �E�B���h�E�N���X
	

public:
	void Init(void);		// ������
	void Update(void);		// �X�V
	void Draw(void);		// �`��
	void Uninit(void);		// �I��
};
