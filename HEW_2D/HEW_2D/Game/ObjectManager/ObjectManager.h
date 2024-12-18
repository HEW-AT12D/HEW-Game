#pragma once
#include "../EntryPoint/main.h"
#include "../../Game/Objcet/BaseObject/GameObject.h"
#include "../Objcet/Player/Player.h"
#include "../Objcet/SoundGun/SoundGun.h"

/**
 * @brief �I�u�W�F�N�g�Ǘ��^�O
*/
enum Tag {
	BACKGROUND,
	UI,
	OBJECT,
	PLAYER,
	ENEMY,
};


/**
 * @brief �I�u�W�F�N�g��map���Ǘ����邽�߂Ɏg��std::pair�̓��R�Â���֐�
*/
struct PairHash {
	template <typename T1, typename T2>
	std::size_t operator()(const std::pair<T1, T2>& pair) const {
		auto hash1 = std::hash<T1>{}(pair.first);  // first �̃n�b�V���l
		auto hash2 = std::hash<T2>{}(pair.second); // second �̃n�b�V���l
		return hash1 ^ (hash2 << 1);               // �n�b�V���l��g�ݍ��킹��
	}
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
	void AddObject(Tag _ObjTag)
	{
		// �L�[�ƃI�u�W�F�N�g���Z�b�g�Œǉ�
		Objects.emplace(_ObjTag, std::make_unique<T>(D3d11));
	}

	/**
	 * @brief �I�u�W�F�N�g�ꊇ�ǉ��֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @tparam ...Args �I�u�W�F�N�g�̃^�O
	 * @param ...args ������
	*/
	template <typename... Ts, typename... Args>
	void AddObject(Args&&... _ObjectsTag)	// &&�Ƃ́u�E�Ӓl�Q�Ɓv�i�E�Ӓl�Ƃ�x = 10 �Ȃ� 10�̂悤�ɕϐ��ɓ�����ۂ̒l�j
	{
		//! �I�u�W�F�N�g�z��Ƀe���v���[�g�^�̃N���X�̃��j�[�N�|�C���^���i�[
		//! �����̍ۂ̃R���X�g���N�^�ɗ^��������̌^(Args)�ƁA�������Ƃ���(args)�����݂��Ă���B
		//! �@�����̏ꍇ�Astd::forward��T�̃R���X�g���N�^�Ɉ����̌^�A�����������̂܂ܓn�����߂ɋL�q����Ă���
		 
		// �L�[�Ɩ��O���Ή����Ă��邩�̊m�F�i��������Ȃ��ꍇ�A�v���O�����͎��s���ꂸ�G���[���o��j
		static_assert(sizeof...(Ts) == sizeof...(Args), "�L�[(�^�O)�̐��ƒǉ��������I�u�W�F�N�g�̐����Ⴂ�܂�");
		 
		//! std::forward�ňقȂ�L�[��ǉ��ł���悤�ɂ��ATs�ňقȂ�^�̃I�u�W�F�N�g��ǉ��ł���悤�ɂ��Ă���
		(Objects.emplace(std::forward<Args>(_ObjectsTag), std::make_unique<Ts>(D3d11)), ...);		// �S�I�u�W�F�N�g��������d3d�̎Q�Ƃ�n��
	}

	/**
	 * @brief �I�u�W�F�N�g�폜�֐�
	 * @param object �폜�ΏۃI�u�W�F�N�g
	*/
	void DeleteObject(Tag _ObjTag);

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
	//! 
	//! �I�u�W�F�N�g�̊Ǘ��̓^�O�i��܂��ȕ��ށj�Ɩ��O�i��ӂ̂��́j���g��
	
	// unordered_map��pair���g���ꍇ�Apair�̕R�Â��Ȃ��Ƃ����Ȃ�����PairHash��map�̈����ɓ����
	std::unordered_map < std::pair<Tag, std::string>, std::unique_ptr<GameObject>, PairHash > Objects;
	D3D11& D3d11;
};

