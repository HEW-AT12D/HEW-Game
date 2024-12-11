#pragma once
#include "../main.h"
#include <Windows.h>

/**
 * @brief ゲームクラスを保持するウィンドウクラス
 *
 * 初期化、ゲームループ、終了処理、ウィンドウプロシージャ関数を機能として持つ
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
	static HINSTANCE   m_hInst;        // インスタンスハンドル
	static HWND        m_hWnd;         // ウィンドウハンドル
	static uint32_t    m_Width;        // ウィンドウの横幅
	static uint32_t    m_Height;       // ウィンドウの縦幅
};

Window::Window()
{
}

Window::~Window()
{
}
