#pragma once
#include "../../EntryPoint/main.h"
#include "../../../Framework/D3D11/D3D11.h"
#include "../../../Framework/WICTextureLoader/WICTextureLoader.h"	// テクスチャ読み込みライブラリ
#include "../../../Framework/Component/Transform/Transform.h"		//Transform.h読み込み

/// <summary>
/// TODO:オブジェクトの描画方法を変更する
/// 
/// 現在：頂点バッファのみで描画
/// 目標：インデックスバッファを使用した描画に変更
/// 
/// 良い点：頂点情報を共有できるので規模が大きくなればなるほど描画処理の負荷が減る
/// 
/// --------------改善案----------------
/// d3dクラスのポインタ→参照？ユニークポインタ？d3dクラスをstatic化？Rendererクラス作成？
/// 
/// オブジェクトが持つもの
/// ・コンポーネントマネージャ
/// ・名前
/// ・タグ
/// 
/// 
/// </summary> 


// オブジェクトの状態（ここに全部書き出しておく）
enum STATE
{
	NORMAL,		// 通常時
	RUN,		// 移動時
	JUMP,		// ジャンプ時
	DAMAGED,	// 被ダメ時
	ATTACKED,	// 攻撃時
};

/**
 * @brief 基本となるゲームオブジェクトクラス
 * 
 * 一旦コンポーネント指向ではなくオブジェクト指向で止めておく
 * @param vertices 頂点データ
 * @param d3d11 d3dクラスのポインタ（描画に使用）
 * @param transform トランスフォーム（座標、回転、大きさ）
 * @param color 色情報
 * 
*/
class GameObject {
private:
	//! 頂点データ
	//! このゲームでは擬音を吸い込むことがあるため頂点を可変にしておく
	std::vector<Vertex> vertices;
	
	// d3dクラス
	D3D11& D3d11;
	// 座標,大きさ,角度
	Transform transform;
	// 色
	Vector4 color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// 頂点バッファ
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	// テクスチャ用変数
	ID3D11ShaderResourceView* m_pTextureView = nullptr;

	//テクスチャが縦横に何分割されているか
	Vector2 m_Split = { 1.0f,1.0f };

	//左上から何段目を切り抜いて表示するか
	Vector2 m_Number = { 0.0f,0.0f };

	// アニメーション用状態管理変数
	STATE m_State = {};

	// アニメーション管理フラグ
	bool IsAnimation = false;

public:
	//GameObject() = default;	// クラスのメンバ変数に参照が入っている場合、デフォルトコンストラクタが使えない（初期化が必須となる）
	GameObject(D3D11& _D3d11);
	virtual ~GameObject();

	virtual void Init(const wchar_t* imgname, bool _animation = false, int sx = 1, int sy = 1); // 初期化
	virtual void Update(void);					// 更新（自オブジェクトに”何か”が当たった判定だけここで確認）
	virtual void Draw(void);					// 描画
	virtual void Uninit(void);					// 終了
	virtual void SetPosition(Vector3 _Pos);		// 座標をセット
	virtual void SetScale(Vector3 _Size);		// 大きさをセット
	virtual void SetRotation(Vector3 _Rot);		// 角度をセット
	virtual void SetColor(Vector4 _Color);		// 色をセット
	virtual void SetUV(Vector2 _UV);            // UV座標をセット
	virtual void Animation(STATE,Vector2);				// アニメーション

	// 個別の当たり判定もここに追加？オブジェクトの基本となるクラスならここじゃなくて、判定が必要なオブジェクトにそれぞれ追加？

	virtual Vector3 GetPosition(void);			// 座標を取得
	virtual Vector3 GetScale(void);				// 大きさを取得
	virtual Vector3 GetRotation(void);			// 角度を取得
	virtual Vector4 GetColor(void);				// 色を取得
	virtual Vector2 GetUV(void);                // UV座標を取得
};
