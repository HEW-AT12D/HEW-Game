#pragma once
#include "../SoundGun/SoundGun.h"
#include "../SoundGun/Magazine.h"


/**
 * @brief プレイヤークラス
 * 
 * ＜必要なもの＞
 * ・移動速度
 * ・ジャンプ力
 * ・当たり判定
 * ・擬音銃
 * ・マガジン
 * 
 * アニメーション問題：キャラごとにステート（状態）を持たせておき、その状態に応じたアニメーションを動かす
 * 
*/
class Player :public GameObject
{
public:
	Player(D3D11& _D3d11) :GameObject(_D3d11),Soundgun(_D3d11) {};
	~Player() {};
	
	void Update(void) override;		// プレイヤー固有の入力はここで取得する
	//void Draw(void);				// 擬音使用で描画方法変更があった場合ように宣言
	void Animation(STATE,Vector2) override;	// プレイヤー個別のアニメーション関数

private:
	SoundGun Soundgun;					// 擬音銃
	std::vector<Magazine> Magazines;	// マガジン（可変長）
};

