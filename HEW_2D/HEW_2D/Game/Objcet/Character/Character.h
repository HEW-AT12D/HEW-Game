#pragma once
#include "../BaseObject/GameObject.h"



/**
 * @brief �S�L�����N�^�[�̌��ƂȂ�N���X
 * �V�[�����ł͓��͂̎擾�A�t���O���Ă������s���A���̃N���X�̔h���N���X�ŌX�̓���������
*/
class Character :public GameObject
{
public:
	Character(D3D11& _D3d11) :GameObject(_D3d11) {
		MoveUp = false;
		MoveDown = false;
		MoveLeft = false;
		MoveRight = false;
		Jump = false;
		Jumping = false;
		OnGround = false;
		m_JumpPower = 0.0f;
		m_MoveSpeed = 0.0f;
	}

	virtual ~Character() {};

	virtual void Update(void) override;

	// �Q�b�^�[�Z�b�^�[�n
	virtual bool GetMoveUp(void);
	virtual bool GetMoveDown(void);
	virtual bool GetMoveLeft(void);
	virtual bool GetMoveRight(void);
	virtual bool GetJump(void);

	virtual void SetMoveUp(bool _flg);
	virtual void SetMoveDown(bool _flg);
	virtual void SetMoveLeft(bool _flg);
	virtual void SetMoveRight(bool _flg);
	virtual void SetJump(bool _flg);


protected:
	// �㉺���E�̈ړ��t���O(�X�e�[�g�ł�������)
	bool MoveUp;		// (���Ȃ�����)��ړ������H
	bool MoveDown;		// (���Ȃ�����)���ړ������H
	bool MoveLeft;		// ���ړ������H
	bool MoveRight;		// �E�ړ������H
	bool Jump;			// �W�����v�������H
	bool Jumping;		// �W�����v�����H

	float m_JumpPower;		// �W�����v��
	float m_MoveSpeed;		// �ړ����x
};

