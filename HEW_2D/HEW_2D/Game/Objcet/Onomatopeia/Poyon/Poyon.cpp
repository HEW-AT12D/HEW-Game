#include "Poyon.h"

void Poyon::Action(std::weak_ptr<GameObject> player)
{
	//playerをGameObject型→Player型に変更
	if (auto sharedPlayer = player.lock())
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