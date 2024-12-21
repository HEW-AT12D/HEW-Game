#pragma once
#include "../BaseObject/GameObject.h"


/**
 * @brief プレイヤーが持つ擬音銃クラス
 * →マガジンも別クラスで持つと良い
 * 
 * 機能としては吸い込み、使用の二つ
 * →使用する場合、使用先が決まっているなら「擬音の能力を付与」しなければならない
*/
class SoundGun : public GameObject
{
public:
	SoundGun(D3D11& _D3d11) :GameObject(_D3d11) {};
	~SoundGun() {};

	

private:

};


