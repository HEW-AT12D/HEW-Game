#include "BiriBiri.h"
#include "../../Player/Player.h"

void BiriBiri::Action(std::weak_ptr<GameObject> player)
{
	Vector3 player_pos = player.lock()->GetPosition();
	Vector3 player_rotation = player.lock()->GetRotation();
	//playerをGameObject型→Player型に変更
	if (BiriBiri_check)
	{
		if (auto sharedPlayer = player.lock())
		{
			//dynamic_pointer_castを使用して派生クラスにキャスト
			auto derivedPlayer = std::dynamic_pointer_cast<Player>(sharedPlayer);
			if (derivedPlayer) {//キャストに成功していたら
				player_rotation.z = 50;
				player.lock()->SetRotation(player_rotation);
				player_pos.x -= knockback_power;
				player.lock()->SetPosition(player_pos);
				BiriBiri_check = false;

			}
			else {
				std::cout << "キャストに失敗しました" << std::endl;
			}
		}
		else {
			std::cout << "playerは無効です" << std::endl;
		}
	}
	else {
		player_rotation.z = 0;
		player.lock()->SetRotation(player_rotation);
	}
}

BiriBiri::~BiriBiri(){}