#pragma once
#include "../BaseObject/GameObject.h"


class Player :public GameObject
{
public:
	Player();
	Player(D3D11& _D3d11) :GameObject(_D3d11) {};
	~Player();

private:

};

Player::Player()
{
}

Player::~Player()
{
}
