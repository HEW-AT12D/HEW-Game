#pragma once
#include "../../Framework/Precompiled/pch.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/WICTextureLoader/WICTextureLoader.h" // �e�N�X�`���ǂݍ��݃��C�u����

/// <summary>
/// ��{�ƂȂ�Q�[���I�u�W�F�N�g�N���X
/// �E��U�R���|�[�l���g�w���ł͂Ȃ��I�u�W�F�N�g�w���Ŏ~�߂Ă���
/// �E���̃N���X�����������Ă���]�T������΃R���|�[�l���g�w���Ɉڍs����
/// </summary>

class GameObject:public Transform {
private:
	// ���_�f�[�^
	Vertex vertexList[4] =
	{
		//   x     y    z       r    g    b    a     u    v
		{ -0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,0.0f},  // 0�Ԗڂ̒��_���W
		{  0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f},  // 1�Ԗڂ̒��_���W
		{ -0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f},  // 2�Ԗڂ̒��_���W
		{  0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f},  // 3�Ԗڂ̒��_���W
	};

	// ���W
	//DirectX::XMFLOAT3 pos = { 0.0f, 0.0f, 0.0f };
	
	// �傫��
	//DirectX::XMFLOAT3 size = { 100.0f, 100.0f, 0.0f };
	
	// �p�x
	float angle = 0.0f;
	// �F
	DirectX::XMFLOAT4 color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// ���_�o�b�t�@
	ID3D11Buffer* m_pVertexBuffer;
	// �e�N�X�`���p�ϐ�
	ID3D11ShaderResourceView* m_pTextureView;

	//�e�N�X�`�����c���ɉ���������Ă��邩
	int splitX = 1;
	int splitY = 1;

public:
	//���ォ�牽�i�ڂ�؂蔲���ĕ\�����邩
	float numU = 0;
	float numV = 0;

	void Init(const wchar_t* imgname, int sx = 1, int sy = 1); //������
	void Draw();                             //�`��
	void Uninit();                           //�I��
	void SetPos(float x, float y, float z);  //���W���Z�b�g
	void SetSize(float x, float y, float z); //�傫�����Z�b�g
	void SetAngle(float a);                  //�p�x���Z�b�g
	void SetColor(float r, float g, float b, float a); //�F���Z�b�g

	DirectX::XMFLOAT3 GetPos(void);  //���W���Q�b�g
	DirectX::XMFLOAT3 GetSize(void); //�傫�����Q�b�g
	float GetAngle(void);            //�p�x���Q�b�g
	DirectX::XMFLOAT4 GetColor(void);//�F���Q�b�g
};
