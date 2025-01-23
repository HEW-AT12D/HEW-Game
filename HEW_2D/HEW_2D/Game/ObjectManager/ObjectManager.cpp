#include "ObjectManager.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"

size_t ObjectManager::GetObjectCount(void)
{
	return Objects.size();
}


/**
 * @brief オブジェクト削除関数
 * @param object 
*/
void ObjectManager::DeleteObject(Tag _ObjName) {
	//! オブジェクト配列が空でなければ
	if (!this->Objects.empty()) {
		//! 指定した要素を削除
		//Objects.(_ObjName);
	}
}


/**
 * @brief プレイヤーと何かの当たり判定
 * 
 * 
*/
void ObjectManager::Collider_Player_to_Object(void)
{
	// プレイヤー取得
	auto playerobj = GetGameObject<Player>(PLAYER, "Player");
	
	// プレイヤーと当たったオブジェクトを確認
	for (auto& obj : Objects) {
		// タグが地面、オブジェクト、敵のものだけ当たり判定を取る
		switch (obj.first.first)
		{
		// オブジェクトが地面なら
		case BACKGROUND:
			// 地面との当たり判定を取る
			ColliderPlayer_Ground(playerobj, obj.second);
			break;
		// 画像は当たり判定を取らない
		case IMAGE:
			break;
		// UIも判定を取らない
		case UI:
			break;
		// ゲームオブジェクトなら判定を取る
		case OBJECT:
			
			break;
		case GROUND:
			break;
		case PLAYER:
			break;
		case ENEMY:
			break;
		default:
			break;
		}
		
	}

}



/**
 * @brief オブジェクト初期化
 * コンストラクタでオブジェクトを一括追加→Init内で初期化が良さげ？→それぞれ初期化値が違うのでここでオブジェクトのInitを回せない
 * 
 * ここではコンテナの初期化だけを行う
*/
void ObjectManager::Init(void) {
	// オブジェクト管理用コンテナの初期化
	Objects.clear();
}

void ObjectManager::Update(void) {

	// 範囲for文
	for (auto& obj : Objects)
	{
		// 画面外に出たらオブジェクトを削除
		// firstがキー（ObjectName）,secondがオブジェクト本体
		if (obj.second->GetPosition().x > SCREEN_WIDTH / 2 || obj.second->GetPosition().x < 0 - SCREEN_WIDTH / 2 ||
			obj.second->GetPosition().y > SCREEN_HEIGHT / 2 || obj.second->GetPosition().y < 0 - SCREEN_HEIGHT / 2) {
			//this->DeleteObject(obj.first);		// オブジェクトのキーを指定して削除
		}
		obj.second->Update();
	}
	
}

void ObjectManager::Draw(void) {
	D3d11.StartRender();
	// 範囲for文
	// 先に背景から描画
	for (auto& obj : Objects)
	{
		if (obj.first.first == BACKGROUND)
		{
			// firstがキー（ObjectName）,secondがオブジェクト本体
			obj.second->Draw();
		}
	}

	// 背景以外を描画
	for (auto& obj : Objects)
	{
		if (obj.first.first != BACKGROUND)
		{
			obj.second->Draw();
		}
	}
	D3d11.FinishRender();
}

void ObjectManager::Uninit(void) {
	// 範囲for文
	for (auto& obj : Objects)
	{
		// firstがキー（ObjectName）,secondがオブジェクト本体
		// オブジェクトの中身を解放
		obj.second->Uninit();
	}
	// コンテナ全体を解放
	Objects.clear();
}
