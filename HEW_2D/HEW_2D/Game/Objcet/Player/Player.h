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
 * �E�[���e
 * �E�}�K�W��
 * 
 * �A�j���[�V�������F�L�������ƂɃX�e�[�g�i��ԁj���������Ă����A���̏�Ԃɉ������A�j���[�V�����𓮂���
 * 
*/
class Player :public GameObject
{
public:
	Player(D3D11& _D3d11) :GameObject(_D3d11),Soundgun(_D3d11) {};
	~Player() {};
	
	void Update(void) override;		// �v���C���[�ŗL�̓��͂͂����Ŏ擾����
	//void Draw(void);				// �[���g�p�ŕ`����@�ύX���������ꍇ�悤�ɐ錾
	void Animation(STATE,Vector2) override;	// �v���C���[�ʂ̃A�j���[�V�����֐�

private:
	SoundGun Soundgun;					// �[���e
	std::vector<Magazine> Magazines;	// �}�K�W���i�ϒ��j
};

