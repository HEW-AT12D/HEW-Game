#include "CrossHair.h"

/**
 * @brief �X�V
*/
void CrossHair::Update(void)
{
	// ���W�ݒ�p�ϐ�
	Vector3 newpos = transform.GetPosition();

	// ���ړ�
	if (MoveLeft)
	{
		newpos.x -= m_Velocity.x;
		transform.SetPosition(newpos);
	}
	// �E�ړ�
	if (MoveRight)
	{
		newpos.x += m_Velocity.x;
		transform.SetPosition(newpos);
	}
	// ��ړ�
	if (MoveUp)
	{
		newpos.y += m_Velocity.y;
		transform.SetPosition(newpos);
	}
	// ���ړ�
	if (MoveDown)
	{
		newpos.y -= m_Velocity.y;
		transform.SetPosition(newpos);
	}
}
