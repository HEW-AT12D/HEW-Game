#pragma once
#include "../BaseObject/GameObject.h"


/**
 * @brief �v���C���[�����[���e�N���X
 * 
 * �E�@�\�Ƃ��Ă͋z�����݁A�g�p�̓��
 * �@���g�p����ꍇ�A�g�p�悪���܂��Ă���Ȃ�u�[���̔\�͂�t�^�v���Ȃ���΂Ȃ�Ȃ�
 * 
 * �E�g�p��̌���������̋@�\�Ƃ��Ď���
 * 
 * �E�X�e�[�W���Ń}�K�W���������\��Ȃ̂�vector�Ń}�K�W������������
 * 
 * ���K�v�Ȃ��́�
*/
class SoundGun : public GameObject
{
public:
	SoundGun(D3D11& _D3d11) :GameObject(_D3d11) {};
	~SoundGun() {};

	void Suction(Vector3, Vector3);//�z�����݊֐�


private:

};

