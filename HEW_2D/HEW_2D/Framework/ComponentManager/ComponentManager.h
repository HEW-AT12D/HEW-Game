#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief コンポーネント管理クラス
 * 
 * コンポーネントどう管理する？
*/
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	/**
	 * @brief コンポーネント追加関数
	 * @tparam T コンポーネント
	 * mapにコンポーネントを追加
	 * 同じコンポーネントが既に存在していたらエラー出したい
	*/
	template <class T>
	void AddComponent(void) 
	{
		// !指定したコンポーネントをmapに追加
		auto component = std::make_shared<T>();
		// !既に同じコンポーネントが存在していれば
		if (m_Components.find(std::type_index(component)) != m_Components.end())
		{
			//! エラー
			throw std::runtime_error("同一コンポーネントが既に存在しています");
		}

		// !なければ初期化して追加
		component->Init();
		m_Components.emplace(std::type_index(typeid(T), component);

		// コンポーネントのポインタを返してもいいかも？
	}

	/**
	 * @brief コンポーネント取得関数
	 * @tparam T コンポーネントの型
	 * @return コンポーネントのポインタ
	*/
	template <class T>
	T* GetComponent(T)
	{
		// コンポーネント内を探索
		for (auto& component : m_Components)
		{
			//! 既に同じコンポーネントが存在していれば→指定した型にキャストできれば
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! そのコンポーネントのポインタを返す
				return comp;
			}
		}
	}

	/**
	 * @brief オブジェクトのコンポーネントをすべて取得する関数
	 * @tparam T 
	 * @param  
	 * @return 全てのコンポーネント
	*/
	/*template <class T>
	std::vector<IComponent*> GetComponents(T)
	{
		
	}*/

private:
	//!	コンポーネントの型をキーにしてコンポーネントのポインタを保持しておく→１つのオブジェクトは同じコンポーネントは一種類しか持てない
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}