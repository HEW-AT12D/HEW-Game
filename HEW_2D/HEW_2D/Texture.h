#pragma once
#include "Framework/D3D11/D3D11.h"
#include "Framework/Component/Transform/Transform.h"

/**
 * Textureクラス
 * 
 * ・画像の読み込み
 * ・描画
 * ・解放
 * を行う
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
