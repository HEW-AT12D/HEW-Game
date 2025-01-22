#pragma once
#include "../SoundGun/SoundGun.h"
#include "../SoundGun/Magazine.h"
#include "../Character/Character.h"


/**
 * @brief �v���C���[�N���X
 * 
 * ���K�v�Ȃ��́�
 * �E�ړ����x
 * �E�W�����v��
 * �E�����蔻��
 * 
 * 
 * ���̓�̓v���C���[�̃����o�Ƃ��Ď�������̂ł͂Ȃ��A�V�[�����ŃI�u�W�F�N�g�}�l�[�W������AddObject���s���A��������e�I�u�W�F�N�g�Ƃ��ăv���C���[���Z�b�g����
 * �E�[���e
 * �E�}�K�W��
 * 
 * �}�K�W�����������摜�o�����ȍ~�͋[���������Ă��Ȃ��Ă��摜��������p�ɂ���
 * 
 * �A�j���[�V�������F�L�������ƂɃX�e�[�g�i��ԁj���������Ă����A���̏�Ԃɉ������A�j���[�V�����𓮂���
 * 
 * �A�j���[�V����
 * �A�N�V�������s���̏ꍇ���t���[���X�v���C�g�؂�ւ�����
 * ���{�^�������Ă鎞�̓A�N�V������
 * 
*/
class Player :public Character
{
public:
	Player(D3D11& _D3d11) :Character(_D3d11) {
		m_Velocity = { 0.0f };
		m_MoveSpeed = 5.0f;
		m_JumpPower = 10.0f;
	};
	~Player() {};
	
	void Update(void) override;		// �v���C���[�ŗL�̓��͂͂����Ŏ擾����
	//void Draw(void) override;		// �[���g�p�ŕ`����@�ύX���������ꍇ�p�ɐ錾
	void Animation(STATE _Anim_Name);	// �v���C���[�ʂ̃A�j���[�V�����֐�

private:
	//SoundGun Soundgun;					// �[���e,Soundgun(_D3d11)
	//std::vector<Magazine> Magazines;	// �}�K�W���i�ϒ��j
};

