#pragma once
#include "../../Precompiled/pch.h"

// TODO 2024/10/4 このTransformクラスの変数transformを、IComponentを継承したTransformComponent？とかに持たせる→Transform完成！！（カラーとか透明度ってどこでする？）
// クラステンプレートとか標準ライブラリ、スマートポインタの勉強も必要かも std::vectorとかでコンポーネントを好きなだけつけれるとかできそう

/// <summary>
/// Transformクラス：全てのオブジェクトが持っている情報（ここでは数値のみを扱う）
/// ・座標
/// ・回転
/// ・大きさ
/// の情報を持つ
/// 
/// 各数値の行列変換は毎フレーム行う→更新は不要
/// ワールド行列への変換はTransform内で行う
/// </summary>

class Transform
{
public:
	Transform() :m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f), m_Scale(1.0f, 1.0f, 0.0f) {};
	~Transform();

	void SetPosition(XMFLOAT3 _Position);
	void SetRotation(XMFLOAT3 _Rotation);
	void SetScale(XMFLOAT3 _Scale);
	XMMATRIX ConvertMatrix(void);		// Transformの各値をかけ合わせてワールド行列に変換

	// 更新するべきなのはコンポーネントなのでここに更新はいらない？
	// →conioのvectorとかと同じノリ？
private:
	XMFLOAT3 m_Position = XMFLOAT3(0.0f, 0.0f, 0.0f);	// 座標
	XMFLOAT3 m_Rotation = XMFLOAT3(0.0f, 0.0f, 0.0f);	// 角度
	XMFLOAT3 m_Scale = XMFLOAT3(0.0f, 0.0f, 0.0f);		// 大きさ
};

Transform::Transform()
{
}

Transform::~Transform()
{
}

