#include "TitleScene.h"
#include "../../Framework/Input/Input.h"



void TitleScene::Init(void) {
	Sound::GetInstance().Play(BGM_TITLE);

	// �w�i
	objectmanager.AddObject<Player>(ENEMY, "player");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(ENEMY, "player").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	//�^�C�g�����S
	objectmanager.AddObject<Player>(UI, "TitleLogo");
	objectmanager.GetGameObjectPtr<Player>(UI, "TitleLogo").lock()->Init(L"Game/Asset/UI/TitleLogo.png");
	objectmanager.GetGameObjectPtr<Player>(UI, "TitleLogo").lock()->SetPosition(Vector3(-400.0f, 300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(UI, "TitleLogo").lock()->SetScale(Vector3(1400.0f, 900.0f, 0.0f));
	Vector3 r_rotation = objectmanager.GetGameObjectPtr<Player>(UI, "TitleLogo").lock()->GetRotation();
	r_rotation.z = 15.0f;
	objectmanager.GetGameObjectPtr<Player>(UI, "TitleLogo").lock()->SetRotation(r_rotation);

	//start���S
	objectmanager.AddObject<GameObject>(UI, "start");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->Init(L"Game/Asset/UI/StartButton.png",2.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->SetPosition(Vector3(500.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "start").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	//end���S
	objectmanager.AddObject<GameObject>(UI, "end");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->Init(L"Game/Asset/UI/EndButton.png", 2.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "end").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	// �J�[�\��
	objectmanager.AddObject<GameObject>(UI, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->Init(L"Game/Asset/UI/CharacterCursor.png", 3.1);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetUV(Int2(2, 0));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Vector3(300.0f, -170.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetScale(Vector3(300.0f, 450.0f, 0.0f));

	//�L�����N�^�[���S
	objectmanager.AddObject<GameObject>(UI, "PlayerLogo");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "PlayerLogo").lock()->Init(L"Game/Asset/Character/Player.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "PlayerLogo").lock()->SetPosition(Vector3(-400.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "PlayerLogo").lock()->SetScale(Vector3(800.0f, 900.0f, 0.0f));
	Vector3 c_rotation = objectmanager.GetGameObjectPtr<GameObject>(UI, "PlayerLogo").lock()->GetRotation();
	c_rotation.z = 15.0f;
	objectmanager.GetGameObjectPtr<GameObject>(UI, "PlayerLogo").lock()->SetRotation(c_rotation);

	std::cout << "TitleSceneInit" << std::endl;
}

void TitleScene::Update(void) {
	// ���͏��̍X�V
	Input::GetInstance().Update();

	// �X�e�B�b�N���͒l���擾
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// �E�X�e�B�b�N����
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// ���X�e�B�b�N����
	
	Vector3 Cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->GetPosition();

	
	// �Q�[���Z���N�g��ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_START) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		// �J�[�\���ʒu����̏ꍇ
		if (Cursol_pos.y == -170.0f)
		{
			// �J�ڐ�V�[�����X�e�[�W�I���ɐݒ�
			m_RequestNext = STAGESELECT;
		}

		// �J�[�\���ʒu�����̏ꍇ
		if (Cursol_pos.y == -370.0f)
		{
			// �J�ڐ���Q�[���I���ɐݒ�
			m_RequestNext = QUIT;
		}
		// �V�[���J�ڃt���O�𗧂Ă�
		SetChangeScene(true);
		// BGM��~
		Sound::GetInstance().Stop(BGM_TITLE);
	}
	else
	{
		// �V�[���J�ڃt���O�𗧂Ă�
		SetChangeScene(false);
	}

	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_DPAD_DOWN) || Input::GetInstance().GetKeyPress(VK_DOWN))
	{
		Cursol_pos.y = -370.0f;
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursol_pos);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}

	// ��{�^�����͊m�F
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_DPAD_UP) || Input::GetInstance().GetKeyPress(VK_UP))
	{
		Cursol_pos.y = -170.0f;
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Cursol").lock()->SetPosition(Cursol_pos);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	
	objectmanager.Uninit();
}

//�I�m�}�g�y��Move�֐�
void TitleScene::Title_Onomatope_Move(std::weak_ptr<GameObject>_onomatope,float deltaTime)
{
	
}
