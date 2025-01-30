#include "Poyon.h"

void Poyon::Action(void)
{
	//�t���O��TRUE�Ȃ�i�[�����������Ă��邩�j
	if (Collision_Onomatope)
	{
		//player��GameObject�^��Player�^�ɕύX
		if (auto sharedPlayer = m_pParent.lock())
		{
			//dynamic_pointer_cast���g�p���Ĕh���N���X�ɃL���X�g
			auto derivedPlayer = std::dynamic_pointer_cast<Player>(sharedPlayer);
			if (derivedPlayer) {//�L���X�g�ɐ������Ă�����
				derivedPlayer->SetJump(true);
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


Poyon::~Poyon()
{
}