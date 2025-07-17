#include "Poyon.h"

void Poyon::Action(Player* _player)
{
	//フラグがTRUEなら（擬音が当たっているか）
	if (Collision_Onomatope)
	{
		//playerをGameObject型→Player型に変更
		if (auto sharedPlayer = _player)
		{
			//dynamic_pointer_castを使用して派生クラスにキャスト
			auto derivedPlayer = dynamic_cast<Player*>(sharedPlayer);
			if (derivedPlayer) {//キャストに成功していたら
				//derivedPlayer->SetJump(true);
				derivedPlayer->m_Velocity.y = 25.0f; //ポヨン付与したときのジャンプ力
			}
			else {
				std::cout << "キャストに失敗しました" << std::endl;
			}
		}
		else {
			std::cout << "playerは無効です" << std::endl;
		}
	}
}

//擬音のセッター
void Poyon::Set_Onomatope(bool _flg)
{
	Collision_Onomatope = _flg;
}

//擬音のゲッター
bool Poyon::Get_Onomatope(void)
{
	return Collision_Onomatope;
}

void Poyon::Set_gion(bool _flg)
{
	Collision_gion = _flg;
}

bool Poyon::Get_gion(void)
{
	return Collision_gion;
}

Poyon::~Poyon()
{
}