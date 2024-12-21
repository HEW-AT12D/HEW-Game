#pragma once
#include "../../Game/ObjectManager/ObjectManager.h"


//! -----------設計メモ：ISceneを作った後の話-----------------
//! シーンクラスはテンプレートにして、基底クラスとしてISceneを持たせとくべきじゃない？？

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
	IScene(D3D11& _D3d11) :objectmanager(_D3d11) {};

	virtual ~IScene() {};

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Uninit(void) = 0;

	void SetChangeScene(bool _Flg);
	bool GetChangeScene(void);

protected:
	ObjectManager objectmanager;
	bool ChangeScene = false;
};
