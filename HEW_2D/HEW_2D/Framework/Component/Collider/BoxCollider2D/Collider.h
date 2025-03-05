#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"
#include <memory>
#include <algorithm> // std::min を使うため

/**
 * @brief 四角と四角の当たり判定
 * @param  
 * @param  
 * @return 結果
*/
template <class T, class U>
bool BoxCollider2(std::shared_ptr<T> _obj1, std::shared_ptr<U> _obj2,std::shared_ptr<Player>_player)
{
	// オブジェクト1の各辺
	float Object1_Right_Collider = _obj1->GetPosition().x + _obj1->GetScale().x / 2;
	float Object1_Left_Collider = _obj1->GetPosition().x - _obj1->GetScale().x / 2;
	float Object1_Top_Collider = _obj1->GetPosition().y + _obj1->GetScale().y / 2;
	float Object1_Bottom_Collider = _obj1->GetPosition().y - _obj1->GetScale().y / 2;

	// オブジェクト2の各辺
	float Object2_Right_Collider = _obj2->GetPosition().x + _obj2->GetScale().x / 2;
	float Object2_Left_Collider = _obj2->GetPosition().x - _obj2->GetScale().x / 2;
	float Object2_Top_Collider = _obj2->GetPosition().y + _obj2->GetScale().y / 2;
	float Object2_Bottom_Collider = _obj2->GetPosition().y - _obj2->GetScale().y / 2;

	// 衝突判定
	if (Object1_Right_Collider > Object2_Left_Collider &&
		Object2_Right_Collider > Object1_Left_Collider &&
		Object1_Bottom_Collider < Object2_Top_Collider &&
		Object1_Top_Collider > Object2_Bottom_Collider)
	{
		// オーバーラップ量の計算
		float overlapRight = Object1_Right_Collider - Object2_Left_Collider;
		float overlapLeft = Object2_Right_Collider - Object1_Left_Collider;
		float overlapBottom = Object2_Top_Collider - Object1_Bottom_Collider;
		float overlapTop = Object1_Top_Collider - Object2_Bottom_Collider;

		// `std::min` を使わずに最小値を求める
		float minOverlap = overlapRight;
		if (overlapLeft < minOverlap) minOverlap = overlapLeft;
		if (overlapBottom < minOverlap) minOverlap = overlapBottom;
		if (overlapTop < minOverlap) minOverlap = overlapTop;

		if (minOverlap == overlapRight) {
			std::cout << "右から衝突" << std::endl;
			_player->SetMoveRight(false);

			return true;  // 右から衝突
		}
		else if (minOverlap == overlapLeft) {
			std::cout << "左から衝突" << std::endl;
			_player->SetMoveLeft(false);

			return true;  // 左から衝突
		}
		else if (minOverlap == overlapBottom) {
			std::cout << "下から衝突" << std::endl;
			_player->SetOnGround(true);
			_player->SetDirection(Vector3({ 0.0f }));
			_player->AddForce(Vector3({ 0.0f }));
			return true;  // 下から衝突
		}
		else {
			std::cout << "上から衝突" << std::endl;
			return true;  // 上から衝突
		}
	}

	return false; // 衝突なし
}

template <class T, class U>
bool BoxCollider(std::shared_ptr<T> _obj1, std::shared_ptr<U> _obj2)
{

	float Object1_Right_Collider, Object1_Left_Collider, Object1_Top_Collider, Object1_Bottom_Collider;//playerの当たり判定変数
	float Object2_Right_Collider, Object2_Left_Collider, Object2_Top_Collider, Object2_Bottom_Collider;//groundの当たり判定変数

	Object1_Right_Collider = _obj1->GetPosition().x + _obj1->GetScale().x / 2; //プレイヤーの右当たり判定変数
	Object1_Left_Collider = _obj1->GetPosition().x - _obj1->GetScale().x / 2;  //プレイヤーの左当たり判定変数
	Object1_Top_Collider = _obj1->GetPosition().y + _obj1->GetScale().y / 2;    //プレイヤーの上当たり判定変数
	Object1_Bottom_Collider = _obj1->GetPosition().y - _obj1->GetScale().y / 2;//プレイヤーの下当たり判定変数

	Object2_Right_Collider = _obj2->GetPosition().x + _obj2->GetScale().x / 2; //グラウンドの右の当たり判定変数
	Object2_Left_Collider = _obj2->GetPosition().x - _obj2->GetScale().x / 2;  //グラウンドの左の当たり判定変数
	Object2_Top_Collider = _obj2->GetPosition().y + _obj2->GetScale().y / 2;    //グラウンドの上の当たり判定変数
	Object2_Bottom_Collider = _obj2->GetPosition().y - _obj2->GetScale().y / 2;//グラウンドの下の当たり判定変数

	// 四角と四角の当たり判定
	if (Object1_Right_Collider > Object2_Left_Collider &&
		Object2_Right_Collider > Object1_Left_Collider &&
		Object1_Bottom_Collider < Object2_Top_Collider &&
		Object1_Top_Collider > Object2_Bottom_Collider)
	{
		return true;
	}
	return false;
}


bool ColliderPlayer_Ground(std::shared_ptr<Player>, std::vector<std::shared_ptr<GameObject>>);	//PlayerとGroundの当たり判定関数

/**
 * @brief 対地面地面の当たり判定
 * @tparam T 何かの型
 * @param  地面
*/
template <class T>
bool Collider_toGround(std::weak_ptr<T> _obj1, std::weak_ptr<GameObject> _obj2)
{
	auto obj1 = _obj1.lock();
	auto obj2 = _obj2.lock();

	if (BoxCollider(obj1, obj2))
	{
		// 地面に当たったオブジェクトの速度、方向ベクトルをリセットする
		obj1->SetDirection(Vector3({0.0f}));
		obj1->AddForce(Vector3({0.0f}));
		obj1->SetOnGround(true);
		return true;
	}
	else {
		//obj1->SetOnGround(false);
		return false;
	}
}

template <class T>
bool Collider_toEnemy(std::weak_ptr<T> _obj1, std::weak_ptr<GameObject> _obj2)
{
	auto obj1 = _obj1.lock();
	auto obj2 = _obj2.lock();

	if (BoxCollider(obj1, obj2))
	{
		// 地面に当たったオブジェクトの速度、方向ベクトルをリセットする
		obj1->SetDirection(Vector3({ 0.0f }));
		obj1->AddForce(Vector3({ 0.0f }));
		obj1->SetOnGround(true);
		return true;
	}
	else {
		obj1->SetOnGround(false);
		return false;
	}
}


/**
 * @brief オブジェクト配列同士の当たり判定を取得(全て四角)
 * @tparam T
 * @tparam U
 * @param _objects1
 * @param _objects2
 * 
 * 中で第一引数のベクトルをリセットする
 * 
 * @return
*/
template <class T, class U>
bool Collider_Objects_Objects(std::vector<std::shared_ptr<T>>_objects1, std::vector<std::shared_ptr<U>>_objects2)
{
	// オブジェクトごとにBoxColliderを回す
	for (auto& obj2 : _objects2)
	{
		for (auto& obj1 : _objects1)
		{
			// 当たった場合
			if (BoxCollider(obj1, obj2))
			{
				// 第一引数側のオブジェクトのベクトルをリセット
				obj1->SetDirection(Vector3({ 0.0f }));
				obj1->AddForce(Vector3({ 0.0f }));
				obj1->SetOnGround(true);
				return true;
			}
			else {
				obj1->SetOnGround(false);
				
			}
		}
	}
	return false;
}



/**
 * @brief プレイヤーとオブジェクトの当たり判定
 * @param _player プレイヤー
 * @param _objects オブジェクトのvector
*/
bool Collider_to_Object(std::weak_ptr<Player> _player, std::weak_ptr<GameObject> _objects);

/**
 * @brief プレイヤーとマガジンの当たり判定
*/
bool Collider_Player_to_Magazine(std::weak_ptr<Player> obj1, std::weak_ptr<Magazine> obj2);



bool ColliderPlayer_Gion(std::shared_ptr<Player>, std::shared_ptr<GameObject>);//Playerと擬音の当たり判定関数

// 扇型と擬音の当たり判定関数
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// 線分と円が交差しているか判定する関数

//void DrawFan(GameObject*, bool);
