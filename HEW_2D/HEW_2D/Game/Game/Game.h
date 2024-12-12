#pragma once
#include "../../Framework/Input/input.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/SceneManager/SceneManager.h"
#include "../../Framework/Window/Window.h"


/**
 * @brief ゲームそのものを管理するクラス（Applicationクラス?）
 * 
 * 流れとしては、
 * ①windowの初期化をする
 * ②HWND（ウィンドウの情報持ってるアドレスへのポインタみたいなもの）を使ってDirectXの初期化をする
 * ③ゲームの中身の初期化をする
 * という流れで進む。普通に考えれば終了処理はその逆の順番なはず
*/
class Game {
private:
	SceneManager scenemanager;	// シーン管理クラス
	D3D11 d3d11;				// DirectX11管理クラス
	Input input;				// 入力管理クラス
	Window window;				// ウィンドウクラス
	

public:
	void Init(void);		// 初期化
	void Update(void);		// 更新
	void Draw(void);		// 描画
	void Uninit(void);		// 終了
};
