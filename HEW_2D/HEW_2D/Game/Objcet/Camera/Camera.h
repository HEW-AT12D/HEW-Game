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
	Camera(D3D11& _D3d11,int) :GameObject(_D3d11) {

	}

	~Camera() {};
	void Update(float,Vector3);	//! カメラスピードとオブジェクトの位置

private:
	Vector3 m_CameraSize;	//! カメラ画面の大きさ
	Vector3 m_CameraPos;	//! カメラの座標
	float cameraSpeed;		//! カメラの移動スピード
	int CameraLimit;		//! カメラの移動最大値
};

