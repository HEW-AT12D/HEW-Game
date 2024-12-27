#include "Game.h"
#include"../../../Framework/Input/Input.h"

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
	if(Input::GetInstance().GetKeyTrigger(VK_RETURN)){ 
		scenemanager.ChangeScene(STAGESELECT); 
	}
	
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
