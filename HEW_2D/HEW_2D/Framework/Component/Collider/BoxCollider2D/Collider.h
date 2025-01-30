#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


bool ColliderPlayer_Ground(std::weak_ptr<Player>, std::weak_ptr<GameObject>);	//Player��Ground�̓����蔻��֐�

/**
 * @brief �Βn�ʒn�ʂ̓����蔻��
 * @tparam T �����̌^
 * @param  �n��
*/
template <class T>
bool Collider_toGround(std::weak_ptr<T> obj1, std::weak_ptr<GameObject> obj2)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player�̓����蔻��ϐ�
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground�̓����蔻��ϐ�

	Player_Right_Collider = obj1.lock()->GetPosition().x + obj1.lock()->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
	Player_Left_Collider = obj1.lock()->GetPosition().x - obj1.lock()->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
	Player_Top_Collider = obj1.lock()->GetPosition().y + obj1.lock()->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
	Player_Bottom_Collider = obj1.lock()->GetPosition().y - obj1.lock()->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�

	Ground_Right_Collider = obj2.lock()->GetPosition().x + obj2.lock()->GetScale().x / 2; //�O���E���h�̉E�̓����蔻��ϐ�
	Ground_Left_Collider = obj2.lock()->GetPosition().x - obj2.lock()->GetScale().x / 2;  //�O���E���h�̍��̓����蔻��ϐ�
	Ground_Top_Collider = obj2.lock()->GetPosition().y + obj2.lock()->GetScale().y / 2;    //�O���E���h�̏�̓����蔻��ϐ�
	Ground_Bottom_Collider = obj2.lock()->GetPosition().y - obj2.lock()->GetScale().y / 2;//�O���E���h�̉��̓����蔻��ϐ�

	Ground_Bottom_Collider = Ground_Bottom_Collider + 150; //Ground�̉��̕����ɓ�����������true��Ԃ��Ȃ��悤�ɂ���i�������W����ɂ����Ă�j

	//�v���C���[�ƃO���E���h�̓����蔻��
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		// �n�ʂɓ��������I�u�W�F�N�g�̑��x�A�����x�N�g�������Z�b�g����
		obj1.lock()->SetDirection(Vector3({ 0.0f }));
		obj1.lock()->AddForce(Vector3({ 0.0f }));
		obj1.lock()->SetOnGround(true);
		return true;
	}
	else {
		obj1.lock()->SetOnGround(false);
		return false;
	}
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



bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player�Ƌ[���̓����蔻��֐�

// ��^�Ƌ[���̓����蔻��֐�
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>>);

bool LineIntersectsCircle(float, float, float, float, float, float, float);// �����Ɖ~���������Ă��邩���肷��֐�

//void DrawFan(GameObject*, bool);
