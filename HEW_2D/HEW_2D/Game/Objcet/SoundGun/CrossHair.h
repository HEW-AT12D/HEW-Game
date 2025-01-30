#pragma once
#include "../BaseObject/GameObject.h"

/**
 * @brief �N���X�w�A�N���X
 * 
 * �N���X�w�A�摜�̈ړ������s��(�N���X�w�A��UI�ݒ�œo�^�����̂œ����蔻����C�ɂ���K�v�͂Ȃ�)
*/
class CrossHair :public GameObject
{
public:
	CrossHair(D3D11& _D3d11):GameObject(_D3d11) {
		MoveLeft = false;
		MoveRight = false;
		MoveUp = false;
		MoveDown = false;
		m_Velocity = { 10.0f };	// �N���X�w�A�̈ړ����x
	}

	~CrossHair() {};
	void Update(void) override;
	void SetMoveLeft(bool _flg) { MoveLeft = _flg; }
	void SetMoveRight(bool _flg) { MoveRight = _flg; }
	void SetMoveUp(bool _flg) { MoveUp = _flg; }
	void SetMoveDown(bool _flg) { MoveDown = _flg; }

private:
	bool MoveLeft;
	bool MoveRight;
	bool MoveUp;
	bool MoveDown;
};

