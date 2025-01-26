#include "Poyon.h"

void Poyon::Action(void)
{
	//playerをGameObject型→Player型に変更
	if (auto sharedPlayer = m_pParent.lock())
	{
		//dynamic_pointer_castを使用して派生クラスにキャスト
		auto derivedPlayer = std::dynamic_pointer_cast<Player>(sharedPlayer);
		if (derivedPlayer) {//キャストに成功していたら
			derivedPlayer->SetJump(true);
		}
		else {
			std::cout << "キャストに失敗しました" << std::endl;
		}
	}
	else {
		std::cout << "playerは無効です" << std::endl;
	}
}


Poyon::~Poyon()
{
}