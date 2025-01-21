#pragma once
#include"../../../../Game/Objcet/BaseObject/Object.h"


//template <class T, class U>
bool ColliderPlayer_Ground(Player* , GameObject* );	//Player‚ÆGround‚Ì“–‚½‚è”»’èŠÖ”

bool ColliderPlayer_Gion(GameObject*, GameObject*);//Player‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”

bool ColliderFan_Gion(GameObject*, GameObject*);//îŒ^‚Æ‹[‰¹‚Ì“–‚½‚è”»’èŠÖ”

bool LineIntersectsCircle(float , float , float , float , float , float , float);// ü•ª‚Æ‰~‚ªŒğ·‚µ‚Ä‚¢‚é‚©”»’è‚·‚éŠÖ”

//void DrawFan(GameObject*, bool);
