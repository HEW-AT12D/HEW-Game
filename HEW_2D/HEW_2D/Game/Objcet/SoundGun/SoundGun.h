#pragma once
#include "../BaseObject/GameObject.h"


/**
 * @brief プレイヤーが持つ擬音銃クラス
 * 
 * ・機能としては吸い込み、使用の二つ
 * 　→使用する場合、使用先が決まっているなら「擬音の能力を付与」しなければならない
 * 
 * ・使用先の決定もここの機能として持つ
 * 
 * ・ステージ内でマガジン数増加予定なのでvectorでマガジンを持たせる
 * 
 * ＜必要なもの＞
*/
class SoundGun : public GameObject
{
public:
	SoundGun(D3D11& _D3d11) :GameObject(_D3d11) {};
	~SoundGun() {};

	void Suction(Vector3, Vector3);//吸い込み関数


private:

};

