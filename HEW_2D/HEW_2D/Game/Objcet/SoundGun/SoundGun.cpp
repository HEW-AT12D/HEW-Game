#include "SoundGun.h"
#include "Magazine.h"


/**
 * @brief �X�V
*/
void SoundGun::Update(void)
{
	// �A�j���[�V�����J�E���g�𑝂₷���̔���
	static bool countup = true;
	// �z�����ݒ��Ȃ�A�j���[�V�����𓮂���
	if (IsSuction)
	{
		if (countup)
		{
			m_Number.y++;
			// �A�j���[�V�������Ō�܂ōs�����ꍇ
			if (m_Number.y == m_Split.y)
			{
				countup = false;
			}
		}
		else
		{
			m_Number.y--;
			// �A�j���[�V�������ŏ��܂Ŗ߂����ꍇ
			if (m_Number.y == 0)
			{
				countup = true;
			}
		}
	}

	// �e�I�u�W�F�N�g�ƍ��W�𓯊�(����͊��N���X�ł��ׂ�)
	// �����ł͂Ƃ肠�����[���e�̍��W�𓯊�������
	Vector3 newpos = m_pParent.lock()->GetPosition();
	newpos.x += transform.GetScale().x / 2 + m_pParent.lock()->GetScale().x / 2;	// �[���e�ƃv���C���[�̑傫���̂��ꂼ�ꔼ���𑫂����l�����Z���č��W��ݒ�
	transform.SetPosition(newpos);
}


/**
 * @brief �`��
 * �z�����ݒ��̂ݕ`����s�� 
*/
void SoundGun::Draw(void)
{
	// �z�����ݒ��Ȃ�
	if (IsSuction)
	{
		this->GameObject::Draw();
	}
}


// �z�����ݏ�Ԃ̃Q�b�^�[�Z�b�^�[
void SoundGun::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
}


bool SoundGun::GetIsSuction(void)
{
	return IsSuction;
}


/**
 * @brief �z�����݊֐�
 * @param _gion_pos
 * @param _p_pos
*/
bool SoundGun::Suction(std::weak_ptr<GameObject> _gion)
{
	// �e�I�u�W�F�N�g(�v���C���[)�����݂��Ă��āA
	if (m_pParent.lock())
	{
		// �z�����ދ[���̏��
		Vector3 gion_pos = _gion.lock()->GetPosition();		// ���W
		Vector3 gion_rot = _gion.lock()->GetRotation();		// �p�x
		Vector3 gion_scale = _gion.lock()->GetScale();		// �T�C�Y

		/*Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�*/
		//�����ɁA�߂Â��X�s�[�h������
		gion_pos.x -= 10;
		_gion.lock()->SetPosition(gion_pos);
		std::cout << "�z������ł܂�" << std::endl;


		// �[���̉�]�A�k��
		gion_rot.z += 40;
		_gion.lock()->SetRotation(gion_rot);	// �p�x�̍Đݒ�

		// �z�����ݒ��͖��t���[���k�������
		if (gion_scale.y >= 0.0f)
		{
			// �T�C�Y��ύX���čĐݒ�
			gion_scale.x -= 8.0f;
			gion_scale.y -= 4.0f;

			_gion.lock()->SetScale(gion_scale);
		}

		// �v���C���[�̍��W�ɓ���������(����Ȃ��߂Â�����)
		if (gion_pos.x - m_pParent.lock()->GetPosition().x <= 100.0f)
		{
			// �e�I�u�W�F�N�g�̃}�K�W���Ɋi�[
			auto player = std::dynamic_pointer_cast<Player>(m_pParent.lock());
			// �����̊֐��ɂ�GameObject�^�Ŏ����Ă��Ă�̂�IOnomatopoeia�^�ɃL���X�g
			auto onomatopoeia = std::dynamic_pointer_cast<IOnomatopoeia>(_gion.lock());

			// �[���̍��W�����ݑI�����Ă���}�K�W���̍��W�ɕύX
			// �����I�����Ă�}�K�W���Ɋ��ɋ[��������ꍇ�A���̃}�K�W���ɑ��U�A���J��Ԃ��A�S�����U����Ă���ꍇ�A���W�͊񂹂邪��]�A�z�����ݏ����͍s��Ȃ�
			onomatopoeia->SetPosition(player->GetUsingMag()->GetPosition());	// ���W��ݒ�
			onomatopoeia->SetRotation(player->GetUsingMag()->GetRotation());	// �p�x��ݒ�
			onomatopoeia->SetScale(player->GetUsingMag()->GetScale());			// �傫����ݒ�
			player->GetUsingMag()->SetOnomatopoeia(onomatopoeia);				// �}�K�W���ɑ��U
			
			// �v���C���[�Ƌ[���e�̋z�����ݏ�Ԃ�����
			this->IsSuction = false;
			player->SetIsSuction(false);

			// �z�����݊����̌��ʂ�Ԃ�
			return true;
		}
	}
	return false;
}


/**
 * @brief �[�����ˊ֐�
 * @param _mag �}�K�W�����
 * 
 * ����
 * ���ˁ��}�K�W���̒e�̏��L�����e�ɓn���i�I������Ă���}�K�W���ԍ��̒��ɂ���e�̏��L����n���j�����̒e���e������
*/
void SoundGun::Shot(std::shared_ptr<Magazine> _mag)
{
	// �����̃}�K�W���̒��ɂ���[���̃T�C�Y�Ȃǂ�ݒ�

	auto gion = _mag->ReleaseBullet();

	Vector3 gion_Rot = gion->GetRotation();		// �[���̉�]���
	Vector3 gion_Scale = gion->GetScale();		// �[���̃T�C�Y���
	Vector3 gion_Pos = transform.GetPosition();	// �[���̍��W(����͋[���e�̏����E�ɏo��������̂ŏe��ł�����)
	Vector3 gion_dir = m_Direction;				// ���˂������(�e�̌����Ă�������ɔ��˂���)

	//gion_Rot.z = 0;		// �z�����݂�

	// �[���̍��W��ݒ�
	gion_Pos.x += 5.0f;		// �[���e�̏����E

	// �[���̃T�C�Y�ݒ�
	gion_Scale.y = 120.0f;
	gion_Scale.x = 240.0f;

	// �e������
	/*gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);*/


	gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);
	gion->SetDirection(gion_dir);

	// AddForce�ő�����邽�߂̑��x�p�ϐ�
	Vector3 velocity;
	velocity.x = m_ShotPower;
	velocity.y = m_ShotPower;
	// TODO:2025/01/27 �����ŉ������̃x�N�g���𖳂����Ă����Ή��ɗ����邱�Ƃ͂Ȃ��͂��I
	// ��Player�̔��ˊ֐��ɂ�邱�Ə����Ă�
	// �[���ɗ͂������Ă܂�������΂�����
	gion->AddForce(velocity);
}
