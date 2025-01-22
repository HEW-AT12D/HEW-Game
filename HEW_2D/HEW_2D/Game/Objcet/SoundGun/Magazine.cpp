#include"Magazine.h"

void Magazine::SetOnomatopoeia(std::unique_ptr<IOnomatopoeia>&& _onomatopoeia)
{
	// ���L�����ړ�
	m_Onomatopoeia = std::move(_onomatopoeia);
}

void Magazine::Update(void)
{
	// �d�͉����x
	if (!OnGround)
	{
		// �ڒn���Ă��Ȃ���Ή��Z
		m_Velocity.y -= 0.5f;
	}
	else {

	}

	// �ړ�����
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// �����x�N�g����X�����̈ړ����x���|�����l�̕��������t���[���i��
	// �V�������W����
	transform.SetPosition(newpos);
}
