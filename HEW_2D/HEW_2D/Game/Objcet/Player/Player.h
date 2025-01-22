#pragma once
#include "../SoundGun/SoundGun.h"
#include "../SoundGun/Magazine.h"
#include "../Character/Character.h"


/**
 * @brief プレイヤークラス
 * 
 * ＜必要なもの＞
 * ・移動速度
 * ・ジャンプ力
 * ・当たり判定
 * 
 * 
 * ↓の二つはプレイヤーのメンバとして持たせるのではなく、シーン内でオブジェクトマネージャからAddObjectを行い、そこから親オブジェクトとしてプレイヤーをセットする
 * ・擬音銃
 * ・マガジン
 * 
 * マガジン→取ったら画像出現→以降は擬音が入っていなくても画像が見える用にする
 * 
 * アニメーション問題：キャラごとにステート（状態）を持たせておき、その状態に応じたアニメーションを動かす
 * 
 * アニメーション
 * アクション実行中の場合毎フレームスプライト切り替えたい
 * →ボタン押してる時はアクション中
 * 
*/
class Player :public Character
{
public:
	Player(D3D11& _D3d11) :Character(_D3d11) {
		m_Velocity = { 0.0f };
		m_MoveSpeed = 5.0f;
		m_JumpPower = 10.0f;
	};
	~Player() {};
	
	void Update(void) override;		// プレイヤー固有の入力はここで取得する
	//void Draw(void) override;		// 擬音使用で描画方法変更があった場合用に宣言
	void Animation(STATE _Anim_Name);	// プレイヤー個別のアニメーション関数

private:
	//SoundGun Soundgun;					// 擬音銃,Soundgun(_D3d11)
	//std::vector<Magazine> Magazines;	// マガジン（可変長）
};

