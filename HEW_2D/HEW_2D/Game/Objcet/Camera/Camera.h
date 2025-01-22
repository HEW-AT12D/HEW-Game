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
	Camera(D3D11& _D3d11) :GameObject(_D3d11) {

	}

	~Camera() {};

private:
	Vector3 m_CameraSize;	// �J������ʂ̑傫��
};

