#pragma once
#include"../../../Game/Objcet/BaseObject/Object.h"



bool ColliderPlayer_Ground(GameObject*, GameObject*);//Player‚ÆGround‚Ì“–‚½‚è”»’èŠÖ”

bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”

bool ColliderFan_Gion(GameObject*, GameObject*);//îŒ^‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”

bool LineIntersectsCircle(float x1, float y1, float x2, float y2, float cx, float cy, float radius);// ü•ª‚Æ‰~‚ªŒğ·‚µ‚Ä‚¢‚é‚©”»’è‚·‚éŠÖ”

void DrawFan(GameObject*, bool);