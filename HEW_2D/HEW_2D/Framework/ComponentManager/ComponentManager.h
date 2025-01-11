#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief コンポーネント管理クラス
 * 
 * コンポーネントどう管理する？
 * 
*/
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	/**
	 * @brief コンポーネント追加関数
	 * @tparam T コンポーネント
	 * 
	 * mapにコンポーネントを追加
	 * 同じコンポーネントが既に存在していたらエラー出したい
	*/
	template <typename T>
	void AddComponent(void) 
	{
		// 指定したコンポーネントをmapに追加
		auto component = std::make_shared<T>();
		// 既に同じコンポーネントが存在していればエラー出力
		if (m_Components.find(std::type_index(component)) != m_Components.end())
		{
			cerr << "同一コンポーネントが既に存在しています" << endl;
		}
		else
		{
			// なければ初期化して追加
			
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