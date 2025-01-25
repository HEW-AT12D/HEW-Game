#pragma once
#include "../../BaseObject/GameObject.h"


/**
 * @brief �[���N���X�i���N���X�j
 *
 *
 * �����ً`�ꂪ����̂ŕ��G
 * ���ʉ摜�ƕʃA�N�V�������K�v
 * 
 * �E���̃f�[�^(�Ӗ��̐�����)
 * �E�[����ɂ��P�ȏ�̓���������
 * 
 * �E�[���͕t�^���ꂽ�e�I�u�W�F�N�g�ɉe����^����
*/
class IOnomatopoeia : public GameObject
{
public:

	virtual ~IOnomatopoeia() {};
	// �[�����I�u�W�F�N�g�ɗ^���铮��(�����ŉ摜�̓�����������)
	virtual void Action(void) = 0;	// �}�K�W�����e�̏ꍇ�͌��ʂ�^���Ȃ�

protected:
	// �R���X�g���N�^��protected�ɂ���Ɣh���N���X���炵���R���X�g���N�^�𓮂����Ȃ�
	// �����̃N���X�̐e�N���X��GameObject�N���X�͎��̂����邪�A���̃N���X���p�������[���N���X�B��IOnomatopoeia�Ƃ��Ď��̂������Ƃ͂ł��Ȃ��Ȃ�
	IOnomatopoeia(D3D11 _D3d11) :GameObject(_D3d11) {

	};
	// �[�����t�^����Ă���I�u�W�F�N�g��GameObject�N���X��m_pParent�Ŕ��f����
	std::string m_Name;				// �[���̖��O
};

