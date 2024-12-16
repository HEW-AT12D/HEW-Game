#include "Game.h"


void Game::Init(void)
{
	scenemanager.Init();
}


void Game::Update(void)
{
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
