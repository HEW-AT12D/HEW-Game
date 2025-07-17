#pragma once
#include "Transform.h"
#include "../../../Game/EntryPoint/main.h"

using namespace SimpleMath;

/// <summary>
/// Transform�N���X�F�S�ẴI�u�W�F�N�g�������Ă�����i�����ł͐��l�݂̂������j
/// �E���W
/// �E��]
/// �E�傫��
/// �̏�������
/// 
/// �e���l�̍s��ϊ��͖��t���[���s�����X�V�͕s�v
/// ���[���h�s��ւ̕ϊ���Transform���ōs��
/// </summary>

class Transform
{
public:
	Transform() :m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f), m_Scale(75.0f, 75.0f, 0.0f) {};
	~Transform() {};

	void SetPosition(Vector3 _Position);	// ���W�ݒ�
	void SetRotation(Vector3 _Rotation);	// �p�x�ݒ�
	void SetScale(Vector3 _Scale);			// �傫���ݒ�
	Vector3 GetPosition(void);
	Vector3 GetRotation(void);
	Vector3 GetScale(void);
	Matrix ConvertMatrix(void);		// Transform�̊e�l���������킹�ă��[���h�s��ɕϊ�
protected:
	Vector3 m_Position;	// ���W
	Vector3 m_Rotation;	// �p�x
	Vector3 m_Scale;	// �傫��
};

