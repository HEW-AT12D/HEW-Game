#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"
#include "../../Player/Player.h"



/**
 * @brief �|�����i��ђ��˂�j
 *
 * �t�^���ꂽ�I�u�W�F�N�g�̒e�͂����߂�
 * ��velocity�����߂�
 * �@�����������璵�˕Ԃ�
 * 
 * 
 * �t�^���ꂽ�I�u�W�F�N�g�ɓ����������̂�e���Ԃ�
 * ���ǂ��ɓ������Ă邩�𔻒肵�āA���������I�u�W�F�N�g�ɂ��̌����̗͂�������
*/
class Poyon : public IOnomatopoeia
{
public:

	Poyon(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {

	}

	~Poyon();
	void Action(void) {};
	void Action(std::weak_ptr<Player>);
	void Set_Onomatope(bool)override;//�[����Action�֐��𓮂������߂̃Q�b�^�[�A�Z�b�^�[
	bool Get_Onomatope(void)override;
	void Set_gion(bool)override;
	bool Get_gion(void)override;
private:

};


