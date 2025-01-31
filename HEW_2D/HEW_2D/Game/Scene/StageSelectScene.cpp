#include "StageSelectScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/SceneManager/SceneManager.h"



void StageSelectScene::Init(void) {
	Sound::GetInstance().Play(BGM_STAGESELECT);

	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/StageSelectBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	
	// �X�e�[�W1�{�^��
	objectmanager.AddObject<GameObject>(UI, "STAGE1");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->Init(L"Game/Asset/UI/Stage1Button.png", 2, 1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetUV(Int2(1, 0));		// �ŏ��̓X�e�[�W1��I��

	// �ʏ펞�s���N�I�𒆉��F
	// �X�e�[�W2�{�^��
	objectmanager.AddObject<GameObject>(UI, "STAGE2");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->Init(L"Game/Asset/UI/Stage2Button.png", 2, 1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->SetPosition(Vector3(0.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	// �J�[�\��
	objectmanager.AddObject<GameObject>(UI, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->Init(L"Game/Asset/UI/TitleCursol.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Vector3(-250.0f, -10.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetScale(Vector3(300.0f, 450.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetUV(Int2(2, 0));


	std::cout << "STAGE1_SCENEInit" << std::endl;
}

void StageSelectScene::Update(void) {
	Input::GetInstance().Update();

	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p

	Vector3 Cursor_pos = objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->GetPosition();
	Int2 Stage1Button_UV = objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->GetUV();
	Int2 Stage2Button_UV = objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->GetUV();


	// �X�^�[�g�{�^�����͎擾
	// (�f�o�b�O�p)�G���^�[�L�[���͎擾
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_START) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		// �J�[�\���ʒu����̏ꍇ
		if (Cursor_pos.y == -10.0f)
		{
			// �J�ڐ�V�[�����X�e�[�W�ɐݒ�
			m_RequestNext = STAGE2;
		}
		
		// �J�[�\���ʒu�����̏ꍇ
		if (Cursor_pos.y == -300.0f)
		{
			// �J�ڐ���X�e�[�W2�ɐݒ�
			m_RequestNext = STAGE2;
		}
		// �V�[���J�ڃt���O�𗧂Ă�
		SetChangeScene(true);
		// BGM��~
		Sound::GetInstance().Stop(BGM_STAGESELECT);
	}
	else
	{
		// �V�[���J�ڃt���O�𗧂Ă�
		SetChangeScene(false);
	}


	
	
	//////////////////////////////////
	//			�J�[�\���ړ�
	//////////////////////////////////
	
	// ���{�^�����͊m�F
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_DPAD_DOWN) || Input::GetInstance().GetKeyPress(VK_DOWN))
	{
		Cursor_pos.y -= 300.0f;
		if (Cursor_pos.y < -300.0f)
		{
			Cursor_pos.y = -300.0f;
		}
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursor_pos);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}

	// ��{�^�����͊m�F
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_DPAD_UP) || Input::GetInstance().GetKeyPress(VK_UP))
	{
		Cursor_pos.y += 300.0f;
		if (Cursor_pos.y > -10.0f)
		{
			Cursor_pos.y = -10.0f;
		}
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursor_pos);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}
	
	// �J�[�\�����W�ɂ���ă{�^���̐F��ω�
	// �X�e�[�W1�I�𒆂̏ꍇ
	if (Cursor_pos.y == 0.0f)
	{
		// �X�e�[�W1�{�^���̉摜��ω�
		Stage1Button_UV.x = 1;	// �X�e�[�W1��I�𒆂�
		Stage2Button_UV.x = 0;	// �X�e�[�W2��ʏ펞��
	}
	// �X�e�[�W2�I�𒆂̏ꍇ
	else if (Cursor_pos.y == -300.0f)
	{
		// �X�e�[�W1�{�^���̉摜��ω�
		Stage1Button_UV.x = 0;	// �X�e�[�W1��ʏ펞��
		Stage2Button_UV.x = 1;	// �X�e�[�W2��I�𒆂�
	}
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE1").lock()->SetUV(Stage1Button_UV);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "STAGE2").lock()->SetUV(Stage2Button_UV);
}



void StageSelectScene::Draw(void) {
	objectmanager.Draw();
}

void StageSelectScene::Uninit(void) {
	// BGM��~
	Sound::GetInstance().Stop(BGM_STAGESELECT);
	objectmanager.Uninit();
}

