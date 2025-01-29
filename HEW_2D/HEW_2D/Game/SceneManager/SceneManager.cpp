#include "SceneManager.h"
// �������V�[���J�ڊm�F�p�ɃC���N���[�h
#include "../../Framework/Input/Input.h"


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


void SceneManager::Update(void)
{
	Scenes[CurrentScene]->Update();

	if (Input::GetInstance().GetKeyTrigger(VK_RETURN)) {
		//Scenes[CurrentScene]->SetChangeScene(STAGESELECT);
		Scenes[CurrentScene]->GetChangeScene();
	}

	// ����m�F�p
	// ���݃V�[���̑J�ڃt���O�������Ă���ꍇ�A�V�[���J��
	if (Scenes[CurrentScene]->GetChangeScene())
	{
		DeleteScene(CurrentScene);
		switch (CurrentScene)
		{
		case TITLE:
			// �G���^�[�ŃX�e�[�W�I����
			// �f�o�b�O�p�ɃX�e�[�W�P�֔��
			ChangeScene(GAME);
			break;
		case STAGESELECT:
			// �X�e�[�W�I���V�[���͕ێ���������̂ŃV�[���J�ڃt���O������false�ɕύX
			ChangeScene(GAME);
			break;
		case GAME:
			// �G���^�[�Ń��U���g��
			ChangeScene(RESULT);
			break;
		case RESULT:	// ���݃V�[�������U���g�Ȃ�
			// �^�C�g���֖߂�A�V�[���̏�����
			ChangeScene(STAGESELECT);
			break;
		case TEST:
			ChangeScene(RESULT);
			break;
		default:
			break;
		}
		
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
	// �؂�ւ��O�̃V�[�����^�C�g���A�X�e�[�W�I����ʂł͂Ȃ��i�ێ����Ă��������V�[���ł͂Ȃ��j�ꍇ�A
	if (CurrentScene != TITLE && CurrentScene != STAGESELECT)
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
			CreateScene<Stage2Scene>(STAGESELECT);
			break;
		case GAME:
			CreateScene<Stage2Scene>(GAME);
			break;
		case RESULT:
			CreateScene<ResultScene>(RESULT);
			break;
		case TEST:
			CreateScene<TestScene>(TEST);
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