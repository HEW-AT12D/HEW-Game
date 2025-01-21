#pragma once
#include "../Onomatopeia/IOnomatopoeia/IOnomatopoeia.h"

/**
 * @brief �[���e�Ɏg���}�K�W���N���X
 * ��������R���e�i�̔z��ɂ��ăv���C���[�̃����o�Ƃ��ĕێ�����
 * 
 * �Z�����o�ϐ�
 * �@�E�e�ɑ��U����Ă��邩�H
 * �@�E�}�K�W���������󂩂ǂ����H
 * 
 * �E�}�K�W���摜�ȊO�ɋ[���̉摜���K�v
 * �E�����蔻��͕s�v
 * 
 * 
 * �}�K�W��(���)
 * �����������Ƀv���C���[��
 * 
 * �}�K�W����UI(��ڈȍ~)
 * ���܂��}�K�W�����I�u�W�F�N�g���Ĕz�u
 * �@���v���C���[�Ƃ��������蔻������
 * �@�@���v���C���[���擾������^�O��UI�ɕύX
 * �@�@�@�����W�A�X�P�[����ύX���ĉ�ʏ�̔C�ӂ̏ꏊ�ɕ\��������
 * 
*/
class Magazine : public GameObject
{
public:
	Magazine(D3D11 _D3d11) :GameObject(_D3d11) {
		// �ŏ��̓}�K�W���ɂ͂ǂ̋[���������Ă��Ȃ�
		//m_Onomatopoeia = nullptr;
	}

	~Magazine();

	// �}�K�W���ɓ������ꍇ�A���̋[���̏��L���̓}�K�W���Ɉڂ�͂��Ȃ̂�unique_ptr
	void SetOnomatopoeia(std::unique_ptr<IOnomatopoeia> _onomatopoeia);

private:
	//std::unique_ptr<IOnomatopoeia> m_Onomatopoeia;
};

