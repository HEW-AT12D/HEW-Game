#pragma once
#include "Component/Transform/Transform.h"
class Texture :public Transform
{
protected:
private:
	void Init();
	void Update();
	void Draw();
	void Uninit();
};