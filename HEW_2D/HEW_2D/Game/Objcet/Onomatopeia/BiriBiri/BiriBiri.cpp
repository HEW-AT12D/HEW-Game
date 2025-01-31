#include "BiriBiri.h"
#include "../../Player/Player.h"

void BiriBiri::Action(std::weak_ptr<GameObject> player)
{
	Vector3 player_pos = player.lock()->GetPosition();
	Vector3 player_rotation = player.lock()->GetRotation();
	//player��GameObject�^��Player�^�ɕύX
	if (Collision_Onomatope) //�t���O��TRUE�Ȃ�i�[�����������Ă��邩�j
	{
		if (auto sharedPlayer = player.lock())
		{
			//dynamic_pointer_cast���g�p���Ĕh���N���X�ɃL���X�g
			auto derivedPlayer = std::dynamic_pointer_cast<Player>(sharedPlayer);
			if (derivedPlayer) {//�L���X�g�ɐ������Ă�����
				player_rotation.z = 50;
				player.lock()->SetRotation(player_rotation);
				player_pos.x -= knockback_power;
				player.lock()->SetPosition(player_pos);
				BiriBiri_check = false;

			}
			else {
				std::cout << "�L���X�g�Ɏ��s���܂���" << std::endl;
			}
		}
		else {
			std::cout << "player�͖����ł�" << std::endl;
		}
	}
	else {
		player_rotation.z = 0;
		player.lock()->SetRotation(player_rotation);
	}
}


//�[���̃Z�b�^�[
void BiriBiri::Set_Onomatope(bool _flg)
{
	Collision_Onomatope = _flg;
}

//�[���̃Q�b�^�[
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