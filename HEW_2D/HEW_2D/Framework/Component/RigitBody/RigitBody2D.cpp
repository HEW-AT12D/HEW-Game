#include"RigitBody2D.h"

/*!
*	�d�͂�K�p������֐�
*	�I�u�W�F�N�g�̍����ƃW�����vor�������n�߂Ă���̎��ԁA�����x���K�v
*	
*/
int RigitBody2D::NaturalFall(int position_y,double time,double velocity)
{

	velocity += gravity * time;		//���x�̌v�Z
	position_y -= velocity * time;	//���x���炙���W���Z�o

	return position_y;
}