#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"

class BiriBiri :public IOnomatopoeia
{
public:
	BiriBiri(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {
		knockback_power = 10;
		BiriBiri_check = false;
	}
	~BiriBiri();	//デストラクタ
	void Action(std::weak_ptr<GameObject>);		//ビリビリ特性の関数

	bool BiriBiri_check;
private:
	float knockback_power;//ノックバックパワー
};
