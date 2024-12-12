#pragma once

#include "../../Game/EntryPoint/main.h"

/**
 * @brief ゲームクラスを保持するウィンドウクラス
 *
 * 初期化、ゲームループ、終了処理、ウィンドウプロシージャ関数を機能として持つ
 * 
 * 
 * ＜今後の自分の勉強のためにも＞
 * 今回の擬音のゲームではウィンドウを１つしか使わない想定なのでこのクラスは静的なものとする（これがシングルトンか...?）
 * →そうするとどこからでも１つのインスタンスにアクセスできるようになる（インスタンスが１つしかない→それにしかアクセスのしようがない）
*/
class Window
{
public:
	Window();
	~Window();

	bool Init(void);			// ウィンドウの初期化処理→これ自体は外からでもしたいのでpublicでいい
	void WinMain(void);			// メインのループ
	void Uninit(void);			// 終了処理

	/**
	 * @brief ゲームループに直接書くことはないが、ウィンドウに起こったイベント（メッセージ）に応じた処理を記述する関数
	 * @param hWnd ウィンドウ情報
	 * @param uMsg メッセージ（イベント：WM_KEYDOWNとか）の情報
	 * @param wParam 32ビットの情報で、メッセージに関連する値（例：キーコードやボタンの状態）を格納する　　らしい
	 * @param lParam 64ビットの情報で、より詳細なデータ（例：座標情報やポインタ）を格納する　　らしい
	 * @return ウィンドウプロシージャ(WndProc)内でメッセージに対する処理結果を返す際に使う。メッセージの処理が成功した場合、0を返すことが一般的　　らしい
	*/
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static Window& GetInstance(void);	// インスタンス取得用関数（シングルトン実現に必要）

private:
	static Window* m_Instance;			// ウィンドウのインスタンス保持用変数（これでシングルトン実現！）
	static HINSTANCE   m_hInst;			// インスタンスハンドル
	static HWND        m_hWnd;			// ウィンドウハンドル
	static uint32_t    m_Width;			// ウィンドウの横幅
	static uint32_t    m_Height;		// ウィンドウの縦幅
};

Window::Window()
{
}

Window::~Window()
{
}
