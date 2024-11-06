#include "Transform.h"

// セッター
void Transform::SetPosition(XMFLOAT3 _Position) {
	m_Position = _Position;
}

void Transform::SetRotation(XMFLOAT3 _Rotation) {
	m_Position = _Rotation;
}

void Transform::SetScale(XMFLOAT3 _Scale) {
	m_Position = _Scale;
}

// 行列変換
XMMATRIX Transform::ConvertMatrix(void) {
	XMMATRIX WorldPos, WorldRot, WorldScale;
	WorldPos = XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);			// 座標ををワールド行列へ
	WorldRot = XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z);	// 角度をワールド行列へ
	WorldScale = XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);						// スケール（大きさ）をワールド行列へ
	return WorldPos * WorldRot * WorldScale;
	// TODO:1105ここまで！→ワールド行列への変換を完成させる

}

