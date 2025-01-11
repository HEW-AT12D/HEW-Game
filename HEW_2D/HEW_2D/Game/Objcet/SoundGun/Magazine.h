#pragma once
#include "../Onomatopeia/Onomatopoeia.h"

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
*/
class Magazine : public GameObject
{
public:
	Magazine();
	Magazine(D3D11 _D3d11) :GameObject(_D3d11) {

	}

	~Magazine();

private:
	std::unique_ptr<Onomatopoeia> Onomatopoeia;
};

