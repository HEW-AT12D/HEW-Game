#include "Game.h"
#include"../../../Framework/Input/Input.h"

/**
 * @brief
 * @param
*/
void Game::Init(void)
{
	// シーンマネージャ初期化
	scenemanager.Init();
}

/**
 * @brief ゲームのループ処理
 * 主なゲーム処理はここに書く
*/
void Game::Update(void)
{
	// ゲーム終了フラグが立っていない場合
	if (!scenemanager.GetIsQuit())
	{
		// イベント発生まではループし続ける
		scenemanager.Update();
	}
	// ゲーム終了フラグが立ったら
	else
	{
		// 「終了しますか？」を表示して
		PostMessage(Window::GetInstance().GetHandleWindow(), WM_CLOSE, 0, 0);
		// ゲーム終了フラグをリセット
		scenemanager.SetIsQuit(false);
	}
}

void Game::Draw(void)
{
	scenemanager.Draw();
}

void Game::Uninit(void)
{
	scenemanager.Uninit();
}
