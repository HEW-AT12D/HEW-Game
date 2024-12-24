#include "Game.h"


/**
 * @brief
 * @param
*/
void Game::Init(void)
{
	scenemanager.Init();
}


/**
 * @brief ゲームのループ処理
 * 主なゲーム処理はここに書く
*/
void Game::Update(void)
{
	// イベント発生まではループし続ける
	scenemanager.Update();

}

void Game::Draw(void)
{
	scenemanager.Draw();
}

void Game::Uninit(void)
{
	scenemanager.Uninit();
}
