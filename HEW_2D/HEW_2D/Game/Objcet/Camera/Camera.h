#pragma once
#include "../BaseObject/GameObject.h"

/**
 * @brief �J�����N���X
 * 
 * ���K�v�Ȃ��́�
 * �@�E�`�悵������ʂ̑傫��(���A����)
 * �@�E�J�����̍��W(�����_�̓Q�[���I�ɕK�v�Ȃ�����)
 * �@�E�`��@�\
 * 
 * ����ȂƂ��납�H�����蔻�������Ȃ���
 * ���ŁA�J������ʓ��ɂ��郂�m�����`�悷��A�Ƃ���΍s����͂�
*/
class Camera : public GameObject
{
public:
	Camera(D3D11& _D3d11,int) :GameObject(_D3d11) {

	}

	~Camera() {};
	void Update(float,Vector3);	//! �J�����X�s�[�h�ƃI�u�W�F�N�g�̈ʒu

private:
	Vector3 m_CameraSize;	//! �J������ʂ̑傫��
	Vector3 m_CameraPos;	//! �J�����̍��W
	float cameraSpeed;		//! �J�����̈ړ��X�s�[�h
	int CameraLimit;		//! �J�����̈ړ��ő�l
};

