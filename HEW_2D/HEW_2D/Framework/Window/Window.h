#pragma once

#include "../../Game/EntryPoint/main.h"

/**
 * @brief �Q�[���N���X��ێ�����E�B���h�E�N���X
 *
 * �������A�Q�[�����[�v�A�I�������A�E�B���h�E�v���V�[�W���֐����@�\�Ƃ��Ď���
 * 
 * 
 * ������̎����̕׋��̂��߂ɂ���
 * ����̋[���̃Q�[���ł̓E�B���h�E���P�����g��Ȃ��z��Ȃ̂ł��̃N���X�͐ÓI�Ȃ��̂Ƃ���i���ꂪ�V���O���g����...?���V���O���g���ƐÓI�N���X�͕ʕ��j
 * ����������Ƃǂ�����ł��P�̃C���X�^���X�ɃA�N�Z�X�ł���悤�ɂȂ�i�C���X�^���X���P�����Ȃ�������ɂ����A�N�Z�X�̂��悤���Ȃ��j
 * �@�������window�̓V���O���g���ɂ͂����Ainput���V���O���g���ɂ���
 * �@�@��window��input�̂ǂ�����V���O���g���ɕύX
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
	 * @param wParam 32�r�b�g�̏��ŁA���b�Z�[�W�Ɋ֘A����l�i��F�L�[�R�[�h��{�^���̏�ԁj���i�[����@�@�炵��
	 * @param lParam 64�r�b�g�̏��ŁA���ڍׂȃf�[�^�i��F���W����|�C���^�j���i�[����@�@�炵��
	 * @return �E�B���h�E�v���V�[�W��(WndProc)���Ń��b�Z�[�W�ɑ΂��鏈�����ʂ�Ԃ��ۂɎg���B���b�Z�[�W�̏��������������ꍇ�A0��Ԃ����Ƃ���ʓI�@�@�炵��
	*/
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/**
	 * @brief �C���X�^���X�擾�p�֐��i�V���O���g�������ɕK�v�j
	 * ��{�E�B���h�E�̃C���X�^���X�͂��̃N���X���Ő�������̂݁B������ŏ��̈�x�����B
	 * �����static�ɂ��Ȃ��ƍŏ��ɌĂяo�����Ƃ��ł��Ȃ��Ȃ�i��x�O�ŃC���X�^���X������Ă���֐��Ăяo�����Ȃ��Ƃ����Ȃ��Ȃ�j������static
	 * @return Window�̃C���X�^���X
	*/
	static Window& GetInstance(void);

	
	HWND GetHandleWindow(void);		//! �E�B���h�E�n���h���擾�֐�
	//MSG* GetMessage(void)

private:
	//! �R���X�g���N�^�ƃf�X�g���N�^��private�ɔz�u���邱�ƂŁA�C���X�^���X�𐶐��ł��Ȃ�����
	//! �R���X�g���N�^�ƃf�X�g���N�^�͕ϐ������ꂽ�Ƃ��Ə�����Ƃ��ɓ��삷��֐�
	//! �܂�A�C���X�^���X����낤�Ƃ��遨�R���X�g���N�^���������Ƃ��邯��private�����瓮���Ȃ����C���X�^���X�����Ȃ�
	//! �ƂȂ�
	Window();
	~Window();

	//static Window* m_Instance;	// �E�B���h�E�̃C���X�^���X�ێ��p�ϐ��i����ŃV���O���g�������I�������o�ϐ��ɂ���Ƃ�₱�����̂ŃQ�b�^�[�֐����̃��[�J���ϐ��Ƃ��Ă���
	static HINSTANCE	m_hInst;	// �C���X�^���X�n���h��(�A�v���P�[�V���������ʂ����񁨂���͂ǂ�Ȑ݌v�ł��P��(static)�ł���ׂ�)
	static HWND			m_hWnd;		// �E�B���h�E�n���h��(�E�B���h�E�̏������|�C���^�݂����Ȃ��́�����̓E�B���h�E�͈�Ȃ̂ŒP��(static)�Ƃ���)
	static uint32_t		m_Width;	// �E�B���h�E�̉���
	static uint32_t		m_Height;	// �E�B���h�E�̏c��
	static MSG			m_Msg;		// �E�B���h�E�̃C�x���g�����ʂ��郁�b�Z�[�W��ێ����邽�߂̍\����
};

