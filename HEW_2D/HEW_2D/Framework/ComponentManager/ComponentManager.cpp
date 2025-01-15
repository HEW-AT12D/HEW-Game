#include "ComponentManager.h"
#include "../Component/Transform/TransformComponent.h"


/**
 * @brief ������
*/
void ComponentManager::Init(void)
{
	// Transform������ǉ�
	auto pt = AddComponent<TransformComponent>();
	// �I�u�W�F�N�g���A�^�b�`
	pt.lock()->SetOwner(m_Owner);
	// ������
	for (auto& component : m_Components) {
		component.second->Init();
	}
}

/**
 * @brief �X�V 
*/
void ComponentManager::Update(void)
{
	for (auto& component : m_Components)
	{
		component.second->Update();
	}
}

/**
 * @brief �I�� 
*/
void ComponentManager::Uninit(void)
{
	for (auto& component : m_Components)
	{
		component.second->Uninit();
	}
}
