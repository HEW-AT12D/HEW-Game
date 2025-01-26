#include "Poyon.h"

void Poyon::Action(void)
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


Poyon::~Poyon()
{
}