#pragma once
#include "../../EntryPoint/main.h"
#include "../../../Framework/D3D11/D3D11.h"
#include "../../../Framework/WICTextureLoader/WICTextureLoader.h"	// �e�N�X�`���ǂݍ��݃��C�u����
#include "../../../Framework/Component/Transform/Transform.h"		//Transform.h�ǂݍ���

/// <summary>
/// TODO:�I�u�W�F�N�g�̕`����@��ύX����
/// 
/// ���݁F���_�o�b�t�@�݂̂ŕ`��
/// �ڕW�F�C���f�b�N�X�o�b�t�@���g�p�����`��ɕύX
/// 
/// �ǂ��_�F���_�������L�ł���̂ŋK�͂��傫���Ȃ�΂Ȃ�قǕ`�揈���̕��ׂ�����
/// 
/// --------------���P��----------------
/// d3d�N���X�̃|�C���^���Q�ƁH���j�[�N�|�C���^�Hd3d�N���X��static���HRenderer�N���X�쐬�H
/// </summary>

/**
 * @brief ��{�ƂȂ�Q�[���I�u�W�F�N�g�N���X
 * 
 * ��U�R���|�[�l���g�w���ł͂Ȃ��I�u�W�F�N�g�w���Ŏ~�߂Ă���
 * @param vertices ���_�f�[�^
 * @param d3d11 d3d�N���X�̃|�C���^�i�`��Ɏg�p�j
 * @param transform �g�����X�t�H�[���i���W�A��]�A�傫���j
 * @param color �F���
 * 
 * 
*/
class GameObject {
protected:
	//! ���_�f�[�^
	//! ���̃Q�[���ł͋[�����z�����ނ��Ƃ����邽�ߒ��_���ςɂ��Ă���
	std::vector<Vertex> vertices;
	
	// d3d�N���X
	D3D11& D3d11;
	// ���W,�傫��,�p�x
	Transform transform;
	// �F
	Vector4 color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// ���_�o�b�t�@
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	// �e�N�X�`���p�ϐ�
	ID3D11ShaderResourceView* m_pTextureView = nullptr;

	//�e�N�X�`�����c���ɉ���������Ă��邩
	Vector2 m_Split = { 1.0f,1.0f };

	//���ォ�牽�i�ڂ�؂蔲���ĕ\�����邩
	Vector2 m_Number = { 0.0f,0.0f };

public:
	
	GameObject() = default;
	GameObject(D3D11& _D3d11);
	~GameObject();

	void Init(const wchar_t* imgname, int sx = 1, int sy = 1); // ������
	void Update(void);					// �X�V�i���I�u�W�F�N�g�Ɂh�����h�������������肾�������Ŋm�F�j
	void Draw(void);					// �`��
	void Uninit(void);					// �I��
	void SetPosition(Vector3 _Pos);		// ���W���Z�b�g
	void SetScale(Vector3 _Size);		// �傫�����Z�b�g
	void SetRotation(Vector3 _Rot);		// �p�x���Z�b�g
	void SetColor(Vector4 _Color);		// �F���Z�b�g

	// �ʂ̓����蔻��������ɒǉ��H�I�u�W�F�N�g�̊�{�ƂȂ�N���X�Ȃ炱������Ȃ��āA���肪�K�v�ȃI�u�W�F�N�g�ɂ��ꂼ��ǉ��H

	Vector3 GetPosition(void);			//���W���擾
	Vector3 GetScale(void);				//�傫�����擾
	Vector3 GetRotation(void);			//�p�x���擾
	Vector4 GetColor(void);				//�F���擾
};