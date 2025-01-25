#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"

class BiriBiri :public IOnomatopoeia
{
public:
	BiriBiri(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {
		knockback_power = 10;
		BiriBiri_check = false;
	}
	~BiriBiri();	//�f�X�g���N�^
	void Action(std::weak_ptr<GameObject>);		//�r���r�������̊֐�

	bool BiriBiri_check;
private:
	float knockback_power;//�m�b�N�o�b�N�p���[
};
