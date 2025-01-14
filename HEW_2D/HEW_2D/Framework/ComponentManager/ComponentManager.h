#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief �R���|�[�l���g�Ǘ��N���X
 * 
 * �R���|�[�l���g�ǂ��Ǘ�����H
*/
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	/**
	 * @brief �R���|�[�l���g�ǉ��֐�
	 * @tparam T �R���|�[�l���g
	 * map�ɃR���|�[�l���g��ǉ�
	 * �����R���|�[�l���g�����ɑ��݂��Ă�����G���[�o������
	*/
	template <class T>
	void AddComponent(void) 
	{
		// !�w�肵���R���|�[�l���g��map�ɒǉ�
		auto component = std::make_shared<T>();
		// !���ɓ����R���|�[�l���g�����݂��Ă����
		if (m_Components.find(std::type_index(component)) != m_Components.end())
		{
			//! �G���[
			throw std::runtime_error("����R���|�[�l���g�����ɑ��݂��Ă��܂�");
		}

		// !�Ȃ���Ώ��������Ēǉ�
		component->Init();
		m_Components.emplace(std::type_index(typeid(T), component);

		// �R���|�[�l���g�̃|�C���^��Ԃ��Ă����������H
	}

	/**
	 * @brief �R���|�[�l���g�擾�֐�
	 * @tparam T �R���|�[�l���g�̌^
	 * @return �R���|�[�l���g�̃|�C���^
	*/
	template <class T>
	T* GetComponent(T)
	{
		// �R���|�[�l���g����T��
		for (auto& component : m_Components)
		{
			//! ���ɓ����R���|�[�l���g�����݂��Ă���΁��w�肵���^�ɃL���X�g�ł����
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! ���̃R���|�[�l���g�̃|�C���^��Ԃ�
				return comp;
			}
		}
	}

	/**
	 * @brief �I�u�W�F�N�g�̃R���|�[�l���g�����ׂĎ擾����֐�
	 * @tparam T 
	 * @param  
	 * @return �S�ẴR���|�[�l���g
	*/
	/*template <class T>
	std::vector<IComponent*> GetComponents(T)
	{
		
	}*/

private:
	//!	�R���|�[�l���g�̌^���L�[�ɂ��ăR���|�[�l���g�̃|�C���^��ێ����Ă������P�̃I�u�W�F�N�g�͓����R���|�[�l���g�͈��ނ������ĂȂ�
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}