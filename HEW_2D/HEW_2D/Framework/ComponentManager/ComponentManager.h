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
	ComponentManager(GameObject& _Owner) :m_Owner(_Owner) {

	}

	~ComponentManager() {
		Uninit();
	};

	//-----------------------
	//-----テンプレート関数-----
	//-----------------------

	/**
	 * @brief 
	 * @tparam T 
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
		if (m_Components.find(std::type_index(typeid(T))) != m_Components.end()) 
		{
			cerr << "同一コンポーネントが既に存在しています" << endl;
		}
		
	}

	/**
	 * @brief コンポーネント追加関数
	 * @tparam T コンポーネント
	 * @return コンポーネントのweak_ptr→返した側でlock()関数を使わないとポインタを使えない
	*/
	template <class T>
	std::weak_ptr<T> AddComponent(void)
	{
		//! コンポーネントのポインタを生成
		auto component = std::make_shared<T>();
		//! 取りつけたいコンポーネントが既に存在していれば
		if (m_Components.find(std::type_index(typeid(T))) != m_Components.end())
		{
			throw std::runtime_error("同一コンポーネントが既に存在しています");
		}
		//! なければコンポーネントに追加
		component->Init();
		m_Components.emplace(std::type_index(typeid(T)), component);
		//! コンポーネントのポインタを返す
		return std::weak_ptr<T>(component);
	}


	/**
	 * @brief コンポーネント取得関数
	 * @tparam T コンポーネントの型
	 * @param  
	 * @return 
	*/
	template <class T>
	std::shared_ptr<T> GetComponent(void)
	{
		//! そのコンポーネントが存在しているかを探索
		for (auto& component : m_Components)
		{
			// そのコンポーネントの型にキャストできれば
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! コンポーネントのポインタを返す
				return std::shared_ptr<T>(component.second, comp);
			}
		}
		//! なければエラー出力
		std::cerr << typeid(T).name() << "を保持していません" << std::endl;
	}

	void Init(void);
	//! Drawは描画機能を持つコンポーネントが担当するのでここには置かない
	void Update(void);
	void Uninit(void);

private:
	//! アタッチしているオブジェクトの参照→アタッチ先のオブジェクトは必ず存在していないといけないため
	GameObject& m_Owner;
	//! 
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};



