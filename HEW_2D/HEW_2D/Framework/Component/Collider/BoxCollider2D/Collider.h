#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"
#include <memory>
#include <algorithm> // std::min ���g������

/**
 * @brief �l�p�Ǝl�p�̓����蔻��
 * @param  
 * @param  
 * @return ����
*/
template <class T, class U>
bool BoxCollider2(T* _obj1, U* _obj2, Player* _player)
{
	// �I�u�W�F�N�g1�̊e��
	float Object1_Right_Collider = _obj1->GetPosition().x + _obj1->GetScale().x / 2;
	float Object1_Left_Collider = _obj1->GetPosition().x - _obj1->GetScale().x / 2;
	float Object1_Top_Collider = _obj1->GetPosition().y + _obj1->GetScale().y / 2;
	float Object1_Bottom_Collider = _obj1->GetPosition().y - _obj1->GetScale().y / 2;

	// �I�u�W�F�N�g2�̊e��
	float Object2_Right_Collider = _obj2->GetPosition().x + _obj2->GetScale().x / 2;
	float Object2_Left_Collider = _obj2->GetPosition().x - _obj2->GetScale().x / 2;
	float Object2_Top_Collider = _obj2->GetPosition().y + _obj2->GetScale().y / 2;
	float Object2_Bottom_Collider = _obj2->GetPosition().y - _obj2->GetScale().y / 2;

	// �Փ˔���
	if (Object1_Right_Collider > Object2_Left_Collider &&
		Object2_Right_Collider > Object1_Left_Collider &&
		Object1_Bottom_Collider < Object2_Top_Collider &&
		Object1_Top_Collider > Object2_Bottom_Collider)
	{
		// �I�[�o�[���b�v�ʂ̌v�Z
		float overlapRight = Object1_Right_Collider - Object2_Left_Collider;
		float overlapLeft = Object2_Right_Collider - Object1_Left_Collider;
		float overlapBottom = Object2_Top_Collider - Object1_Bottom_Collider;
		float overlapTop = Object1_Top_Collider - Object2_Bottom_Collider;

		// `std::min` ���g�킸�ɍŏ��l�����߂�
		float minOverlap = overlapRight;
		if (overlapLeft < minOverlap) minOverlap = overlapLeft;
		if (overlapBottom < minOverlap) minOverlap = overlapBottom;
		if (overlapTop < minOverlap) minOverlap = overlapTop;

		if (minOverlap == overlapRight) {
			std::cout << "�E����Փ�" << std::endl;
			_player->SetMoveRight(false);

			return true;  // �E����Փ�
		}
		else if (minOverlap == overlapLeft) {
			std::cout << "������Փ�" << std::endl;
			_player->SetMoveLeft(false);

			return true;  // ������Փ�
		}
		else if (minOverlap == overlapBottom) {
			std::cout << "������Փ�" << std::endl;
			_player->SetOnGround(true);
			_player->SetDirection(Vector3(0.0f, 0.0f, 0.0f));
			_player->AddForce(Vector3(0.0f, 0.0f, 0.0f));

		/*�C��07/13�@Player�̂߂荞�݉���*/
			// �I�[�o�[���b�v���␳
			Vector3 pos = _player->GetPosition();
			pos.y += overlapBottom;  // �v���C���[����ɂ��炷
			_player->SetPosition(pos);

			return true;  // ������Փ�
		}

		else {
			std::cout << "�ォ��Փ�" << std::endl;
			
			return true;  // �ォ��Փ�
		}
	}
	//_player->SetOnGround(false);
	return false; // �Փ˂Ȃ�
}

template <class T, class U>
bool BoxCollider(T* _obj1, U* _obj2)
{

	float Object1_Right_Collider, Object1_Left_Collider, Object1_Top_Collider, Object1_Bottom_Collider;//player�̓����蔻��ϐ�
	float Object2_Right_Collider, Object2_Left_Collider, Object2_Top_Collider, Object2_Bottom_Collider;//ground�̓����蔻��ϐ�

	Object1_Right_Collider = _obj1->GetPosition().x + _obj1->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
	Object1_Left_Collider = _obj1->GetPosition().x - _obj1->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
	Object1_Top_Collider = _obj1->GetPosition().y + _obj1->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
	Object1_Bottom_Collider = _obj1->GetPosition().y - _obj1->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�

	Object2_Right_Collider = _obj2->GetPosition().x + _obj2->GetScale().x / 2; //�O���E���h�̉E�̓����蔻��ϐ�
	Object2_Left_Collider = _obj2->GetPosition().x - _obj2->GetScale().x / 2;  //�O���E���h�̍��̓����蔻��ϐ�
	Object2_Top_Collider = _obj2->GetPosition().y + _obj2->GetScale().y / 2;    //�O���E���h�̏�̓����蔻��ϐ�
	Object2_Bottom_Collider = _obj2->GetPosition().y - _obj2->GetScale().y / 2;//�O���E���h�̉��̓����蔻��ϐ�

	// �l�p�Ǝl�p�̓����蔻��
	if (Object1_Right_Collider > Object2_Left_Collider &&
		Object2_Right_Collider > Object1_Left_Collider &&
		Object1_Bottom_Collider < Object2_Top_Collider &&
		Object1_Top_Collider > Object2_Bottom_Collider)
	{
		return true;
	}
	return false;
}


bool ColliderPlayer_Ground(Player*, std::vector<GameObject*>);	//Player��Ground�̓����蔻��֐�

/**
 * @brief �Βn�ʒn�ʂ̓����蔻��
 * @tparam T �����̌^
 * @param  �n��
*/
template <class T, class U>
bool Collider_toGround(T* _obj1, U* _obj2)
{
	auto obj1 = _obj1;
	auto obj2 = _obj2;

	if (BoxCollider(obj1, obj2))
	{
		// �n�ʂɓ��������I�u�W�F�N�g�̑��x�A�����x�N�g�������Z�b�g����
		obj1->SetDirection(Vector3({0.0f}));
		obj1->AddForce(Vector3({0.0f}));
		obj1->SetOnGround(true);
		return true;
	}
	else {
		//obj1->SetOnGround(false);
		return false;
	}
}

template <class T>
bool Collider_toEnemy(T* _obj1, GameObject* _obj2)
{
	auto obj1 = _obj1;
	auto obj2 = _obj2;

	if (BoxCollider(obj1, obj2))
	{
		// �n�ʂɓ��������I�u�W�F�N�g�̑��x�A�����x�N�g�������Z�b�g����
		obj1->SetDirection(Vector3({ 0.0f }));
		obj1->AddForce(Vector3({ 0.0f }));
		obj1->SetOnGround(true);
		return true;
	}
	else {
		obj1->SetOnGround(false);
		return false;
	}
}


/**
 * @brief �I�u�W�F�N�g�z�񓯎m�̓����蔻����擾(�S�Ďl�p)
 * @tparam T
 * @tparam U
 * @param _objects1
 * @param _objects2
 * 
 * ���ő������̃x�N�g�������Z�b�g����
 * 
 * @return
*/
template <class T, class U>
bool Collider_Objects_Objects(std::vector<T*>_objects1, std::vector<U*>_objects2)
{
	// �I�u�W�F�N�g���Ƃ�BoxCollider����
	for (auto& obj2 : _objects2)
	{
		for (auto& obj1 : _objects1)
		{
			// ���������ꍇ
			if (BoxCollider(obj1, obj2))
			{
				// ���������̃I�u�W�F�N�g�̃x�N�g�������Z�b�g
				obj1->SetDirection(Vector3({ 0.0f }));
				obj1->AddForce(Vector3({ 0.0f }));
				obj1->SetOnGround(true);
				return true;
			}
			else {
				obj1->SetOnGround(false);
			}
		}
	}
	return false;
}

/**
 * @brief �v���C���[�ƃI�u�W�F�N�g�̓����蔻��
 * @param _player �v���C���[
 * @param _objects �I�u�W�F�N�g��vector
*/
bool Collider_to_Object(Player* _player, GameObject* _objects);

/**
 * @brief �v���C���[�ƃ}�K�W���̓����蔻��
*/
bool Collider_Player_to_Magazine(Player* obj1, Magazine* obj2);


bool ColliderPlayer_Gion(Player*, GameObject*);//Player�Ƌ[���̓����蔻��֐�

// ��^�Ƌ[���̓����蔻��֐�
std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> ColliderFan_Gion(Player* fan, std::vector<std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// �����Ɖ~���������Ă��邩���肷��֐�
