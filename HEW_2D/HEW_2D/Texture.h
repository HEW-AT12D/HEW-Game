#pragma once
#include "Framework/Component/Transform/Transform.h"




/**
 * Textureクラス
 * 
 * ・画像の読み込み
 * ・描画
 * ・解放
 * を行う
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
