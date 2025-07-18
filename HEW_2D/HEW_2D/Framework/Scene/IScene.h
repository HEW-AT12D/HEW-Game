#pragma once
#include "../../Game/ObjectManager/ObjectManager.h"
#include "../Sound/sound.h"


enum FRAME {
	FRAME1,
	FRAME2,
	FRAME3,
	FRAME4,

	FRAME_MAX
};

enum SceneName {
	TITLE,			// タイトル
	STAGESELECT,	// ステージ選択
	TEST,
	STAGE1,			// ステージ2
	STAGE2,			// ステージ2
	RESULT,			// リザルト
	QUIT,			// ゲーム終了

	SCENE_MAX
};


/**
 * @brief シーンの抽象クラス
 *
 * 全てのシーンがこれを継承するのでポリモーフィズムでシーンを管理できる
 *
 * ここにオブジェクトマネージャ置いとくべき？
 *
 * シーン内のオブジェクトマネージャがオブジェクト生成時にd3dの参照を渡す
 */
class IScene
{
public:
	IScene(D3D11& _D3d11) :objectmanager(_D3d11), frame2(_D3d11) {
		m_Frame = FRAME1;
		m_MagCount = 1;
	};

	virtual ~IScene() {};

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void ChangeFRAME(void);

	virtual void SetChangeScene(bool _Flg);
	virtual bool GetChangeScene(void);

	virtual SceneName GetRequestScene(void);		// 次に遷移したいシーンを取得する関数

protected:
	Sound sound;					// サウンドクラス
	ObjectManager objectmanager;	// オブジェクトマネージャ
	ObjectManager frame2;           //frame2のオブジェクト
	SceneName m_RequestNext;		// 次に遷移したいシーン
	FRAME m_Frame;					// 現在フレーム
	bool ChangeScene = false;		// シーン切り替えフラグ
	bool ChangeFrame = false;		// フレーム切り替えフラグ
	int m_MagCount;					// マガジン数
};
