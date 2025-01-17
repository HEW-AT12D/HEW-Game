#pragma once
#include "../../BaseObject/GameObject.h"


/**
 * @brief 擬音クラス（基底クラス）
 *
 *
 * 同音異義語があるので複雑
 * →別画像と別アクションが必要
 * 
 * ・音のデータ(意味の数だけ)
 * ・擬音一つにつき１つ以上の動きがある
*/
class IOnomatopoeia : public GameObject
{
public:
	IOnomatopoeia(D3D11 _D3d11) :GameObject(_D3d11) {

	};

	virtual ~IOnomatopoeia() {};
	virtual void Action(void) = 0;	// 擬音のがオブジェクトに与える動き(ここで画像の動きをいじる)

protected:
	GameObject* m_AttachedObj;		// 擬音が付与されているオブジェクト
	std::string m_Name;				// 擬音の名前
};

