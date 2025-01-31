#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


/**
 * @brief �l�p�Ǝl�p�̓����蔻��
 * @param  
 * @param  
 * @return ����
*/
template <class T, class U>
bool BoxCollider(std::shared_ptr<T> _obj1, std::shared_ptr<U> _obj2)
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
	else
	{
		return false;
	}

	
}


bool ColliderPlayer_Ground(std::shared_ptr<Player>, std::vector<std::shared_ptr<GameObject>>);	//Player��Ground�̓����蔻��֐�

/**
 * @brief �Βn�ʒn�ʂ̓����蔻��
 * @tparam T �����̌^
 * @param  �n��
*/
template <class T>
bool Collider_toGround(std::weak_ptr<T> _obj1, std::weak_ptr<GameObject> _obj2)
{
	auto obj1 = _obj1.lock();
	auto obj2 = _obj2.lock();

	if (BoxCollider(obj1, obj2))
	{
		// �n�ʂɓ��������I�u�W�F�N�g�̑��x�A�����x�N�g�������Z�b�g����
		obj1->SetDirection(Vector3({0.0f}));
		obj1->AddForce(Vector3({0.0f}));
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
bool Collider_Objects_Objects(std::vector<std::shared_ptr<T>>_objects1, std::vector<std::shared_ptr<U>>_objects2)
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
bool Collider_to_Object(std::weak_ptr<Player> _player, std::weak_ptr<GameObject> _objects);

/**
 * @brief �v���C���[�ƃ}�K�W���̓����蔻��
*/
bool Collider_Player_to_Magazine(std::weak_ptr<Player> obj1, std::weak_ptr<Magazine> obj2);



bool ColliderPlayer_Gion(std::shared_ptr<Player>, std::shared_ptr<GameObject>);//Player�Ƌ[���̓����蔻��֐�

// ��^�Ƌ[���̓����蔻��֐�
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// �����Ɖ~���������Ă��邩���肷��֐�

//void DrawFan(GameObject*, bool);
