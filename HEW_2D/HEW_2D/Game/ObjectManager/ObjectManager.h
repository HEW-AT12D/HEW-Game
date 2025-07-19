#pragma once
#include "../EntryPoint/main.h"
#include "../../Game/Objcet/BaseObject/GameObject.h"
#include "../Objcet/Player/Player.h"
#include "../Objcet/SoundGun/SoundGun.h"
#include "../Objcet/Camera/Camera.h"

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
	ObjectManager(D3D11& _D3d11, Sound& _sound) : D3d11(_D3d11), SoundRef(_sound) {

	}
	~ObjectManager() {};

	/**
	 * @brief �I�u�W�F�N�g�ʒǉ��֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @param _SceneName
	 * �ǉ�����make_pair���������Ɉ�������������œ��삳���������֐����ň�����̌^���m�F���A��̌^��Tag��string�ł����make_pair����map�ɒǉ�����
	*/
	template <typename T>
	void AddObject(const Tag& _Tag, const std::string& _Name, bool _hasSound = false)
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

		// ����ł���΃L�[�ƃI�u�W�F�N�g���Z�b�g�Œǉ�(�������I�u�W�F�N�g�Ȃ�T�E���h�N���X�𒍓�����)
		std::unique_ptr<T> obj;
		if (_hasSound) {
			obj = std::make_unique<T>(D3d11, &SoundRef);
		}
		else {
			obj = std::make_unique<T>(D3d11);
		}
		Objects.emplace(std::move(key), std::move(obj));
	}

	/**
	 * @brief �w�肵���^�O�̃I�u�W�F�N�g��vector�œn���Ēǉ�����֐�
	*/
	template <typename T>
	void AddObject(Tag _Tag, std::vector<T*> _Objects)
	{
		// �����̒������I�u�W�F�N�g�ǉ��֐�����
		for (auto&& object : _Objects)
		{
			AddObject<T>(_Tag, object);
		}
	}

	/**
	 * @brief �I�u�W�F�N�g�����ǉ��֐�
	 * @tparam T ��������I�u�W�F�N�g�̌^
	 * @tparam ...Keys �󂯎��L�[�̌^�istd::pair<Tag, std::string>��z��j
	 * @param ...keys ���ۂɎ󂯎�����
	*/
	template <typename T, typename ...Keys>
	void AddObjects(Keys&&... keys)
	{
		(AddObject<T>(std::forward<Keys>(keys).first, std::forward<Keys>(keys).second), ...);
	}

	/**
	 * @brief �I�u�W�F�N�g�擾�֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @param _tag �^�O
	 * @param _name ���O
	 * @return map�ɓo�^����Ă�����(�^�O�Ɩ��O���Z�b�g�ɂȂ������)�ł̃I�u�W�F�N�g
	*/
	template <class T>
	std::pair<const std::pair<Tag, std::string>, T*> GetGameObject(const Tag& _tag, const std::string& _name)
	{
		// ���O�ƃ^�O�����I�u�W�F�N�g��T��
		//std::pair<std::pair<Tag, std::string>, std::shared_ptr<T>> retobj;
		for (auto& obj : Objects)
		{
			// ���O�ƃ^�O����v�����
			if (obj.first.first == _tag && obj.first.second == _name)
			{
				// �_�E���L���X�g�����݂�
				auto castedObj = dynamic_cast<T*>(obj.second.get());
				if (castedObj)
				{
					// �L���X�g�������A�K�؂ɕԂ�
					return std::make_pair(obj.first, castedObj);
				}
				else
				{
					// �L���X�g���s���̏����i��O�𓊂���A�������̓G���[�n���h�����O�j
					throw std::runtime_error("�w�肵���I�u�W�F�N�g�̌^�ɃL���X�g�ł��܂���ł���");
				}
			}
		}
		// ��v����I�u�W�F�N�g��������Ȃ��ꍇ
		throw std::runtime_error("�w�肳�ꂽ�^�O�Ɩ��O�̃I�u�W�F�N�g��������܂���ł���");
	}

	/**
	 * @brief	�I�u�W�F�N�g��z��Ŏ擾����֐�
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @param  �I�u�W�F�N�g�̃^�O
	 * @return �^�O�Ŏw�肵���I�u�W�F�N�g���}�l�[�W���ɓo�^������Ԃ�vector�ɂ�������
	*/
	template <class T>
	std::vector<std::pair<std::pair<Tag, std::string>, T*>> GetGameObjectPair(const Tag& _tag)
	{
		std::vector<std::pair<std::pair<Tag, std::string>, T*>> returnobjects;
		// map����T��
		for (auto& obj : Objects)
		{
			// �^�O��������
			if (obj.first.first == _tag)
			{
				// �L���X�g�ł���Ȃ�L���X�g���Ĕz��Ɋi�[
				if (auto casted = dynamic_cast<T*>(obj.second.get()))
				{
					//returnobjects.emplace_back(obj.first, casted);
					returnobjects.emplace_back(std::make_pair(std::pair<Tag, std::string>(obj.first), casted));
				}
				// ���N���X�Ȃ炻�̂܂܊i�[
				else
				{
					//returnobjects.emplace_back(obj.first, static_cast<T*>(obj.second.get()));
					returnobjects.emplace_back(std::pair<std::pair<Tag, std::string>, T*>{ obj.first, static_cast<T*>(obj.second.get()) });
				}
			}
		}
		return returnobjects;
	}

	//�^�O�Ɩ��O
	template <class T>
	std::vector<std::pair<std::pair<Tag, std::string>, T*>> GetGameObjectPair2(const Tag& _tag, std::string _name)
	{
		std::vector<std::pair<std::pair<Tag, std::string>, T*>> returnobjects;
		// map����T��
		for (auto& obj : Objects)
		{
			// �^�O�Ɩ��O����v���Ă��邩�m�F
			if (obj.first.first == _tag && obj.first.second == _name)
			{
				if (auto casted = dynamic_cast<T*>(obj.second.get()))
				{
					returnobjects.emplace_back(std::pair<std::pair<Tag, std::string>, T*>{ {obj.first.first, obj.first.second}, casted });
				}
				else
				{
					returnobjects.emplace_back(std::pair<std::pair<Tag, std::string>, T*>{ {obj.first.first, obj.first.second}, static_cast<T*>(obj.second.get()) });
				}
			}
		}
		return returnobjects;
	}


	/**
	 * @brief �I�u�W�F�N�g�擾�֐�(�^�O�A�^�w�肵�ăI�u�W�F�N�g���̂��̂�weak_ptr��Ԃ�)
	 * @tparam T �I�u�W�F�N�g�̌^
	 * @param _tag �I�u�W�F�N�g�^�O
	 * @return �w�肵���^�E�^�O�Ɠ���̏������I�u�W�F�N�g�̔z��
	 *
	 * 2025/01/22 �ԍ��F���O�U��悤�ɍ�������ǂ��̎d�g�݂܂����ĂȂ�����g��Ȃ������I�I
	*/
	template <class T>
	std::vector<T*> GetObjects(Tag _tag)
	{
		// �I�u�W�F�N�g�ۑ��p�R���e�i
		std::vector<T*> objects;
		for (auto& obj : Objects)
		{
			// �^�O���������𒲂ׁA
			if (obj.first.first == _tag)
			{
				auto casted = dynamic_cast<T*>(obj.second.get());
				// dynamic_pointer_cast�Ō^�`�F�b�N���A�^�������ł���Δz��ɒǉ�
				if (casted) {
					objects.push_back(casted);
				}
			}
		}
		return objects;
	}

	/**
	 * @brief �I�u�W�F�N�g�폜�֐�
	 * @param object �폜�ΏۃI�u�W�F�N�g
	*/
	void DeleteObject(Tag _ObjTag, const std::string& objString);

	/**
	 * @brief �I�u�W�F�N�g�擾�֐�(weak_ptr��Ԃ�)
	 * @param _Tag �I�u�W�F�N�g�^�O
	 * @param _Name �t����
	 * @return �I�u�W�F�N�g�̐��|�C���^(�^�O�̌^�ɃL���X�g���Ă���Ԃ�)
	*/
	template <class T>
	T* GetGameObjectPtr(const Tag& _Tag, const std::string& _Name)
	{
		// �^�O�Ɩ��O�̈�v����I�u�W�F�N�g��������(������Ȃ��ꍇ��end()���Ԃ��Ă���)
		auto iterator = Objects.find(std::make_pair(_Tag, _Name));
		// ���������ꍇ
		if (iterator != Objects.end())
		{
			// �|�C���^���擾���Č^�ɍ��킹�Ĉ�xshared_ptr�ɃL���X�g
			T* castedptr = dynamic_cast<T*>(iterator->second.get());

			// �L���X�g�����������ꍇ(nullptr�ł͂Ȃ��ꍇ)
			if (castedptr)
			{
				// �|�C���^��Ԃ�(�����Ŏ����I��weak_ptr�ɕϊ������)
				return castedptr;
			}
		}
		// ������Ȃ���΋��weak_ptr��Ԃ�
		return nullptr;
	}

	// �S�I�u�W�F�N�g���擾����
	std::vector<std::pair<std::pair<Tag, std::string>, GameObject*>> GetAllObjects(void);
	// �v���C���[���ӂ̋[�����擾����
	std::vector<std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>> GetOnomatopoeiaAroundPlayer(void);

	// �J����������΂��̃|�C���^��Ԃ��֐�
	Camera* HasCamera(void);

	/**
	 * @brief �^�O�ύX�֐�
	 * @param _tag
	 * @param _name
	 * @param _newTag
	 * @return
	*/
	bool ChangeTag(Tag _tag, const std::string _name, Tag _newTag);

	// �����蔻��m�F&�ꍇ���������������s���֐�
	void Collider_Player_to_Object(void);

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	//! �I�u�W�F�N�g�̊Ǘ��̓^�O�i��܂��ȕ��ށj�Ɩ��O�i��ӂ̂��́j���g��
	// unordered_map��pair���g���ꍇ�Apair�̕R�Â��Ȃ��Ƃ����Ȃ�����PairHash��map�̈����ɓ����
	std::unordered_map<std::pair<Tag, std::string>, std::unique_ptr<GameObject>, PairHash> Objects;
	D3D11& D3d11;
	Sound& SoundRef; // Sound�N���X�̎Q�Ƃ�ێ�(�I�u�W�F�N�g�������Ɏg�p)
};