#include "SoundGun.h"

void SoundGun::Suction(Vector3 _gion_pos, Vector3 _p_pos)
{
	if (_gion_pos.x-_p_pos.x <= 100)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
	{
		//ここに、近づくスピードを書く
		_gion_pos.x--;
		std::cout << "吸い込んでます" << std::endl;
		
	}
}

