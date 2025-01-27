#pragma once
#include "../../Framework/Scene/IScene.h"


/**
 * @brief タイトルシーンクラス
 *
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
 *
 * オブジェクトをコンストラクタで代入しておき、シーンの初期化処理内でオブジェクトを初期化する
*/
class Re_TitleScene :public IScene
{
public:
	Re_TitleScene(D3D11& _D3d11) :IScene(_D3d11) {
		// オブジェクトの追加はシーンの初期化で行う
		// サウンドとかこのシーンのみ存在するものがあればその初期化を行う

	};
	~Re_TitleScene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:

};
