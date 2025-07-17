#include "Poyon.h"

void Poyon::Action(Player* _player)
{
	//�t���O��TRUE�Ȃ�i�[�����������Ă��邩�j
	if (Collision_Onomatope)
	{
		//player��GameObject�^��Player�^�ɕύX
		if (auto sharedPlayer = _player)
		{
			//dynamic_pointer_cast���g�p���Ĕh���N���X�ɃL���X�g
			auto derivedPlayer = dynamic_cast<Player*>(sharedPlayer);
			if (derivedPlayer) {//�L���X�g�ɐ������Ă�����
				//derivedPlayer->SetJump(true);
				derivedPlayer->m_Velocity.y = 25.0f; //�|�����t�^�����Ƃ��̃W�����v��
			}
			else {
				std::cout << "�L���X�g�Ɏ��s���܂���" << std::endl;
			}
		}
		else {
			std::cout << "player�͖����ł�" << std::endl;
		}
	}
}

//�[���̃Z�b�^�[
void Poyon::Set_Onomatope(bool _flg)
{
	Collision_Onomatope = _flg;
}

//�[���̃Q�b�^�[
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