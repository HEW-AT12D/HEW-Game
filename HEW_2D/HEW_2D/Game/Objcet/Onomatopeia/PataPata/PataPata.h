#pragma once
#include "../IOnomatopoeia/IOnomatopoeia.h"


/**
 * @brief パタパタ(羽ばたき)
 * 
 * TODO:2025/01/25 赤根 現状擬音のAction関数の引数に擬音の影響を受けるオブジェクトのポインタを渡してるので、引数なしで実行できるようにする
 * →直接付与されているオブジェクトのみで完結できるようにする
*/
class PataPata :public IOnomatopoeia
{
public:
	PataPata(D3D11& _D3d11) :IOnomatopoeia(_D3d11) {
		Max_altitude = 300.0f;		// 限界高度仮設定(Y:+400)
		Collider_check = false;
	}
	~PataPata();	//デストラクタ
	void Action(void) override;		// 付与されたオブジェクトに効果を与える
	void Action(std::weak_ptr<GameObject>, std::weak_ptr<Player>);	//オーバーロード

private:
	bool Collider_check;
	float Max_altitude;		//限界高度
};
