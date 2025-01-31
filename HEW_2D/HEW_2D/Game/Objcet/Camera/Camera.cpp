#include "Camera.h"


void Camera::Update(void)
{
	// �t�F�[�h����
	if (OnFade)
	{
		// �t�F�[�h�C�����Ă���Ƃ���
		if (FadeIn)
		{
			// �摜�̓����x�������Ă���
			Color newcol = m_Color;
			newcol.w -= 0.01f;
			m_Color = newcol;
			// ���]����������
			if (m_Color.w < 0.0f)
			{
				// �����x��0�ŌŒ�
				m_Color.w = 0.0f;
				OnFade = false;		// �t�F�[�h�C���ɕύX
				FadeIn = false;		// �t���O���t�F�[�h�A�E�g�ɕύX
				//IsMoving = true;	// �J�����ړ��J�n
			}
		}
		// �t�F�[�h�A�E�g����
		else
		{
			// �摜�̓����x���グ�Ă���
			Color newcol = m_Color;
			newcol.w -= 0.01f;
			m_Color = newcol;
			// �Ó]����������
			if (m_Color.w > 1.0f)
			{
				// �����x��1�ŌŒ�
				m_Color.w = 1.0f;
				OnFade = false;		// �t�F�[�h�C��
				FadeIn = true;		// �t���O���t�F�[�h�C���ɕύX
				//IsMoving = false;	// �J�����ړ����~
			}
		}
	}

	// �t�F�[�h�A�E�g���J�������W�ړ����t�F�[�h�C���A�Ƃ������ɂ�����
	if (IsMoving)
	{
		// ���W��ύX
		Vector3 newpos = transform.GetPosition();
		newpos.x += transform.GetScale().x;			// 1920���Z����
		transform.SetPosition(newpos);

		IsMoving = false;		// �ړ�����	
		OnFade = true;			// �t�F�[�h�A�E�g�J�n
	}
}