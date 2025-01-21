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
*/
class IOnomatopoeia : public GameObject
{
public:
	IOnomatopoeia(D3D11 _D3d11) :GameObject(_D3d11) {

	};

	virtual ~IOnomatopoeia() {};
	virtual void Action(void) = 0;	// �[���̂��I�u�W�F�N�g�ɗ^���铮��(�����ŉ摜�̓�����������)

protected:
	GameObject* m_AttachedObj;		// �[�����t�^����Ă���I�u�W�F�N�g
	std::string m_Name;				// �[���̖��O
};

