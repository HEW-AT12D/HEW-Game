#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


//template <class T, class U>
bool ColliderPlayer_Ground(Player* , GameObject* );	//Player��Ground�̓����蔻��֐�

bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player�Ƌ[���̓����蔻��֐�

bool ColliderFan_Gion(GameObject*, GameObject*);//��^�Ƌ[���̓����蔻��֐�

bool LineIntersectsCircle(float , float , float , float , float , float , float);// �����Ɖ~���������Ă��邩���肷��֐�

//void DrawFan(GameObject*, bool);
