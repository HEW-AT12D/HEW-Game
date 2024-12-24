#include "IScene.h"


bool IScene::GetChangeScene(void)
{
	return ChangeScene;
}

void IScene::SetChangeScene(bool _Flg)
{
	ChangeScene = _Flg;
}
