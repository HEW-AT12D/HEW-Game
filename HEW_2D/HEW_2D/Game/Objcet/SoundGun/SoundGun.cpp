#include "SoundGun.h"

void SoundGun::Suction(Vector3 _gion_pos, Vector3 _p_pos)
{
	if (_gion_pos.x-_p_pos.x <= 100)/*Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�*/
	{
		//�����ɁA�߂Â��X�s�[�h������
		_gion_pos.x--;
		std::cout << "�z������ł܂�" << std::endl;
		
	}
}

