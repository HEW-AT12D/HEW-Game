#pragma once
#include "../IComponent/IComponent.h"

/**
 * @brief �������Z
 * 
 * 3D�ɂ��ł���悤��
*/
class RigitBody2D :public IComponent
{
public:
	RigitBody2D();

	~RigitBody2D();



private:
	float m_Angulr;
	float m_Velocity;
};

RigitBody2D::RigitBody2D()
{
}

RigitBody2D::~RigitBody2D()
{
}: