#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../../Framework/Sound/sound.h"
#include "../../Framework/D3D11/D3D11.h"


/**
 * @brief タイトルシーンクラス
 * 
 * サウンド、背景などのゲームオブジェクトを配列（array）で持つ
 * 
 * オブジェクトをコンストラクタで代入しておき、シーンの初期化処理内でオブジェクトを初期化する
*/
class TitleScene :public IScene
{
public:
	TitleScene(D3D11& _D3d11) :IScene(_D3d11) {
		// オブジェクトの追加はシーンの初期化で行う
		// サウンドとかこのシーンのみ存在するものがあればその初期化を行う

	};
	~TitleScene() {};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:

};


