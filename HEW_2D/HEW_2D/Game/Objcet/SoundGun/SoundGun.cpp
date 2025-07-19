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
	Vector3 newpos = m_pParent->GetPosition();
	newpos.x += transform.GetScale().x / 2 + m_pParent->GetScale().x / 2;	// �[���e�ƃv���C���[�̑傫���̂��ꂼ�ꔼ���𑫂����l�����Z���č��W��ݒ�
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

/**
 * @brief �z�����ݏ�Ԃ̃Z�b�^�[
 * @param _flg �z�����ݏ�Ԃɂ��邩�ǂ���
*/
void SoundGun::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
}

/**
 * @brief �z�����ݏ�Ԃ̃Q�b�^�[
 * @return �z�����ݒ����ǂ���
*/
bool SoundGun::GetIsSuction(void)
{
	return IsSuction;
}

/**
 * @brief �z�����݊֐�
 * @param _gion_pos
 * @param _p_pos
*/
bool SoundGun::Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> _onomatopoeia)
{
	// �e�I�u�W�F�N�g(�v���C���[)�����݂��Ȃ���ΏI��
	if (!m_pParent) { return false; }

	// �v���C���[�擾
	Vector3 player_pos = m_pParent->GetPosition();

	// �v���C���[�̑O���x�N�g���擾
	Vector3 forward = m_pParent->GetDirection(); // ��: {0, 0, 1} �Ȃ�
	forward.Normalize();
	// �I�t�Z�b�g����(�v���C���[�Ƌ[���e)�̌v�Z
	Vector3 offset = XMVectorAbs(player_pos - this->transform.GetPosition());
	// �z�����݂̒��S = �v���C���[�ʒu + ���ʕ��� * �I�t�Z�b�g����
	Vector3 suction_center = player_pos + forward * offset;

	// �z�����ދ[���̏��
	Vector3 onomat_pos = _onomatopoeia.second->GetPosition();		// ���W
	Vector3 onomat_rot = _onomatopoeia.second->GetRotation();		// �p�x
	Vector3 onomat_scale = _onomatopoeia.second->GetScale();		// �T�C�Y

	// Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�
	// �[�� �� �z�����ݒ��S �ւ̕����x�N�g�����v�Z
	Vector3 dir = suction_center - onomat_pos;
	dir.Normalize();
	// �ړ����x�������Ĉʒu���X�V
	onomat_pos += dir * 10.0f;	// 10.0f�͋z�����ݑ��x
	_onomatopoeia.second->SetPosition(onomat_pos);
	std::cout << "�z������ł܂�" << std::endl;

	// �[���̉�]�E�k��
	onomat_rot.z += 40;
	_onomatopoeia.second->SetRotation(onomat_rot);	// �p�x�̍Đݒ�

	// �z�����ݒ��͖��t���[���k�������
	if (onomat_scale.y >= 0.0f)
	{
		// �T�C�Y��ύX���čĐݒ�
		onomat_scale.x -= 8.0f;
		onomat_scale.y -= 4.0f;

		_onomatopoeia.second->SetScale(onomat_scale);
	}

	// �v���C���[�̍��W�ɓ���������(����Ȃ��߂Â�����)
	if ((onomat_pos - m_pParent->GetPosition()).Length() <= 100.0f)
	{
		// �e�I�u�W�F�N�g�̃}�K�W���Ɋi�[
		auto player = dynamic_cast<Player*>(m_pParent);
		// �����̊֐��ɂ�GameObject�^�Ŏ����Ă��Ă�̂�IOnomatopoeia�^�ɃL���X�g

		// �[���̍��W�����ݑI�����Ă���}�K�W���̍��W�ɕύX
		// �����I�����Ă�}�K�W���Ɋ��ɋ[��������ꍇ�A���̃}�K�W���ɑ��U�A���J��Ԃ��A�S�����U����Ă���ꍇ�A���W�͊񂹂邪��]�A�z�����ݏ����͍s��Ȃ�
		if (!_onomatopoeia.second) return false;

		// �}�K�W���̃|�C���^���擾
		std::vector<Magazine*> mags = player->GetMagazines();

		// �[���̎�ނɂ���ă}�K�W��UI�̌`��SRT�ƐF��ݒ�
		if (_onomatopoeia.first.first == Tag::Doon) {
			// ��ڂ̃h�H���Ȃ�SRT���h�H���p�}�K�W���ɍ��킹�đ��U
			if (!mags[0]) {
				_onomatopoeia.second->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
				_onomatopoeia.second->SetScale(Vector3(300.0f, 150.0f, 0.0f));
				_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
			}
			// ��ڈȍ~�͍��W�ύX���ē����x0�ɂ���
			else {
				_onomatopoeia.second->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
				_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));
			}
			mags[0]->SetOnomatopoeia(_onomatopoeia.second);	// �}�K�W���ɋ[�����Z�b�g
		}
		else {
			_onomatopoeia.second->SetRotation(player->GetUsingMag()->GetRotation());
			_onomatopoeia.second->SetScale(player->GetUsingMag()->GetScale());			// �傫����ݒ�
			_onomatopoeia.second->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));				// �F�̏�����

			// ���ݑI�𒆂̃}�K�W���ɋ[�����Ȃ���΂��ׂĂ̋󂫂�T���đ��U
			if (!mags[player->GetMagIdx()]->GetBulletPointer()) {
				_onomatopoeia.second->SetPosition(mags[player->GetMagIdx()]->GetPosition());	// ���ݑI�𒆂̃}�K�W���̍��W�ɍ��킹��
				mags[player->GetMagIdx()]->SetOnomatopoeia(_onomatopoeia.second);
			}
			else {
				for (size_t idx = 1; idx < player->GetMagCount(); idx++)
				{
					// �}�K�W��������Ȃ�[�����Z�b�g���ă��[�v�𔲂���
					if (!mags[idx]->GetBulletPointer()) {
						_onomatopoeia.second->SetPosition(mags[player->GetMagIdx()]->GetPosition());	// ���ݑI�𒆂̃}�K�W���̍��W�ɍ��킹��
						mags[idx]->SetOnomatopoeia(_onomatopoeia.second);
						break;
					}
				}
			}
		}		

		// �v���C���[�Ƌ[���e�̋z�����ݏ�Ԃ�����
		this->IsSuction = false;
		player->SetIsSuction(false);

		// �z�����݊����̌��ʂ�Ԃ�
		return true;
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
void SoundGun::Shot(Magazine* _mag)
{
	// �����̃}�K�W���̒��ɂ���[���̃T�C�Y�Ȃǂ�ݒ�
	auto gion = _mag->ReleaseBullet();

	Vector3 gion_Rot = gion->GetRotation();		// �[���̉�]���
	Vector3 gion_Scale = gion->GetScale();		// �[���̃T�C�Y���
	Vector3 gion_Pos = transform.GetPosition();	// �[���̍��W(����͋[���e�̏����E�ɏo��������̂ŏe��ł�����)
	Vector3 gion_dir = m_Direction;				// ���˂������(�e�̌����Ă�������ɔ��˂���)

	// �[���̍��W��ݒ�
	if (m_Direction.x > 0.0f) { gion_Pos.x += 5.0f; }		// �E�����Ȃ�[���e�̏����E
	if (m_Direction.x < 0.0f) { gion_Pos.x -= 5.0f; }		// �������Ȃ�[���e�̏�����

	// �[���̃T�C�Y�ݒ�
	gion_Scale.y = 120.0f;
	gion_Scale.x = 240.0f;

	gion->SetPosition(gion_Pos);
	gion->SetRotation(gion_Rot);
	gion->SetScale(gion_Scale);
	gion->SetDirection(gion_dir);

	// AddForce�ő�����邽�߂̑��x�p�ϐ�
	Vector3 velocity;
	velocity.x = m_ShotPower;
	velocity.y = m_ShotPower;
	// ��Player�̔��ˊ֐��ɂ�邱�Ə����Ă�
	// �[���ɗ͂������Ă܂�������΂�����
	gion->AddForce(velocity);
}
