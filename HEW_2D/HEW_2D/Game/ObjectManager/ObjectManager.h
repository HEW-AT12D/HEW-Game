#pragma once
#include "../EntryPoint/main.h"
#include "../../Game/Objcet/BaseObject/GameObject.h"

enum ObjectName {
	OBJECT,
	PLAYER,
};

/**
 * @brief �I�u�W�F�N�g���Ǘ�����N���X
*/
class ObjectManager
{
public:
	ObjectManager() = default;
	ObjectManager(D3D11& _D3d11) :D3d11(_D3d11) {

	}
	~ObjectManager() {};

	/**
	 * @brief �I�u�W�F�N�g�ʒǉ��֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @param _SceneName 
	*/
	template <typename T>
	void AddObject(ObjectName _ObjName)
	{
		// �L�[�ƃI�u�W�F�N�g���Z�b�g�Œǉ�
		Objects.emplace(_ObjName, std::make_unique<T>(d3d11));
	}

	/**
	 * @brief �I�u�W�F�N�g�ꊇ�ǉ��֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @tparam ...Args �ϒ������̌^
	 * @param ...args ������
	*/
	template <typename... Ts, typename... Args>
	void AddObject(Args&&... _ObjectsName)	// &&�Ƃ́u�E�Ӓl�Q�Ɓv�i�E�Ӓl�Ƃ�x = 10 �Ȃ� 10�̂悤�ɕϐ��ɓ�����ۂ̒l�j
	{
		//! �I�u�W�F�N�g�z��Ƀe���v���[�g�^�̃N���X�̃��j�[�N�|�C���^���i�[
		//! �����̍ۂ̃R���X�g���N�^�ɗ^��������̌^(Args)�ƁA�������Ƃ���(args)�����݂��Ă���B
		//! �@�����̏ꍇ�Astd::forward��T�̃R���X�g���N�^�Ɉ����̌^�A�����������̂܂ܓn�����߂ɋL�q����Ă���
		 
		// �L�[�Ɩ��O���Ή����Ă��邩�̊m�F�i��������Ȃ��ꍇ�A�v���O�����͎��s���ꂸ�G���[���o��j
		static_assert(sizeof...(Ts) == sizeof...(Args), "�L�[�̐��ƒǉ��������I�u�W�F�N�g�̐����Ⴂ�܂�");
		 
		//! std::forward�ňقȂ�L�[��ǉ��ł���悤�ɂ��ATs�ňقȂ�^�̃I�u�W�F�N�g��ǉ��ł���悤�ɂ��Ă���
		(Objects.emplace(std::forward<Args>(_ObjectsName), std::make_unique<Ts>(D3d11)), ...);		// �S�I�u�W�F�N�g��������d3d�̎Q�Ƃ�n��
	}

	/**
	 * @brief �I�u�W�F�N�g�폜�֐�
	 * @param object �폜�ΏۃI�u�W�F�N�g
	*/
	void DeleteObject(ObjectName _ObjName);

	/**
	 * @brief �I�u�W�F�N�g�̐���Ԃ��֐�
	 * @return �I�u�W�F�N�g��
	 * 
	 * map�ɂ��Ă邵�A����ȊO�̏ꍇ�ł��R���e�i������T�C�Y�Ԃ��K�v���邩�H
	*/
	size_t GetObjectCount(void);

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

	// �����蔻����ǉ��\��

private:
	//TODO:1216�����܂ŁI�I�u�W�F�N�g�Ǘ���map���g��&�I�u�W�F�N�g�����֐��ň�x�ŕ����̃I�u�W�F�N�g���Ăяo����悤�ɕύX����I�I
	//! �I�u�W�F�N�g�̃��j�[�N�|�C���^��map�Ŏ����I�u�W�F�N�g�}�l�[�W���[���I�u�W�F�N�g���Ǘ�����
	//! 
	//! (�����������獶�ɂ���I�u�W�F�N�g���珇�ɔz��ɕێ����Ă����������H�����̏ꍇ������x�݌v���K�v)
	std::unordered_map<ObjectName, std::unique_ptr<GameObject>> Objects;
	D3D11& D3d11;
};

