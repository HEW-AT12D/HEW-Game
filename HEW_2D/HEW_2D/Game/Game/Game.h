#pragma once
#include "../../Framework/Input/input.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/SceneManager/SceneManager.h"
#include "../../Framework/Window/Window.h"


class Game {
private:
	SceneManager scenemanager;	// �V�[���Ǘ��N���X
	D3D11 d3d11;				// DirectX11�Ǘ��N���X
	Input input;				// ���͊Ǘ��N���X
	Window window;				// �E�B���h�E�N���X
	

public:
	void Init(HWND hWnd); // ������
	void Update(void);    // �X�V
	void Draw();          // �`��
	void Uninit();        // �I��
};
