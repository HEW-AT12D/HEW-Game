#pragma once
#include "../Onomatopeia/IOnomatopoeia/IOnomatopoeia.h"

/**
 * @brief 擬音銃に使うマガジンクラス
 * →これをコンテナの配列にしてプレイヤーのメンバとして保持する
 * 
 * 〇メンバ変数
 * 　・銃に装填されているか？
 * 　・マガジン内部が空かどうか？
 * 
 * ・マガジン画像以外に擬音の画像が必要
 * ・当たり判定は不要
 * 
 * 
 * マガジン(一個目)
 * →初期化時にプレイヤーの
 * 
 * マガジンのUI(二個目以降)
 * →まずマガジンをオブジェクトして配置
 * 　→プレイヤーとだけ当たり判定を取る
 * 　　→プレイヤーが取得したらタグをUIに変更
 * 　　　→座標、スケールを変更して画面上の任意の場所に表示させる
 * 
*/
class Magazine : public GameObject
{
public:
	Magazine(D3D11 _D3d11) :GameObject(_D3d11) {
		// 最初はマガジンにはどの擬音も入っていない
		//m_Onomatopoeia = nullptr;
	}

	~Magazine();

	// マガジンに入った場合、その擬音の所有権はマガジンに移るはずなのでunique_ptr
	void SetOnomatopoeia(std::unique_ptr<IOnomatopoeia> _onomatopoeia);

private:
	//std::unique_ptr<IOnomatopoeia> m_Onomatopoeia;
};

