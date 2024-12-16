#pragma once
#include "../Scene/IScene.h"

//! TODO:scenemanagerでtitlesceneとresultsceneをインクルードすると、それぞれでインクルードされているobjectmanagerとISceneが衝突してしまう
//! →scenemanager.cppでのみtitlesceneとresultsceneをインクルードして解決
//! 


enum SceneName {
	TITLE,
	GAME,
	RESULT,

	SCENE_MAX
};

/**
 * @brief シーン管理クラス
 *
 * 初期化でシーンをすべて配列に格納
 * シーン切り替え関数が必要
*/
class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(D3D11& _D3d11) :scenes(_D3d11)
	~SceneManager();

	void Init(void);		//! 初期化
	void Update(void);		//! 更新
	void Draw(void);		//! 描画
	void Uninit(void);		//! 終了

	void ChangeScene(SceneName scene);	//! シーン切り替え

private:
	std::unordered_map<SceneName, std::unique_ptr<IScene>> scenes;	// シーン配列
	SceneName scenename;
};

