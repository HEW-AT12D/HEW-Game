#include "Camera.h"


void Camera::Update(void)
{
	// フェード中で
	if (OnFade)
	{
		// フェードインしているときは
		if (FadeIn)
		{
			// 画像の透明度を下げていく
			Color newcol = m_Color;
			newcol.w -= 0.01f;
			m_Color = newcol;
			// 明転しきったら
			if (m_Color.w < 0.0f)
			{
				// 透明度を0で固定
				m_Color.w = 0.0f;
				OnFade = false;		// フェードインに変更
				FadeIn = false;		// フラグをフェードアウトに変更
				//IsMoving = true;	// カメラ移動開始
			}
		}
		// フェードアウト中は
		else
		{
			// 画像の透明度を上げていく
			Color newcol = m_Color;
			newcol.w -= 0.01f;
			m_Color = newcol;
			// 暗転しきったら
			if (m_Color.w > 1.0f)
			{
				// 透明度を1で固定
				m_Color.w = 1.0f;
				OnFade = false;		// フェードイン
				FadeIn = true;		// フラグをフェードインに変更
				//IsMoving = false;	// カメラ移動を停止
			}
		}
	}

	if (IsMoving)
	{
		// 座標を変更
		Vector3 newpos = transform.GetPosition();
		newpos.x += transform.GetScale().x;			// 1920加算する
		transform.SetPosition(newpos);

		IsMoving = false;		// 移動完了	
		OnFade = true;			// フェードアウト開始
	}

	// 注視点オブジェクトがあれば
	//if (m_pTarget)
	//{
	//	Vector3 targetPos = m_pTarget->GetPosition();
	//	Vector3 halfScreenSize = transform.GetScale() * 0.5f;

	//	// カメラの左上座標を更新（画面中心にターゲットを置く）
	//	Vector3 newCameraPos = targetPos - halfScreenSize;
	//	transform.SetPosition(newCameraPos);
	//}
}

void Camera::Draw(void){

}
