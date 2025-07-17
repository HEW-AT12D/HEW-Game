#include"Enemy.h"


void Enemy::Update()
{
    m_Direction = { 0.0f };
    Vector3 enemy_pos = transform.GetPosition();

    // ▼ タイマーで向き切り替え
    m_Timer += 1.0f / 60.0f;  // 仮に60FPS換算
    if (m_Timer >= m_ChangeDirInterval)
    {
        m_Timer = 0.0f;
        m_FacingLeft = !m_FacingLeft;
    }

    // ▼ 向きに応じて移動方向設定
    if (m_FacingLeft)
    {
        m_Direction.x -= 1.0f;
    }
    else
    {
        m_Direction.x += 1.0f;
    }

    // ▼ ジャンプ処理
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

    // ▼ ベクトル正規化
    if (m_Direction.Length() > 0.0f)
    {
        m_Direction.Normalize();
    }
    else
    {
        m_Direction = { 0.0f, 0.0f, 0.0f };
    }

    // ▼ 重力
    if (!OnGround)
    {
        Jumping = true;
        m_Velocity.y -= 0.2f;
    }
    else
    {
        Jumping = false;
    }

    // ▼ 移動
    m_Velocity.x = m_Direction.x * m_MoveSpeed;
    enemy_pos += m_Velocity;
    transform.SetPosition(enemy_pos);
}

Enemy::~Enemy()
{

}