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
	virtual void Action(void) = 0;		// �}�K�W�����e�̏ꍇ�͌��ʂ�^���Ȃ�
	virtual void Fade_in_out(void);		// �[���̃t�F�[�h�C��/�t�F�[�h�A�E�g
	virtual void Update(void) override;	// �X�V
	virtual void Set_Onomatope(bool) = 0;   //�[���̃t���O�Z�b�g
	virtual bool Get_Onomatope(void) = 0;   //�[���̃t���O�Q�b�g
	virtual void Set_gion(bool) = 0;
	virtual bool Get_gion(void) = 0;

protected:
	// �R���X�g���N�^��protected�ɂ���Ɣh���N���X���炵���R���X�g���N�^�𓮂����Ȃ�
	// �����̃N���X�̐e�N���X��GameObject�N���X�͎��̂����邪�A���̃N���X���p�������[���N���X�B��IOnomatopoeia�Ƃ��Ď��̂������Ƃ͂ł��Ȃ��Ȃ�
	IOnomatopoeia(D3D11& _D3d11) :GameObject(_D3d11) {

	};
	// �[�����t�^����Ă���I�u�W�F�N�g��GameObject�N���X��m_pParent�Ŕ��f����
	std::string m_Name;				// �[���̖��O
	bool fade_check = false;
	bool Collision_Onomatope = false; //�[�����I�u�W�F�N�g�ɕt�^����Ă��邩�̔��f�t���O
	bool Collision_gion = false;
};

