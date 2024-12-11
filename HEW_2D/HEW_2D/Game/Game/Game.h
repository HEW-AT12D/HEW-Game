#pragma once
#include "../../Framework/Input/input.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/SceneManager/SceneManager.h"
#include "../../Framework/Window/Window.h"


class Game {
private:
	SceneManager scenemanager;	// シーン管理クラス
	D3D11 d3d11;				// DirectX11管理クラス
	Input input;				// 入力管理クラス
	Window window;				// ウィンドウクラス
	

public:
	void Init(HWND hWnd); // 初期化
	void Update(void);    // 更新
	void Draw();          // 描画
	void Uninit();        // 終了
};
