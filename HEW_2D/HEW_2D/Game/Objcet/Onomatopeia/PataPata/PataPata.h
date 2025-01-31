#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"


class Player;

/**
 * @brief �p�^�p�^(�H�΂���)
 * 
 * TODO:2025/01/25 �ԍ� ����[����Action�֐��̈����ɋ[���̉e�����󂯂�I�u�W�F�N�g�̃|�C���^��n���Ă�̂ŁA�����Ȃ��Ŏ��s�ł���悤�ɂ���
 * �����ڕt�^����Ă���I�u�W�F�N�g�݂̂Ŋ����ł���悤�ɂ���
 * 
 * ���t�^���ꂽ�I�u�W�F�N�g�̓�����
 * �E�ړ����x�̕��������t���[���ړ�����
 * �E�t�^���ꂽ�I�u�W�F�N�g�͖��t���[���ӂ���ƕ����オ���(�v���C���[�ɕt�^�����ꍇ�A�W�����v�{�^���������Ă���Ԃ͕����オ�葱����A�Ȃ�)
 * �����t���[���ق�̏�������������ɗ͂������遨�I�u�W�F�N�g�͈ړ����Ȃ��̂ŉ������̕����x�N�g�����������邱�Ƃ͂Ȃ��A�΂߂Ɉړ����邱�Ƃ͂Ȃ�
 * 
*/
class PataPata :public IOnomatopoeia
{
public:
	PataPata(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {
		Max_altitude = 300.0f;		// ���E���x���ݒ�(Y:+400)
		Collider_check = false;
	}
	~PataPata();	//�f�X�g���N�^
	void Update(void) override;
	void Action(void) override;		// �t�^���ꂽ�I�u�W�F�N�g�Ɍ��ʂ�^����
	void Action(std::weak_ptr<GameObject>, std::weak_ptr<Player>);	//�I�[�o�[���[�h
	void Set_Onomatope(bool)override; //�[����Action�֐��𓮂������߂̃Q�b�^�[�A�Z�b�^�[
	bool Get_Onomatope(void)override;
	void Set_gion(bool)override;
	bool Get_gion(void)override;

private:
	bool Collider_check;
	float Max_altitude;		//���E���x
};
