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
	ComponentManager();
	~ComponentManager();

	/**
	 * @brief �R���|�[�l���g�ǉ��֐�
	 * @tparam T �R���|�[�l���g
	 * 
	 * map�ɃR���|�[�l���g��ǉ�
	 * �����R���|�[�l���g�����ɑ��݂��Ă�����G���[�o������
	*/
	template <typename T>
	void AddComponent(void) 
	{
		// �w�肵���R���|�[�l���g��map�ɒǉ�
		auto component = std::make_shared<T>();
		// ���ɓ����R���|�[�l���g�����݂��Ă���΃G���[�o��
		if (m_Components.find(std::type_index(component)) != m_Components.end())
		{
			cerr << "����R���|�[�l���g�����ɑ��݂��Ă��܂�" << endl;
		}
		else
		{
			// �Ȃ���Ώ��������Ēǉ�
			
			m_Components.emplace(component);
		}


	}

private:
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}