#include "Player.h"
#include "../../../Framework/Input/Input.h"
#include "../../../Framework/Component/Collider/BoxCollider2D/Collider.h"

/**
 * @brief �X�V
*/
void Player::Update(void)
{
	// �����x�N�g��������
	m_Direction = { 0.0f };

	// �����x�N�g��������
	// �W�����v�����ꍇ
	if (Jump && !Jumping)
	{
		// �W�����v���łȂ����
		// �W�����v����
		Jumping = true;					// �W�����v���ɐݒ�(����X�e�[�g�ł���������)
		m_Velocity.y += m_JumpPower;	// ���x��Y�����ɃW�����v�͂���
		m_Direction.y += 1.0f;			// ������̕����x�N�g�������Z
		Jump = false;
		Animation(JUMP);
	}
	// ���~���Ă���ꍇ(�W�����v���Ńx�N�g����Y��������(-)�̎�)
	if (Jumping && m_Velocity.y < 0.0f)
	{
		if (isFacingLeft) { Animation(LEFTJUMP); }
		else {
			Animation(JUMP);
		}
		// �n�ʂɑ��������ꍇ�͕����x�N�g�������Z�b�g
		if (OnGround)
		{
			// ���n�t���O�𗧂Ă�
			Jumping = false;
			// �ʏ펞�A�j���[�V�����֕ύX
			Animation(RUN);
		}
		else
		{
			// �����łȂ��ꍇ(���~���̏ꍇ)
			m_Direction.y -= 1.0f;	// �������̕����x�N�g�������Z
		}
	}
	
	// ���������Ă���Ԃ͋z�����ݏ���
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTriggerPress()) {
		// �z�����ݒ��̏���
		IsSuction = true;	// �z�����ݒ��t���O�𗧂Ă�
		m_Soundgun->SetIsSuction(true);	// �z�����ݏ��������s
	}
	else {
		IsSuction = false;	// �z�����ݒ��t���O�����낷
		m_Soundgun->SetIsSuction(false);	// �z�����ݏ��������s
	}

	// ���ˏ���
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger()) {
		// ���ˏ���
		IsShot = true;	// ���˒��t���O�𗧂Ă�
		this->Shot();
		IsShot = false;
	}
	this->UpdateMove();
	this->UpdateCurrentMag();	// ���݂̃}�K�W�����Z�b�g
	this->UpdateCrossHair();	// �N���X�w�A�̍X�V

	if (MoveLeft)
	{
		isFacingLeft = true; // �� �������t���O��ON
		m_Direction.x -= 1.0f;
		if (Jumping)
		{
			Animation(LEFTJUMP);
		}
		else {
			Animation(LEFTRUN);
		}
		MoveLeft = false;
	}

	if (MoveRight)
	{
		isFacingLeft = false; // �� �E�����t���O��OFF
		m_Direction.x += 1.0f;
		if (Jumping)
		{
			Animation(JUMP);
		}
		else {
			Animation(RUN);
		}
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
		Jumping = true;
		m_Velocity.y -= 0.5f;	// �d�͉����x�����̏ꍇ������ύX
	}
	else {
		// �ڒn���Ă���΃W�����v���ł͂Ȃ�
		Jumping = false;
		// �ʏ펞�A�j���[�V�����֕ύX(�����~�܂��Ă鎞�ɃA�j���[�V�����͂������Ȃ��̂ŁA��Ԏ��R�ȏ�Ԃ̉摜�ɐݒ�)
		if (isFacingLeft)
		{
			m_Number.y = 3; // �����������G
		}
		else {
			m_Number.y = 0;
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
 * �z�����݃G�t�F�N�g�A�q�I�u�W�F�N�g�Ƃ��Đݒ肵��UI�̃}�K�W�����`�悷��
*/
void Player::Draw(void)
{
	// �܂����g�̕`��
	this->GameObject::Draw();

	// TODO:(����)�A�j���[�V�����̈�a�������
	// TODO:�A�^�b�`���ꂽ�I�u�W�F�N�g�̕`��
	// TODO:�W�����v�̐�s���͎��Ă��܂��̂𒼂�

	// �[���e�̋z�����ݎ��̗�����`�悵�������A���񗳊���UI�ɂ��Ă��āA�I�u�W�F�N�g�Ƃ��ēo�^���Ă��܂��Ɠ����蔻�������Ă��܂��̂ł����ŋ[���e�̕`��܂ōs��
	// �[���e�������Ă����
	if (m_Soundgun)
	{
		// �X�P�[�����]�iX���̂ݔ��]�j
		Vector3 gunScale = m_Soundgun->GetScale();
		gunScale.x = isFacingLeft ? -abs(gunScale.x) : abs(gunScale.x);
		m_Soundgun->SetScale(gunScale);

		// �v���C���[�̍��E�ɏe���ړ�
		Vector3 gunPos = transform.GetPosition();
		float offset = transform.GetScale().x / 2 + m_Soundgun->GetScale().x / 2;
		gunPos.x += isFacingLeft ? -offset : offset;
		m_Soundgun->SetPosition(gunPos);
	}
}

/**
 ** @brief �������
**/
void Player::Uninit(void)
{
	// �}�K�W���̃R���e�i����ɂ���
	m_Magazines.clear();

	// �v���C���[�̉��
	this->GameObject::Uninit();
}


/**
 * @brief �A�j���[�V�����֐�
 * @param �ǂ̃A�j���[�V�������Đ����邩�̗񋓌^
 * �ڒn�����Ƃ��ɍ��E�ړ��L�[�����Ȃ��ƒʏ펞�ɖ߂�Ȃ��̂ł���������
 * TODO:2025/01/21 �������Ɉړ������Ƃ��̏������܂��I�I�I�I�I�I�I�I�I�I�I�I�I�I
*/
void Player::Animation(ANIMATIONSTATE _Anim_Name)
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
	case LEFTRUN:
		this->m_Number.y = 3;	// 3�ԏ�̒i���g��

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
	case LEFTJUMP:
		if (!Jumping && Jump)
		{
			this->m_Number.y = 4;	// ��Ԗڂ̒i��
			this->m_Number.x = 0;	// �����g��
		}
		// �E�㏸���̂Ƃ����W�����v���Ńx�N�g����Y��������(+)�̎�
		if (Jumping && m_Velocity.y > 0.0f)
		{
			// �ʉ摜���Ȃ��̂œ������̂��g��
			this->m_Number.y = 4;	// ��Ԗڂ̒i��
			this->m_Number.x = 0;	// �����g��
		}
		// �E���~���̂Ƃ����W�����v���Ńx�N�g����Y��������(-)�̎�
		if (Jumping && m_Velocity.y < 0.0f)
		{
			this->m_Number.y = 4;	// ��Ԗڂ̒i��
			this->m_Number.x = 1;	// �E���g��
		}
		// �E���n�����Ƃ����W�����v���ŉ������̃x�N�g����0�ɂȂ�����(�v���C���[���n�ʂɐڐG�����Ƃ�)
		if (Jumping && m_Velocity.y == 0)
		{
			this->m_Number.y = 4;	// ��Ԗڂ̒i��
			this->m_Number.x = 1;	// �E���g��
		}
		break;
		// ���͉摜���Ȃ��̂ō��̂Ƃ�������\��Ȃ�
	case DAMAGED:
		break;
	case ATTACKED:
		break;
	default:
		break;
	}
}


/**
 * @brief �q�I�u�W�F�N�g���Z�b�g
 * @param _child �q�I�u�W�F�N�g�̃|�C���^
 *
 * �Z�}�K�W���擾�̗���
 * �@�E�}�K�W�����E�����^�O��UI�ɕύX���傫���ƍ��W��ύX�A�Ƃ�����
*/
void Player::SetChild(GameObject* _child)
{
	// �ݒ肷��q�I�u�W�F�N�g���}�K�W���ł����(�L���X�g�ł����)
	if (auto casted = dynamic_cast<Magazine*>(_child))
	{
		// �}�K�W���̍��W�ƃX�P�[����ύX����(�������}�K�W�����ɂ���ĕς�����)
		// �ǂ�����H
		// ���}�K�W���̑傫����UI�����ɕύX���}�K�W����̑傫���������E�ɂ��炵�č��W��ݒ肷��΂�����H���������I

		// �傫������
		casted->SetScale(Vector3(120.0f, 120.0f, 0.0f));
		// ��ڂ́u�h�H���v������}�K�W���Ȃ̂ŁA���W�𒼐ڐݒ�
		if (m_Magazines.empty())
		{
			// ���W�ݒ�
			casted->SetPosition(Vector3(810.0f, 450.0f, 0.0f));
			// ���̃}�K�W�������傫����ς���
			casted->SetScale(Vector3(300.0f, 300.0f, 0.0f));
		}
		// ��ڂ̃}�K�W��(�[���e�ɑ��U����p�̃}�K�W��)��ǉ�����ꍇ
		else if (m_Magazines.size() == 1)
		{
			// ���W�ݒ�
			casted->SetPosition(Vector3(-900.0f, 500.0f, 0.0f));
		}
		// ���Ƀ}�K�W������ȏ㏊�����Ă���ꍇ��
		else
		{
			// �}�K�W�������v�Z
			size_t magcnt = m_Magazines.size();

			// �`�悵�������W���v�Z
			Vector3 newMagPos;
			// X���W�͂����΂���̃}�K�W���̍��W���� �ǉ�����}�K�W���̑傫�� / 2�����l �𑫂������W�ɕ\������
			newMagPos.x = m_Magazines.back()->GetPosition().x + casted->GetScale().x;
			// Y���W�������悤�ɐݒ�
			newMagPos.y = m_Magazines.back()->GetPosition().y;
			// ���W����
			casted->SetPosition(newMagPos);
		}

		// �v���C���[�̃}�K�W���ɒǉ�����
		m_Magazines.push_back(casted);
		// �q�I�u�W�F�N�g�Ƃ��Ă��ݒ�
		m_pChildren.push_back(casted);

		// �v���C���[���}�K�W���̐e�Ƃ��Đݒ肷��
		// shared_from_this��������GameObject�^�ɂȂ�̂ŁAPlayer�^�ɃL���X�g���Ă���n��
		_child->SetParent(dynamic_cast<Player*>(this));
	}
	// �[���e�Ȃ�
	else if (auto casted = dynamic_cast<SoundGun*>(_child))
	{
		// �q�I�u�W�F�N�g�ɐݒ�
		m_Soundgun = casted;
		m_pChildren.push_back(casted);

		// ���W���v���C���[�̏����E�ɒ���(������W�ϊ��ł���悤�ɂ�����)
		Vector3 newpos = transform.GetPosition();
		newpos.x += transform.GetScale().x / 2 + casted->GetScale().x / 2;	// �[���e�ƃv���C���[�̑傫���̂��ꂼ�ꔼ���𑫂����l�����Z���č��W��ݒ�
		casted->SetPosition(newpos);

	}
	// �N���X�w�A�̏ꍇ
	else if (auto casted = dynamic_cast<CrossHair*>(_child))
	{
		// �q�I�u�W�F�N�g�ɐݒ�
		m_pCrossHair = casted;
		m_pChildren.push_back(casted);
	}
	else
	{
		// �q�I�u�W�F�N�g�ɒǉ�
		m_pChildren.push_back(_child);
	}
	// �q�I�u�W�F�N�g���ɂ����̃I�u�W�F�N�g��e�Ƃ��Đݒ�
	_child->SetParent(this);
}

/**
 * @brief �v���C���[�̎��͂ɂ���[�����擾����֐�
 * @param _onomatopoeias �V�[������󂯎�����v���C���[���ӂ̋[��
 * @return �߂��ɂ���[���̃y�A(�^�O�Ɩ��O�A�|�C���^)
 *
 * ���v���C���[�̎��͂ɂ���[�����擾����
 * �����̒�����A�z�����߂�[����T��
*/
std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> Player::StartSuction(std::vector<std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>> _onomatopoeias)
{
	std::pair closest = ColliderFan_Gion(this, _onomatopoeias);
	if (closest.second) {
		IsSuction = true;
	}
	return closest;
}

/**
 * @brief �z�����ދ[����T���֐�
 *
 * �V�[������󂯎�����v���C���[���ӂ̋[������A�z�����߂�[����T��
 *
 * �����̋[�����}�K�W���ɑg�ݍ��ޏ�����ǉ�����
 *  ���v���C���[�Ɠ�����܂ŋz�����񂾂�A�}�K�W���ɒǉ�
 * @param _gion_pos
 * @param _p_pos
*/
bool Player::Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> _onomatopoeia)
{
	// �[���e�����݂��Ȃ��ꍇ�͉������Ȃ�
	if (!m_Soundgun) return false;


	// �t���O�𗧂Ăċ[���e�̋z�����ݏ��������s
	m_Soundgun->SetIsSuction(true);

	// �[���e�̋z�����݂̌��ʂ�Ԃ�
	if (m_Soundgun->Suction(_onomatopoeia)) {
		// �����h�H���Ȃ�J�E���g���Z
		if (_onomatopoeia.first.first == Tag::Doon) {
			BombCount++;
		}
		return true;	// �z�����ݐ���
	}
	return false;	// �z�����ݎ��s
}


/**
 * @brief �[���e�̃G�C���̍��W����ɋ[���𔭎�
 * @param _gion
 *
 * ��邱��
 * ���N���X�w�A���[���e�̎q�I�u�W�F�N�g�ɐݒ聨���͂�����đ���\�ɂ��遨�v���C���[�̔��ˊ֐��ł��̃N���X�w�A���ƃ}�K�W���ɓ����Ă�[�������g����悤�ɂ���
 *
 * ��肽�����Ɓ��g���[��(�}�K�W��)�����߂遨�G�C������(����͂��ł��ł���悤�ɂ���)������
*/
void Player::Shot(void)
{
	//����
	if (IsShot)
	{
		if (!m_Magazines[UsingMagIdx]->GetBulletPointer()) { return; }
		//==========================================
		//=======�P���Q�U������======================
		//Player�̂O�x�`�P�W�O�x�܂ł���������Ƃ�Ă��Ȃ�
		//�P�W�O�x�𒴂���Ɓ{�ɕϊ������i��F�Q�S�O�x�œ��͂���ƁA�P�Q�O�x�Ŕ��˂����j
		//==============================================================================

		Vector3 vertex;			// 
		float hypotenuse;		// �Εӂ̓��
		float root_hypotenuse;	// �������̌v�Z�������Ε�
		float Radians;			// �p�x
		float Degrees;			// �x
		float M_PI;				// �~����

		//-----------����----------//
		//Player�𒆐S�ɂ���,�Ə������킹�Ă���ꏊ��GetPos�Ŏ����,//
		//�G�C�����Ď�����|�W�V��������A�����ɍ~�낵�ĎO�_���//

		//�Ε�^2 = �G�C�����Ď����X���W�̃|�W�V���� ^ 2 - (�G�C�����Ď�����|�W�V��������A�����ɍ~�낵��X���W - Player��X���W) ^ 2//
		//cos�� = (�G�C�����Ď�����|�W�V��������A�����ɍ~�낵��X���W - Player��X���W) / �Ε�

		Vector3 p_aim = m_pCrossHair->GetPosition();				// �N���X�w�A���W
		Vector3 p_player = this->transform.GetPosition();		// �v���C���[���W
		Vector3 p_gion = m_Magazines[UsingMagIdx]->GetBulletPointer()->GetPosition();		// ���˂���[���̍��W
		vertex.x = p_aim.x - p_player.x;			// �Ə���Player��X���W�̍��i��Ӂj
		vertex.y = p_aim.y - p_player.y;			// �Ə���Player��Y���W��  �i�����j
		hypotenuse = (vertex.y * vertex.y) + (vertex.x * vertex.x); //�Εӂ̌v�Z�i��ӂ̓��{�����̓�恁�Εӂ̓��j
		root_hypotenuse = std::sqrt(hypotenuse);	// �Εӂ̕������̌v�Z(�����Ńx�N�g���̒��������܂�)

		// �x�N�g���𐳋K��
		Vector3 normalized_vector;
		normalized_vector.x = vertex.x / root_hypotenuse;
		normalized_vector.y = vertex.y / root_hypotenuse;

		// �e�̌�����ݒ�(���Ōv�Z���Đ��K�����������x�N�g�����g�p)
		m_Soundgun->SetDirection(normalized_vector);

		// �[���̔��ˊ֐��ɂ͌����͂Ƃ��͋C�ɂ��Ȃ��Ă�����0�ɐݒ肷�遨�܂��������ł���
		// �g���}�K�W���̏����󂯎���ċ[���e�Ŕ���
		m_Soundgun->Shot(m_Magazines[UsingMagIdx]);

		// ���˃t���O�����Z�b�g
		IsShot = false;
		//m_Magazines[UsingMagIdx].reset();
	}
}

/**
 * @brief �}�K�W���J�[�\���̐ݒ�
 * @param _cursor �}�K�W���J�[�\���̃|�C���^
 *
 * �}�K�W���J�[�\����ݒ肷��
 * �}�K�W���J�[�\���̍��W�Ƒ傫����ݒ肵�āA�q�I�u�W�F�N�g�ɒǉ�����
*/
void Player::SetMagCursor(GameObject* _cursor)
{
	// �}�K�W���J�[�\����ݒ�
	if (_cursor)
	{
		m_pMagCursor = _cursor;
		// �}�K�W���J�[�\�����q�I�u�W�F�N�g�ɒǉ�
		m_pChildren.push_back(_cursor);
	}
}

/**
 * @brief �v���C���[�̈ړ��X�V
 * ���͂ɍ��킹�ăv���C���[�̈ړ��t���O���X�V����
 * �E�X�e�B�b�N�̓��͂ŃW�����v�A���X�e�B�b�N�̓��͂ō��E�ړ����s��
*/
void Player::UpdateMove(void)
{
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();
	// ���͊Ǘ�
	// �E�ړ�
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		this->MoveRight = true;
	}
	else {
		this->MoveRight = false;
	}
	// ���ړ�
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		this->MoveLeft = true;
	}
	else {
		this->MoveLeft = false;
	}
	// �W�����v
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		this->Jump = true;
	}
	else {
		this->Jump = false;
	}
}

/**
 * @brief ���݂̃}�K�W�����X�V
 * R1�Ń}�K�W���J�[�\�����E�Ɉړ��AL1�ō��Ɉړ�
 * �}�K�W���J�[�\���̍��W���X�V����
*/
void Player::UpdateCurrentMag(void)
{
	// �J�[�\���̍��W�擾
	Vector3 p_frame = m_pMagCursor->GetPosition();

	// R1�Ń}�K�W���J�[�\���E�ړ�
	if (Input::GetInstance().GetKeyTrigger(VK_P) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		// �h�H���p�}�K�W����������ԍŌ�̃}�K�W����I�����Ă��Ȃ����
		if (this->UsingMagIdx != m_Magazines.size() - 1)
		{
			// �}�K�W���I��ԍ����P���₵�ăJ�[�\�����E�Ɉړ�
			this->UsingMagIdx += 1;
			p_frame.x += 120.0f;
		}
		// ��ԍŌ�̃}�K�W����I�����Ă���ꍇ
		else
		{
			// �}�K�W���I��ԍ����P(�h�H���p�}�K�W����������ԍŏ�)�ɖ߂��ăJ�[�\���������ʒu�Ɉړ�
			this->UsingMagIdx = 1;
			p_frame.x = -900.0f;
		}
		// ���W��ݒ�
		m_pMagCursor->SetPosition(p_frame);
		// SE�Đ�
		m_pSound->Play(SE_CLICK);
	}
	// L1�Ń}�K�W���J�[�\�����ړ�
	if (Input::GetInstance().GetKeyTrigger(VK_O) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_LEFT_SHOULDER))
	{
		// �h�H���p�}�K�W����������ԍŏ��̃}�K�W����I�����Ă��Ȃ����
		if (this->UsingMagIdx != 1)
		{
			m_pSound->Play(SE_CLICK);
			// �}�K�W���I��ԍ����P���炵��
			this->UsingMagIdx -= 1;
			// �J�[�\�������Ɉړ�
			p_frame.x -= 120.0f;
		}
		// ��ԍŏ��̃}�K�W����I�����Ă���ꍇ
		else
		{
			// �}�K�W���I��ԍ���(�h�H���p�}�K�W��������)��Ԍ��ɂ���
			this->UsingMagIdx = m_Magazines.size() - 1;
			// �J�[�\������Ԍ��̈ʒu�Ɉړ�
			p_frame.x = -900.0f + m_pMagCursor->GetScale().x * (m_Magazines.size() - 2);	// �����ʒu + �J�[�\���̑傫�� * �}�K�W����(�h�H������Ȃ��̂�-2)
		}
		// �}�K�W���A�E�g���C���̍��W��ݒ�
		m_pMagCursor->SetPosition(p_frame);
		// SE�Đ�
		m_pSound->Play(SE_CLICK);
	}
}

/**
 * @brief �N���X�w�A�̍X�V
 * �E�X�e�B�b�N�̓��͂ɍ��킹�ăN���X�w�A�̍��W���X�V����
 * ��ʊO�ɏo�Ȃ��悤�ɐ�����������
*/
void Player::UpdateCrossHair(void)
{
	// �N���X�w�A�̍��W���v���C���[�̍��W�ɍ��킹��
	if (!m_pCrossHair) return; // �N���X�w�A���ݒ肳��Ă��Ȃ��ꍇ�͉������Ȃ�

	Vector2 input = Input::GetInstance().GetRightAnalogStick(); // �E�X�e�B�b�N�̓��͂��擾

	// �X�e�B�b�N�̓��͂ɍ��킹�ăN���X�w�A�̍��W���ړ�
	if (input != Vector2{ 0.0f }) {

		Vector3 crosshairvelocity = m_pCrossHair->GetVelocity();
		Vector3 newPos = m_pCrossHair->GetPosition() + Vector3(input.x, input.y, 0.0f) * crosshairvelocity;

		// �N���X�w�A�̍��W����ʓ��ɒ���
		// X���W�̐���
		if(newPos.x < 0 - 1920.0f / 2){
			newPos.x = 0 - 1920.0f / 2; // ���[
		}
		else if(newPos.x > 1920.0f / 2){
			newPos.x = 1920.0f / 2; // �E�[
		}
		// Y���W�̐���
		if(newPos.y < 0 - 1080.0f / 2){
			newPos.y = 0 - 1080.0f / 2; // ���[
		}
		else if(newPos.y > 1080.0f / 2){
			newPos.y = 1080.0f / 2; // ��[
		}
		m_pCrossHair->SetPosition(newPos);
	}
}

/**
 * @brief �I�����Ă���}�K�W�����̋[���̏���Ԃ��֐�
 * @return ���U����Ă���[��
*/
IOnomatopoeia* Player::GetLoadedBullet(void)
{
	// ���U���̃}�K�W���ɓ����Ă�[����Ԃ�
	return m_Magazines[UsingMagIdx]->GetBulletPointer();
}

/**
 * @brief �v���C���[�������Ă���}�K�W���̃R���e�i��Ԃ��֐�
 * @return �}�K�W���̃R���e�i
*/
std::vector<Magazine*>& Player::GetMagazines(void)
{
	return m_Magazines;
}

/**
 * @brief �I�����Ă�}�K�W����Ԃ��֐�
 * @return �I�𒆂̃}�K�W��
*/
Magazine* Player::GetUsingMag(void)
{
	return m_Magazines[UsingMagIdx];
}


// �ˌ���Ԃ̃Q�b�^�[�A�Z�b�^�[
bool Player::GetIsShot(void)
{
	return IsShot;
}

void Player::SetIsShot(bool _flg)
{
	IsShot = _flg;
}

// �z�����ݏ�Ԃ̃Q�b�^�[�Z�b�^�[
bool Player::GetIsSuction(void)
{
	return IsSuction;
}

void Player::SetIsSuction(bool _flg)
{
	IsSuction = _flg;
	m_Soundgun->SetIsSuction(_flg);	// �[���e�̋z�����ݏ�Ԃ��X�V
}

// �I������Ă���}�K�W���ԍ��̃Z�b�^�[�Q�b�^�[
void Player::SetMagIdx(int _num)
{
	this->UsingMagIdx = _num;
}


int Player::GetMagIdx(void)
{
	return this->UsingMagIdx;
}

// �}�K�W�����̃Q�b�^�[
size_t Player::GetMagCount(void)
{
	return m_Magazines.size();
}
