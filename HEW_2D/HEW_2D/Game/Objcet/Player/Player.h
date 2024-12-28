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

	void Update(void) override;
	void Animation(AnimationName animation_name,Vector2 _UV)override;

private:
	SoundGun soundgun;
};

