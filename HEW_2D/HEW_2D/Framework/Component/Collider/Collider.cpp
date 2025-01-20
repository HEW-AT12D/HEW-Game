#include"Collider.h"
#include"../../../Game/Objcet/BaseObject/Object.h"


//Player��Ground�̓����蔻��
bool ColliderPlayer_Ground(GameObject* player, GameObject* ground)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Up_Collider, Player_Bottom_Collider;//player�̓����蔻��ϐ�
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Up_Collider, Ground_Bottom_Collider;//ground�̓����蔻��ϐ�

	Player_Right_Collider = player->GetPosition().x + player->GetScale().x / 2; //�v���C���[�̉E�����蔻��ϐ�
	Player_Left_Collider = player->GetPosition().x - player->GetScale().x / 2;  //�v���C���[�̍������蔻��ϐ�
	Player_Up_Collider = player->GetPosition().y + player->GetScale().y / 2;    //�v���C���[�̏㓖���蔻��ϐ�
	Player_Bottom_Collider = player->GetPosition().y - player->GetScale().y / 2;//�v���C���[�̉������蔻��ϐ�

	Ground_Right_Collider = ground->GetPosition().x + ground->GetScale().x / 2; //�O���E���h�̉E�̓����蔻��ϐ�
	Ground_Left_Collider = ground->GetPosition().x - ground->GetScale().x / 2;  //�O���E���h�̍��̓����蔻��ϐ�
	Ground_Up_Collider = ground->GetPosition().y + ground->GetScale().y / 2;    //�O���E���h�̏�̓����蔻��ϐ�
	Ground_Bottom_Collider = ground->GetPosition().y - ground->GetScale().y / 2;//�O���E���h�̉��̓����蔻��ϐ�

	//�v���C���[�ƃO���E���h�̓����蔻��
	if (1.0f > Player_Left_Collider - Ground_Right_Collider && 1.0f > Ground_Left_Collider - Player_Right_Collider && 0.5f > Player_Bottom_Collider - Ground_Up_Collider)
	{
		return true;
	}
	else {
		return false;
	}
}


//Player��Gion�̓����蔻��
bool ColliderPlayer_Gion(GameObject* player, GameObject* gion)
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
	if (1.0f > Player_Left_Collider - Gion_Right_Collider && 1.0f > Gion_Left_Collider - Player_Right_Collider && 0.5f > Player_Bottom_Collider - Gion_Up_Collider)
	{
		std::cout << "Player�Ƌ[�����Փ˂��܂���" << std::endl;
  		return true;
	}
	else {
		return false;
	}
}


//��^�Ƌ[���̓����蔻��
bool ColliderFan_Gion(GameObject*fan, GameObject*gion)
{
	float PI = 3.14159265;
	float fanAngle = PI / 6;
	//��^�̏��擾
	float fanCenterX = fan->GetPosition().x-30;   //��^�̒��SX���W
	float fanCenterY = fan->GetPosition().y;   //��^�̒��SY���W
	float fanRadius = fan->GetScale().x / 2;   //��^�̔��a�i�X�P�[����X�������g�p�j

	//��^�̕����x�N�g�����E�����ɌŒ�
	float fanDirX = 1.0f;//�E�����̐���
	float fanDirY = 0.0f;//������̐���

	//�[���̏��擾
	float Gion_Right_Collider = gion->GetPosition().x + gion->GetScale().x / 2; //�[���̉E�[
	float Gion_Left_Collider = gion->GetPosition().x - gion->GetScale().x / 2;  //�[���̍��[
	float Gion_Up_Collider = gion->GetPosition().y + gion->GetScale().y / 2;    //�[���̏�[
	float Gion_Bottom_Collider = gion->GetPosition().y - gion->GetScale().y / 2;//�[���̉��[

	//�[���̎l�̒��_
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
				return true;//���_����^��
			}
		}
	}

	//�l�p�`�̕ӂ���^�̉~�ʂƌ������Ă��邩�m�F
	float edges[4][4] = {
		{Gion_Left_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Up_Collider},        //���
		{Gion_Right_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Bottom_Collider},   //�E��
		{Gion_Left_Collider,Gion_Bottom_Collider,Gion_Right_Collider,Gion_Bottom_Collider},//����
		{Gion_Left_Collider,Gion_Up_Collider,Gion_Left_Collider,Gion_Bottom_Collider}      //����
	};
	for (int i = 0; i < 4; ++i) {
		if (LineIntersectsCircle(edges[i][0], edges[i][1], edges[i][2], edges[i][3], fanCenterX, fanCenterY, fanRadius)) {
			std::cout << "�l�p�`�̕ӂ���^�̉~�ʂƌ������Ă��܂�" << std::endl;
			return true;//�l�p�`�̕ӂ���^�̉~�ʂƌ���
		}
	}
	//��^�̒��S���l�p�`���ɂ��邩�m�F
	if (fanCenterX >= Gion_Left_Collider && fanCenterX <= Gion_Right_Collider &&
		fanCenterY >= Gion_Bottom_Collider && fanCenterY <= Gion_Up_Collider) {
		return true;//��^�����S���l�p�`��
	}
	return false;//�ǂ�ɂ��Y�����Ȃ��ꍇ�A�������Ă��Ȃ�
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


void DrawFan(GameObject* fan, bool isColliding)
{
	//��^�̏��擾
	float centerX = fan->GetPosition().x;
	float centerY = fan->GetPosition().y;
	float radius = fan->GetScale().x / 2;
	float M_PI = 3.14159265;
	float fanAngle = M_PI / 6;//�J���p�x�i30�x�j
	float dirX = cosf(fan->GetRotation().z);
	float dirY = sinf(fan->GetRotation().z);

	//�F����
	float r, g, b;
	if (isColliding) {
		r = 1.0f; g = 0.0f; b = 0.0f;//��
	}
	else {
		r = 0.0f, g = 1.0f, b = 0.0f;//��
	}
}