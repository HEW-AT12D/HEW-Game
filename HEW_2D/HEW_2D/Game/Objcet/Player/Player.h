#pragma once
#include "../SoundGun/SoundGun.h"


/**
 * @brief プレイヤークラス
*/
class Player :public GameObject
{
public:
	Player();
	Player(D3D11& _D3d11) :GameObject(_D3d11),soundgun(_D3d11) {};
	~Player() {};

private:
	SoundGun soundgun;
};

