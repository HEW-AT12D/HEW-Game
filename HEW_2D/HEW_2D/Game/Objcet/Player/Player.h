#pragma once
#include "../SoundGun/SoundGun.h"
#include "../SoundGun/Magazine.h"


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
*/
class Player :public GameObject
{
public:
	Player(D3D11& _D3d11) :GameObject(_D3d11) {};
	~Player() {};
	
	void Update(void) override;		// �v���C���[�ŗL�̓��͂͂����Ŏ擾����
	void Draw(void);				// �[���g�p�ŕ`����@�ύX���������ꍇ�悤�ɐ錾
	void Animation(STATE,Vector2) override;	// �v���C���[�ʂ̃A�j���[�V�����֐�

private:
	//SoundGun Soundgun;					// �[���e,Soundgun(_D3d11)
	//std::vector<Magazine> Magazines;	// �}�K�W���i�ϒ��j
};

