#pragma once

#include "../../Game/EntryPoint/main.h"

/**
 * @brief �Q�[���N���X��ێ�����E�B���h�E�N���X
 *
 * �������A�Q�[�����[�v�A�I�������A�E�B���h�E�v���V�[�W���֐����@�\�Ƃ��Ď���
 * 
 * 
 * ������̎����̕׋��̂��߂ɂ���
 * ����̋[���̃Q�[���ł̓E�B���h�E���P�����g��Ȃ��z��Ȃ̂ł��̃N���X�͐ÓI�Ȃ��̂Ƃ���i���ꂪ�V���O���g����...?�j
 * ����������Ƃǂ�����ł��P�̃C���X�^���X�ɃA�N�Z�X�ł���悤�ɂȂ�i�C���X�^���X���P�����Ȃ�������ɂ����A�N�Z�X�̂��悤���Ȃ��j
*/
class Window
{
public:
	Window();
	~Window();

	bool Init(void);			// �E�B���h�E�̏��������������ꎩ�̂͊O����ł��������̂�public�ł���
	void WinMain(void);			// ���C���̃��[�v
	void Uninit(void);			// �I������

	/**
	 * @brief �Q�[�����[�v�ɒ��ڏ������Ƃ͂Ȃ����A�E�B���h�E�ɋN�������C�x���g�i���b�Z�[�W�j�ɉ������������L�q����֐�
	 * @param hWnd �E�B���h�E���
	 * @param uMsg ���b�Z�[�W�i�C�x���g�FWM_KEYDOWN�Ƃ��j�̏��
	 * @param wParam 32�r�b�g�̏��ŁA���b�Z�[�W�Ɋ֘A����l�i��F�L�[�R�[�h��{�^���̏�ԁj���i�[����@�@�炵��
	 * @param lParam 64�r�b�g�̏��ŁA���ڍׂȃf�[�^�i��F���W����|�C���^�j���i�[����@�@�炵��
	 * @return �E�B���h�E�v���V�[�W��(WndProc)���Ń��b�Z�[�W�ɑ΂��鏈�����ʂ�Ԃ��ۂɎg���B���b�Z�[�W�̏��������������ꍇ�A0��Ԃ����Ƃ���ʓI�@�@�炵��
	*/
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static Window& GetInstance(void);	// �C���X�^���X�擾�p�֐��i�V���O���g�������ɕK�v�j

private:
	static Window* m_Instance;			// �E�B���h�E�̃C���X�^���X�ێ��p�ϐ��i����ŃV���O���g�������I�j
	static HINSTANCE   m_hInst;			// �C���X�^���X�n���h��
	static HWND        m_hWnd;			// �E�B���h�E�n���h��
	static uint32_t    m_Width;			// �E�B���h�E�̉���
	static uint32_t    m_Height;		// �E�B���h�E�̏c��
};

Window::Window()
{
}

Window::~Window()
{
}
