#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"


/**
 * @brief �p�^�p�^(�H�΂���)
 * 
 * TODO:2025/01/25 �ԍ� ����[����Action�֐��̈����ɋ[���̉e�����󂯂�I�u�W�F�N�g�̃|�C���^��n���Ă�̂ŁA�����Ȃ��Ŏ��s�ł���悤�ɂ���
 * �����ڕt�^����Ă���I�u�W�F�N�g�݂̂Ŋ����ł���悤�ɂ���
*/
class PataPata :public IOnomatopoeia
{
public:
	PataPata(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {
		Max_altitude = 300.0f;		// ���E���x���ݒ�(Y:+400)
		Collider_check = false;
	}
	~PataPata();	//�f�X�g���N�^
	void Action(void) override;		// �t�^���ꂽ�I�u�W�F�N�g�Ɍ��ʂ�^����
	void Action(std::weak_ptr<GameObject>, std::weak_ptr<Player>);	//�I�[�o�[���[�h

private:
	bool Collider_check;
	float Max_altitude;		//���E���x
};
