#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"
#include "../../Player/Player.h"



/**
 * @brief �|�����i��ђ��˂�j
 *
 * �t�^���ꂽ�I�u�W�F�N�g�̒e�͂����߂�
 * ��velocity�����߂�
 * �@�����������璵�˕Ԃ�
*/



class Poyon : public IOnomatopoeia
{
public:
	Poyon(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {

	}
	~Poyon();
	void Action(std::weak_ptr<GameObject>) override;
private:

};


