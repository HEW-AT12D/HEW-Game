#pragma once
#include "../../../Game/SceneManager/SceneManager.h"
#include "../../../Framework/D3D11/D3D11.h"
#include"../../../Game/Scene/Stage1Scene.h"
#include "../../../Framework/Sound/sound.h"

/**
 * @brief ゲームクラス
 * アプリケーションクラスが保持するゲームクラス
 * →このクラスを切り替えれば他のゲームでもこの外側のクラスは使いまわせる
*/
class Game
{
public:
	// コンストラクタ(ここでサウンドマネージャー生成)
	Game(D3D11& _D3d11) :m_pGameSound(std::make_unique<Sound>()), scenemanager(_D3d11, *m_pGameSound) {};
	~Game() {};

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	std::unique_ptr<Sound> m_pGameSound;	// ゲーム全体のサウンド管理クラス(ゲームごとに使う音は違うのでここに配置)
	SceneManager scenemanager;				// シーン管理クラス
};
