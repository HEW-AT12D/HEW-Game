#include"Enemy.h"


void Enemy::Update()
{
    m_Direction = { 0.0f };
    Vector3 enemy_pos = transform.GetPosition();

    // �� �^�C�}�[�Ō����؂�ւ�
    m_Timer += 1.0f / 60.0f;  // ����60FPS���Z
    if (m_Timer >= m_ChangeDirInterval)
    {
        m_Timer = 0.0f;
        m_FacingLeft = !m_FacingLeft;
    }

    // �� �����ɉ����Ĉړ������ݒ�
    if (m_FacingLeft)
    {
        m_Direction.x -= 1.0f;
    }
    else
    {
        m_Direction.x += 1.0f;
    }

    // �� �W�����v����
    if (Jump && !Jumping)
    {
        Jumping = true;
        m_Velocity.y += m_JumpPower;
        m_Direction.y += 1.0f;
        Jump = false;
    }

    if (Jumping && m_Velocity.y < 0.0f)
    {
        if (OnGround)
        {
            Jumping = false;
        }
        else
        {
            m_Direction.y -= 1.0f;
        }
    }

    // �� �x�N�g�����K��
    if (m_Direction.Length() > 0.0f)
    {
        m_Direction.Normalize();
    }
    else
    {
        m_Direction = { 0.0f, 0.0f, 0.0f };
    }

    // �� �d��
    if (!OnGround)
    {
        Jumping = true;
        m_Velocity.y -= 0.2f;
    }
    else
    {
        Jumping = false;
    }

    // �� �ړ�
    m_Velocity.x = m_Direction.x * m_MoveSpeed;
    enemy_pos += m_Velocity;
    transform.SetPosition(enemy_pos);
}

Enemy::~Enemy()
{

}