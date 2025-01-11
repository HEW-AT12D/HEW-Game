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
/// 
/// �I�u�W�F�N�g��������
/// �E�R���|�[�l���g�}�l�[�W��
/// �E���O
/// �E�^�O
/// 
/// 
/// </summary> 


// �I�u�W�F�N�g�̏�ԁi�����ɑS�������o���Ă����j
enum STATE
{
	NORMAL,		// �ʏ펞
	RUN,		// �ړ���
	JUMP,		// �W�����v��
	DAMAGED,	// ��_����
	ATTACKED,	// �U����
};

/**
 * @brief ��{�ƂȂ�Q�[���I�u�W�F�N�g�N���X
 * 
 * ��U�R���|�[�l���g�w���ł͂Ȃ��I�u�W�F�N�g�w���Ŏ~�߂Ă���
 * @param vertices ���_�f�[�^
 * @param d3d11 d3d�N���X�̃|�C���^�i�`��Ɏg�p�j
 * @param transform �g�����X�t�H�[���i���W�A��]�A�傫���j
 * @param color �F���
 * 
*/
class GameObject {
private:
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

	// �A�j���[�V�����p��ԊǗ��ϐ�
	STATE m_State = {};

	// �A�j���[�V�����Ǘ��t���O
	bool IsAnimation = false;

public:
	//GameObject() = default;	// �N���X�̃����o�ϐ��ɎQ�Ƃ������Ă���ꍇ�A�f�t�H���g�R���X�g���N�^���g���Ȃ��i���������K�{�ƂȂ�j
	GameObject(D3D11& _D3d11);
	virtual ~GameObject();

	virtual void Init(const wchar_t* imgname, bool _animation = false, int sx = 1, int sy = 1); // ������
	virtual void Update(void);					// �X�V�i���I�u�W�F�N�g�Ɂh�����h�������������肾�������Ŋm�F�j
	virtual void Draw(void);					// �`��
	virtual void Uninit(void);					// �I��
	virtual void SetPosition(Vector3 _Pos);		// ���W���Z�b�g
	virtual void SetScale(Vector3 _Size);		// �傫�����Z�b�g
	virtual void SetRotation(Vector3 _Rot);		// �p�x���Z�b�g
	virtual void SetColor(Vector4 _Color);		// �F���Z�b�g
	virtual void SetUV(Vector2 _UV);            // UV���W���Z�b�g
	virtual void Animation(STATE,Vector2);				// �A�j���[�V����

	// �ʂ̓����蔻��������ɒǉ��H�I�u�W�F�N�g�̊�{�ƂȂ�N���X�Ȃ炱������Ȃ��āA���肪�K�v�ȃI�u�W�F�N�g�ɂ��ꂼ��ǉ��H

	virtual Vector3 GetPosition(void);			// ���W���擾
	virtual Vector3 GetScale(void);				// �傫�����擾
	virtual Vector3 GetRotation(void);			// �p�x���擾
	virtual Vector4 GetColor(void);				// �F���擾
	virtual Vector2 GetUV(void);                // UV���W���擾
};
