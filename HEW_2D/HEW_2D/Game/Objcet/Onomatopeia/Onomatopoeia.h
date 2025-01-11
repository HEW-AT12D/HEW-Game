#pragma once
#include "../BaseObject/GameObject.h"

/**
 * @brief 擬音クラス（基底クラス）
 *
 *
 * 同音異義語があるので複雑
 * →別画像と別アクションが必要
 * 
 * 擬音一つにつき
*/
class Onomatopoeia : public GameObject
{
public:
	Onomatopoeia();
	Onomatopoeia(D3D11 _D3d11) :GameObject(_D3d11) {

	};

	~Onomatopoeia() {};

private:

};

