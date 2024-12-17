#pragma once
#include "../BaseObject/GameObject.h"

class SoundGun : public GameObject
{
public:
	SoundGun();
	SoundGun(D3D11& _D3d11) :GameObject(_D3d11) {};
	~SoundGun();

private:

};


SoundGun::~SoundGun()
{
}
