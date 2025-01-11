#pragma once
#include "../Onomatopeia/Onomatopoeia.h"

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
*/
class Magazine : public GameObject
{
public:
	Magazine();
	Magazine(D3D11 _D3d11) :GameObject(_D3d11) {

	}

	~Magazine();

private:
	std::unique_ptr<Onomatopoeia> Onomatopoeia;
};

