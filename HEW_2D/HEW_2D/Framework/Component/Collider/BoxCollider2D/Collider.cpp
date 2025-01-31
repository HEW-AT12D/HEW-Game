#include "Collider.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
/// �E��{�l�p�œ����蔻�����遨�����������̂���������肳���ł���΃I�u�W�F�N�g�}�l�[�W���ő����炢�����
/// �E�I�u�W�F�N�g���n�ʂɓ����������̊֐����K�v�����͌ʂŉ񂵂Ă�̂ŃI�u�W�F�N�g�}�l�[�W���ŉ񂵂���
/// 
/// 
/// �����FBoxCollider�ɂ����ꍇ�������蔻������I������I�u�W�F�N�g�͔���`�F�b�N����O���Ƃ�������
///////////////////////////////////////////////////////////////////////////////////////////////////


//Player��Ground�̓����蔻��(�z��)
//template <class T, class U>
bool ColliderPlayer_Ground(std::shared_ptr<Player> _player, std::vector<std::shared_ptr<GameObject>> _objects)
{
	// �n�ʂ̔z��̗v�f�������[�v
	for (auto& ground : _objects) {
		if (BoxCollider(_player, ground))
		{
			// ���������I�u�W�F�N�g�̑��x�A�����x�N�g�������Z�b�g����
			_player->SetDirection(Vector3({ 0.0f }));
			_player->AddForce(Vector3({ 0.0f }));
			std::cout << "�n�ʂƐG��Ă܂�" << std::endl;

			_player->SetOnGround(true);
			return true;
		}
		else
		{
			_player->SetOnGround(false);
			return false;
		}
	}	
}


/**
 * @brief �v���C���[�ƃ}�K�W��
 * 
 * ���͂������g��Ȃ�
*/
bool Collider_Player_to_Magazine(std::weak_ptr<Player> obj1, std::weak_ptr<Magazine> obj2)
{
	// ---------------------�����g���܂킹��ȁH�H�H�H�H�H�H�H�H�H�H�H�H�H�H�H
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

	//�v���C���[�ƃ}�K�W���̓����蔻��
	if (Player_Left_Collider < Ground_Right_Collider &&
		Ground_Left_Collider < Player_Right_Collider &&
		Player_Bottom_Collider < Ground_Top_Collider &&
		Player_Top_Collider > Ground_Bottom_Collider)
	{
		return true;
	}
	else {
		return false;
	}
}



/**
 * @brief �v���C���[�ƃI�u�W�F�N�g�̓����蔻��
 * @return ����
*/
bool Collider_to_Object(std::weak_ptr<Player> _player, std::weak_ptr<GameObject> _object) {
	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player�̓����蔻��ϐ�
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground�̓����蔻��ϐ�

	Player_Right_Collider = _player.lock()->GetPosition().x + _player.lock()->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
	Player_Left_Collider = _player.lock()->GetPosition().x - _player.lock()->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
	Player_Top_Collider = _player.lock()->GetPosition().y + _player.lock()->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
	Player_Bottom_Collider = _player.lock()->GetPosition().y - _player.lock()->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�

	Ground_Right_Collider = _object.lock()->GetPosition().x + _object.lock()->GetScale().x / 2; //�O���E���h�̉E�̓����蔻��ϐ�
	Ground_Left_Collider = _object.lock()->GetPosition().x - _object.lock()->GetScale().x / 2;  //�O���E���h�̍��̓����蔻��ϐ�
	Ground_Top_Collider = _object.lock()->GetPosition().y + _object.lock()->GetScale().y / 2;    //�O���E���h�̏�̓����蔻��ϐ�
	Ground_Bottom_Collider = _object.lock()->GetPosition().y - _object.lock()->GetScale().y / 2;//�O���E���h�̉��̓����蔻��ϐ�

	
	//// **�I�u�W�F�N�g�̏㑤�iTop�j�œ�����������**
	//if (Player_Bottom_Collider <= Ground_Top_Collider &&  // �v���C���[�̉��[���I�u�W�F�N�g�̏�[�ȉ�
	//	Player_Top_Collider > Ground_Top_Collider &&      // �v���C���[�̏�[���I�u�W�F�N�g�̏�[����
	//	Player_Right_Collider > Ground_Left_Collider &&   // �������ł��d�Ȃ��Ă���
	//	Player_Left_Collider < Ground_Right_Collider &&
	//	_player.lock()->GetVelocity().y <= 0) {                   // �������Ɉړ����̂ݓK�p
	//	_player.lock()->SetOnGround(true);  // �n�ʂ̏�ɂ���
	//	//_player.lock()->SetVelocityY(0);    // �������~�߂�
	//	std::cout << "�I�u�W�F�N�g�̏㑤�œ������Ă��܂�" << std::endl;
	//	return  true;
	//}



	//Player�ƃI�u�W�F�N�g���Փ˂����Ƃ����ɐi�߂Ȃ�
	if (Player_Right_Collider > Ground_Left_Collider &&
		Player_Bottom_Collider <= Ground_Top_Collider &&
		Player_Left_Collider < Ground_Left_Collider)
	{
		_player.lock()->SetMoveRight(false);
		_player.lock()->SetOnGround(true);  // �n�ʂ̏�ɂ���

		std::cout << "�E���������Ă��܂�" << std::endl;
		return true;
	}
	else if (Player_Left_Collider < Ground_Right_Collider &&
		Player_Bottom_Collider <= Ground_Top_Collider &&
		Player_Right_Collider > Ground_Right_Collider)
	{
		_player.lock()->SetMoveLeft(false);
		_player.lock()->SetOnGround(true);  // �n�ʂ̏�ɂ���

		std::cout << "�����������Ă��܂�" << std::endl;
		return true;
	}
	
	

}





/**
 * @brief �v���C���[�ƃI�u�W�F�N�g
*/
//void Collider_Player_to_Object(std::weak_ptr<Player> _player, std::vector<std::weak_ptr<GameObject>> _objects) {
//	float Player_Right_Collider, Player_Left_Collider, Player_Top_Collider, Player_Bottom_Collider;//player�̓����蔻��ϐ�
//	float Ground_Right_Collider, Ground_Left_Collider, Ground_Top_Collider, Ground_Bottom_Collider;//ground�̓����蔻��ϐ�
//
//	Player_Right_Collider = _player.lock()->GetPosition().x + _player.lock()->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
//	Player_Left_Collider = _player.lock()->GetPosition().x - _player.lock()->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
//	Player_Top_Collider = _player.lock()->GetPosition().y + _player.lock()->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
//	Player_Bottom_Collider = _player.lock()->GetPosition().y - _player.lock()->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�
//
//	// vector�̃T�C�Y�����[�v
//	for (auto& obj : _objects) {
//		Ground_Right_Collider = obj.lock()->GetPosition().x + obj.lock()->GetScale().x / 2; //�O���E���h�̉E�̓����蔻��ϐ�
//		Ground_Left_Collider = obj.lock()->GetPosition().x - obj.lock()->GetScale().x / 2;  //�O���E���h�̍��̓����蔻��ϐ�
//		Ground_Top_Collider = obj.lock()->GetPosition().y + obj.lock()->GetScale().y / 2;    //�O���E���h�̏�̓����蔻��ϐ�
//		Ground_Bottom_Collider = obj.lock()->GetPosition().y - obj.lock()->GetScale().y / 2;//�O���E���h�̉��̓����蔻��ϐ�
//
//		//�v���C���[�ƃI�u�W�F�N�g�̓����蔻��
//		if (Player_Left_Collider < Ground_Right_Collider &&
//			Ground_Left_Collider < Player_Right_Collider &&
//			Player_Bottom_Collider < Ground_Top_Collider &&
//			Player_Top_Collider > Ground_Bottom_Collider)
//		{
//			// ���������I�u�W�F�N�g���n�ʂł���΂̑��x�A�����x�N�g�������Z�b�g����
//			_player.lock()->SetDirection(Vector3({ 0.0f }));
//			_player.lock()->AddForce(Vector3({ 0.0f }));
//			_player.lock()->SetOnGround(true);
//		}
//		else {
//			_player.lock()->SetOnGround(false);
//		}
//	}
//	
//}





//Player��Gion�̓����蔻��
bool ColliderPlayer_Gion(std::shared_ptr<Player> player, std::shared_ptr<GameObject> gion)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Up_Collider, Player_Bottom_Collider;//player�̓����蔻��ϐ�
	float Gion_Right_Collider, Gion_Left_Collider, Gion_Up_Collider, Gion_Bottom_Collider;        //gion�̓����蔻��ϐ�

	Player_Right_Collider = player->GetPosition().x + player->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
	Player_Left_Collider = player->GetPosition().x - player->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
	Player_Up_Collider = player->GetPosition().y + player->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
	Player_Bottom_Collider = player->GetPosition().y - player->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�

	Gion_Right_Collider = gion->GetPosition().x + gion->GetScale().x / 2;   //�[���̉E�����蔻��
	Gion_Left_Collider = gion->GetPosition().x - gion->GetScale().x / 2;    //�[���̍������蔻��
	Gion_Up_Collider = gion->GetPosition().y + gion->GetScale().y / 2;      //�[���̏㓖���蔻��
	Gion_Bottom_Collider = gion->GetPosition().y - gion->GetScale().y / 2;	//�[���̉������蔻��

	//Player�Ƌ[���̓����蔻��
	if (Player_Right_Collider>Gion_Left_Collider&&
		Player_Left_Collider<Gion_Right_Collider&&
		Player_Up_Collider>Gion_Bottom_Collider&&
		Player_Bottom_Collider<Gion_Up_Collider)
	{
		std::cout << "Player�Ƌ[�����Փ˂��܂���" << std::endl;
		player->SetOnGround(true);
		return true;
	}
	else {
		player->SetOnGround(false);

		return false;
	}
}


//��^�Ƌ[���̓����蔻��

/**
 * @brief �v���C���[�Ƌ[���̓����蔻��
 * @param fan �v���C���[(���������^�ɔ͈͂�ݒ�)
 * @param gion �[��(vector�őS���n��)
 * @return ���������[��
*/
std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>> ColliderFan_Gion(std::weak_ptr<Player> fan, std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<IOnomatopoeia>>> _onomatopoeias)
{
	float PI = 3.14159265;
	float fanAngle = PI / 6;
	//��^�̏��擾
	float fanCenterX = fan.lock()->GetPosition().x + 200.0f;	//��^�̒��SX���W
	//float fanCenterX = fan.lock()->GetPosition().x + 200.0f;	//��^�̒��SX���W

	float fanCenterY = fan.lock()->GetPosition().y;   //��^�̒��SY���W
	float fanRadius = fan.lock()->GetScale().x / 2;   //��^�̔��a�i�X�P�[����X�������g�p�j

	//��^�̕����x�N�g�����E�����ɌŒ�
	float fanDirX = 1.0f;//�E�����̐���
	float fanDirY = 0.0f;//������̐���
	
	//�[���̏��擾
	float Gion_Right_Collider;		// �[���̉E�[
	float Gion_Left_Collider;		// �[���̍��[
	float Gion_Up_Collider;			// �[���̏�[
	float Gion_Bottom_Collider;		// �[���̉��[
	
	// �[���Ƃ̓����蔻����擾
	for (auto& onomat : _onomatopoeias) {
		// �[���̓����蔻��͈͂��擾
		Gion_Right_Collider = onomat.second->GetPosition().x + onomat.second->GetScale().x / 2; //�[���̉E�[
		Gion_Left_Collider = onomat.second->GetPosition().x - onomat.second->GetScale().x / 2;  //�[���̍��[
		Gion_Up_Collider = onomat.second->GetPosition().y + onomat.second->GetScale().y / 2;    //�[���̏�[
		Gion_Bottom_Collider = onomat.second->GetPosition().y - onomat.second->GetScale().y / 2;//�[����

		//------------��`�Ƌ[���̎l�̒��_------------
		float vertices[4][2] = {
			{Gion_Left_Collider,Gion_Up_Collider},//����
			{Gion_Right_Collider,Gion_Up_Collider},//�E��
			{Gion_Left_Collider,Gion_Bottom_Collider},//����
			{Gion_Right_Collider,Gion_Bottom_Collider},//�E��
		};

		//�l�p�`�̊e���_����`���Ɋ܂܂�邩�m�F
		for (int i = 0; i < 4; ++i) {
			float dx = vertices[i][0] - fanCenterX;   //��^���S���璸�_�ւ̃x�N�g��X
			float dy = vertices[i][1] - fanCenterY;   //��^���S���璸�_�ւ̃x�N�g��Y
			float distance = sqrtf(dx * dx + dy * dy);//�������v�Z

			//���������a�����m�F
			if (distance <= fanRadius) {
				//�x�N�g���̊p�x�̌v�Z�i���ρj
				float dot = (dx * fanDirX + dy * fanDirY) / (distance);//cos��=����/(|v1|*|v2|)

				//�p�x���͈͓����m�F
				float cosLimit = cosf(fanAngle);//��^�̊p�x�͈͂�cos�l
				if (dot >= cosLimit) {
					std::cout << "���_����^���ł�" << std::endl;
					// �[���̒��_����^���Ȃ̂ł��̋[����Ԃ�
					return onomat;
				}
			}
		}

		//---------------��`�Ǝl�p�`�̕ӂ���^�̉~�ʂƌ������Ă��邩�m�F------------------
		float edges[4][4] = {
			{Gion_Left_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Up_Collider},        //���
			{Gion_Right_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Bottom_Collider},   //�E��
			{Gion_Left_Collider,Gion_Bottom_Collider,Gion_Right_Collider,Gion_Bottom_Collider},//����
			{Gion_Left_Collider,Gion_Up_Collider,Gion_Left_Collider,Gion_Bottom_Collider}      //����
		};
		for (int i = 0; i < 4; ++i) {
			if (LineIntersectsCircle(edges[i][0], edges[i][1], edges[i][2], edges[i][3], fanCenterX, fanCenterY, fanRadius)) {
				std::cout << "�l�p�`�̕ӂ���^�̉~�ʂƌ������Ă��܂�" << std::endl;
				// �l�p�`�̕ӂ���^�̉~�ʂƌ���
				return onomat;
			}
		}
		// ��^�̒��S���l�p�`���ɂ��邩�m�F
		if (fanCenterX >= Gion_Left_Collider && fanCenterX <= Gion_Right_Collider &&
			fanCenterY >= Gion_Bottom_Collider && fanCenterY <= Gion_Up_Collider) {
			// ��^�̒��S���l�p�`��
			return onomat;
		}
	}
	//�ǂ�ɂ��Y�����Ȃ��ꍇ�A�������Ă��Ȃ��̂ŉ����Ԃ��Ȃ�
	return {};
}

// �����Ɖ~���������Ă��邩���肷��֐�
bool LineIntersectsCircle(float x1, float y1, float x2, float y2, float cx, float cy, float radius)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float fx = x1 - cx;
	float fy = y1 - cy;

	float a = dx * dx + dy * dy;
	float b = 2 * (fx * dx + fy * dy);
	float c = (fx * fx + fy * fy) - radius * radius;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		return false;//�������Ă��Ȃ�
	}
	else {
		discriminant = sqrtf(discriminant);
		float t1 = (-b - discriminant) / (2 * a);
		float t2 = (-b + discriminant) / (2 * a);

		return (t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1);
	}
}


// �����蔻�蒅�F�p
//void DrawFan(GameObject* fan, bool isColliding)
//{
//	//��^�̏��擾
//	float centerX = fan->GetPosition().x;
//	float centerY = fan->GetPosition().y;
//	float radius = fan->GetScale().x / 2;
//	float M_PI = 3.14159265;
//	float fanAngle = M_PI / 6;//�J���p�x�i30�x�j
//	float dirX = cosf(fan->GetRotation().z);
//	float dirY = sinf(fan->GetRotation().z);

//	//�F����
//	float r, g, b;
//	if (isColliding) {
//		r = 1.0f; g = 0.0f; b = 0.0f;//��
//	}
//	else {
//		r = 0.0f, g = 1.0f, b = 0.0f;//��
//	}
//}


