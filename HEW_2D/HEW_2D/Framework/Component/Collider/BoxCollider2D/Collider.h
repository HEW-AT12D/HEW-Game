#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


/**
 * @brief lŠp‚ÆlŠp‚Ì“–‚½‚è”»’è
 * @param  
 * @param  
 * @return Œ‹‰Ê
*/
template <class T, class U>
bool BoxCollider(std::shared_ptr<T> _obj1, std::shared_ptr<U> _obj2)
{

	float Object1_Right_Collider, Object1_Left_Collider, Object1_Top_Collider, Object1_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
	float Object2_Right_Collider, Object2_Left_Collider, Object2_Top_Collider, Object2_Bottom_Collider;//ground‚Ì“–‚½‚è”»’è•Ï”

	Object1_Right_Collider = _obj1->GetPosition().x + _obj1->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Object1_Left_Collider = _obj1->GetPosition().x - _obj1->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Object1_Top_Collider = _obj1->GetPosition().y + _obj1->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Object1_Bottom_Collider = _obj1->GetPosition().y - _obj1->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

	Object2_Right_Collider = _obj2->GetPosition().x + _obj2->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
	Object2_Left_Collider = _obj2->GetPosition().x - _obj2->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
	Object2_Top_Collider = _obj2->GetPosition().y + _obj2->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
	Object2_Bottom_Collider = _obj2->GetPosition().y - _obj2->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”

	// lŠp‚ÆlŠp‚Ì“–‚½‚è”»’è
	if (Object1_Right_Collider < Object2_Right_Collider &&
		Object2_Left_Collider < Object1_Left_Collider &&
		Object1_Bottom_Collider < Object2_Top_Collider &&
		Object1_Top_Collider > Object2_Top_Collider)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool ColliderPlayer_Ground(std::shared_ptr<Player>, std::vector<std::shared_ptr<GameObject>>);	//Player‚ÆGround‚Ì“–‚½‚è”»’èŠÖ”

/**
 * @brief ‘Î’n–Ê’n–Ê‚Ì“–‚½‚è”»’è
 * @tparam T ‰½‚©‚ÌŒ^
 * @param  ’n–Ê
*/
template <class T>
bool Collider_toGround(std::weak_ptr<T> _obj1, std::weak_ptr<GameObject> _obj2)
{
	auto obj1 = _obj1.lock();
	auto obj2 = _obj2.lock();

<<<<<<< HEAD
	if (BoxCollider(obj1, obj2))
=======
	Player_Right_Collider = obj1.lock()->GetPosition().x + obj1.lock()->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Player_Left_Collider = obj1.lock()->GetPosition().x - obj1.lock()->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Player_Top_Collider = obj1.lock()->GetPosition().y + obj1.lock()->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Player_Bottom_Collider = obj1.lock()->GetPosition().y - obj1.lock()->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

	Ground_Right_Collider = obj2.lock()->GetPosition().x + obj2.lock()->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
	Ground_Left_Collider = obj2.lock()->GetPosition().x - obj2.lock()->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
	Ground_Top_Collider = obj2.lock()->GetPosition().y + obj2.lock()->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
	Ground_Bottom_Collider = obj2.lock()->GetPosition().y - obj2.lock()->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”

	Ground_Bottom_Collider = Ground_Bottom_Collider + 150; //Ground‚Ì‰º‚Ì•”•ª‚É“–‚½‚Á‚½‚Étrue‚ğ•Ô‚³‚È‚¢‚æ‚¤‚É‚·‚éi­‚µÀ•W‚ğã‚É‚ ‚°‚Ä‚éj

	//ƒvƒŒƒCƒ„[‚ÆƒOƒ‰ƒEƒ“ƒh‚Ì“–‚½‚è”»’è
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
>>>>>>> ä¿é™ºãƒ–ãƒ©ãƒ³ãƒ
	{
		// ’n–Ê‚É“–‚½‚Á‚½ƒIƒuƒWƒFƒNƒg‚Ì‘¬“xA•ûŒüƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg‚·‚é
		obj1->SetDirection(Vector3({0.0f}));
		obj1->AddForce(Vector3({0.0f}));
		obj1->SetOnGround(true);
		return true;
	}
	else {
		obj1->SetOnGround(false);
		return false;
	}
}


/**
 * @brief ƒIƒuƒWƒFƒNƒg”z—ñ“¯m‚Ì“–‚½‚è”»’è‚ğæ“¾(‘S‚ÄlŠp)
 * @tparam T
 * @tparam U
 * @param _objects1
 * @param _objects2
 * 
 * ’†‚Å‘æˆêˆø”‚ÌƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg‚·‚é
 * 
 * @return
*/
template <class T, class U>
bool Collider_Objects_Objects(std::vector<std::shared_ptr<T>>_objects1, std::vector<std::shared_ptr<U>>_objects2)
{
	// ƒIƒuƒWƒFƒNƒg‚²‚Æ‚ÉBoxCollider‚ğ‰ñ‚·
	for (auto& obj2 : _objects2)
	{
		for (auto& obj1 : _objects1)
		{
			// “–‚½‚Á‚½ê‡
			if (BoxCollider(obj1, obj2))
			{
				// ‘æˆêˆø”‘¤‚ÌƒIƒuƒWƒFƒNƒg‚ÌƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg
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
 * @brief ƒvƒŒƒCƒ„[‚ÆƒIƒuƒWƒFƒNƒg‚Ì“–‚½‚è”»’è
 * @param _player ƒvƒŒƒCƒ„[
 * @param _objects ƒIƒuƒWƒFƒNƒg‚Ìvector
*/
bool Collider_to_Object(std::weak_ptr<Player> _player, std::weak_ptr<GameObject> _objects);

/**
 * @brief ƒvƒŒƒCƒ„[‚Æƒ}ƒKƒWƒ“‚Ì“–‚½‚è”»’è
*/
bool Collider_Player_to_Magazine(std::weak_ptr<Player> obj1, std::weak_ptr<Magazine> obj2);



bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”

// îŒ^‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// ü•ª‚Æ‰~‚ªŒğ·‚µ‚Ä‚¢‚é‚©”»’è‚·‚éŠÖ”

//void DrawFan(GameObject*, bool);
