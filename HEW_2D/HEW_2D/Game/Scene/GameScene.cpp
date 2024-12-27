#include "GameScene.h"

void GameScene::Init(void){
	
}

void GameScene::Update(void){
	// オブジェクトの数分ループを回す
	for (size_t i = 0; i < objectmanager.GetObjectCount(); i++)
	{

	}
}

void GameScene::Draw(void){
	objectmanager.Draw();
}

void GameScene::Uninit(void){

}
