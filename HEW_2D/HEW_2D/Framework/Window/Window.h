#pragma once
#include "../main.h"
#include <Windows.h>

/**
 * @brief �Q�[���N���X��ێ�����E�B���h�E�N���X
 *
 * �������A�Q�[�����[�v�A�I�������A�E�B���h�E�v���V�[�W���֐����@�\�Ƃ��Ď���
*/
class Window
{
public:
	Window();
	~Window();

	bool Init(void);
	void WinMain(void);
	void Uninit(void);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


private:
	static HINSTANCE   m_hInst;        // �C���X�^���X�n���h��
	static HWND        m_hWnd;         // �E�B���h�E�n���h��
	static uint32_t    m_Width;        // �E�B���h�E�̉���
	static uint32_t    m_Height;       // �E�B���h�E�̏c��
};

Window::Window()
{
}

Window::~Window()
{
}
