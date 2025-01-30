#include "SceneManager.h"
#include "../../Game/Scene/StageSelectScene.h"
#include "../../Game/Scene/Stage1Scene.h"
#include "../../Game/Scene/Stage2Scene.h"
#include "../../Game/Scene/ResultScene.h"
#include "../../Game/Scene/GameScene.h"
#include "../../Game/Scene/TitleScene2.h"
#include "../../Game/Scene/TestScene.h"

/**
 * @brief �V�[���z�񏉊���
*/
void SceneManager::Init(void) 
{
	//! �^�C�g���V�[���𐶐����ăR���e�i�ɒǉ�
	Scenes.emplace(TITLE, std::make_unique<TitleScene>(D3d11));
	//Scenes���݃V�[�����^�C�g���V�[���ɐݒ�
	CurrentScene = TITLE;
	Scenes[CurrentScene]->Init();
}

/**
 * @brief �X�V
*/
void SceneManager::Update(void)
{
	// ���݃V�[���̍X�V
	Scenes[CurrentScene]->Update();


	// ����
	// ���݃V�[���Őݒ肳��Ă���J�ڐ�V�[�����m�F�����̃V�[���ɑJ��
	// �������V�[���ɔ�ڂ��Ƃ��Ă�ꍇ�͈�U�t�F�[�h�A�E�g���A���̃V�[���̏��������s���Ă���t�F�[�h�C��

	// ���݃V�[���̑J�ڃt���O�������Ă���ꍇ�A�V�[���J��
	if (Scenes[CurrentScene]->GetChangeScene())
	{
		// ���݃V�[�����X�e�[�W�I���Ȃ�A�J�ڐ�V�[���m�F���J�ڊ֐����s
		// �����łȂ��Ȃ�V�[���J�ڊ֐����s���邾��

		
		// �J�ڐ�V�[�����m�F���đJ�ڏ������s
		ChangeScene(Scenes[CurrentScene]->GetRequestScene());
		

		//// �V�[���I���ȊO�̏ꍇ�͈���ʍs
		//else
		//{
		//	switch (CurrentScene)
		//	{
		//	case TITLE:
		//		// �G���^�[�ŃX�e�[�W�I����
		//		// �f�o�b�O�p�ɃX�e�[�W�P�֔��
		//		ChangeScene(STAGESELECT);
		//		break;
		//	case STAGE1:
		//		// �G���^�[�Ń��U���g��
		//		ChangeScene(RESULT);
		//		break;
		//	case RESULT:	// ���݃V�[�������U���g�Ȃ�
		//		// �^�C�g���֖߂�A�V�[���̏�����
		//		ChangeScene(STAGESELECT);
		//		break;
		//	case TEST:
		//		ChangeScene(RESULT);
		//		break;
		//	default:
		//		break;
		//	}
		//}
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
	// �S�ẴV�[���̏I������
	for (auto& scene : Scenes)
	{
		// �V�[���̒��g�����
		scene.second.reset();
	}
	// �V�[���z��S�̂����
	Scenes.clear();
}

/**
 * @brief �V�[���؂�ւ��֐�
 * �^�C�g���A�I����ʁi�H�j�A�X�e�[�W�I���V�[���̓V�[���Ƃ��ĕێ��������Ă��������i�p�ɂɎg�����߁A���񐶐���������Ȃ��Ă��ǂ��Ȃ��H�j
 * @param  ���̃V�[���^�O
 * 
 * �t�F�[�h�C���Ƃ������������̂ŁA���̏ꍇ�A
 * �E�V�[���؂�ւ����؂�ւ��t���O�𗧂Ă�
 *�@ ���؂�ւ����Ɏ��V�[�������ƃt�F�[�h�A�E�g
 * �@�@���t�F�[�h�A�E�g������i�������͐�������������j�O�V�[��������A�t�F�[�h�C���i�����őO�V�[������j
*/
void SceneManager::ChangeScene(SceneName _Nextscene) {
	// �؂�ւ��O�̃V�[���X�e�[�W�I����ʂł͂Ȃ��i�ێ����Ă��������V�[���ł͂Ȃ��j�ꍇ�A
	if (CurrentScene != STAGESELECT)
	{
		// ���݃V�[�������
		DeleteScene(CurrentScene);
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
		case STAGESELECT:
			CreateScene<StageSelectScene>(STAGESELECT);
			break;
		case STAGE1:
			CreateScene<Stage1Scene>(STAGE1);
			break;
		case STAGE2:
			CreateScene<Stage2Scene>(STAGE2);
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

	// �؂�ւ����V�[���̏������������؂�ւ��O�V�[���Ɠ����V�[���Ɉȍ~�Ƃ��Ă�ꍇ�͂�����x�v���C���悤�Ƃ��Ă�̂ŏ���������܂łɃt�F�[�h�A�E�g�E�C�������Ƃ��K�v
	Scenes[CurrentScene]->Init();
}

/**
 * @brief �V�[���擾�֐�
 * @param _SceneName �V�[���̃^�O
 * @return �V�[���̃|�C���^
*/
IScene* SceneManager::GetScene(SceneName& _SceneName)
{
	// �V�[���̃C�e���[�^���擾
	auto iterator = Scenes.find(_SceneName);

	// �V�[�����������
	if (iterator != Scenes.end())
	{
		// �V�[���̃|�C���^��Ԃ�
		return iterator->second.get();
	}
	// ������Ȃ����nullptr��Ԃ�
	return nullptr;
}

/**
 * @brief �V�[���폜�֐�
 * @param _SceneName �폜�������V�[���̌^�imap�̃L�[�j

*/
void SceneManager::DeleteScene(SceneName _SceneName)
{
	// �w�肵���V�[�����폜
	Scenes.erase(_SceneName);
	std::cout << _SceneName << std::endl;
}