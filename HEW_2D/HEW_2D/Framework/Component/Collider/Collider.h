#pragma once
#include"../../../Game/Objcet/BaseObject/Object.h"



bool ColliderPlayer_Ground(GameObject*, GameObject*);//Player��Ground�̓����蔻��֐�

bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player�Ƌ[���̓����蔻��֐�

bool ColliderFan_Gion(GameObject*, GameObject*);//��^�Ƌ[���̓����蔻��֐�

bool LineIntersectsCircle(float x1, float y1, float x2, float y2, float cx, float cy, float radius);// �����Ɖ~���������Ă��邩���肷��֐�

void DrawFan(GameObject*, bool);