#pragma once
#include "../main.h"
#include "../../Framework/Scene/IScene.h"


//! TODO:scenemanagerでtitlesceneとresultsceneをインクルードすると、それぞれでインクルードされているobjectmanagerとISceneが衝突してしまう
//! →scenemanager.cppでのみtitlesceneとresultsceneをインクルードして解決

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

private:
	std::array<std::unique_ptr<IScene>, 3> scenes;
	SceneName scenename;
};

