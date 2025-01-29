#include "Camera.h"
/*Camera::Camera(D3D11& _D3d11, int StageSize) :GameObject(_D3d11)
{
	m_CameraSize.x = 1920;
	m_CameraSize.y = 1080;
	m_CameraPos.x = 0;
	m_CameraPos.y = 0;
	cameraSpeed = StageSize / 100;	//!ステージの移動スピード
}

void Camera::Update(float cameraSpeed,Vector3 pos)
{
	//! カメラのポジションを限界地まで移動させていく
	if (m_CameraPos.x < CameraLimit)
	{
		pos.x -= cameraSpeed;
		m_CameraPos.x += cameraSpeed;
	}

	//! カメラ画面内以外のオブジェクトを描画しないようにする
	if (pos.x< -m_CameraSize.x / 2 || pos.x>-m_CameraSize.x / 2)
	{
		//! オブジェクトの描画をoffに
	}
	else
	{
		//! オブジェクトの描画をonに
	}
}*/