#include "TestScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/SoundGun/SoundGun.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"
#include "../../Game/Objcet/Enemy/Enemy.h"
#include "../../Game/Objcet/Onomatopeia/Poyon/Poyon.h"
#include "../../Game/Objcet/Onomatopeia/PataPata/PataPata.h"
#include "../../Game/Objcet/Onomatopeia/BiriBiri/BiriBiri.h"


/**
 * @brief �^�C�g���V�[���̏�����
 *
 * �V�[�����Ƃɏ������͍ŏ��̈�x�̂�
 * ��
*/



void TestScene::Init(void) {
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

	//�[���i�ǂ���j
	objectmanager.AddObject<Poyon>(OBJECT, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/Gion.png");
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));


	// �}�K�W��
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Magazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// �n��
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1200.0f, 120.0f, 0.0f));

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

	//50��
	objectmanager.AddObject<GameObject>(OBJECT, "Moji");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->Init(L"Game/Asset/GameObject/Moji.png", 12, 5);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetScale(Vector3(300.0f, 300.0f, 0.0f));

	//// UI1(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER);
}



void TestScene::Update(void)
{

	// ���͏��̍X�V
	Input::GetInstance().Update();


	auto playerShared = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground2");
	auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(OBJECT, "Gion");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime");
	Vector3 player_angre = playerShared.lock()->GetRotation();

	// ���͊Ǘ�
	// �E�ړ�
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// ���ړ�
	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// �W�����v
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE))
	{
		if (Collider_toGround(playerShared, groundShared))
		{
			objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);

			/*Vector3 pos = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetPosition();
			pos.x -= 5.0f;
			objectmanager.GetGameObjectPtr(PLAYER, "Player")->SetPosition(pos);

			Vector2 num = objectmanager.GetGameObjectPtr(PLAYER, "Player")->GetUV();
			objectmanager.GetGameObjectPtr(PLAYER, "Player")->Animation();*/

			//�f�o�b�N�p
			std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
		}

	}

	//50���̐؂�ւ�(�m�F�p)
	if (Input::GetInstance().GetKeyRelease(VK_N))
	{
		Int2 moji = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->GetUV();
		moji.y++;
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetUV(moji);
		if (moji.y >= 5)
		{
			moji.y = 0;
			moji.x++;
			objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Moji").lock()->SetUV(moji);
		}
	}


	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}


	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���


	//----------------�����蔻��-----------------------

	//---------------�����͕ς���ׂ���--------------//
	if (Collider_toGround(playerShared, groundShared2))
	{
		Collider_toGround(playerShared, groundShared2);//�t�^����Ground
	}
	else if (Collider_toGround(playerShared, groundShared))//Player��Ground�̓����蔻��
	{
		Collider_toGround(playerShared, groundShared);
	}
	//----------------------------------------------//

	Collider_toGround(enemyShared, groundShared);//Enemy��Ground�̓����蔻��
	Collider_toGround(objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine"), objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "Ground"));//�}�K�W����Ground�̓����蔻��

	//�t�^�\���Ground�Ƃ̓����蔻��
	if (Collider_toGround(gionShared, groundShared2))
	{

		//�[���̃`�F�b�N�t���O
		//gionShared.lock()->Collider_check = true;
		if (Collider_toGround(playerShared, groundShared2))
		{
			//gionShared.lock()->BriBri_check = true;
			//gionShared.lock()->Action(playerShared);

			gionShared.lock()->Action();

		}
		else {
			//�܂��t�^����Ă��Ȃ�Player��Ground���Փ˂��Ă���
			Collider_toGround(playerShared, groundShared);
			playerShared.lock()->SetRotation(player_angre);
		}

	}
	//Player�ƕt�^���ꂽGround���Փ˂��Ă���̂�


	//gionShared.lock()->Action(playerShared);//�I�u�W�F�N�g���t�^�����

	//------------�������Ƃ�������������͂���------------------------

	// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
	if (Input::GetInstance().GetKeyPress(VK_F))
	{
		//�����Ɉʒu�𐶓����蔻��ǉ����Ă���������
		if (ColliderFan_Gion(playerShared, gionShared))
		{
			playerShared.lock()->Suction(gionShared);

			//�[���̃f�[�^�������Ɋi�[���Ă���H
			//playerShared.lock()->magazine.push_back(gionShared.lock());
		}
	}

	//-----------------�f���o���̏���--------------------//
	if (Input::GetInstance().GetKeyPress(VK_R))
	{
		//�f���o���̏���
		playerShared.lock()->Reverse(gionShared);
	}
	

	//Enemy�̓���
	Vector3 slime_pos = objectmanager.GetGameObjectPtr<Enemy>(OBJECT, "Slime").lock()->GetPosition();
	std::cout << "�X���C���̍��W�F" << slime_pos.y << std::endl;
	objectmanager.Update();

}

void TestScene::Draw(void) {
	objectmanager.Draw();
}

void TestScene::Uninit(void) {
	objectmanager.Uninit();
}
