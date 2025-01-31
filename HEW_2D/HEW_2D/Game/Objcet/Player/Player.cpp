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
		Animation(JUMP);
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
	// ���ړ����悤�Ƃ��Ă���ꍇ
	if (MoveLeft)
	{
		m_Direction.x -= 1.0f;	// �������̕����x�N�g�������Z
		// �W�����v���̓W�����v���[�V�����D��
		if (Jumping)
		{
			Animation(JUMP);
		}
		else {
			Animation(RUN);
		}
		MoveLeft = false;
	}
	// �E�ړ����悤�Ƃ��Ă���ꍇ
	if (MoveRight)
	{
		m_Direction.x += 1.0f;	// �E�����̕����x�N�g�������Z
		// �W�����v���̓W�����v���[�V�����D��
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
		m_Number.y = 0;			// 2025/01/23 �ԍ�: �Ȃ����񖇖ڂ̂ق��ɐݒ肳��邯�ǈ�a���̓}�V�ɂȂ����̂ň�U����Œu���Ƃ�
	}

	// �ړ�����
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// �����x�N�g����X�����̈ړ����x���|�����l�̕��������t���[���i��
	// �V�������W����
	transform.SetPosition(newpos);


	// �z�����ݏ����͈������K�v�Ȃ̂ŃV�[���Œ��ڍs��

	//if (IsSuction)
	//{
	//	Suction();
	//}

	// ���ˏ���

	if (IsShot)
	{
		Shot();
		IsShot = false;
	}

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
		// �`��(���̒��ŋz�����ݒ����𔻒肵�Ă�)
		m_Soundgun->Draw();
	}
}

/**
 * @brief �������
*/
void Player::Uninit(void)
{
	for (auto& mag : m_Magazines) {
		// �}�K�W����S�ĊJ��
		mag->Uninit();
		// ���L�����̂Ă�
		mag.reset();
	}
	// �}�K�W���̃R���e�i����ɂ���
	m_Magazines.clear();

	// �[���e�̉��
	//m_Soundgun->Uninit();   //�����΂���
	// ���L�����̂Ă�
	m_Soundgun.reset();

	// �N���X�w�A�̉��
	//m_CrossHair->Uninit();
	m_CrossHair.reset();

	// �v���C���[�̉��
	this->GameObject::Uninit();
}


/**
 * @brief �A�j���[�V�����֐�
 * @param �ǂ̃A�j���[�V�������Đ����邩�̗񋓌^
 * �ڒn�����Ƃ��ɍ��E�ړ��L�[�����Ȃ��ƒʏ펞�ɖ߂�Ȃ��̂ł���������
 * TODO:2025/01/21 �������Ɉړ������Ƃ��̏������܂��I�I�I�I�I�I�I�I�I�I�I�I�I�I
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


/**
 * @brief �q�I�u�W�F�N�g���Z�b�g
 * @param _child �q�I�u�W�F�N�g�̃|�C���^
 *
 * �Z�}�K�W���擾�̗���
 * �@�E�}�K�W�����E�����^�O��UI�ɕύX���傫���ƍ��W��ύX�A�Ƃ�����
*/
void Player::SetChild(std::shared_ptr<GameObject> _child)
{
	// �ݒ肷��q�I�u�W�F�N�g���}�K�W���ł����(�L���X�g�ł����)
	if (auto casted = std::dynamic_pointer_cast<Magazine>(_child))
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
		_child->SetParent(std::dynamic_pointer_cast<Player>(shared_from_this()));
	}
	// �[���e�Ȃ�
	else if (auto casted = std::dynamic_pointer_cast<SoundGun>(_child))
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
	else if (auto casted = std::dynamic_pointer_cast<CrossHair>(_child))
	{
		// �q�I�u�W�F�N�g�ɐݒ�
		m_CrossHair = casted;
		m_pChildren.push_back(casted);
	}
	else
	{
		// �q�I�u�W�F�N�g�ɒǉ�
		m_pChildren.push_back(_child);
	}
	// �q�I�u�W�F�N�g���ɂ����̃I�u�W�F�N�g��e�Ƃ��Đݒ�
	_child->SetParent(shared_from_this());
}


/**
 * @brief �[���z�����݊֐�
 *
 *
 * �V�[���Ŕ��肵���[���Ƃ̓����蔻����g���ē��������[���̍��W���ړ�������
 *
 * �����̋[�����}�K�W���ɑg�ݍ��ޏ�����ǉ�����
 *  ���v���C���[�Ɠ�����܂ŋz�����񂾂�A�}�K�W���ɒǉ�
 * @param _gion_pos
 * @param _p_pos
*/
bool Player::Suction(std::weak_ptr<GameObject> _gion)
{
	// �t���O�𗧂Ăċ[���e�̋z�����ݏ��������s
	m_Soundgun->SetIsSuction(true);

	// �[���e�̋z�����݂̌��ʂ�Ԃ�
	return m_Soundgun->Suction(_gion);
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

		Vector3 p_aim = m_CrossHair->GetPosition();				// �N���X�w�A���W
		Vector3 p_player = this->transform.GetPosition();		// �v���C���[���W
		Vector3 p_gion = m_Magazines[UseMagNumber]->GetBulletPointer()->GetPosition();		// ���˂���[���̍��W
		vertex.x = p_aim.x - p_player.x;			// �Ə���Player��X���W�̍��i��Ӂj
		vertex.y = p_aim.y - p_player.y;			// �Ə���Player��Y���W��  �i�����j
		hypotenuse = (vertex.y * vertex.y) + (vertex.x * vertex.x); //�Εӂ̌v�Z�i��ӂ̓��{�����̓�恁�Εӂ̓��j
		root_hypotenuse = std::sqrt(hypotenuse);	// �Εӂ̕������̌v�Z(�����Ńx�N�g���̒��������܂�)

		// �x�N�g���𐳋K��
		Vector3 normalized_vector;
		normalized_vector.x = vertex.x / root_hypotenuse;
		normalized_vector.y = vertex.y / root_hypotenuse;




		///////////////////////////////////////////////////////////////////////////////////////
		///			�A�̊撣����g�����߂ɃR�����g�A�E�g(���Ŏ�v�Z���Ă��̂Ł��͎g��Ȃ��ł���)			///
		///////////////////////////////////////////////////////////////////////////////////////
		///*p_aim�̈ʒu��
		//  (vertex.y, vertex.x) = ( 1, 1)�c���ی�
		//�@(vertex.y, vertex.x) = (-1, 1)�c���ی�
		//�@(vertex.y, vertex.x) = (-1,-1)�c��O�ی�
		//�@(vertex.y, vertex.x) = ( 1,-1)�c��l�ی�
		// ���Ċ���*/
		//Radians = std::atan2(vertex.y, vertex.x); //p_aim�̃|�W�V�������扽�ی��ɂ��邩�m�F

		//// ���˂������������e�̌���������ݒ�
		//// �p�x���x�N�g���ɕϊ�
		//Vector3 direction;
		//direction.x = std::cos(Radians);	// �x�N�g����X����
		//direction.y = std::sin(Radians);	// �x�N�g����Y����

		///////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////

		// �e�̌�����ݒ�(���Ōv�Z���Đ��K�����������x�N�g�����g�p)
		m_Soundgun->SetDirection(normalized_vector);



		// �������牺�͖��t���[���Ăяo���O��ŏ�����Ă���̂ŕύX���K�v

		// �[���e�̔��ˊ֐����Ăяo�������t���[���Ăяo���z��ŏ�����Ă�
		/*p_gion.x += directionX * 5;
		p_gion.y += directionY * 5;*/

		// �[���̍��W��ݒ�
		//m_Magazines[UseMagNumber]->GetBulletPointer()->SetPosition(p_gion);


		// �[���̔��ˊ֐��ɂ͌����͂Ƃ��͋C�ɂ��Ȃ��Ă�����0�ɐݒ肷�遨�܂��������ł���
		// �g���}�K�W���̏����󂯎���ċ[���e�Ŕ���
		m_Soundgun->Shot(m_Magazines[UseMagNumber]);

		// ���˃t���O�����Z�b�g
		IsShot = false;
	}
}


/**
 * @brief �I�����Ă���}�K�W�����̋[���̏���Ԃ��֐�
 * @return ���U����Ă���[��
*/
IOnomatopoeia* Player::GetLoadedBullet(void)
{
	// ���U���̃}�K�W���ɓ����Ă�[����Ԃ�
	return m_Magazines[UseMagNumber]->GetBulletPointer();
}


/**
 * @brief �I�����Ă�}�K�W����Ԃ��֐�
 * @return �I�𒆂̃}�K�W��
*/
std::shared_ptr<Magazine> Player::GetUsingMag(void)
{
	return m_Magazines[UseMagNumber];
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
}

// �I������Ă���}�K�W���ԍ��̃Z�b�^�[�Q�b�^�[
void Player::SetMagNumber(int _num)
{
	this->UseMagNumber = _num;
}

int Player::GetMagNumber(void)
{
	return this->UseMagNumber;
}

// �}�K�W�����̃Q�b�^�[
size_t Player::GetMagCount(void)
{
	return m_Magazines.size();
}
