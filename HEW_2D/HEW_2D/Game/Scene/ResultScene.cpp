#include "ResultScene.h"
#include "../../Framework/Input/Input.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include <Xinput.h>

void ResultScene::Init(void) {
	// �I�u�W�F�N�g�ǉ�
	//�w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "background").lock()->SetScale(Vector3(1960.0f, 1080.0f, 0.0f));

	objectmanager.AddObject<GameObject>(OBJECT, "Cursol");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->Init(L"Game/Asset/UI/TitleCursol.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(Vector3(-250.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetScale(Vector3(300.0f, 300.0f, 0.0f));

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE1");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->Init(L"Game/Asset/UI/BacktoTitleButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));
	Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
	Button2.x = 1;
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);

	objectmanager.AddObject<Poyon>(OBJECT, "STAGE2");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->Init(L"Game/Asset/UI/EndButton.png", 2, 1);
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetScale(Vector3(500.0f, 400.0f, 0.0f));

	

	// �v���C���[
	/*objectmanager.AddObject<Player>(PLAYER, "Player_Result");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetPosition(Vector3(-500.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));*/

	//// �n��
	//objectmanager.AddObject<GameObject>(GROUND, "Ground_Result");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	std::cout << "ResultSceneInit" << std::endl;
}


void ResultScene::Update(void) {
	Input::GetInstance().Update();
	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}

	objectmanager.Update();
	

	if(Input::GetInstance().GetKeyPress(VK_DOWN)){
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();
		cursol_pos.y = -400.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(cursol_pos);
		Int2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->GetUV();
		Button1.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetUV(Button1);
		Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
		Button2.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);
	}

	if (Input::GetInstance().GetKeyPress(VK_UP)) {
		Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();
		cursol_pos.y = -200.0f;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->SetPosition(cursol_pos);
		Int2 Button1 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->GetUV();
		Button1.x = 0;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE2").lock()->SetUV(Button1);
		Int2 Button2 = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->GetUV();
		Button2.x = 1;
		objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "STAGE1").lock()->SetUV(Button2);
	}
	Vector3 cursol_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Cursol").lock()->GetPosition();

	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{

		if (cursol_pos.y == -200.0f)
		{
			m_RequestNext = TITLE;
			SetChangeScene(true);
		}

		if (cursol_pos.y == -400.0f)
		{
			m_RequestNext = QUIT;
			SetChangeScene(true);
		}
	}

	//// �X�e�B�b�N���͒l���擾
	//Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// �E�X�e�B�b�N����
	//Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// ���X�e�B�b�N����

	//auto playerResult = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result");
	//auto groundResult = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground_Result");
	////playerResult.lock()->Update();
	///*if (!BoxCollider2(playerResult.lock(), groundResult.lock(), playerResult.lock()))
	//{
	//	playerResult.lock()->SetOnGround(false);
	//}*/

	//// ���͊Ǘ�
	//	// �E�ړ�
	//if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetMoveRight(true);
	//	//sound.Play(SOUND_LABEL_BGM000);
	//	//�f�o�b�N�p
	//	//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	//}
	//// ���ړ�
	//if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetMoveLeft(true);

	//	//�f�o�b�N�p
	//	//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	//}
	//// �W�����v
	//if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	//{
	//	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player_Result").lock()->SetJump(true);
	//	//�f�o�b�N�p
	//	//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	//}

	//// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
	//	// �v���C���[���̐�^�Ɠ������Ă�[����T����(��ԋ߂���)�������Ă�[�����z������
	//if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	//{
	//	// �z�����߂�[����T��
	//	// ���̃t���[�����̃^�O���[���̂��̑S�Ď擾������ƃv���C���[����o���^�̓����蔻����擾
	//	//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
	//	auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);

	//	//�o�C�u���[�V�����X�^�[�g
	//	Input::GetInstance().SetVibration(0.5f, 1.0f);

	//	// �[����0�ł͂Ȃ����
	//	if (!onomatopoeias.empty())
	//	{

	//		// ��`�Ƃ̓����蔻����擾
	//		auto HitOnomatopoeia = ColliderFan_Gion(playerResult.lock(), onomatopoeias);

	//		// �|�C���^�ɒl�������Ă����(��`�͈͓��ɓ��������[���������)
	//		if (HitOnomatopoeia.second)
	//		{
	//			// �[���̋z�����ݎ��s
	//			playerResult.lock()->SetIsSuction(true);			// �v���C���[�̏�Ԃ��z�����ݒ��ɐݒ�

	//			// �z�����ݏ������I�������
	//			if (playerResult.lock()->Suction(HitOnomatopoeia.second))
	//			{

	//				// �z�����ݏ������I��������ɋ[���̃^�O��UI�ɕύX�A�ˌ�����Ƃ��Ƀ^�O���[���ɕύX���鏈�����܂�
	//				objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);
	//				/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
	//				gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
	//			}
	//		}
	//		// �[����0(�z�����ݒ��ɐ�^�͈͂���[�������Ȃ��Ȃ����ꍇ)
	//		else
	//		{
	//			// �v���C���[�̏�Ԃ�ύX
	//			playerResult.lock()->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
	//		}
	//	}
	//	// �[����0(�t���[�����̋[�����Ȃ��ꍇ)
	//	else
	//	{
	//		// �v���C���[�̏�Ԃ�ύX
	//		playerResult.lock()->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
	//	}
	//}
	//else {
	//	Input::GetInstance().SetVibration(0.0f, 0.0f); //�o�C�u���[�V����������
	//}

	//if (Input::GetInstance().GetKeyTrigger(VK_RETURN) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_Y))
	//{
	//	//������TITLE�ɖ߂�
	//	m_RequestNext = TITLE;
	//	SetChangeScene(true);
	//}

}


void ResultScene::Draw(void) {
	objectmanager.Draw();
}


void ResultScene::Uninit(void) {

}

void ResultScene::ChangeFRAME(void) {
	std::cout << "ChangeFRAME�֐�" << std::endl;
}