#include "Camera.h"
/*Camera::Camera(D3D11& _D3d11, int StageSize) :GameObject(_D3d11)
{
	m_CameraSize.x = 1920;
	m_CameraSize.y = 1080;
	m_CameraPos.x = 0;
	m_CameraPos.y = 0;
	cameraSpeed = StageSize / 100;	//!�X�e�[�W�̈ړ��X�s�[�h
}

void Camera::Update(float cameraSpeed,Vector3 pos)
{
	//! �J�����̃|�W�V���������E�n�܂ňړ������Ă���
	if (m_CameraPos.x < CameraLimit)
	{
		pos.x -= cameraSpeed;
		m_CameraPos.x += cameraSpeed;
	}

	//! �J������ʓ��ȊO�̃I�u�W�F�N�g��`�悵�Ȃ��悤�ɂ���
	if (pos.x< -m_CameraSize.x / 2 || pos.x>-m_CameraSize.x / 2)
	{
		//! �I�u�W�F�N�g�̕`���off��
	}
	else
	{
		//! �I�u�W�F�N�g�̕`���on��
	}
}*/