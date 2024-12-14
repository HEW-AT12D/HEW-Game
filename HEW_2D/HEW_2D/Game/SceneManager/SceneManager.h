#pragma once
#include "../../Framework/Scene/IScene.h"


//! TODO:scenemanagerでtitlesceneとresultsceneをインクルードすると、それぞれでインクルードされているobjectmanagerとISceneが衝突してしまう
//! →scenemanager.cppでのみtitlesceneとresultsceneをインクルードして解決
//! TODO:シーンをvectorで持つべき？mapで持つべき？
//! 
//! 使っていないシーンはロードせず、現在シーンだけを更新、描画するようにしたい
//! シーン遷移の時に前シーンを解放して新しいシーンを初期化、という流れにしたい

enum SceneName {
	TITLE,
	GAME,
	RESULT,

	SCENE_MAX
};

/**
 * @brief シーン管理クラス
 * 
 * タイトル、ゲーム、リザルトの３つだけなので今回はarrayを使用
 * 初期化でシーンをすべて配列に格納
 * シーン切り替え関数が必要
*/
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init(void);		//! 初期化
	void Update(void);		//! 更新
	void Draw(void);		//! 描画
	void Uninit(void);		//! 終了

	void ChangeScene(SceneName scene);	//! シーン切り替え

	template <typename T>
	void CreateScene(SceneName _name)
	{
		// タグを設定してシーンを追加
		Scenes.emplace(_name, std::make_unique<T>());
	}

private:
	std::map<std::string, std::unique_ptr<IScene>> Scenes;	//! シーン配列
	SceneName CurrentScene;
};

