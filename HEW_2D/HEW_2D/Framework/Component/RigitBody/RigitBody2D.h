#pragma once


/**
 * @brief �������Z
 * 
 * 3D�ɂ��ł���悤��
*/
class RigitBody2D
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