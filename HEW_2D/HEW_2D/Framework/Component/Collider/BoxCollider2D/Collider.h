#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


bool ColliderPlayer_Ground(std::weak_ptr<Player>, std::weak_ptr<GameObject>);	//PlayerとGroundの当たり判定関数

/**
 * @brief 対地面地面の当たり判定
 * @tparam T 何かの型
 * @param  地面
*/
template <class T>
bool Collider_toGround(std::weak_ptr<T> obj1, std::weak_ptr<GameObject> obj2)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//playerの当たり判定変数
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//groundの当たり判定変数

	Player_Right_Collider = obj1.lock()->GetPosition().x + obj1.lock()->GetScale().x / 2; //プレイヤーの右当たり判定変数
	Player_Left_Collider = obj1.lock()->GetPosition().x - obj1.lock()->GetScale().x / 2;  //プレイヤーの左当たり判定変数
	Player_Top_Collider = obj1.lock()->GetPosition().y + obj1.lock()->GetScale().y / 2;    //プレイヤーの上当たり判定変数
	Player_Bottom_Collider = obj1.lock()->GetPosition().y - obj1.lock()->GetScale().y / 2;//プレイヤーの下当たり判定変数

	Ground_Right_Collider = obj2.lock()->GetPosition().x + obj2.lock()->GetScale().x / 2; //グラウンドの右の当たり判定変数
	Ground_Left_Collider = obj2.lock()->GetPosition().x - obj2.lock()->GetScale().x / 2;  //グラウンドの左の当たり判定変数
	Ground_Top_Collider = obj2.lock()->GetPosition().y + obj2.lock()->GetScale().y / 2;    //グラウンドの上の当たり判定変数
	Ground_Bottom_Collider = obj2.lock()->GetPosition().y - obj2.lock()->GetScale().y / 2;//グラウンドの下の当たり判定変数

	Ground_Bottom_Collider = Ground_Bottom_Collider + 150; //Groundの下の部分に当たった時にtrueを返さないようにする（少し座標を上にあげてる）

	//プレイヤーとグラウンドの当たり判定
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		// 地面に当たったオブジェクトの速度、方向ベクトルをリセットする
		obj1.lock()->SetDirection(Vector3({ 0.0f }));
		obj1.lock()->AddForce(Vector3({ 0.0f }));
		obj1.lock()->SetOnGround(true);
		return true;
	}
	else {
		obj1.lock()->SetOnGround(false);
		return false;
	}
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



bool ColliderPlayer_Gion(GameObject*, GameObject*);//Playerと擬音の当たり判定関数

// 扇型と擬音の当たり判定関数
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// 線分と円が交差しているか判定する関数

//void DrawFan(GameObject*, bool);
