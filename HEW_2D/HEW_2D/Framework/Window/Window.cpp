#include "Window.h"


HINSTANCE Window::m_hInst = nullptr;	// �C���X�^���X�n���h��(�A�v���P�[�V���������ʂ����񁨂���͂ǂ�Ȑ݌v�ł��P��(static)�ł���ׂ�)
HWND Window::m_hWnd = nullptr;			// �E�B���h�E�n���h��(�E�B���h�E�̏������|�C���^�݂����Ȃ��́�����̓E�B���h�E�͈�Ȃ̂ŒP��(static)�Ƃ���)
uint32_t Window::m_Width = 0;			// �E�B���h�E�̉���
uint32_t Window::m_Height = 0;			// �E�B���h�E�̏c��
MSG Window::m_Msg = { nullptr };		// �E�B���h�E����̃��b�Z�[�W���󂯎��\���̂�������


Window::Window()
{
}

Window::~Window()
{
}


/**
 * @brief �C���X�^���X�擾�֐�
 * @param  �Ȃ�
 * @return ���g�̃C���X�^���X
 *
 * ��x�ڂ̃C���X�^���X�Ăяo���ł���Ύ��g�𐶐����A���ɃC���X�^���X�����݂��Ă���΂����Ԃ�
*/
Window& Window::GetInstance(void) {
	// ���g�̃C���X�^���X��static�Ő���
	static Window Instance;

	return Instance;
}


/**
 * @brief �E�B���h�E�̏�����
 *
 * �E�B���h�E�̓o�^�ƍ쐬"����"���s��
 *
 * @param �E�B���h�E�̕��A����
*/
bool Window::Init(uint32_t _Screen_width, uint32_t _Screen_height) {
	//! �����Őݒ肵���E�B���h�E�T�C�Y�������o�ϐ��ɑ��
	m_Width = _Screen_width;
	m_Height = _Screen_height;

	//! �E�B���h�E�̏�����
	// �C���X�^���X�n���h�����擾.
	auto hInst = GetModuleHandle(nullptr);
	if (hInst == nullptr)
	{
		return false;
	}

	// �E�B���h�E�̐ݒ�.
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hIcon = LoadIcon(hInst, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInst, IDC_ARROW);
	wc.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = ClassName;
	wc.hIconSm = LoadIcon(hInst, IDI_APPLICATION);

	// �E�B���h�E�̓o�^.
	if (!RegisterClassEx(&wc))
	{
		return false;
	}

	// �C���X�^���X�n���h���ݒ�.
	m_hInst = hInst;

	// �E�B���h�E�̃T�C�Y��ݒ�.
	RECT rc = {};
	rc.right = static_cast<LONG>(m_Width);
	rc.bottom = static_cast<LONG>(m_Height);

	// �E�B���h�E�T�C�Y�𒲐�.
	auto style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	AdjustWindowRect(&rc, style, FALSE);

	// �E�B���h�E�𐶐�.
	m_hWnd = CreateWindowEx(
		0,
		//        WS_EX_TOPMOST,
		ClassName,				// �g���E�B���h�E�X�^�C��
		WindowName,				// �E�B���h�E�̖��O
		style,					// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,			// �E�B���h�E�̍���w���W
		CW_USEDEFAULT,			// �E�B���h�E�̍���x���W 
		rc.right - rc.left,		// �E�B���h�E�̕�
		rc.bottom - rc.top,		// �E�B���h�E�̍���
		nullptr,				// �e�E�B���h�E�̃n���h��
		nullptr,				// ���j���[�n���h���܂��͎q�E�B���h�EID
		m_hInst,				// �C���X�^���X�n���h��
		nullptr);				// �E�B���h�E�쐬�f�[�^

	// �����E�B���h�E�̏�񂪂Ȃ��i�E�B���h�E�쐬�����܂������ĂȂ��j�Ȃ�
	if (m_hWnd == nullptr)
	{
		// ���������s�Ƃ���
		return false;
	}

	// �E�B���h�E��\��.
	ShowWindow(m_hWnd, SW_SHOWNORMAL);

	// �E�B���h�E���X�V.
	UpdateWindow(m_hWnd);

	// �E�B���h�E�Ƀt�H�[�J�X��ݒ�.
	SetFocus(m_hWnd);

	// ����I���i�E�B���h�E�n���h����Ԃ��j.
	return true;
}


//-----------------------------------------------------------------------------
// ���b�Z�[�W���[�v�i���b�Z�[�W������Ԃ������[�v����֐��j
//-----------------------------------------------------------------------------
bool Window::MessageLoop(void) {
	// �V���Ƀ��b�Z�[�W(WM_KEYDOWN�Ƃ������������)�������
	while (PeekMessage(&m_Msg, NULL, 0, 0, PM_REMOVE))
	{
		// �E�B���h�E�v���V�[�W���֐��Ƀ��b�Z�[�W�𑗂�
		TranslateMessage(&m_Msg);
		DispatchMessage(&m_Msg);

		// �uWM_QUIT�v���b�Z�[�W���󂯎�����烋�[�v�𔲂���
		if (m_Msg.message == WM_QUIT) {
			// �Q�[���I���i�E�B���h�E�����j
			return false;
		}
	}
	//! ���b�Z�[�W���Ȃ�(�Ȃ��Ȃ���)�̂Ŏ��̏�����
	return true;
}


//-----------------------------------------------------------------------------
// �E�B���h�E�̏I������
//-----------------------------------------------------------------------------
void Window::Uninit(void) {
	// �E�B���h�E�̓o�^������.
	if (m_hInst != nullptr)
	{
		UnregisterClass(ClassName, m_hInst);
	}

	m_hInst = nullptr;
	m_hWnd = nullptr;
}


//--------------------------------------------------------------------------------------
//�E�B���h�E�v���V�[�W���i�v���V�[�W�� = �葱���j
//--------------------------------------------------------------------------------------
LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ��ԊǗ��p�ϐ�
	static bool isFullScreen = false;
	static bool isMessageBoxShowed = false;

	switch (uMsg)
	{
	case WM_DESTROY:// �E�B���h�E�j���̃��b�Z�[�W
		PostQuitMessage(0);// �uWM_QUIT�v���b�Z�[�W�𑗂�@���@�A�v���I��
		break;
	case WM_CLOSE:  // �ux�v�{�^���������ꂽ��
	{
		// ���b�Z�[�W�{�b�N�\�����ɂ��������s�����̂ł����ɓ���\��������
		isMessageBoxShowed = true;
		int res = MessageBoxA(NULL, "�I�����܂����H", "�m�F", MB_OKCANCEL);
		isMessageBoxShowed = false;
		if (res == IDOK) {
			DestroyWindow(hWnd);  // �uWM_DESTROY�v���b�Z�[�W�𑗂�
		}
	}
	break;
	case WM_KEYDOWN: //�L�[���͂��������ꍇ�̃��b�Z�[�W
		if (LOWORD(wParam) == VK_ESCAPE) { //���͂��ꂽ�L�[��ESCAPE�Ȃ�
			PostMessage(hWnd, WM_CLOSE, wParam, lParam);//�uWM_CLOSE�v�𑗂�
		}
		else if (LOWORD(wParam) == VK_F11) {
			// F11�L�[�Ńt���X�N���[���ɐ؂�ւ�
			isFullScreen = !isFullScreen;
			if (isFullScreen) {
				// �^���t���X�N���[�����[�h�ɕύX
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP | WS_MINIMIZEBOX);	// �E�B���h�E�g���폜
				// �f�B�X�v���C�𑜓x���擾
				int	screenWidth = GetSystemMetrics(SM_CXSCREEN);
				int screenHeight = GetSystemMetrics(SM_CYSCREEN);
				// �E�B���h�E�T�C�Y��ς���
				SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
			}
			else {
				// �ʏ�E�B���h�E�ɖ߂�
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);			// �E�B���h�E�g���폜
				SetWindowPos(hWnd, HWND_TOP, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
			}
		}
		else {

		}
		break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			// �t���X�N���[���\�������b�Z�[�W�{�b�N�X��\���̂Ƃ�
			if (isFullScreen && !isMessageBoxShowed) {
				// �E�B���h�E���ŏ�������i�^�X�N�؂�ւ����ɔw��Ɏc����΍�j
				ShowWindow(hWnd, SW_MINIMIZE);
			}
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);	// �W�����������s�����邽��
		break;
	default:
		// ���ʂ���Ȃ��i����case�Œ�`����Ă��Ȃ��悤�ȁj���b�Z�[�W�i�����j�̏ꍇ�͂������ɔ��
		// �󂯎�������b�Z�[�W�ɑ΂��ăf�t�H���g�̏��������s
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}

/**
 * @brief �E�B���h�E�n���h���擾�֐�
 * �E�B���h�E�n���h���̓E�B���h�E�̏������������ŃE�B���h�E�̓o�^�Ȃǂ��ς܂��Ă��珉�߂ď��Ƃ��Đ�������
 * ��static�ɂ���i�C���X�^���X�����O�ɌĂяo����悤�ɂ���j�K�v�͂Ȃ�
 * @return �E�B���h�E�n���h��
*/
HWND Window::GetHandleWindow(void)
{
	return this->m_hWnd;
}
