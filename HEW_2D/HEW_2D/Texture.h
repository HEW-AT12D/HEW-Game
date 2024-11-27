#pragma once
#include "Framework/D3D11/D3D11.h"
#include "Framework/Component/Transform/Transform.h"

/**
 * Texture�N���X
 * 
 * �E�摜�̓ǂݍ���
 * �E�`��
 * �E���
 * ���s��
 * 
 * @brief 
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
