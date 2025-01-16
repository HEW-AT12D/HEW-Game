#pragma once
#include "../IComponent/IComponent.h"

/**
 * @brief 物理演算
*/
class RigitBody2D :public IComponent
{
public:
	RigitBody2D();
	~RigitBody2D();
	int NaturalFall(int);	//!　物体の自然落下の計算

private:
	double gravity = 9.8;	//!　重力
	double velocity;		//!　加速度
	int  steptime = 0.01;		//!　時間
};

RigitBody2D::RigitBody2D()
{
}

RigitBody2D::~RigitBody2D()
{
}
