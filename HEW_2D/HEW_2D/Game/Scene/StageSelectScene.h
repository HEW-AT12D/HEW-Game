#pragma once
#include "../../Framework/Scene/IScene.h"


/**
 * @brief ステージ選択シーン
 * このシーンはゲーム中常に保持しておく
 * 
 * 順番にステージを開けていく設計にするならそれを管理する仕組みも必要
*/
class StageSelectScene :public IScene
{
public:
	StageSelectScene() = default;
	StageSelectScene(D3D11& _D3d11) :IScene(_D3d11) {}
	~StageSelectScene();

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:

};

// TODO:ここの謎のエラーを直す
StageSelectScene::~StageSelectScene()
{

}
