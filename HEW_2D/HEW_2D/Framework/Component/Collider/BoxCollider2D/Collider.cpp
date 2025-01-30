#include "Collider.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
/// EŠî–{lŠp‚Å“–‚½‚è”»’è‚ğæ‚é¨“–‚½‚Á‚½‚à‚Ì‚ª‰½‚©‚ğ“Á’è‚³‚¦‚Å‚«‚ê‚ÎƒIƒuƒWƒFƒNƒgƒ}ƒl[ƒWƒƒ‚Å‘¤‚©‚ç‚¢‚¶‚ê‚é
/// EƒIƒuƒWƒFƒNƒg‚ª’n–Ê‚É“–‚½‚Á‚½‚©‚ÌŠÖ”‚à•K—v¨¡‚ÍŒÂ•Ê‚Å‰ñ‚µ‚Ä‚é‚Ì‚ÅƒIƒuƒWƒFƒNƒgƒ}ƒl[ƒWƒƒ‚Å‰ñ‚µ‚½‚¢
/// 
/// 
/// ƒƒ‚FBoxCollider‚É‚µ‚½ê‡¨“–‚½‚è”»’è‚ğæ‚èI‚í‚Á‚½ƒIƒuƒWƒFƒNƒg‚Í”»’èƒ`ƒFƒbƒN‚©‚çŠO‚·‚Æ‚¢‚¢‚©‚à
///////////////////////////////////////////////////////////////////////////////////////////////////


//Player‚ÆGround‚Ì“–‚½‚è”»’è(”z—ñ)
//template <class T, class U>
bool ColliderPlayer_Ground(std::shared_ptr<Player> _player, std::vector<std::shared_ptr<GameObject>> _objects)
{
<<<<<<< HEAD
	// ’n–Ê‚Ì”z—ñ‚Ì—v‘f”•ªƒ‹[ƒv
	for (auto& ground : _objects) {
		if (BoxCollider(_player, ground))
		{
			// “–‚½‚Á‚½ƒIƒuƒWƒFƒNƒg‚Ì‘¬“xA•ûŒüƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg‚·‚é
			_player->SetDirection(Vector3({ 0.0f }));
			_player->AddForce(Vector3({ 0.0f }));
			_player->SetOnGround(true);
			return true;
		}
		else
		{
			_player->SetOnGround(false);
			return false;
		}
	}	
=======
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground‚Ì“–‚½‚è”»’è•Ï”
	
	Player_Right_Collider = obj1.lock()->GetPosition().x + obj1.lock()->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Player_Left_Collider = obj1.lock()->GetPosition().x - obj1.lock()->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Player_Top_Collider = obj1.lock()->GetPosition().y + obj1.lock()->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Player_Bottom_Collider = obj1.lock()->GetPosition().y - obj1.lock()->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

  	Ground_Right_Collider = obj2.lock()->GetPosition().x + obj2.lock()->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
	Ground_Left_Collider = obj2.lock()->GetPosition().x - obj2.lock()->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
	Ground_Top_Collider = obj2.lock()->GetPosition().y + obj2.lock()->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
	Ground_Bottom_Collider = obj2.lock()->GetPosition().y - obj2.lock()->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”

	//ƒvƒŒƒCƒ„[‚ÆƒOƒ‰ƒEƒ“ƒh‚Ì“–‚½‚è”»’è
	if (Player_Left_Collider < Ground_Right_Collider && 
		Ground_Left_Collider < Player_Right_Collider && 
		Player_Bottom_Collider < Ground_Top_Collider && 
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		// “–‚½‚Á‚½ƒIƒuƒWƒFƒNƒg‚Ì‘¬“xA•ûŒüƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg‚·‚é
		obj1.lock()->SetDirection(Vector3({ 0.0f }));
		obj1.lock()->AddForce(Vector3({ 0.0f }));
		obj1.lock()->SetOnGround(true);
		return true;
	}
	else {
		obj1.lock()->SetOnGround(false);
		return false;
	}
>>>>>>> ä¿é™ºãƒ–ãƒ©ãƒ³ãƒ
}


/**
 * @brief ƒvƒŒƒCƒ„[‚Æƒ}ƒKƒWƒ“
 * 
 * ¡‚Í‚±‚Á‚¿g‚í‚È‚¢
*/
bool Collider_Player_to_Magazine(std::weak_ptr<Player> obj1, std::weak_ptr<Magazine> obj2)
{
	// ---------------------‚±‚±g‚¢‚Ü‚í‚¹‚é‚ÈHHHHHHHHHHHHHHHH
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground‚Ì“–‚½‚è”»’è•Ï”

	Player_Right_Collider = obj1.lock()->GetPosition().x + obj1.lock()->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Player_Left_Collider = obj1.lock()->GetPosition().x - obj1.lock()->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Player_Top_Collider = obj1.lock()->GetPosition().y + obj1.lock()->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Player_Bottom_Collider = obj1.lock()->GetPosition().y - obj1.lock()->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

	Ground_Right_Collider = obj2.lock()->GetPosition().x + obj2.lock()->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
	Ground_Left_Collider = obj2.lock()->GetPosition().x - obj2.lock()->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
	Ground_Top_Collider = obj2.lock()->GetPosition().y + obj2.lock()->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
	Ground_Bottom_Collider = obj2.lock()->GetPosition().y - obj2.lock()->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”

	//ƒvƒŒƒCƒ„[‚Æƒ}ƒKƒWƒ“‚Ì“–‚½‚è”»’è
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		return true;
	}
	else {
		return false;
	}
}



/**
 * @brief ƒvƒŒƒCƒ„[‚ÆƒIƒuƒWƒFƒNƒg‚Ì“–‚½‚è”»’è
 * @return Œ‹‰Ê
*/
bool Collider_to_Object(std::weak_ptr<Player> _player, std::weak_ptr<GameObject> _object) {
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground‚Ì“–‚½‚è”»’è•Ï”

	Player_Right_Collider = _player.lock()->GetPosition().x + _player.lock()->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Player_Left_Collider = _player.lock()->GetPosition().x - _player.lock()->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Player_Top_Collider = _player.lock()->GetPosition().y + _player.lock()->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Player_Bottom_Collider = _player.lock()->GetPosition().y - _player.lock()->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

	Ground_Right_Collider = _object.lock()->GetPosition().x + _object.lock()->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
	Ground_Left_Collider = _object.lock()->GetPosition().x - _object.lock()->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
	Ground_Top_Collider = _object.lock()->GetPosition().y + _object.lock()->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
	Ground_Bottom_Collider = _object.lock()->GetPosition().y - _object.lock()->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”

	//ƒvƒŒƒCƒ„[‚ÆƒIƒuƒWƒFƒNƒg‚Ì“–‚½‚è”»’è
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		return true;
	}
	else {
		return false;
	}

}





/**
 * @brief ƒvƒŒƒCƒ„[‚ÆƒIƒuƒWƒFƒNƒg
*/
//void Collider_Player_to_Object(std::weak_ptr<Player> _player, std::vector<std::weak_ptr<GameObject>> _objects) {
//	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
//	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground‚Ì“–‚½‚è”»’è•Ï”
//
//	Player_Right_Collider = _player.lock()->GetPosition().x + _player.lock()->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
//	Player_Left_Collider = _player.lock()->GetPosition().x - _player.lock()->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
//	Player_Top_Collider = _player.lock()->GetPosition().y + _player.lock()->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
//	Player_Bottom_Collider = _player.lock()->GetPosition().y - _player.lock()->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”
//
//	// vector‚ÌƒTƒCƒY•ªƒ‹[ƒv
//	for (auto& obj : _objects) {
//		Ground_Right_Collider = obj.lock()->GetPosition().x + obj.lock()->GetScale().x / 2; //ƒOƒ‰ƒEƒ“ƒh‚Ì‰E‚Ì“–‚½‚è”»’è•Ï”
//		Ground_Left_Collider = obj.lock()->GetPosition().x - obj.lock()->GetScale().x / 2;  //ƒOƒ‰ƒEƒ“ƒh‚Ì¶‚Ì“–‚½‚è”»’è•Ï”
//		Ground_Top_Collider = obj.lock()->GetPosition().y + obj.lock()->GetScale().y / 2;    //ƒOƒ‰ƒEƒ“ƒh‚Ìã‚Ì“–‚½‚è”»’è•Ï”
//		Ground_Bottom_Collider = obj.lock()->GetPosition().y - obj.lock()->GetScale().y / 2;//ƒOƒ‰ƒEƒ“ƒh‚Ì‰º‚Ì“–‚½‚è”»’è•Ï”
//
//		//ƒvƒŒƒCƒ„[‚ÆƒIƒuƒWƒFƒNƒg‚Ì“–‚½‚è”»’è
//		if (Player_Left_Collider < Ground_Right_Collider &&
//			Ground_Left_Collider < Player_Right_Collider &&
//			Player_Bottom_Collider < Ground_Top_Collider &&
//			Player_Top_Collider > Ground_Bottom_Collider)
//		{
//			// “–‚½‚Á‚½ƒIƒuƒWƒFƒNƒg‚ª’n–Ê‚Å‚ ‚ê‚Î‚Ì‘¬“xA•ûŒüƒxƒNƒgƒ‹‚ğƒŠƒZƒbƒg‚·‚é
//			_player.lock()->SetDirection(Vector3({ 0.0f }));
//			_player.lock()->AddForce(Vector3({ 0.0f }));
//			_player.lock()->SetOnGround(true);
//		}
//		else {
//			_player.lock()->SetOnGround(false);
//		}
//	}
//	
//}





//Player‚ÆGion‚Ì“–‚½‚è”»’è
bool ColliderPlayer_Gion(GameObject* player, GameObject* gion)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Up_Collider, Player_Bottom_Collider;//player‚Ì“–‚½‚è”»’è•Ï”
	float Gion_Right_Collider, Gion_Left_Collider, Gion_Up_Collider, Gion_Bottom_Collider;        //gion‚Ì“–‚½‚è”»’è•Ï”

	Player_Right_Collider = player->GetPosition().x + player->GetScale().x / 2; //ƒvƒŒƒCƒ„[‚Ì‰E“–‚½‚è”»’è•Ï”
	Player_Left_Collider = player->GetPosition().x - player->GetScale().x / 2;  //ƒvƒŒƒCƒ„[‚Ì¶“–‚½‚è”»’è•Ï”
	Player_Up_Collider = player->GetPosition().y + player->GetScale().y / 2;    //ƒvƒŒƒCƒ„[‚Ìã“–‚½‚è”»’è•Ï”
	Player_Bottom_Collider = player->GetPosition().y - player->GetScale().y / 2;//ƒvƒŒƒCƒ„[‚Ì‰º“–‚½‚è”»’è•Ï”

	Gion_Right_Collider = gion->GetPosition().x + gion->GetScale().x / 2;   //‹[‰¹‚Ì‰E“–‚½‚è”»’è
	Gion_Left_Collider = gion->GetPosition().x - gion->GetScale().x / 2;    //‹[‰¹‚Ì¶“–‚½‚è”»’è
	Gion_Up_Collider = gion->GetPosition().y + gion->GetScale().y / 2;      //‹[‰¹‚Ìã“–‚½‚è”»’è
	Gion_Bottom_Collider = gion->GetPosition().y - gion->GetScale().y / 2;	//‹[‰¹‚Ì‰º“–‚½‚è”»’è

	//Player‚Æ‹[‰¹‚Ì“–‚½‚è”»’è
	if (1.0f > Player_Left_Collider - Gion_Right_Collider && 1.0f > Gion_Left_Collider - Player_Right_Collider && 0.5f > Player_Bottom_Collider - Gion_Up_Collider)
	{
		std::cout << "Player‚Æ‹[‰¹‚ªÕ“Ë‚µ‚Ü‚µ‚½" << std::endl;
		return true;
	}
	else {
		return false;
	}
}


//îŒ^‚Æ‹[‰¹‚Ì“–‚½‚è”»’è

/**
 * @brief ƒvƒŒƒCƒ„[‚Æ‹[‰¹‚Ì“–‚½‚è”»’è
 * @param fan ƒvƒŒƒCƒ„[(‚»‚±‚©‚çîŒ^‚É”ÍˆÍ‚ğİ’è)
 * @param gion ‹[‰¹(vector‚Å‘S•”“n‚·)
 * @return “–‚½‚Á‚½‹[‰¹
*/
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>> _onomatopoeias)
{
	float PI = 3.14159265;
	float fanAngle = PI / 6;
	//îŒ^‚Ìî•ñæ“¾
	float fanCenterX = fan.lock()->GetPosition().x + 200.0f;	//îŒ^‚Ì’†SXÀ•W
	float fanCenterY = fan.lock()->GetPosition().y;   //îŒ^‚Ì’†SYÀ•W
	float fanRadius = fan.lock()->GetScale().x / 2;   //îŒ^‚Ì”¼ŒaiƒXƒP[ƒ‹‚ÌX•ûŒü‚ğg—pj

	//îŒ^‚Ì•ûŒüƒxƒNƒgƒ‹‚ğ‰E•ûŒü‚ÉŒÅ’è
	float fanDirX = 1.0f;//‰E•ûŒü‚Ì¬•ª
	float fanDirY = 0.0f;//ã•ûŒü‚Ì¬•ª
	
	//‹[‰¹‚Ìî•ñæ“¾
	float Gion_Right_Collider;		// ‹[‰¹‚Ì‰E’[
	float Gion_Left_Collider;		// ‹[‰¹‚Ì¶’[
	float Gion_Up_Collider;			// ‹[‰¹‚Ìã’[
	float Gion_Bottom_Collider;		// ‹[‰¹‚Ì‰º’[
	
	// ‹[‰¹‚Æ‚Ì“–‚½‚è”»’è‚ğæ“¾
	for (auto& onomat : _onomatopoeias) {
		// ‹[‰¹‚Ì“–‚½‚è”»’è”ÍˆÍ‚ğæ“¾
		Gion_Right_Collider = onomat.second->GetPosition().x + onomat.second->GetScale().x / 2; //‹[‰¹‚Ì‰E’[
		Gion_Left_Collider = onomat.second->GetPosition().x - onomat.second->GetScale().x / 2;  //‹[‰¹‚Ì¶’[
		Gion_Up_Collider = onomat.second->GetPosition().y + onomat.second->GetScale().y / 2;    //‹[‰¹‚Ìã’[
		Gion_Bottom_Collider = onomat.second->GetPosition().y - onomat.second->GetScale().y / 2;//‹[‰¹‚Ì

		//------------îŒ`‚Æ‹[‰¹‚Ìl‚Â‚Ì’¸“_------------
		float vertices[4][2] = {
			{Gion_Left_Collider,Gion_Up_Collider},//¶ã
			{Gion_Right_Collider,Gion_Up_Collider},//‰Eã
			{Gion_Left_Collider,Gion_Bottom_Collider},//¶‰º
			{Gion_Right_Collider,Gion_Bottom_Collider},//‰E‰º
		};

		//lŠpŒ`‚ÌŠe’¸“_‚ªîŒ`“à‚ÉŠÜ‚Ü‚ê‚é‚©Šm”F
		for (int i = 0; i < 4; ++i) {
			float dx = vertices[i][0] - fanCenterX;   //îŒ^’†S‚©‚ç’¸“_‚Ö‚ÌƒxƒNƒgƒ‹X
			float dy = vertices[i][1] - fanCenterY;   //îŒ^’†S‚©‚ç’¸“_‚Ö‚ÌƒxƒNƒgƒ‹Y
			float distance = sqrtf(dx * dx + dy * dy);//‹——£‚ğŒvZ

			//‹——£‚ª”¼Œa“à‚©Šm”F
			if (distance <= fanRadius) {
				//ƒxƒNƒgƒ‹‚ÌŠp“x‚ÌŒvZi“àÏj
				float dot = (dx * fanDirX + dy * fanDirY) / (distance);//cosƒÆ=“àÏ/(|v1|*|v2|)

				//Šp“x‚ª”ÍˆÍ“à‚©Šm”F
				float cosLimit = cosf(fanAngle);//îŒ^‚ÌŠp“x”ÍˆÍ‚Ìcos’l
				if (dot >= cosLimit) {
					std::cout << "’¸“_‚ªîŒ^“à‚Å‚·" << std::endl;
					// ‹[‰¹‚Ì’¸“_‚ªîŒ^“à‚È‚Ì‚Å‚»‚Ì‹[‰¹‚ğ•Ô‚·
					return onomat;
				}
			}
		}

		//---------------îŒ`‚ÆlŠpŒ`‚Ì•Ó‚ªîŒ^‚Ì‰~ŒÊ‚ÆŒğ·‚µ‚Ä‚¢‚é‚©Šm”F------------------
		float edges[4][4] = {
			{Gion_Left_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Up_Collider},        //ã•Ó
			{Gion_Right_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Bottom_Collider},   //‰E•Ó
			{Gion_Left_Collider,Gion_Bottom_Collider,Gion_Right_Collider,Gion_Bottom_Collider},//‰º•Ó
			{Gion_Left_Collider,Gion_Up_Collider,Gion_Left_Collider,Gion_Bottom_Collider}      //¶•Ó
		};
		for (int i = 0; i < 4; ++i) {
			if (LineIntersectsCircle(edges[i][0], edges[i][1], edges[i][2], edges[i][3], fanCenterX, fanCenterY, fanRadius)) {
				std::cout << "lŠpŒ`‚Ì•Ó‚ªîŒ^‚Ì‰~ŒÊ‚ÆŒğ·‚µ‚Ä‚¢‚Ü‚·" << std::endl;
				// lŠpŒ`‚Ì•Ó‚ªîŒ^‚Ì‰~ŒÊ‚ÆŒğ·
				return onomat;
			}
		}
		// îŒ^‚Ì’†S‚ªlŠpŒ`“à‚É‚ ‚é‚©Šm”F
		if (fanCenterX >= Gion_Left_Collider && fanCenterX <= Gion_Right_Collider &&
			fanCenterY >= Gion_Bottom_Collider && fanCenterY <= Gion_Up_Collider) {
			// îŒ^‚Ì’†S‚ªlŠpŒ`“à
			return onomat;
		}
	}
	//‚Ç‚ê‚É‚àŠY“–‚µ‚È‚¢ê‡A“–‚½‚Á‚Ä‚¢‚È‚¢‚Ì‚Å‰½‚à•Ô‚³‚È‚¢
	return {};
}

// ü•ª‚Æ‰~‚ªŒğ·‚µ‚Ä‚¢‚é‚©”»’è‚·‚éŠÖ”
bool LineIntersectsCircle(float x1, float y1, float x2, float y2, float cx, float cy, float radius)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float fx = x1 - cx;
	float fy = y1 - cy;

	float a = dx * dx + dy * dy;
	float b = 2 * (fx * dx + fy * dy);
	float c = (fx * fx + fy * fy) - radius * radius;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		return false;//Œğ·‚µ‚Ä‚¢‚È‚¢
	}
	else {
		discriminant = sqrtf(discriminant);
		float t1 = (-b - discriminant) / (2 * a);
		float t2 = (-b + discriminant) / (2 * a);

		return (t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1);
	}
}


// “–‚½‚è”»’è’…F—p
//void DrawFan(GameObject* fan, bool isColliding)
//{
//	//îŒ^‚Ìî•ñæ“¾
//	float centerX = fan->GetPosition().x;
//	float centerY = fan->GetPosition().y;
//	float radius = fan->GetScale().x / 2;
//	float M_PI = 3.14159265;
//	float fanAngle = M_PI / 6;//ŠJ‚«Šp“xi30“xj
//	float dirX = cosf(fan->GetRotation().z);
//	float dirY = sinf(fan->GetRotation().z);

//	//F”»’è
//	float r, g, b;
//	if (isColliding) {
//		r = 1.0f; g = 0.0f; b = 0.0f;//Ô
//	}
//	else {
//		r = 0.0f, g = 1.0f, b = 0.0f;//—Î
//	}
//}


