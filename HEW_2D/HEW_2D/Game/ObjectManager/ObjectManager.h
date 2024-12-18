#pragma once
#include "../EntryPoint/main.h"
#include "../../Game/Objcet/BaseObject/GameObject.h"
#include "../Objcet/Player/Player.h"
#include "../Objcet/SoundGun/SoundGun.h"

/**
 * @brief オブジェクト管理タグ
*/
enum Tag {
	BACKGROUND,
	UI,
	OBJECT,
	PLAYER,
	ENEMY,
};


/**
 * @brief オブジェクトのmapを管理するために使うstd::pairの二つを紐づける関数
*/
struct PairHash {
	template <typename T1, typename T2>
	std::size_t operator()(const std::pair<T1, T2>& pair) const {
		auto hash1 = std::hash<T1>{}(pair.first);  // first のハッシュ値
		auto hash2 = std::hash<T2>{}(pair.second); // second のハッシュ値
		return hash1 ^ (hash2 << 1);               // ハッシュ値を組み合わせる
	}
};

/**
 * @brief オブジェクトを管理するクラス
*/
class ObjectManager
{
public:
	ObjectManager() = default;
	ObjectManager(D3D11& _D3d11) :D3d11(_D3d11) {

	}
	~ObjectManager() {};

	/**
	 * @brief オブジェクト個別追加関数
	 * @tparam T オブジェクトの型
	 * @param _SceneName 
	*/
	template <typename T>
	void AddObject(Tag _ObjTag)
	{
		// キーとオブジェクトをセットで追加
		Objects.emplace(_ObjTag, std::make_unique<T>(D3d11));
	}

	/**
	 * @brief オブジェクト一括追加関数
	 * @tparam T オブジェクトの型
	 * @tparam ...Args オブジェクトのタグ
	 * @param ...args 実引数
	*/
	template <typename... Ts, typename... Args>
	void AddObject(Args&&... _ObjectsTag)	// &&とは「右辺値参照」（右辺値とはx = 10 なら 10のように変数に入る実際の値）
	{
		//! オブジェクト配列にテンプレート型のクラスのユニークポインタを格納
		//! →その際のコンストラクタに与える引数の型(Args)と、実引数として(args)が存在している。
		//! 　→この場合、std::forwardはTのコンストラクタに引数の型、実引数をそのまま渡すために記述されている
		 
		// キーと名前が対応しているかの確認（数が合わない場合、プログラムは実行されずエラーが出る）
		static_assert(sizeof...(Ts) == sizeof...(Args), "キー(タグ)の数と追加したいオブジェクトの数が違います");
		 
		//! std::forwardで異なるキーを追加できるようにし、Tsで異なる型のオブジェクトを追加できるようにしている
		(Objects.emplace(std::forward<Args>(_ObjectsTag), std::make_unique<Ts>(D3d11)), ...);		// 全オブジェクト生成時にd3dの参照を渡す
	}

	/**
	 * @brief オブジェクト削除関数
	 * @param object 削除対象オブジェクト
	*/
	void DeleteObject(Tag _ObjTag);

	/**
	 * @brief オブジェクトの数を返す関数
	 * @return オブジェクト数
	 * 
	 * mapにしてるし、それ以外の場合でもコンテナだからサイズ返す必要あるか？
	*/
	size_t GetObjectCount(void);

	

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

	// 当たり判定も追加予定

private:
	//TODO:1216ここまで！オブジェクト管理にmapを使う&オブジェクト生成関数で一度で複数のオブジェクトを呼び出せるように変更する！！
	//! オブジェクトのユニークポインタをmapで持つ→オブジェクトマネージャーがオブジェクトを管理する
	//! 
	//! (もしかしたら左にあるオブジェクトから順に配列に保持してもいいかも？→その場合もう一度設計が必要)
	//! 
	//! オブジェクトの管理はタグ（大まかな分類）と名前（一意のもの）を使う
	
	// unordered_mapにpairを使う場合、pairの紐づけないといけないためPairHashをmapの引数に入れる
	std::unordered_map < std::pair<Tag, std::string>, std::unique_ptr<GameObject>, PairHash > Objects;
	D3D11& D3d11;
};

