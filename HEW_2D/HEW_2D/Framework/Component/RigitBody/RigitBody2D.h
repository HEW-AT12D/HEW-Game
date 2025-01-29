#pragma once
#include "../IComponent/IComponent.h"

using namespace SimpleMath;

/**
 * @brief �������Z
 * 
 * ���̃R���|�[�l���g�������Ă��Ă������蔻������m���Ȃ��ݒ�ɕύX�ł���悤�ɂ�����
 * 
 * �d�́A���C�Ȃǂ��K�v
 * 
 * 
 * 2. �ŏI�I�ȃR�[�h�̃C���[�W
C++ �� RigidBody::Update(float deltaTime) ����������Ȃ�A���̂悤�Ȍ`�ɂȂ�܂��B

cpp
�R�s�[����
�ҏW����
void RigidBody::Update(float deltaTime) {
    // 1. �͂̓K�p�i��: �d�́j
    force += mass * gravity;

    // 2. �����x�����߂�
    Vector3 acceleration = force / mass;

    // 3. ���x���X�V
    velocity += acceleration * deltaTime;

    // 4. �ʒu���X�V
    position += velocity * deltaTime;

    // 5. �p���x�̍X�V
    Vector3 angularAcceleration = torque / inertia;
    angularVelocity += angularAcceleration * deltaTime;
    rotation += angularVelocity * deltaTime;

    // 6. �Փ˔���
    if (isColliding) {
        velocity = Reflect(velocity, collisionNormal) * restitution;
    }

    // 7. �͂����Z�b�g�i���t���[�����Z�b�g���ĐV�����͂��󂯕t����j
    force = Vector3(0, 0, 0);
    torque = Vector3(0, 0, 0);
}
3. �܂Ƃ�
update �̗���͎��̂悤�ɂȂ�܂��F

�O�́i�d�́E����j��������
�����x�����߂đ��x���X�V
���x���g���č��W���X�V
�p�^���i��]�j���v�Z
�Փˏ���
���t���[���̗͂����Z�b�g
+��: �����x�ȕ�����ڎw���Ȃ�
�I�C���[�ϕ��̑����Verlet�ϕ���Runge-Kutta�@���g��
�Փˌ��o����萳�m�ɁiAABB, OBB, GJK�A���S���Y���j
���̓��m�̖��C��e���Փ˂̌v�Z
�Œ莞�ԃX�e�b�v�̓����i�����X�V�͌Œ�t���[���Ŏ��{�j
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