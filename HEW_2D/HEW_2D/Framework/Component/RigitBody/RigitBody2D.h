#pragma once
#include "../IComponent/IComponent.h"

using namespace SimpleMath;

/**
 * @brief 物理演算
 * 
 * このコンポーネントを取りつけていても当たり判定を検知しない設定に変更できるようにしたい
*/
class RigitBody2D :public IComponent
{
public:
	RigitBody2D();
	~RigitBody2D();

	void AddForce(Vector3);
	

private:
	bool m_DetectCollision;		// 衝突判定を有効にするか
	//float 
};

RigitBody2D::RigitBody2D()
{
}

RigitBody2D::~RigitBody2D()
{
}