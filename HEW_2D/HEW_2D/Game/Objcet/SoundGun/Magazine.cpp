#include"Magazine.h"

/**
 * @brief �[�����U
 * @param _onomatopoeia ���U����[��
 *
 * �[���𑕓U���������[�����I�u�W�F�N�g�}�l�[�W���ŊǗ����遨shared_ptr�ŊǗ����Ă�̂ŁA�֐��ŏ��L�����}�K�W���ɂ��n��
*/
//void Magazine::SetOnomatopoeia(Tag, std::string, std::shared_ptr<GameObject>&& _onomatopoeia)
//{
//	// ���L�����ړ�
//	m_Onomatopoeia = (_onomatopoeia);
//
//}


/**
 * @brief �X�V
 *
 * ���g�̃^�O��UI�Ȃ�d�͉����x���󂯂Ȃ��A�Ƃ��ɂ���������
 * �������Ȃ̂ŁA�e�I�u�W�F�N�g������ꍇ�A�d�͉����x���󂯂Ȃ��A�Ƃ���
 *
 *
*/
void Magazine::Update(void)
{
	// �e�I�u�W�F�N�g�����Ȃ��ꍇ
	if (!m_pParent.lock())
	{
		// �d�͉����x�̉e�����󂯂�
		if (!OnGround)
		{
			// �ڒn���Ă��Ȃ���Ή��Z
			m_Velocity.y -= 0.5f;
		}
		else {

		}
	}


	// �ړ�����
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// �����x�N�g����X�����̈ړ����x���|�����l�̕��������t���[���i��
	// �V�������W����
	transform.SetPosition(newpos);
}


/**
 * @brief �`��
*/
void Magazine::Draw(void)
{
	// ��Ƀ}�K�W����`��
	this->GameObject::Draw();

	// ���ɋ[���������Ă���΋[����`��
	if (m_Onomatopoeia)
	{
		m_Onomatopoeia->Draw();
	}
}


/**
 * @brief ���U����Ă���[����Ԃ��֐�
 * @return �[���̐��|�C���^(���L���̈ړ��͂Ȃ��̂Ő��|��n���ĊǗ�����)
*/
IOnomatopoeia* Magazine::GetBulletPointer(void)
{
	return m_Onomatopoeia.get();
}


/**
 * @brief �}�K�W���ɋ[���𑕓U����֐�
 * @param _onomat �[��
*/
void Magazine::SetOnomatopoeia(std::shared_ptr<IOnomatopoeia> _onomat)
{
	// �}�K�W���ɑ��U
	m_Onomatopoeia = _onomat;
	// �[�����}�K�W���̎q�I�u�W�F�N�g�ɐݒ�
	SetChild(_onomat);
}


/**
 * @brief ���ˎ��ɋ[���̏��L�����[���e�ɓn���ă}�K�W��������ɂ���֐�
 * @return �[���̃|�C���^
*/
std::shared_ptr<IOnomatopoeia> Magazine::ReleaseBullet(void)
{
	// ���L�����Ϗ�
	return std::move(m_Onomatopoeia);
}
