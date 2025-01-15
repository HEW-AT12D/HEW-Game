#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief コンポーネント管理クラス
 * 
 * コンポーネントどう管理する？→shared_ptrで管理
 * 
 * このクラスで持つべきもの
 * このクラスを保持する親オブジェクトのポインタ
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
	 * mapにコンポーネントを追加
	 * 同じコンポーネントが既に存在していたらエラー出したい
	*/

	/**
	 * @brief コンポーネント追加関数
	 * @tparam T コンポーネント
	 * @param  
	 * @return コンポーネントのweak_ptr→もし使う場合はlock()をつかってshared_ptrに変換してから使う(参照カウントは増えないので大丈夫)
	*/
	template <class T>
	std::weak_ptr<T> AddComponent(void) 
	{
		// !指定したコンポーネントをmapに追加
		auto component = std::make_shared<T>();
		// !既に同じコンポーネントが存在していれば
		if (m_Components.find(std::type_index(typeid(T))) != m_Components.end())
		{
			//! エラー
			throw std::runtime_error("同一コンポーネントが既に存在しています");
		}

		// !なければ初期化して追加
		component->Init();
		m_Components.emplace(std::type_index(typeid(T)), component);

		// 使う使わないは置いておいて、コンポーネントのポインタを返してもいいかも？
		// →shared_ptrを返すと変に所有者が増加する可能性があるので、weak_ptrを返す
		return std::weak_ptr<T>(component);
	}

	/**
	 * @brief コンポーネント取得関数
	 * @tparam T コンポーネントの型
	 * @return コンポーネントのポインタ
	 * 
	 * weak_ptrで取得する関数あってもいいかも
	*/
	template <class T>
	std::shared_ptr<T> GetComponent(void)
	{
		// コンポーネント内を探索
		for (auto& component : m_Components)
		{
			//! 既に同じコンポーネントが存在していれば→指定した型にキャストできれば
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! そのコンポーネントのポインタを返す
				return std::shared_ptr<T>(component.second, comp);
			}
		}
		// コンポーネントが存在しなければエラー出力
		std::cerr<< typeid(T).name() << "を持っていません" <<std::endl;
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

	//-----------------------
	//--------通常関数--------
	//-----------------------
	void Init(void);	// 所有するオブジェクトのポインタをどう渡すか→コンストラクタ？関数？
	void Update(void);
	void Uninit(void);


private:
	//! コンポーネントマネージャを保持するオブジェクトの参照（コンポーネントを持つオブジェクトは必ず存在していなければいけないため）
	GameObject& m_Owner;
	//!	コンポーネントの型をキーにしてコンポーネントのポインタを保持しておく→１つのオブジェクトは同じコンポーネントは一種類しか持てない
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};


