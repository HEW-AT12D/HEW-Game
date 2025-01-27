#include "SoundGun.h"
#include "Magazine.h"

/**
 * @brief 吸い込み関数
 * @param _gion_pos 
 * @param _p_pos 
*/
void SoundGun::Suction(Vector3 _gion_pos, Vector3 _p_pos)
{
	if (_gion_pos.x-_p_pos.x <= 100)/*Playerと擬音の距離が一定に来たら、擬音が徐々に近づく*/
	{
		//ここに、近づくスピードを書く
		_gion_pos.x--;
		std::cout << "吸い込んでます" << std::endl;
		
	}
}


/**
 * @brief 擬音発射関数
 * @param _mag マガジン情報
*/
void SoundGun::Shot(std::shared_ptr<Magazine> _mag)
{
	// AddForceで代入するための速度用変数
	Vector3 velocity;
	velocity.x = m_ShotPower;
	// TODO:2025/01/27 ここで下方向のベクトルを無くしておけば下に落ちることはないはず！
	// →Playerの発射関数にやること書いてる
	// 擬音に力を加えてまっすぐ飛ばしたい
	_mag->GetBulletPointer()->AddForce(velocity);
}
