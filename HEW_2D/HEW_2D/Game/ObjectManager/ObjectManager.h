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
	IMAGE,
	UI,
	OBJECT,
	PLAYER,
	ENEMY,
};


/**
 * @brief �I�u�W�F�N�g��map���Ǘ����邽�߂Ɏg��std::pair�̓��map�ɕR�Â���֐�
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
	 * �ǉ�����make_pair���������Ɉ�������������œ��삳���������֐����ň�����̌^���m�F���A��̌^��Tag��string�ł����make_pair����map�ɒǉ�����
	*/
	template <typename T>
	void AddObject(const Tag& _Tag, std::string _Name)
	{
		// ����̃^�O�Ɩ��O�����I�u�W�F�N�g�����݂���ꍇ�ɂ̓G���[���o���悤�ɂ���
		// ���O����̏ꍇ�͒ǉ����Ȃ�
		if (_Name.empty()) {
			std::cerr << "�I�u�W�F�N�g�ɖ��O���ݒ肳��Ă��܂���" << std::endl;
			return; // �����Ȗ��O�̏ꍇ�͒ǉ����Ȃ�
		}

		// ���O������΂Ƃ肠�����L�[�Ƃ��č쐬
		std::pair key = std::make_pair(_Tag, _Name);
		// �L�[�Ɠ����I�u�W�F�N�g��end����Ȃ������������ꍇ�A�G���[�o��
		if (Objects.find(key) != Objects.end())
		{
			std::cerr << "����^�O�Ɩ��O�����I�u�W�F�N�g�����ɑ��݂��Ă��܂�" << std::endl;
			return; // ���łɓ����L�[�����݂���ꍇ�͒ǉ����Ȃ�
		}

		// ����ł���΃L�[�ƃI�u�W�F�N�g���Z�b�g�Œǉ�
		Objects.emplace(std::move(key), std::make_unique<T>(D3d11));
	}


	// TODO:12/19�����܂ŁB�����ǉ��֐��͈�U������߂Ĉ���ǉ�����
	/**
	 * @brief �I�u�W�F�N�g�����ǉ��֐�
	 * @tparam ...Ts �ǉ�����I�u�W�F�N�g�̌^�i�����ł�ok�j
	 * @tparam ...Args �I�u�W�F�N�g�̃^�O�Ɩ��O
	 * @param ..._Tag_and_Name ������
	*/
	template <typename... Ts>
	void AddObject(std::pair<Tag, std::string>&&... _Tag_and_Name) {
		// �L�[�Ɩ��O�̐����������̊m�F�i��������Ȃ��ꍇ�A�v���O�����͎��s���ꂸ�G���[���o��j, typename... Args
		static_assert(sizeof...(Ts) == sizeof...(_Tag_and_Name), "�L�[(�^�O)�̐��ƒǉ��������I�u�W�F�N�g�̐����Ⴂ�܂�");

		// ��������̓n�������ǂ��������Fpair������Ă���n�����ق�������

		//! std::forward�ň����̌^�ƈ������̂��̂����̂܂ܓn���Ă���
		//! map�ɒǉ�		�^�O�Ɩ��O		�w�肵���^�̃I�u�W�F�N�g�̃C���X�^���X�����j�[�N�|�C���^�ō쐬(D3D11�N���X�̎Q�Ƃ�n��)
		(Objects.emplace(std::move(_Tag_and_Name), std::make_unique<Ts>(D3d11)), ...);
		(Objects.emplace(std::forward<std::pair<Tag, std::string>>(_Tag_and_Name), std::make_unique<Ts>(D3d11)), ...);
	}

	/**
	 * @brief �I�u�W�F�N�g�폜�֐�
	 * @param object �폜�ΏۃI�u�W�F�N�g
	*/
	void DeleteObject(Tag _ObjTag);

	// �I�u�W�F�N�g�擾�֐�
	GameObject* GetGameObject(const Tag& _Tag, const std::string _Name);


	/**
	 * @brief �I�u�W�F�N�g�̐���Ԃ��֐�
	 * @return �I�u�W�F�N�g��
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

