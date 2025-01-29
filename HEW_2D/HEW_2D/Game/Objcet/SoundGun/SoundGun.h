#pragma once
#include "../BaseObject/GameObject.h"


class Magazine;

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
	SoundGun(D3D11& _D3d11) :GameObject(_D3d11) {
		IsSuction = false;
		IsShot = false;
		m_ShotPower = 25.0f;
	};
	~SoundGun() {};

	// TODO:2025/01/27 �z�����݊֐���肫�遨�O���ł���Ă邩��ǂ����邩�����߂�A�[���e���z�����ݒ��̎������摜�ƃA�j���[�V��������
	// W��������G���[�f���̂𒼂�
	bool Suction(std::weak_ptr<GameObject> _gion);	// �z�����݊֐�(�z�����ދ[���̃f�[�^�A�����߂�l�œn���A�}�K�W���ɓ��ꍞ��)
	void Shot(std::shared_ptr<Magazine> _mag);		// ���ˊ֐�(�I�������}�K�W�����̋[���𔭎˂���)

	void SetIsSuction(bool _flg);
	bool GetIsSuction(void);
	void Update(void) override;
	void Draw(void)override;

private:
	bool IsSuction;			// �z�����ݒ����H
	bool IsShot;			// ���˂������H
	float m_ShotPower;		// �ˌ���
};

