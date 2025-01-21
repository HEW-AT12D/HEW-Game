#include "Player.h"
#include "../../../Framework/Input/Input.h"


/**
 * @brief �X�V
*/
void Player::Update(void) 
{
	// �����x�N�g��������
	m_Direction = { 0.0f };

	// �����x�N�g��������
	// �W�����v�����ꍇ
	if (Jump)
	{
		Jumping = true;					// �W�����v���ɐݒ�(����X�e�[�g�ł���������)
		m_Velocity.y += m_JumpPower;	// ���x��Y�����ɃW�����v�͂���
		m_Direction.y += 1.0f;			// ������̕����x�N�g�������Z
		Jump = false;
		Animation(JUMP);
	}
	// ���~���Ă���ꍇ(�W�����v���Ńx�N�g����Y��������(-)�̎�)
	if (Jumping && m_Velocity.y < 0.0f)
	{
		Animation(JUMP);
		// �n�ʂɑ��������ꍇ�͕����x�N�g�������Z�b�g
		if (m_Velocity.y == 0.0f)
		{
			Jumping = false;
		}
		else
		{
			// �����łȂ��ꍇ(���~���̏ꍇ)
			m_Direction.y -= 1.0f;	// �������̕����x�N�g�������Z
		}
	}
	// ���ړ����悤�Ƃ��Ă���ꍇ
	if (MoveLeft)
	{
		m_Direction.x -= 1.0f;	// �������̕����x�N�g�������Z
		Animation(RUN);
		MoveLeft = false;
	}
	// �E�ړ����悤�Ƃ��Ă���ꍇ
	if (MoveRight)
	{
		m_Direction.x += 1.0f;	// �E�����̕����x�N�g�������Z
		Animation(RUN);
		MoveRight = false;
	}

	// ���K��(�������P�ɑ�����)
	if (m_Direction.Length() > 0.0f)
	{
		m_Direction.Normalize();
	}
	else
	{
		m_Direction = { 0.0f, 0.0f, 0.0f };  // �����I�ɕ����x�N�g�������Z�b�g
	}

	// X�����̈ړ����x������x�N�g���ƈړ����x����v�Z
	m_Velocity.x = m_Direction.x * m_MoveSpeed;

	// �n�ʂ̏�ɂ��Ȃ��ꍇ�A�d�͕����x�����Z
	if (!OnGround)
	{
		m_Velocity.y -= 0.5f;	// �d�͉����x�����̏ꍇ������ύX
	}

	// �ړ�����
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// �����x�N�g����X�����̈ړ����x���|�����l�̕��������t���[���i��
	// �V�������W����
	transform.SetPosition(newpos);
	
}

/**
 * @brief �A�j���[�V�����֐�
 * @param �ǂ̃A�j���[�V�������Đ����邩�̗񋓌^
 * �W�����v���Ɉړ������Ⴄ�ƈړ��A�j���[�V�������D�悳��Ă��܂��̂ł�����������
 * �ڒn�����Ƃ��ɍ��E�ړ��L�[�����Ȃ��ƒʏ펞�ɖ߂�Ȃ��̂ł���������
*/
void Player::Animation(STATE _Anim_Name)
{
	// ��ԏ��߂̓A�j���[�V�������Z�Ȃ̂�CountUp��true�ɐݒ�
	static bool CountUp = true;
	static bool CountDown = false;
	// �f�B���C�p�t���[���J�E���g�ϐ�
	static int framecount = 0;

	// UV�ԍ��ő�l�Ŋ��遨�]�肪����΂܂����Z�ł���
	// �]��Ȃ����A�j���[�V�����ŏI�t���[���Ȃ̂Ō��Z�J�n
	// ���s�������A�j���[�V�����̎�ނ��������ő��遨�֐����Ōv�Z���ĉ��Z�������Z�����𔻒f������΂���
	switch (_Anim_Name)
	{
	case NORMAL:
		// �ʏ펞�͉������Ȃ�(�����݂ȏc�h��A�j���[�V�����Ƃ�����΂����ɏ���)
		break;
	case RUN:
		// �ʏ�ړ���
		//TODO:2025/01/21 �������Ɉړ������Ƃ��̏������܂��I�I�I�I�I�I�I�I�I�I�I�I�I�I
		this->m_Number.y = 0;	// ��ԏ�̒i���g��

		// �t���[�������Z
		framecount++;
		if (framecount == 3)
		{
			// ���Z����
			if (CountUp)
			{
				// �A�j���[�V�����ԍ����Z(�A�j���[�V�������Ƃɕ��������Ⴄ�ꍇ��switch�ŏ����������Ă����ɕ�����������΂���)
				m_Number.x += 1;
				// �A�j���[�V�����ԍ��]��Ȃ����A�j���[�V�����ŏI�t���[���Ȃ̂Ō��Z�J�n
				if (m_Number.x % m_Split.x == 0)
				{
					CountDown = true;
					CountUp = false;
				}
			}
			// ���Z����
			if (CountDown)
			{
				// �A�j���[�V�����ԍ����Z
				m_Number.x -= 1;
				// �A�j���[�V�����ԍ���0��菬�������A�j���[�V�����̊J�n�t���[���Ȃ̂Ŕԍ���0�ɖ߂��ĉ��Z�J�n
				if (m_Number.x < 0)
				{
					m_Number.x = 0;
					CountUp = true;
					CountDown = false;
				}
			}
			framecount = 0;
		}
		break;
	case JUMP:
		// ��������₱����
		// �E�W�����v�����Ƃ����W�����v���ł͂Ȃ��W�����v�t���O����������
		// �E�㏸���̂Ƃ����W�����v���Ńx�N�g����Y��������(+)�̎�
		// �E���~���̂Ƃ����W�����v���Ńx�N�g����Y��������(-)�̎�
		// �E���n�����Ƃ����W�����v���ŉ������̃x�N�g����0�ɂȂ�����(�v���C���[���n�ʂɐڐG�����Ƃ�)

		// �W�����v��
		// �E�W�����v�����Ƃ����W�����v���ł͂Ȃ��W�����v�t���O����������
		if (!Jumping && Jump)
		{
			this->m_Number.y = 1;	// ��Ԗڂ̒i��
			this->m_Number.x = 0;	// �����g��
		}
		// �E�㏸���̂Ƃ����W�����v���Ńx�N�g����Y��������(+)�̎�
		if (Jumping && m_Velocity.y > 0.0f)
		{
			// �ʉ摜���Ȃ��̂œ������̂��g��
			this->m_Number.y = 1;	// ��Ԗڂ̒i��
			this->m_Number.x = 0;	// �����g��
		}
		// �E���~���̂Ƃ����W�����v���Ńx�N�g����Y��������(-)�̎�
		if (Jumping && m_Velocity.y < 0.0f)
		{
			this->m_Number.y = 1;	// ��Ԗڂ̒i��
			this->m_Number.x = 1;	// �E���g��
		}
		// �E���n�����Ƃ����W�����v���ŉ������̃x�N�g����0�ɂȂ�����(�v���C���[���n�ʂɐڐG�����Ƃ�)
		if (Jumping && m_Velocity.y == 0)
		{
			this->m_Number.y = 1;	// ��Ԗڂ̒i��
			this->m_Number.x = 1;	// �E���g��
		}

		break;

	// ���͉摜���̂ō��̂Ƃ�������\��Ȃ�
	case DAMAGED:
		break;
	case ATTACKED:
		break;
	default:
		break;
	}
}
