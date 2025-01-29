#include"Enemy.h"

void Enemy::Update()
{
	m_Direction = { 0.0f };
	Vector3 enemy_pos = transform.GetPosition();

	// �����x�N�g��������
	// �W�����v�����ꍇ
	
		// �W�����v���łȂ����
		// �W�����v����
	if (Jump && !Jumping)
	{

		Jumping = true;					// �W�����v���ɐݒ�(����X�e�[�g�ł���������)
		m_Velocity.y += m_JumpPower;	// ���x��Y�����ɃW�����v�͂���
		m_Direction.y += 1.0f;			// ������̕����x�N�g�������Z
		Jump = false;                   //�W�����v�t���O��false

	}
		
	

	// ���~���Ă���ꍇ(�W�����v���Ńx�N�g����Y��������(-)�̎�)
	if (Jumping && m_Velocity.y < 0.0f)
	{
		//Animation(JUMP);
		// �n�ʂɑ��������ꍇ�͕����x�N�g�������Z�b�g
		if (OnGround)
		{
			// ���n�t���O�𗧂Ă�
			Jumping = false;
			// �ʏ펞�A�j���[�V�����֕ύX
			//Animation(RUN);
		}
		else
		{
			// �����łȂ��ꍇ(���~���̏ꍇ)
			m_Direction.y -= 1.0f;	// �������̕����x�N�g�������Z
		}
	}
	

	// ���ړ����悤�Ƃ��Ă���ꍇ
	m_Direction.x -= 1.0f;	// �������̕����x�N�g�������Z

	// ���K��(�������P�ɑ�����)
	if (m_Direction.Length() > 0.0f)
	{
		m_Direction.Normalize();
	}
	else
	{
		m_Direction = { 0.0f, 0.0f, 0.0f };  // �����I�ɕ����x�N�g�������Z�b�g
	}

	// �n�ʂ̏�ɂ��Ȃ��ꍇ�A�d�͕����x�����Z
	if (!OnGround)
	{
		Jumping = true;
		m_Velocity.y -= 0.2f;	// �d�͉����x�����̏ꍇ������ύX
	}
	else {
		// �ڒn���Ă���΃W�����v���ł͂Ȃ�
		Jumping = false;
	}

	m_Velocity.x = m_Direction.x * m_MoveSpeed;
	enemy_pos += m_Velocity;
	transform.SetPosition(enemy_pos);
	//MoveLeft = false;
}

Enemy::~Enemy()
{

}