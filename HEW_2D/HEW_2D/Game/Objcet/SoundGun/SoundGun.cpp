#include "SoundGun.h"
#include "Magazine.h"

/**
 * @brief �z�����݊֐�
 * @param _gion_pos 
 * @param _p_pos 
*/
void SoundGun::Suction(Vector3 _gion_pos, Vector3 _p_pos)
{
	if (_gion_pos.x-_p_pos.x <= 100)/*Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�*/
	{
		//�����ɁA�߂Â��X�s�[�h������
		_gion_pos.x--;
		std::cout << "�z������ł܂�" << std::endl;
		
	}
}


/**
 * @brief �[�����ˊ֐�
 * @param _mag �}�K�W�����
*/
void SoundGun::Shot(std::shared_ptr<Magazine> _mag)
{
	// AddForce�ő�����邽�߂̑��x�p�ϐ�
	Vector3 velocity;
	velocity.x = m_ShotPower;
	// TODO:2025/01/27 �����ŉ������̃x�N�g���𖳂����Ă����Ή��ɗ����邱�Ƃ͂Ȃ��͂��I
	// ��Player�̔��ˊ֐��ɂ�邱�Ə����Ă�
	// �[���ɗ͂������Ă܂�������΂�����
	_mag->GetBulletPointer()->AddForce(velocity);
}
