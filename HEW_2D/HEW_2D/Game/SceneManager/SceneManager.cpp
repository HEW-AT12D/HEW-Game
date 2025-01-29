#include "SceneManager.h"
// 今だけシーン遷移確認用にインクルード
#include "../../Framework/Input/Input.h"


/**
 * @brief シーン配列初期化
*/
void SceneManager::Init(void) 
{
	//! タイトルシーンを生成してコンテナに追加
	Scenes.emplace(TITLE, std::make_unique<TitleScene>(D3d11));
	//Scenes現在シーンをタイトルシーンに設定
	CurrentScene = TITLE;
	Scenes[CurrentScene]->Init();
}


void SceneManager::Update(void)
{
	Scenes[CurrentScene]->Update();

	if (Input::GetInstance().GetKeyTrigger(VK_RETURN)) {
		//Scenes[CurrentScene]->SetChangeScene(STAGESELECT);
		Scenes[CurrentScene]->GetChangeScene();
	}

	// 動作確認用
	// 現在シーンの遷移フラグが立っている場合、シーン遷移
	if (Scenes[CurrentScene]->GetChangeScene())
	{
		DeleteScene(CurrentScene);
		switch (CurrentScene)
		{
		case TITLE:
			// エンターでステージ選択へ
			// デバッグ用にステージ１へ飛ぶ
			ChangeScene(GAME);
			break;
		case STAGESELECT:
			// ステージ選択シーンは保持し続けるのでシーン遷移フラグだけをfalseに変更
			ChangeScene(GAME);
			break;
		case GAME:
			// エンターでリザルトへ
			ChangeScene(RESULT);
			break;
		case RESULT:	// 現在シーンがリザルトなら
			// タイトルへ戻り、シーンの初期化
			ChangeScene(STAGESELECT);
			break;
		case TEST:
			ChangeScene(RESULT);
			break;
		default:
			break;
		}
		
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
	// 全てのシーンの終了処理
	for (auto& scene : Scenes)
	{
		// シーンの中身を解放
		scene.second.reset();
	}
	// シーン配列全体を解放
	Scenes.clear();
}

/**
 * @brief シーン切り替え関数
 * タイトル、終了画面（？）、ステージ選択シーンはシーンとして保持し続けておきたい（頻繁に使うため、毎回生成→解放しなくても良くない？）
 * @param  次のシーンタグ
 * 
 * フェードインとかもさせたいので、その場合、
 * ・シーン切り替え→切り替えフラグを立てる
 *　 →切り替え中に次シーン生成とフェードアウト
 * 　　→フェードアウトしたら（もしくは生成完了したら）前シーン解放し、フェードイン（ここで前シーン解放）
*/
void SceneManager::ChangeScene(SceneName _Nextscene) {
	// 切り替え前のシーンがタイトル、ステージ選択画面ではない（保持しておきたいシーンではない）場合、
	if (CurrentScene != TITLE && CurrentScene != STAGESELECT)
	{
		// 現在シーンを解放
		DeleteScene(CurrentScene);
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
		case STAGESELECT:
			CreateScene<Stage2Scene>(STAGESELECT);
			break;
		case GAME:
			CreateScene<Stage2Scene>(GAME);
			break;
		case RESULT:
			CreateScene<ResultScene>(RESULT);
			break;
		case TEST:
			CreateScene<TestScene>(TEST);
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

/**
 * @brief シーン取得関数
 * @param _SceneName シーンのタグ
 * @return シーンのポインタ
*/
IScene* SceneManager::GetScene(SceneName& _SceneName)
{
	// シーンのイテレータを取得
	auto iterator = Scenes.find(_SceneName);

	// シーンが見つかれば
	if (iterator != Scenes.end())
	{
		// シーンのポインタを返す
		return iterator->second.get();
	}
	// 見つからなければnullptrを返す
	return nullptr;
}

/**
 * @brief シーン削除関数
 * @param _SceneName 削除したいシーンの型（mapのキー）

*/
void SceneManager::DeleteScene(SceneName _SceneName)
{
	// 指定したシーンを削除
	Scenes.erase(_SceneName);
	std::cout << _SceneName << std::endl;
}