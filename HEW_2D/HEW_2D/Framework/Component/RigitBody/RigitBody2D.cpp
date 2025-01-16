#include"RigitBody2D.h"

int RigitBody2D::NaturalFall(int position)
{
	velocity += gravity * steptime;
	position -= velocity * steptime;

	return position;
}