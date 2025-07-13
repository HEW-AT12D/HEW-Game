#pragma once

#include "../../Game/EntryPoint/main.h"

/**
 * @brief �Q�[���N���X��ێ�����E�B���h�E�N���X
 * �������A�Q�[�����[�v�A�I�������A�E�B���h�E�v���V�[�W���֐����@�\�Ƃ��Ď���
*/
class Window
{
public:

	/**
	 * @brief �E�B���h�E�̏���������
	 * �����ꎩ�̂͊O����ł��������̂�public�ł���
	 * @param screen_width �E�B���h�E�̕�
	 * @param screen_height �E�B���h�E�̍���
	 * @return ����������or���s
	*/
	bool Init(uint32_t _Screen_width = SCREEN_WIDTH, uint32_t _Screen_height = SCREEN_HEIGHT);
	bool MessageLoop(void);		// ���b�Z�[�W���[�v
	void Uninit(void);			// �I������

	/**
	 * @brief �Q�[�����[�v�ɒ��ڏ������Ƃ͂Ȃ����A�E�B���h�E�ɋN�������C�x���g�i���b�Z�[�W�j�ɉ������������L�q����֐�
	 * @param hWnd �E�B���h�E���
	 * @param uMsg ���b�Z�[�W�i�C�x���g�FWM_KEYDOWN�Ƃ��j�̏��
	 * @param wParam 32�r�b�g�̏��ŁA���b�Z�[�W�Ɋ֘A����l�i��F�L�[�R�[�h��{�^���̏�ԁj���i�[����
	 * @param lParam 64�r�b�g�̏��ŁA���ڍׂȃf�[�^�i��F���W����|�C���^�j���i�[����
	 * @return �E�B���h�E�v���V�[�W��(WndProc)���Ń��b�Z�[�W�ɑ΂��鏈�����ʂ�Ԃ��ۂɎg���B���b�Z�[�W�̏��������������ꍇ�A0��Ԃ����Ƃ���ʓI
	*/
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/**
	 * @brief �C���X�^���X�擾�p�֐��i�V���O���g�������ɕK�v�j
	 * ��{�E�B���h�E�̃C���X�^���X�͂��̃N���X���Ő�������̂݁B������ŏ��̈�x�����B
	 * @return Window�̃C���X�^���X
	*/
	static Window& GetInstance(void);

	HWND GetHandleWindow(void);		//! �E�B���h�E�n���h���擾�֐�

private:
	//! �R���X�g���N�^�ƃf�X�g���N�^��private�ɔz�u���邱�ƂŁA�C���X�^���X�𐶐��ł��Ȃ�����
	//! �R���X�g���N�^�ƃf�X�g���N�^�͕ϐ������ꂽ�Ƃ��Ə�����Ƃ��ɓ��삷��֐�
	//! �܂�A�C���X�^���X����낤�Ƃ��遨�R���X�g���N�^���������Ƃ��邯��private�����瓮���Ȃ����C���X�^���X�����Ȃ�
	Window();
	~Window();

	static HINSTANCE	m_hInst;	// �C���X�^���X�n���h��(�A�v���P�[�V���������ʂ����񁨂���͂ǂ�Ȑ݌v�ł��P��(static)�ł���ׂ�)
	static HWND			m_hWnd;		// �E�B���h�E�n���h��(�E�B���h�E�̏������|�C���^�݂����Ȃ��́�����̓E�B���h�E�͈�Ȃ̂ŒP��(static)�Ƃ���)
	static uint32_t		m_Width;	// �E�B���h�E�̉���
	static uint32_t		m_Height;	// �E�B���h�E�̏c��
	static MSG			m_Msg;		// �E�B���h�E�̃C�x���g�����ʂ��郁�b�Z�[�W��ێ����邽�߂̍\����
};

