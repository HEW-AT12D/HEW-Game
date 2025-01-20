#pragma once
#include "../BaseObject/GameObject.h"



/**
 * @brief 全キャラクターの元となるクラス
 * シーン側では入力の取得、フラグ立てだけを行い、このクラスの派生クラスで個々の動きを書く
*/
class Character:public GameObject
{
public:
	Character();
	~Character();

protected:

};

Character::Character()
{
}

Character::~Character()
{
}