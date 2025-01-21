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
		m_JumpPower = 0.0f;
		m_MoveSpeed = 0.0f;
		m_Direction = { 0.0f,0.0f,0.0f };
		m_Velocity = { 0.0f,0.0f,0.0f };
	}

	virtual ~Character() {};

	virtual void Update(void) override;


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
	// �㉺���E�̈ړ��t���O
	bool MoveUp;
	bool MoveDown;
	bool MoveLeft;
	bool MoveRight;
	bool Jump;
	bool Jumping;

	float m_JumpPower;		// �W�����v��
	float m_MoveSpeed;		// �ړ����x
	Vector3 m_Velocity;		// ���x(����͖��t���[���ω�����l)
	Vector3 m_Direction;	// �ړ��p�����x�N�g��
};

