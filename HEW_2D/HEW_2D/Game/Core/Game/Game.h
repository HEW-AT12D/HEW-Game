#pragma once
#include "../../EntryPoint/main.h"
#include "../../../Framework/SceneManager/SceneManager.h"


/**
 * @brief ゲームクラス
 * アプリケーションクラスが保持するゲームクラス
 * →このクラスを切り替えれば他のゲームでもこの外側のクラスは使いまわせる
*/
class Game
{
public:
	Game() = default;
	Game(D3D11& _D3d11) :scenemanager(_D3d11){}
	~Game();

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	SceneManager scenemanager;	// シーン管理クラス
};

Game::Game()
{
}

Game::~Game()
{
}