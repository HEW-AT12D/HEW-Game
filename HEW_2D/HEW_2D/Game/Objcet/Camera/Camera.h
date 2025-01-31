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
 * �E���Ԃ��Ȃ��̂ō���̃J�����͍��̉摜�����������ʂ̃I�u�W�F�N�g�Ƃ���
 * 
 * ����ȂƂ��납�H�����蔻�������Ȃ���
 * ���ŁA�J������ʓ��ɂ��郂�m�����`�悷��A�Ƃ���΍s����͂�
*/
class Camera : public GameObject
{
public:
	Camera(D3D11& _D3d11) :GameObject(_D3d11) {
		//! �J�����̈ړ��X�s�[�h
		m_Velocity = { 20.0f };
		Vector3 scele = { 1920.0f, 1080.0f, 0.0f };
		transform.SetScale(scele);
		transform.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		//cameraSpeed = StageSize / 100;	//!�X�e�[�W�̈ړ��X�s�[�h

		// �ŏ��̓t�F�[�h�C������n�߂����̂Ńt�F�[�h�̃t���O�݂̂�ݒ肵�Ă���
		OnFade = true;
		FadeIn = true;
		IsMoving = false;
	}

	~Camera() {};
	
	void Update(void) override;		//! �J�����X�s�[�h�ƃI�u�W�F�N�g�̈ʒu
	void SetIsMoving(bool _flg) { IsMoving = _flg; }

private:
	bool OnFade;	// �t�F�[�h��
	bool FadeIn;	// �t�F�[�h�C��/�A�E�g����
	bool IsMoving;	// �ړ���������
};

