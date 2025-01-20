#pragma once
#include "../IComponent/IComponent.h"

/**
 * @brief �������Z
*/
class RigitBody2D :public IComponent
{
public:
	RigitBody2D();
	~RigitBody2D();
	int NaturalFall(int);	//!�@���̂̎��R�����̌v�Z

private:
	double gravity = 9.8;	//!�@�d��
	double velocity;		//!�@�����x
	int  steptime = 0.01;		//!�@����
};

RigitBody2D::RigitBody2D()
{
}

RigitBody2D::~RigitBody2D()
{
}
