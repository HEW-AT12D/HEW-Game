#include "Game.h"
#include"../../../Framework/Input/Input.h"

/**
 * @brief
 * @param
*/
void Game::Init(void)
{
	// シーンマネージャ、サウンドの初期化
	scenemanager.Init();
	sound.Init();
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
	sound.Uninit();
}
