#include "SceneManager.h"
#include "../../Game/Scene/TitleScene.h"
#include "../../Game/Scene/ResultScene.h"
#include "../../Game/Scene/GameScene.h"

SceneManager::SceneManager()
{
	//! タイトルシーンを生成してシーン配列に追加
	Scenes.emplace(std::make_unique<TitleScene>());
	/*scenes[0] = std::make_unique<TitleScene>();
	scenes[1] = std::make_unique<GameScene>();
	scenes[2] = std::make_unique<TitleScene>();*/
}

SceneManager::~SceneManager()
{

}

/**
 * @brief シーン配列初期化
 * @param  
*/
void SceneManager::Init(void) 
{
	//! シーンの初期化

}

void SceneManager::Draw(void) {
	//! 現在シーンによってそのシーンを描画
	//! →これだとシーンの解放を考えられてなくない？添え字を指定しちゃってるからvectorな意味ないかも
	switch (CurrentScene)
	{
	case TITLE:
		Scenes[TITLE]->Draw();
		break;
	case GAME:
		Scenes[GAME]->Draw();
		break;
	case RESULT:
		Scenes[RESULT]->Draw();
		break;
	default:
		break;
	}
}

void SceneManager::Uninit(void) {
	// シーンの終了処理
	Scenes[CurrentScene]->Uninit();
}

/**
 * @brief シーン切り替え関数
 * @param  
*/
void SceneManager::ChangeScene(SceneName _Scene) {
	this->CurrentScene = _Scene;
}
