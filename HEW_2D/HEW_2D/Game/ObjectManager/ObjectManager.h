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
 * @brief オブジェクトのmapを管理するために使うstd::pairの二つmapに紐づける関数
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
	void AddObject(const std::pair<Tag, std::string>& _Tag_and_Name)
	{
		// キーとオブジェクトをセットで追加
		Objects.emplace(_Tag_and_Name, std::make_unique<T>(D3d11));
	}


	// TODO:12/19ここまで。複数追加関数は一旦あきらめて一個ずつ追加する
	/**
	 * @brief オブジェクト複数追加関数
	 * @tparam ...Ts 追加するオブジェクトの型（複数でもok）
	 * @tparam ...Args オブジェクトのタグと名前
	 * @param ..._Tag_and_Name 実引数
	*/
	//template <typename... Ts>
	//void AddObject(std::pair<Tag, std::string>&&... _Tag_and_Name) {
	//	// キーと名前の数が同じかの確認（数が合わない場合、プログラムは実行されずエラーが出る）, typename... Args
	//	static_assert(sizeof...(Ts) == sizeof...(_Tag_and_Name), "キー(タグ)の数と追加したいオブジェクトの数が違います");

	//	//! std::forwardで引数の型と引数そのものをそのまま渡している
	//	//! mapに追加		タグと名前		指定した型のオブジェクトのインスタンスをユニークポインタで作成(D3D11クラスの参照を渡す)
	//	(Objects.emplace(std::move(_Tag_and_Name), std::make_unique<Ts>(D3d11)), ...);
	//	(Objects.emplace(std::make_pair(std::move(_Tag_and_Name).first, std::move(_Tag_and_Name).second), std::make_unique<Ts>(D3d11)), ...);
	//	(Objects.emplace(std::forward<std::pair<Tag, std::string>>(_Tag_and_Name), std::make_unique<Ts>(D3d11)), ...);
	//}

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

