#pragma once
#include "../BaseObject/GameObject.h"

/**
 * @brief カメラクラス
 * 
 * ＜必要なもの＞
 * 　・描画したい画面の大きさ(幅、高さ)
 * 　・カメラの座標(注視点はゲーム的に必要なさそう)
 * 　・描画機能
 * 
 * こんなところか？当たり判定もいらないし
 * →で、カメラ画面内にあるモノだけ描画する、とすれば行けるはず
*/
class Camera : public GameObject
{
public:
	Camera(D3D11& _D3d11) :GameObject(_D3d11) {

	}

	~Camera() {};

private:
	Vector3 m_CameraSize;	// カメラ画面の大きさ
};

