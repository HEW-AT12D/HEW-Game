#pragma once
#include "../../Precompiled/pch.h"

// TODO 2024/10/4 ����Transform�N���X�̕ϐ�transform���AIComponent���p������TransformComponent�H�Ƃ��Ɏ������遨Transform�����I�I�i�J���[�Ƃ������x���Ăǂ��ł���H�j
// �N���X�e���v���[�g�Ƃ��W�����C�u�����A�X�}�[�g�|�C���^�̕׋����K�v���� std::vector�Ƃ��ŃR���|�[�l���g���D���Ȃ��������Ƃ��ł�����

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
	Transform() :m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f), m_Scale(1.0f, 1.0f, 0.0f) {};
	~Transform();

	void SetPosition(XMFLOAT3 _Position);
	void SetRotation(XMFLOAT3 _Rotation);
	void SetScale(XMFLOAT3 _Scale);
	XMMATRIX ConvertMatrix(void);		// Transform�̊e�l���������킹�ă��[���h�s��ɕϊ�

	// �X�V����ׂ��Ȃ̂̓R���|�[�l���g�Ȃ̂ł����ɍX�V�͂���Ȃ��H
	// ��conio��vector�Ƃ��Ɠ����m���H
private:
	XMFLOAT3 m_Position = XMFLOAT3(0.0f, 0.0f, 0.0f);	// ���W
	XMFLOAT3 m_Rotation = XMFLOAT3(0.0f, 0.0f, 0.0f);	// �p�x
	XMFLOAT3 m_Scale = XMFLOAT3(0.0f, 0.0f, 0.0f);		// �傫��
};

Transform::Transform()
{
}

Transform::~Transform()
{
}

