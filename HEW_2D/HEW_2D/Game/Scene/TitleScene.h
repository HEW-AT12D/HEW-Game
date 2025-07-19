#pragma once
#include "../../Framework/Scene/IScene.h"


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
	TitleScene(D3D11& _D3d11, Sound& _sound) :IScene(_D3d11, _sound) {
		// オブジェクトの追加はシーンの初期化で行う
		// サウンドとかこのシーンのみ存在するものがあればその初期化を行う
	};
	~TitleScene() {
		Uninit();
	};
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;
	void ChangeFRAME(void)override;

	void Title_Onomatope_Move(std::weak_ptr<GameObject>,float); //TitleSceneの装飾用の擬音の動き

protected:
	
};
