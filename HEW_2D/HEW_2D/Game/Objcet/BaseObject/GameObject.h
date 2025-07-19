#pragma once
#include "../../EntryPoint/main.h"
#include "../../../Framework/D3D11/D3D11.h"
#include "../../../Framework/WICTextureLoader/WICTextureLoader.h"	// �e�N�X�`���ǂݍ��݃��C�u����
#include "../../../Framework/Component/Transform/Transform.h"		//Transform.h�ǂݍ���
#include "../../../Framework/Sound/Sound.h"

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
/// </summary> 

/**
 * @brief �I�u�W�F�N�g�Ǘ��^�O
*/
enum Tag {
	NONE = -1,	// �^�O�Ȃ�
	BACKGROUND,
	IMAGE,
	UI,
	OBJECT,
	GROUND,
	ONOMATOPOEIA,
	PLAYER,
	ENEMY,
	CAMERA,
	Doon
};

// �I�u�W�F�N�g�̏�ԁi�����ɑS�������o���Ă����j
enum ANIMATIONSTATE
{
	NORMAL,		// �ʏ펞
	RUN,		// �ړ���
	LEFTRUN,	// ���ړ�
	JUMP,		// �W�����v��
	LEFTJUMP,	// ���W�����v
	DAMAGED,	// ��_����
	ATTACKED,	// �U����
	EFECT,      // �G�t�F�N�g
};

class IOnomatopoeia;

/**
 * @brief ��{�ƂȂ�Q�[���I�u�W�F�N�g�N���X
 * 
 * std::enable_shared_from_this:���g��shared_ptr�𐶐����邽�߂ɕK�v
 * 
 * ��U�R���|�[�l���g�w���ł͂Ȃ��I�u�W�F�N�g�w���Ŏ~�߂Ă���
 * @param vertices ���_�f�[�^
 * @param d3d11 d3d�N���X�̃|�C���^�i�`��Ɏg�p�j
 * @param transform �g�����X�t�H�[���i���W�A��]�A�傫���j
 * @param color �F���
 * 
*/
class GameObject
{
public:
	// ���x(����͖��t���[���ω�����l)
	Vector3 m_Velocity;
	Vector3 m_Direction;
	// �e�I�u�W�F�N�g�̃|�C���^
	GameObject* m_pParent = nullptr;	// �e�͈�������ĂȂ��̂Ń|�C���^�ŗǂ�
	// �q�I�u�W�F�N�g�̃|�C���^
	std::vector<GameObject*> m_pChildren;		// �q�͕������݂���\��������̂�vector

	//// �^�O(�I�u�W�F�N�g�̕���)
	Tag m_Tag;

	ConstBuffer cb;
	//Tag tag;

	//GameObject() = default;	// �N���X�̃����o�ϐ��ɎQ�Ƃ������Ă���ꍇ�A�f�t�H���g�R���X�g���N�^���g���Ȃ��i���������K�{�ƂȂ�j
	GameObject(D3D11& _D3d11, Sound* _sound = nullptr);
	virtual ~GameObject();

	virtual void Init(const wchar_t* imgname, int sx = 1, int sy = 1, bool _animation = false); // ������
	virtual void Update(void);						// �X�V�i���I�u�W�F�N�g�Ɂh�����h�������������肾�������Ŋm�F�j
	virtual void Draw(void);						// �`��
	virtual void Uninit(void);						// �I��
	virtual void SetPosition(Vector3 _Pos);			// ���W���Z�b�g
	virtual void SetScale(Vector3 _Size);			// �傫�����Z�b�g
	virtual void SetRotation(Vector3 _Rot);			// �p�x���Z�b�g
	virtual void SetColor(const Color _Color);	// �F���Z�b�g
	virtual void SetUV(const XMINT2 _UV);			// UV���W���Z�b�g
	virtual void Animation(ANIMATIONSTATE, GameObject*);		// �A�j���[�V����
	// TODO:2025/01/24 �ԍ�:�v���C���[�ɐe�q�֌W����������ۂ̊֐��̈����Ƀ^�O�Ɩ��O������悤�ɕύX���遨�v���C���[���ŃI�[�o�[���C�h���āA�^�O���}�K�W���ł���΃^�O��ύX�A�ɂ��悤�Ǝv�������A���ꂾ�ƃI�u�W�F�N�g�}�l�[�W���̊Ǘ��O�ł̏������������邩�����I�u�W�F�N�g�ɂ̓I�u�W�F�N�g�̃|�C���^���������������ق����ǂ�����
	virtual void SetParent(GameObject* _Parent);	// �e�I�u�W�F�N�g���Z�b�g
	virtual void AddForce(const Vector3 _Vel);		// ���x���Z�b�g(�����ł͑����ɒl�����Z������@������遨unity��forcemode.impulse�݂����Ȃ��)
	virtual void SetDirection(Vector3 _Dir);		// �����x�N�g�����Z�b�g
	virtual void SetOnGround(bool _flg);			// �ڒn���Ă��邩�H
	virtual void SetIsDelete(bool _flg);			// �폜�\��Z�b�g
	virtual void SetChild(GameObject* _Child);		// �q�I�u�W�F�N�g���Z�b�g

	// �ʂ̓����蔻��������ɒǉ��H�I�u�W�F�N�g�̊�{�ƂȂ�N���X�Ȃ炱������Ȃ��āA���肪�K�v�ȃI�u�W�F�N�g�ɂ��ꂼ��ǉ��H

	virtual Vector3 GetPosition(void);		// ���W���擾
	virtual Vector3 GetScale(void);			// �傫�����擾
	virtual Vector3 GetRotation(void);		// �p�x���擾
	virtual Color GetColor(void);			// �F���擾
	virtual XMINT2 GetUV(void);				// UV���W���擾
	virtual Vector3 GetVelocity(void);		// ���x���擾
	virtual Vector3 GetDirection(void);		// �����x�N�g�����擾
	virtual bool GetOnGround(void);         //�f�o�b�N�p

protected:
	//! ���_�f�[�^
	//! ���̃Q�[���ł͋[�����z�����ނ��Ƃ����邽�ߒ��_���ςɂ��Ă���
	std::vector<Vertex> vertices;
	
	// d3d�N���X
	D3D11& D3d11;

	// ���W,�傫��,�p�x
	Transform transform;
	
	// �F
	Color m_Color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// �T�E���h�Đ��p�|�C���^(DI:�K�v�ɉ����ăA�^�b�`����̂Ń|�C���^�Ǘ�)
	Sound* m_pSound = nullptr;

	// ���_�o�b�t�@
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	
	// �e�N�X�`���p�ϐ�
	ID3D11ShaderResourceView* m_pTextureView = nullptr;

	//�e�N�X�`�����c���ɉ���������Ă��邩
	XMINT2 m_Split = { 1,1 };
	
	//���ォ�牽�i�ڂ�؂蔲���ĕ\�����邩
	XMINT2 m_Number = { 0,0 };

	// �A�j���[�V�����p��ԊǗ��ϐ�
	ANIMATIONSTATE m_AnimState = {};

	// �A�j���[�V�����Ǘ��t���O
	bool IsAnimation = false;

	// �ڒn���Ă��邩�H
	bool OnGround = false;

	// �폜�\��t���O(���t���[�����̃t���O���m�F���A�����Ă���I�u�W�F�N�g�͍폜����)
	bool IsDelete = false;
	

	// �����x(���ꂼ��̎��̕����̉����x(�d�͂Ƃ�)��ݒ聨���t���[�����̒l(�������Ǝ���)����Z�����l�𑬓x�ɑ������A�Ƃ����悤�Ɏg��)
	//Vector3 m_Acceleration;�����x����Z�o�ł���̂ł���Ȃ�

	// �t�^����Ă���[���̃|�C���^
	IOnomatopoeia* m_pAttachedOnomatopoeia;

	//// ���O(��ӂ̂���)
	//std::string m_Name;
};
