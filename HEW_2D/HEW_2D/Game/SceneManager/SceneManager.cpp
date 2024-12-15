#include "SceneManager.h"
#include "../../Game/Scene/StageSelectScene.h"
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

void SceneManager::Update(void)
{
	// イベント発生でシーン遷移
	if (true)
	{

	}
	
}


void SceneManager::Draw(void) {
	//! 現在シーンによってそのシーンを描画
	//! →これだとシーンの解放を考えられてなくない？添え字を指定しちゃってるからvectorな意味ないかも
	//! 　→map使う？？？
	
	// 現在シーンの描画
	Scenes[CurrentScene]->Draw();
}

void SceneManager::Uninit(void) {
	// シーンの終了処理
	Scenes[CurrentScene]->Uninit();
}

/**
 * @brief シーン切り替え関数
 * タイトル、終了画面（？）、ステージ選択シーンはシーンとして保持し続けておきたい（頻繁に使うため、毎回生成→解放しなくても良くない？）
 * @param  次のシーンタグ
*/
void SceneManager::ChangeScene(SceneName _Nextscene) {
	// 切り替え前のシーンがタイトル、終了画面、ステージ選択画面ではない場合、
	if (CurrentScene != TITLE && CurrentScene != RESULT && CurrentScene != STAGESELECT)
	{
		// 現在シーン解放
		Scenes.erase(CurrentScene);
	}

	// 切り替え予定のシーンが存在していない場合
	if (Scenes.find(_Nextscene) == Scenes.end())
	{
		// シーンを生成してmapに追加
		switch (_Nextscene)
		{
		case TITLE:
			CreateScene<TitleScene>(TITLE);
			break;
		//case STAGESELECT:
		//	CreateScene<StageSelectScene>(STAGESELECT);
		//	break;
		case GAME:
			CreateScene<GameScene>(GAME);
			break;
		case RESULT:
			CreateScene<ResultScene>(RESULT);
			break;
		default:
			break;
		}
	}
	// 現在シーンを切り替え
	this->CurrentScene = _Nextscene;

	// 切り替えたシーンの初期化
	Scenes[CurrentScene]->Init();
	
}
