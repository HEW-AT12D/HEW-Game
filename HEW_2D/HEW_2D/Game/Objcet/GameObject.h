#pragma once
#include "../../Framework/Precompiled/pch.h"
#include "../../Framework/D3D11/D3D11.h"
#include "../../Framework/WICTextureLoader/WICTextureLoader.h" // テクスチャ読み込みライブラリ

/// <summary>
/// 基本となるゲームオブジェクトクラス
/// ・一旦コンポーネント指向ではなくオブジェクト指向で止めておく
/// ・このクラスを完成させてから余裕があればコンポーネント指向に移行する
/// </summary>

class GameObject:public Transform {
private:
	// 頂点データ
	Vertex vertexList[4] =
	{
		//   x     y    z       r    g    b    a     u    v
		{ -0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,0.0f},  // 0番目の頂点座標
		{  0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f},  // 1番目の頂点座標
		{ -0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f},  // 2番目の頂点座標
		{  0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f},  // 3番目の頂点座標
	};

	// 座標
	//DirectX::XMFLOAT3 pos = { 0.0f, 0.0f, 0.0f };
	
	// 大きさ
	//DirectX::XMFLOAT3 size = { 100.0f, 100.0f, 0.0f };
	
	// 角度
	float angle = 0.0f;
	// 色
	DirectX::XMFLOAT4 color = { 1.0f, 1.0f, 1.0f, 1.0f };

	// 頂点バッファ
	ID3D11Buffer* m_pVertexBuffer;
	// テクスチャ用変数
	ID3D11ShaderResourceView* m_pTextureView;

	//テクスチャが縦横に何分割されているか
	int splitX = 1;
	int splitY = 1;

public:
	//左上から何段目を切り抜いて表示するか
	float numU = 0;
	float numV = 0;

	void Init(const wchar_t* imgname, int sx = 1, int sy = 1); //初期化
	void Draw();                             //描画
	void Uninit();                           //終了
	void SetPos(float x, float y, float z);  //座標をセット
	void SetSize(float x, float y, float z); //大きさをセット
	void SetAngle(float a);                  //角度をセット
	void SetColor(float r, float g, float b, float a); //色をセット

	DirectX::XMFLOAT3 GetPos(void);  //座標をゲット
	DirectX::XMFLOAT3 GetSize(void); //大きさをゲット
	float GetAngle(void);            //角度をゲット
	DirectX::XMFLOAT4 GetColor(void);//色をゲット
};
