#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"


/**
 * @brief �^�C�g���V�[���̏�����
 *
 * �V�[�����Ƃɏ������͍ŏ��̈�x�̂�
 * ��
 *
 * �X�e�[�W�́A�c�Q�O�}�X�����S�O�}�X
*/
void TitleScene::Init(void) {
	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();


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
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/Cyclon.png", 4, 1);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


	//�[���i�ǂ���j
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	// �}�K�W��(���������ԂŃX�^�[�g�A�����Ă�͈̂����)
	// ���
	objectmanager.AddObject<Magazine>(UI, "Magazine1");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	// ���
	objectmanager.AddObject<Magazine>(UI, "Magazine2");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// ��͎q�I�u�W�F�N�g�ɐݒ肵��UI�ɕύX���Ă���
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second);

	// �ύX����ׂ����Ɓ��擾�����}�K�W�����������莩�g�̏��L�I�u�W�F�N�g�Ƃ��Đݒ肷��
	// ��
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->Set
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	// �O��
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


	// �n��
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	// �n��2
	objectmanager.AddObject<GameObject>(OBJECT, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->SetPosition(Vector3(700.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(OBJECT, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	// �N���X�w�A
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(30.0f, 30.0f, 0.0f));
	// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	std::cout << "GameSceneInit" << std::endl;
	//// UI1(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER);
}



void TitleScene::Update(void)
{

	// ���͏��̍X�V
	Input::GetInstance().Update();

	// �V�[���X�V�ɕK�v�ȏ����擾
	auto playerShared = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2");
	auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime");
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");


	// ���͊Ǘ�
	DirectX::XMFLOAT2 PlayerMove = Input::GetInstance().GetLeftAnalogStick();
	if (PlayerMove.x > 0.0f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	if (PlayerMove.x < 0.0f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}

	// �W�����v
	if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}


	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}


	//----------------�����蔻��-----------------------

	ColliderPlayer_Ground(playerShared, groundShared);

	//! �N���X�w�A�̓��͎擾(�{���̓v���C���[�̃t���O�𗧂ĂāA�v���C���[�̍X�V�̒��ŃN���X�w�A�𓮂����ׂ�)
	//! �E�X�e�B�b�N�̍��W������čX�V����
	DirectX::XMFLOAT2 crosshairSharedMove = Input::GetInstance().GetRightAnalogStick();
	if (crosshairSharedMove.x < 0.0f)
	{
		crosshairShared.lock()->SetMoveLeft(true);
		crosshairShared.lock()->SetMoveRight(false);
	}
	else if (crosshairSharedMove.x > 0.0f)
	{
		crosshairShared.lock()->SetMoveLeft(false);
		crosshairShared.lock()->SetMoveRight(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveLeft(false);
		crosshairShared.lock()->SetMoveRight(false);
	}

	if (crosshairSharedMove.y < 0.0f)
	{
		crosshairShared.lock()->SetMoveDown(true);
		crosshairShared.lock()->SetMoveUp(false);
	}
	else if (crosshairSharedMove.y > 0.0f)
	{
		crosshairShared.lock()->SetMoveDown(false);
		crosshairShared.lock()->SetMoveUp(true);
	}
	else
	{
		crosshairShared.lock()->SetMoveDown(false);
		crosshairShared.lock()->SetMoveUp(false);
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
	if (Input::GetInstance().IzZRPressed()==true)
	{
		// �}�K�W���ɋ[�������U����Ă��邩�`�F�b�N
		if (playerShared.lock()->GetLoadedBullet())
		{
			Vector3 gion_Rot = gionShared.lock()->GetRotation();	// �[���̉�]���
			Vector3 gion_Scale = gionShared.lock()->GetScale();		// �[���̃T�C�Y���
			gion_Rot.z = 0;
			// �[���̃T�C�Y�ݒ�
			gion_Scale.y = 120;
			gion_Scale.x = 240;
			// �e�����Đݒ�
			gionShared.lock()->SetRotation(gion_Rot);
			gionShared.lock()->SetScale(gion_Scale);
			playerShared.lock()->SetIsShot(true);


			//--------------------------------------
			//			�[���̃^�O�ύX����
			//--------------------------------------

			// �����ŋ[���̃^�O��UI����[���ɕύX
			// ���[���̃|�C���^�����킩���Ă�̂ɃL�[�̓��肪�X���[�Y�ɂł��Ȃ��̂ł���ς�Ǘ����@�ς����ق�������(�o�^����Ă�^�O�𖈃t���[���m�F���ē���������Ƃ�)

			// �����ł͎����Ă����[�����L���X�g�ł����^�ɂ���Ă��̋[���̃^�O��ς���悤�ɂ���
			auto bullet = playerShared.lock()->GetLoadedBullet();

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
		}
	}

	// �����̃I�u�W�F�N�g�ɓ���������[���̈ړ����~�߂鏈��
	if (Collider_toGround(groundShared2, gionShared))
	{
		playerShared.lock()->SetIsShot(false);

	}
	else {

	}


	//playerShared.lock()->Shot(gionShared);



	// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
	// �v���C���[���̐�^�Ɠ������Ă�[����T����(��ԋ߂���)�������Ă�[�����z������
	if (Input::GetInstance().IzZLPressed() == true)
	{
		// �z�����߂�[����T��
		// ���̃t���[�����̃^�O���[���̂��̑S�Ď擾������ƃv���C���[����o���^�̓����蔻����擾
		auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
		// ��`�Ƃ̓����蔻����擾
		auto HitOnomatopoeia = ColliderFan_Gion(playerShared, onomatopoeias);

		// �|�C���^�ɒl�������Ă����(��`�͈͓��ɓ��������[���������)
		if (HitOnomatopoeia.lock())
		{
			// �[���̋z�����ݎ��s
			playerShared.lock()->Suction(HitOnomatopoeia);
		}


		//Vector3 p_pos = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->GetPosition();
		//Vector3 gion_pos = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->GetPosition();
		////Suction(gion_pos, p_pos);
		//if (gion_pos.x - p_pos.x <= 300 && gion_pos.x - p_pos.x >= 0)/*Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�*/
		//{
		//	//�����ɁA�߂Â��X�s�[�h������
		//	gion_pos.x -= 14;
		//	std::cout << "�z������ł܂�" << std::endl;
		//	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Gion").lock()->SetPosition(gion_pos);
		//}
		//std::cout << "�[�����W�F" << gion_pos.x << std::endl;
	}
	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���



	// �����Ń}�K�W����UI�ɂȂ��Ă��Ȃ���Γ����蔻�����肽��
	if (m_MagCount >= 1)
	{
		// �P�̃V�[���ɗ����Ă�}�K�W�����͈�Ȃ̂ŁA�V�[���̎��}�K�W���J�E���g���P�Ȃ�܂��������Ă��Ȃ�
		// ������`�F�b�N����

		auto magShared = objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine3");

		// �}�K�W���ƒn��
		Collider_toGround(std::weak_ptr<Magazine>(magShared.second), groundShared);
		// �v���C���[�ƃ}�K�W��������������
		if (Collider_Player_to_Magazine(playerShared, objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3")))
		{
			// �}�K�W���̃^�O��ύX
			objectmanager.ChangeTag(magShared.first.first, magShared.first.second, UI);
			// �v���C���[�̎q�I�u�W�F�N�g�ɐݒ�
			playerShared.lock()->SetChild(magShared.second);
			/*magShared.second->SetScale(Vector3(75.0f, 75.0f, 0.0f));
			magShared.second->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));*/
			m_MagCount = 0;
		}

	}

	// �}�K�W���Ƃ̓����蔻��𖈃t���[����遨�}�K�W�����擾�����炻�̔���`�F�b�N�͂��Ȃ��Ă���
	//objectmanager.Collider_Player_to_Object();		// �����œ���������}�K�W�������P���炷

	objectmanager.Update();

}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
