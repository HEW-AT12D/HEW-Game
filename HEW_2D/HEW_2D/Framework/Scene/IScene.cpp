#include "IScene.h"

/**
 * @brief �V�[���J�ڊm�F�֐�
 * @return �V�[���J�ڃt���O
*/
bool IScene::GetChangeScene(void)
{
	return ChangeScene;
}

void IScene::SetChangeScene(bool _Flg)
{
	ChangeScene = _Flg;
}

/**
 * @brief �J�ڐ���m�F����֐�
 * @return �J�ڐ�̃V�[����
*/
SceneName IScene::GetRequestScene(void)
{
	return m_RequestNext;
}