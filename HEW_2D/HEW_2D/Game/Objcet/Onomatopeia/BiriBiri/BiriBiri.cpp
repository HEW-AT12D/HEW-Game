#include "BiriBiri.h"
#include "../../Player/Player.h"

void BiriBiri::Action(Player* player)
{
	Vector3 player_pos = player->GetPosition();
	Vector3 player_rotation = player->GetRotation();
	//playerをGameObject型→Player型に変更
	if (Collision_Onomatope) //フラグがTRUEなら（擬音が当たっているか）
	{
		if (auto sharedPlayer = player)
		{
			//dynamic_pointer_castを使用して派生クラスにキャスト
			auto derivedPlayer = dynamic_cast<Player*>(sharedPlayer);
			if (derivedPlayer) {//キャストに成功していたら
				player_rotation.z = 50;
				player->SetRotation(player_rotation);
				player_pos.x -= knockback_power;
				player->SetPosition(player_pos);
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
		player->SetRotation(player_rotation);
	}
}


//擬音のセッター
void BiriBiri::Set_Onomatope(bool _flg)
{
	Collision_Onomatope = _flg;
}

//擬音のゲッター
bool BiriBiri::Get_Onomatope(void)
{
	return Collision_Onomatope;
}

void BiriBiri::Set_gion(bool _flg)
{
	Collision_gion = _flg;
}

bool BiriBiri::Get_gion(void)
{
	return Collision_gion;
}

BiriBiri::~BiriBiri(){}