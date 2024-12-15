#include "SceneManager.h"
#include "../../Game/Scene/StageSelectScene.h"
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

void SceneManager::Update(void)
{
	// �C�x���g�����ŃV�[���J��
	if (true)
	{

	}
	
}


void SceneManager::Draw(void) {
	//! ���݃V�[���ɂ���Ă��̃V�[����`��
	//! �����ꂾ�ƃV�[���̉�����l�����ĂȂ��Ȃ��H�Y�������w�肵������Ă邩��vector�ȈӖ��Ȃ�����
	//! �@��map�g���H�H�H
	
	// ���݃V�[���̕`��
	Scenes[CurrentScene]->Draw();
}

void SceneManager::Uninit(void) {
	// �V�[���̏I������
	Scenes[CurrentScene]->Uninit();
}

/**
 * @brief �V�[���؂�ւ��֐�
 * �^�C�g���A�I����ʁi�H�j�A�X�e�[�W�I���V�[���̓V�[���Ƃ��ĕێ��������Ă��������i�p�ɂɎg�����߁A���񐶐���������Ȃ��Ă��ǂ��Ȃ��H�j
 * @param  ���̃V�[���^�O
*/
void SceneManager::ChangeScene(SceneName _Nextscene) {
	// �؂�ւ��O�̃V�[�����^�C�g���A�I����ʁA�X�e�[�W�I����ʂł͂Ȃ��ꍇ�A
	if (CurrentScene != TITLE && CurrentScene != RESULT && CurrentScene != STAGESELECT)
	{
		// ���݃V�[�����
		Scenes.erase(CurrentScene);
	}

	// �؂�ւ��\��̃V�[�������݂��Ă��Ȃ��ꍇ
	if (Scenes.find(_Nextscene) == Scenes.end())
	{
		// �V�[���𐶐�����map�ɒǉ�
		switch (_Nextscene)
		{
		case TITLE:
			CreateScene<TitleScene>(TITLE);
			break;
		//case STAGESELECT:
		//	CreateScene<StageSelectScene>(STAGESELECT);
		//	break;
		case GAME:
			CreateScene<GameScene>(GAME);
			break;
		case RESULT:
			CreateScene<ResultScene>(RESULT);
			break;
		default:
			break;
		}
	}
	// ���݃V�[����؂�ւ�
	this->CurrentScene = _Nextscene;

	// �؂�ւ����V�[���̏�����
	Scenes[CurrentScene]->Init();
	
}
