#include "ObjectManager.h"




size_t ObjectManager::GetObjectCount(void)
{
	return Objects.size();
}


/**
 * @brief オブジェクト取得関数
 * @param _Tag オブジェクトタグ
 * @param _Name 付けたい名前
 * @return オブジェクトの生ポインタ
*/
GameObject* ObjectManager::GetGameObject(const Tag& _Tag, const std::string _Name)
{
	// タグと名前の一致するオブジェクトを見つける(見つからない場合はend()が返ってくる)
	auto iterator = Objects.find(std::make_pair(_Tag, _Name));
	// 見つかった場合
	if (iterator != Objects.end())
	{
		return iterator->second.get();
	}

	// 見つからなければnullprtを返す
	return nullptr;
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
	}
	
}

void ObjectManager::Draw(void) {
	D3d11.StartRender();
	// 範囲for文
	for (auto& obj : Objects)
	{
		// firstがキー（ObjectName）,secondがオブジェクト本体
		obj.second->Draw();
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
