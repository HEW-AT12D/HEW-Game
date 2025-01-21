#pragma once
#include "../IComponent/IComponent.h"

using namespace SimpleMath;

/**
 * @brief �������Z
 * 
 * ���̃R���|�[�l���g�������Ă��Ă������蔻������m���Ȃ��ݒ�ɕύX�ł���悤�ɂ�����
*/
class RigitBody2D :public IComponent
{
public:
	RigitBody2D();
	~RigitBody2D();

	void AddForce(Vector3);
	

private:
	bool m_DetectCollision;		// �Փ˔����L���ɂ��邩
	//float 
};

RigitBody2D::RigitBody2D()
{
}

RigitBody2D::~RigitBody2D()
{
}