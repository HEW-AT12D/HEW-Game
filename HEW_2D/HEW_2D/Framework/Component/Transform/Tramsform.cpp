#include "Transform.h"

// �Z�b�^�[
void Transform::SetPosition(XMFLOAT3 _Position) {
	m_Position = _Position;
}

void Transform::SetRotation(XMFLOAT3 _Rotation) {
	m_Position = _Rotation;
}

void Transform::SetScale(XMFLOAT3 _Scale) {
	m_Position = _Scale;
}

// �s��ϊ�
XMMATRIX Transform::ConvertMatrix(void) {
	XMMATRIX WorldPos, WorldRot, WorldScale;
	WorldPos = XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);			// ���W�������[���h�s���
	WorldRot = XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z);	// �p�x�����[���h�s���
	WorldScale = XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);						// �X�P�[���i�傫���j�����[���h�s���
	return WorldPos * WorldRot * WorldScale;
	// TODO:1105�����܂ŁI�����[���h�s��ւ̕ϊ�������������

}

