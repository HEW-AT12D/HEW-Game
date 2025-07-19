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
	SoundGun(D3D11& _D3d11, Sound* _sound = nullptr) :GameObject(_D3d11, _sound) {
		IsSuction = false;
		IsShot = false;
		m_ShotPower = 25.0f;
	};
	~SoundGun() {};

	bool Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> _onomatopoeia);	// �z�����݊֐�(�z�����ދ[���̃f�[�^�A�����߂�l�œn���A�}�K�W���ɓ��ꍞ��)
	void Shot(Magazine* _mag);		// ���ˊ֐�(�I�������}�K�W�����̋[���𔭎˂���)

	void SetIsSuction(bool _flg);
	bool GetIsSuction(void);
	void Update(void) override;
	void Draw(void)override;

private:
	Magazine* m_pMagazine;	// ���ݎg�p���̃}�K�W��
	bool IsSuction;			// �z�����ݒ����H
	bool IsShot;			// ���˂������H
	float m_ShotPower;		// �ˌ���
};

