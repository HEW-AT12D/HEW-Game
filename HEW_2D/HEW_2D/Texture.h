#pragma once
#include "Framework/Component/Transform/Transform.h"




/**
 * Texture�N���X
 * 
 * �E�摜�̓ǂݍ���
 * �E�`��
 * �E���
 * ���s��
 * 
 */
class Texture
{
protected:
	Transform transform;
private:
	void Init();
	void Update();
	void Draw();
	void Uninit();
};
