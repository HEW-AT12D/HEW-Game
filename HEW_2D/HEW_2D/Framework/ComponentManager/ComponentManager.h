#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief �R���|�[�l���g�Ǘ��N���X
 *
 * �R���|�[�l���g�ǂ��Ǘ�����H
 *
*/
class ComponentManager
{
public:
	ComponentManager(GameObject& _Owner) :m_Owner(_Owner) {

	}

	~ComponentManager() {
		Uninit();
	};

	//-----------------------
	//-----�e���v���[�g�֐�-----
	//-----------------------

	/**
	 * @brief �R���|�[�l���g�ǉ��֐�
	 * @tparam T �R���|�[�l���g
	 * @return �R���|�[�l���g��weak_ptr���Ԃ�������lock()�֐����g��Ȃ��ƃ|�C���^���g���Ȃ�
	*/
	template <class T>
	std::weak_ptr<T> AddComponent(void)
	{
		//! �R���|�[�l���g�̃|�C���^�𐶐�
		auto component = std::make_shared<T>();
		//! ���������R���|�[�l���g�����ɑ��݂��Ă����
		if (m_Components.find(std::type_index(typeid(T))) != m_Components.end())
		{
			throw std::runtime_error("����R���|�[�l���g�����ɑ��݂��Ă��܂�");
		}
		//! �Ȃ���΃R���|�[�l���g�ɒǉ�
		component->Init();
		m_Components.emplace(std::type_index(typeid(T)), component);
		//! �R���|�[�l���g�̃|�C���^��Ԃ�
		return std::weak_ptr<T>(component);
	}


	/**
	 * @brief �R���|�[�l���g�擾�֐�
	 * @tparam T �R���|�[�l���g�̌^
	 * @return �R���|�[�l���g�̃|�C���^
	*/
	template <class T>
	std::shared_ptr<T> GetComponent(void)
	{
		//! ���̃R���|�[�l���g�����݂��Ă��邩��T��
		for (auto& component : m_Components)
		{
			// ���̃R���|�[�l���g�̌^�ɃL���X�g�ł����
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! �R���|�[�l���g�̃|�C���^��Ԃ�
				return std::shared_ptr<T>(component.second, comp);
			}
		}
		//! �Ȃ���΃G���[�o��
		std::cerr << typeid(T).name() << "��ێ����Ă��܂���" << std::endl;
	}

	void Init(void);
	//! Draw�͕`��@�\�����R���|�[�l���g���S������̂ł����ɂ͒u���Ȃ�
	void Update(void);
	void Uninit(void);

private:
	//! �A�^�b�`���Ă���I�u�W�F�N�g�̎Q�Ɓ��A�^�b�`��̃I�u�W�F�N�g�͕K�����݂��Ă��Ȃ��Ƃ����Ȃ�����
	GameObject& m_Owner;
	//! �R���|�[�l���g�̌^�ƃ|�C���^���Z�b�g��map�ɕێ�
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};



