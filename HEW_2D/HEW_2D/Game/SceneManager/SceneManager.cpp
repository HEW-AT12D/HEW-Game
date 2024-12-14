#include "SceneManager.h"
#include "../../Game/Scene/TitleScene.h"
#include "../../Game/Scene/ResultScene.h"
#include "../../Game/Scene/GameScene.h"

SceneManager::SceneManager()
{
	//! �^�C�g���V�[���𐶐����ăV�[���z��ɒǉ�
	Scenes.emplace(std::make_unique<TitleScene>());
	/*scenes[0] = std::make_unique<TitleScene>();
	scenes[1] = std::make_unique<GameScene>();
	scenes[2] = std::make_unique<TitleScene>();*/
}

SceneManager::~SceneManager()
{

}

/**
 * @brief �V�[���z�񏉊���
 * @param  
*/
void SceneManager::Init(void) 
{
	//! �V�[���̏�����

}

void SceneManager::Draw(void) {
	//! ���݃V�[���ɂ���Ă��̃V�[����`��
	//! �����ꂾ�ƃV�[���̉�����l�����ĂȂ��Ȃ��H�Y�������w�肵������Ă邩��vector�ȈӖ��Ȃ�����
	switch (CurrentScene)
	{
	case TITLE:
		Scenes[TITLE]->Draw();
		break;
	case GAME:
		Scenes[GAME]->Draw();
		break;
	case RESULT:
		Scenes[RESULT]->Draw();
		break;
	default:
		break;
	}
}

void SceneManager::Uninit(void) {
	// �V�[���̏I������
	Scenes[CurrentScene]->Uninit();
}

/**
 * @brief �V�[���؂�ւ��֐�
 * @param  
*/
void SceneManager::ChangeScene(SceneName _Scene) {
	this->CurrentScene = _Scene;
}
