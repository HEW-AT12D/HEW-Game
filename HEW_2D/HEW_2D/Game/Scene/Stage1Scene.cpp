#include "Stage1Scene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../Objcet/Camera/Camera.h"


/**
 * @brief �^�C�g���V�[���̏�����
 *
 * �V�[�����Ƃɏ������͍ŏ��̈�x�̂�
 * ��
 * 
 * �X�e�[�W�́A�c�Q�O�}�X�����S�O�}�X
*/
void Stage1Scene::Init(void) {
	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();

	// BGM�Đ�
	Sound::GetInstance().Play(BGM_INGAME);
	

	//-----------------------
	//-----�I�u�W�F�N�g�ǉ�-----
	//-----------------------
	// TODO:1218�����܂� �I�u�W�F�N�g�̊Ǘ���enum����ύX��tag�Ɩ��O�ɂ�����
	
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	
	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(260.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

	//�[���i�|�����j
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Wiin.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	
	// �}�K�W��(���������ԂŃX�^�[�g�A�����Ă�͈̂����)
	// 1��(�h�H����p)
	objectmanager.AddObject<Magazine>(UI, "SpecialMagazine");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 2��
	objectmanager.AddObject<Magazine>(UI, "Magazine1");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// 3��
	objectmanager.AddObject<Magazine>(UI, "Magazine2");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// 3�͎q�I�u�W�F�N�g�ɐݒ肵��UI�ɕύX���Ă���
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "SpecialMagazine").second);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	// 3��(�t�B�[���h�ɗ����Ă�}�K�W��)
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// �n��
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	// �n��2
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(700.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// �N���X�w�A
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(30.0f, 30.0f, 0.0f));
	// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//�}�K�W���̊O�g(�����ʒu�͈�ԍ���̃}�K�W��)
	objectmanager.AddObject<GameObject>(UI, "Frame");    // ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

	//// �J����
	//objectmanager.AddObject<Camera>(CAMERA, "Camera");    // ���O�v�ύX
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->Init(L"Game/Asset/UI/BlackImage.png");
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	std::cout << "GameSceneInit" << std::endl;
	//// UI1(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER);
}



void Stage1Scene::Update(void)
{

	// ���͏��̍X�V
	Input::GetInstance().Update();
	// �X�e�B�b�N���͒l���擾
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// �E�X�e�B�b�N����
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// ���X�e�B�b�N����

	// �V�[���X�V�ɕK�v�ȏ����擾
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");		// �v���C���[
	auto grounds = objectmanager.GetObjects<GameObject>(GROUND);						// �n��(�z��)
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");	// �n��1(��)
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");	// �n��2
	auto onopatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);			// �[��(�z��)
	auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");		// �[��(��)
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");			// �G(��)
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");	// �N���X�w�A


	// ���͊Ǘ�
	// �E�ړ�
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		//sound.Play(SOUND_LABEL_BGM000);
		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// ���ړ�
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// �W�����v
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonPress(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}


	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		SetChangeScene(true);
	}


	//----------------�����蔻��-----------------------

	ColliderPlayer_Ground(playerShared.second, grounds);			// �v���C���[�ƒn��
	Collider_Objects_Objects(onopatopoeias,grounds);		// �[���ƒn��
	//ColliderPlayer_Ground(playerShared, groundShared2);


	// �N���X�w�A�̓��͎擾(�{���̓v���C���[�̃t���O�𗧂ĂāA�v���C���[�̍X�V�̒��ŃN���X�w�A�𓮂����ׂ�)
	if (Input::GetInstance().GetKeyPress(VK_UP) || RightStickInput.y > 0.1f)
	{
		crosshairShared.lock()->SetMoveUp(true);
	}
	else {
		crosshairShared.lock()->SetMoveUp(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_DOWN) || RightStickInput.y < -0.1f)
	{
		crosshairShared.lock()->SetMoveDown(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveDown(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_RIGHT) || RightStickInput.x > 0.1f)
	{
		crosshairShared.lock()->SetMoveRight(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveRight(false);
	}

	if (Input::GetInstance().GetKeyPress(VK_LEFT) || RightStickInput.x < -0.1f)
	{
		crosshairShared.lock()->SetMoveLeft(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveLeft(false);
	}



	////�[���̋z����247�s�ڂ̋z�����ݏ����ɕύX�A����
	//if (Input::GetInstance().GetKeyPress(VK_F))
	//{
	//	if (ColliderFan_Gion(playerShared, gionShared))
	//	{
	//		//���̉������ɂ܂Ƃ߂Ă����������H
	//		playerShared.lock()->Suction(gionShared, playerShared);
	//		//�[���̋z�����ݎ��̉�]�E�T�C�Y�ύX
	//		gionShared.lock()->Onomatopeia_ObjectMave(gionShared);
	//	}
	//}

	// �}�K�W���ɋ[���������Ă���΃G�C���̈ʒu�ɔ���
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger())
	{
		// �}�K�W���ɋ[�������U����Ă��邩�`�F�b�N
		if (playerShared.second->GetLoadedBullet())
		{
			playerShared.second->SetIsShot(true);


			//--------------------------------------
			//			�[���̃^�O�ύX����
			//--------------------------------------

			// �����I�u�W�F�N�g�}�l�[�W������[���̏�񎝂��Ă����ق����ǂ������H

			// �����ŋ[���̃^�O��UI����[���ɕύX
			// ���[���̃|�C���^�����킩���Ă�̂ɃL�[�̓��肪�X���[�Y�ɂł��Ȃ��̂ł���ς�Ǘ����@�ς����ق�������(�o�^����Ă�^�O�𖈃t���[���m�F���ē���������Ƃ�)

			// �����ł͎����Ă����[�����L���X�g�ł����^�ɂ���Ă��̋[���̃^�O��ς���悤�ɂ���
			auto bullet = playerShared.second->GetLoadedBullet();

			// �[����"�p�^�p�^"�̏ꍇ
			if (dynamic_cast<PataPata*>(bullet))
			{
				objectmanager.ChangeTag(UI, "PataPata", ONOMATOPOEIA);
			}
			// "�r���r��"�̏ꍇ
			else if (dynamic_cast<BiriBiri*>(bullet))
			{
				objectmanager.ChangeTag(UI, "BiriBiri", ONOMATOPOEIA);
			}
			// "�|����"�̏ꍇ
			else if (dynamic_cast<Poyon*>(bullet))
			{
				objectmanager.ChangeTag(UI, "Poyon", ONOMATOPOEIA);
			}
			// ����ȊO(�s���Ȍ^)�̏ꍇ
			else
			{
				throw std::runtime_error("�[�����L���X�g�ł��܂���ł���");
			}
			// SE�Đ�
			Sound::GetInstance().Play(SE_SHOT);
		}
	}


	//playerShared.lock()->Shot(gionShared);


	// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
	// �v���C���[���̐�^�Ɠ������Ă�[����T����(��ԋ߂���)�������Ă�[�����z������
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	{
		// �z�����߂�[�����Ȃ��Ă����o�����s��
		// SE�Đ�
		Sound::GetInstance().Play(SE_SUCTION);
		// 

		// �z�����߂�[����T��
		// ���̃t���[�����̃^�O���[���̂��̑S�Ď擾������ƃv���C���[����o���^�̓����蔻����擾
		//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
		auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);

		// �[����0�ł͂Ȃ����
		if (!onomatopoeias.empty())
		{
			// ��`�Ƃ̓����蔻����擾
			auto HitOnomatopoeia = ColliderFan_Gion(playerShared.second, onomatopoeias);

			// �|�C���^�ɒl�������Ă����(��`�͈͓��ɓ��������[���������)
			if (HitOnomatopoeia.second)
			{
				// �[���̋z�����ݎ��s
				playerShared.second->SetIsSuction(true);			// �v���C���[�̏�Ԃ��z�����ݒ��ɐݒ�

				// �z�����ݏ������I�������
				if (playerShared.second->Suction(HitOnomatopoeia.second))
				{
					// �z�����ݏ������I��������ɋ[���̃^�O��UI�ɕύX����
					objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);

					//// �}�K�W���ԍ������ֈڍs
					//playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() + 1);
				}
			}
			// �[����0(�z�����ݒ��ɐ�^�͈͂���[�������Ȃ��Ȃ����ꍇ)
			else
			{
				// �v���C���[�̏�Ԃ�ύX
				playerShared.second->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
			}
		}
		// �[����0(�t���[�����̋[�����Ȃ��ꍇ)
		else
		{
			// �v���C���[�̏�Ԃ�ύX
			playerShared.second->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
		}
		
	}
	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���

	/////////////////////////////////////////////////////
	// �����Ń}�K�W����UI�ɂȂ��Ă��Ȃ���Γ����蔻������
	/////////////////////////////////////////////////////
	if (m_MagCount >= 1)
	{
		// �P�̃V�[���ɗ����Ă�}�K�W�����͈�Ȃ̂ŁA�V�[���̎��}�K�W���J�E���g���P�Ȃ�܂��������Ă��Ȃ�
		// ������`�F�b�N����

		auto magShared = objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine3");

		// �}�K�W���ƒn��
		Collider_toGround(std::weak_ptr<Magazine>(magShared.second), groundShared);
		// �v���C���[�ƃ}�K�W��������������
		if (Collider_Player_to_Magazine(playerShared.second, objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")))
		{
			// �}�K�W���̃^�O��ύX
			objectmanager.ChangeTag(magShared.first.first, magShared.first.second, UI);
			// �v���C���[�̎q�I�u�W�F�N�g�ɐݒ�
			playerShared.second->SetChild(magShared.second);
			/*magShared.second->SetScale(Vector3(75.0f, 75.0f, 0.0f));
			magShared.second->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));*/
			m_MagCount = 0;

			// �T�E���h�Đ�
			Sound::GetInstance().Play(SE_GETMAGAZINE);
		}

	}

	/////////////////////////////////
	// �J�[�\���ړ����ċ[���̑I��
	/////////////////////////////////
	
	// R1�Ń}�K�W���J�[�\���E�ړ�
	if (Input::GetInstance().GetKeyTrigger(VK_P) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		// �J�[�\���̍��W�擾
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();

		// �h�H���p�}�K�W����������ԍŌ�̃}�K�W����I�����Ă��Ȃ����
		if (playerShared.second->GetMagNumber() != playerShared.second->GetMagCount() - 1)
		{
			// �}�K�W���I��ԍ����P���₵��
			playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() + 1);
			// �J�[�\�����E�Ɉړ�
			p_frame.x += 120.0f;
		}
		// ��ԍŌ�̃}�K�W����I�����Ă���ꍇ
		else
		{
			// �}�K�W���I��ԍ����P(�h�H���p�}�K�W����������ԍŏ�)�ɖ߂���
			playerShared.second->SetMagNumber(1);
			// �J�[�\���������ʒu�Ɉړ�
			p_frame.x = -900.0f;
		}
		// ���W��ݒ�
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}
	// L1�Ń}�K�W���J�[�\�����ړ�
	if (Input::GetInstance().GetKeyTrigger(VK_O) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_LEFT_SHOULDER))
	{
		// �J�[�\���̍��W�擾
		Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();

		// �h�H���p�}�K�W����������ԍŏ��̃}�K�W����I�����Ă��Ȃ����
		if (playerShared.second->GetMagNumber() != 1)
		{
			Sound::GetInstance().Play(SE_CLICK);
			// �}�K�W���I��ԍ����P���炵��
			playerShared.second->SetMagNumber(playerShared.second->GetMagNumber() - 1);
			// �J�[�\�������Ɉړ�
			p_frame.x -= 120.0f;
		}
		// ��ԍŏ��̃}�K�W����I�����Ă���ꍇ
		else
		{
			// �}�K�W���I��p�J�[�\�����擾
			auto magcursor = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock();
			// �}�K�W���I��ԍ���(�h�H���p�}�K�W��������)��Ԍ��ɂ���
			playerShared.second->SetMagNumber(playerShared.second->GetMagCount() - 1);
			// �J�[�\������Ԍ��̈ʒu�Ɉړ�
			p_frame.x = -900.0f + magcursor->GetScale().x * (playerShared.second->GetMagCount() - 2);	// �����ʒu + �J�[�\���̑傫�� * �}�K�W����(�h�H������Ȃ��̂�-2)
		}
		// ���W��ݒ�
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		// SE�Đ�
		Sound::GetInstance().Play(SE_CLICK);
	}

	// �}�K�W���Ƃ̓����蔻��𖈃t���[����遨�}�K�W�����擾�����炻�̔���`�F�b�N�͂��Ȃ��Ă���
	//objectmanager.Collider_Player_to_Object();		// �����œ���������}�K�W�������P���炷

	objectmanager.Update();
	
}

void Stage1Scene::Draw(void) {
	objectmanager.Draw();
}

void Stage1Scene::Uninit(void) {
	// BGM��~
	Sound::GetInstance().Stop(BGM_INGAME);
	objectmanager.Uninit();
}
