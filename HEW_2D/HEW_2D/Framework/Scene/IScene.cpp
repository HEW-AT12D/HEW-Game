#include "IScene.h"

/**
 * @brief シーン遷移確認関数
 * @return シーン遷移フラグ
*/
bool IScene::GetChangeScene(void)
{
	return ChangeScene;
}

void IScene::SetChangeScene(bool _Flg)
{
	ChangeScene = _Flg;
}
