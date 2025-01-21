#pragma once
#include "../EntryPoint/main.h"
#include "../../Game/Objcet/BaseObject/GameObject.h"
#include "../Objcet/Player/Player.h"
#include "../Objcet/SoundGun/SoundGun.h"

//TODO: いちいちダウンキャストするのめんどくさいから関数にしちゃって、指定した型にダウンキャストしたポインタを返す関数作ったほうがいい

/**
 * @brief オブジェクト管理タグ
*/
enum Tag {
	BACKGROUND,
	IMAGE,
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
	 * 追加時にmake_pairを書かずに引数二つ書くだけで動作させたい→関数内で引数二つの型を確認し、二つの型がTagとstringであればmake_pairしてmapに追加する
	*/
	template <typename T>
	void AddObject(const Tag& _Tag, std::string _Name)
	{
		// 同一のタグと名前を持つオブジェクトが存在する場合にはエラーを出すようにする
		// 名前が空の場合は追加しない
		if (_Name.empty()) {
			std::cerr << "オブジェクトに名前が設定されていません" << std::endl;
			return; // 無効な名前の場合は追加しない
		}

		// 名前があればとりあえずキーとして作成
		std::pair key = std::make_pair(_Tag, _Name);
		// キーと同じオブジェクトがendじゃない→見つかった場合、エラー出力
		if (Objects.find(key) != Objects.end())
		{
			std::cerr << "同一タグと名前を持つオブジェクトが既に存在しています" << std::endl;
			return; // すでに同じキーが存在する場合は追加しない
		}

		// 正常であればキーとオブジェクトをセットで追加
		Objects.emplace(std::move(key), std::make_shared<T>(D3d11));
	}

	///**
	// * @brief すでに完成したオブジェクトをタグと合わせて追加する関数
	// * @tparam T オブジェクトの型
	// * @param  オブジェクトタグ
	// * @param  オブジェクトのユニークポインタ
	//*/
	//template <typename T>
	//void AddObject(const Tag& _Tag, std::unique_ptr<T>&& _Object) {
	//	// 今回は弾幕シューティングなので、オブジェクトタグが弾の場合、それぞれ名前の後ろに新しく番号を振ってオブジェクト追加する

	//	//TODO:改善案
	//	// 追加しようとしているオブジェクトを探す→そのオブジェクトの数+1したものを名前の後ろに付け加える
	//	// っていう処理で全てのオブジェクトに対応できる


	//	// 弾か敵が追加されようとしている場合
	//	if (_Tag == PLAYER_BULLET || _Tag == ENEMY_BULLET || _Tag == ENEMY)
	//	{
	//		// 名前を設定
	//		std::string name;
	//		switch (_Tag)
	//		{
	//		case PLAYER_BULLET:
	//			//TODO:弾オブジェクトごとに番号をふって、特定のタグのオブジェクト同士の当たり判定だけを確認する→負荷が少しはマシになる
	//			BulletCount_P += 1;		// プレイヤー弾カウントを加算

	//			// 名前に番号を付けて更新
	//			name += "PlayerBullet_" + std::to_string(BulletCount_P);
	//			break;
	//		case ENEMY_BULLET:
	//			BulletCount_E += 1;		// 敵弾カウント加算

	//			// 名前に番号を付けて更新
	//			name += "EnemyBullet_" + std::to_string(BulletCount_E);
	//			break;
	//		case ENEMY:
	//			EnemyCount += 1;
	//			name += "Enemy_" + std::to_string(EnemyCount);
	//			break;
	//		default:
	//			break;
	//		}

	//		// 名前とタグをpairのキーにする
	//		std::pair key = std::make_pair(_Tag, name);
	//		// mapにオブジェクトの所有権を渡す
	//		Objects.emplace(std::move(key), std::move(_Object));
	//	}
	//}

	/**
	 * @brief 指定したタグのオブジェクトをvectorで渡して追加する関数
	*/
	template <typename T>
	void AddObject(Tag _Tag, std::vector<std::unique_ptr<T>> _Objects)
	{
		// 引数の長さ分オブジェクト追加関数を回す
		for (auto&& object : _Objects)
		{
			AddObject(_Tag, std::move(object));
		}
	}

	/**
	 * @brief オブジェクト複数追加関数
	 * @tparam T 生成するオブジェクトの型
	 * @tparam ...Keys 受け取るキーの型（std::pair<Tag, std::string>を想定）
	 * @param ...keys 実際に受け取る引数
	*/
	template <typename T, typename ...Keys>
	void AddObjects(Keys&&... keys)
	{
		(AddObject<T>(std::forward<Keys>(keys).first, std::forward<Keys>(keys).second), ...);
	}

	/**
	 * @brief オブジェクト削除関数
	 * @param object 削除対象オブジェクト
	*/
	void DeleteObject(Tag _ObjTag);

	// オブジェクト取得関数
	//GameObject* GetGameObject(const Tag& _Tag, const std::string _Name);


	/**
	 * @brief オブジェクト取得関数
	 * @param _Tag オブジェクトタグ
	 * @param _Name 付けたい名前
	 * @return オブジェクトの生ポインタ(タグの型にキャストしてから返す)
	*/
	template <class T>
	std::weak_ptr<T> GetGameObject(const Tag& _Tag, const std::string _Name)
	{
		// タグと名前の一致するオブジェクトを見つける(見つからない場合はend()が返ってくる)
		auto iterator = Objects.find(std::make_pair(_Tag, _Name));
		// 見つかった場合
		if (iterator != Objects.end())
		{
			// ポインタを取得して型に合わせて一度shared_ptrにキャスト
			std::shared_ptr<T> castedptr = std::dynamic_pointer_cast<T>(iterator->second);

			// キャストが成功した場合(nullptrではない場合)
			if (castedptr)
			{
				// ポインタを返す(ここで自動的にweak_ptrに変換される)
				return castedptr;
			}
		}
		// 見つからなければ空のweak_ptrを返す
		return std::weak_ptr<T>();
	}



	/**
	 * @brief オブジェクトの数を返す関数
	 * @return オブジェクト数
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
	std::unordered_map <std::pair<Tag, std::string>, std::shared_ptr<GameObject>, PairHash> Objects;
	D3D11& D3d11;
};

