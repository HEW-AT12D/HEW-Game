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
	StageSelectScene();
	~StageSelectScene();

private:

};

StageSelectScene::StageSelectScene()
{
}

StageSelectScene::~StageSelectScene()
{
}
