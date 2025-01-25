#include "PataPata.h"
#include "../../../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Player/Player.h"


void PataPata::Action(void)
{
	
}


void PataPata::Action(std::weak_ptr<GameObject> obj, std::weak_ptr<Player> player)
{
	Vector3 patapata_pos = obj.lock()->GetPosition();
	Vector3 player_pos = player.lock()->GetPosition();
	auto patapataShared = obj;
	auto playerShared = player;
	if (Collider_check)
	{
		if (patapata_pos.y <= Max_altitude)
		{
			if (Collider_toGround(obj, player))
			{
				player_pos.y += 5;
				player.lock()->SetPosition(player_pos);
			}
			patapata_pos.y += 5;
			
			obj.lock()->SetPosition(patapata_pos);
			
		}
		else {
			Collider_check = false;
		}
	}

}


PataPata::~PataPata()
{

}