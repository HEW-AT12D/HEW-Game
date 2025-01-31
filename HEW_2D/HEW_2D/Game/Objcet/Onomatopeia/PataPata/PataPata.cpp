#include "PataPata.h"
#include "../../../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Player/Player.h"


/**
 * @brief �X�V
 * 
 * �I�u�W�F�N�g�������̓v���C���[�ɕt�^����Ă��鎞�̂݁A���t���[����������ɕ����オ��A�I�u�W�F�N�g�ɕt�^����Ă���Ƃ��͏��������オ�����㉺�~����A���J���
*/
void PataPata::Update(void)
{
	// ���̋[���̐e�I�u�W�F�N�g��
	if (true)
	{

	}
}


void PataPata::Action(void)
{
	
}


void PataPata::Action(std::weak_ptr<GameObject> obj, std::weak_ptr<Player> player)
{
	Vector3 patapata_pos = obj.lock()->GetPosition();
	Vector3 player_pos = player.lock()->GetPosition();
	auto patapataShared = obj;
	auto playerShared = player;

	//�t���O��TRUE�Ȃ�i�[�����������Ă��邩�j
	if (Collision_Onomatope)
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


//�[���̃Z�b�^�[
void PataPata::Set_Onomatope(bool _flg)
{
	Collision_Onomatope = _flg;
}

//�[���̃Q�b�^�[
bool PataPata::Get_Onomatope(void)
{
	return Collision_Onomatope;
}

void PataPata::Set_gion(bool _flg)
{
	Collision_gion = _flg;
}

bool PataPata::Get_gion(void)
{
	return Collision_gion;
}


PataPata::~PataPata()
{

}