#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include "../../Game/Objcet/SoundGun/SoundGun.h"
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
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	//�[���i�ǂ���j
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/Gion.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetPosition(Vector3(500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	
	// �}�K�W��
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Magazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	// �n��
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->SetPosition(Vector3(0.0f, -400.0f, 0.0f));
	objectmanager.GetGameObject<GameObject>(OBJECT, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

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
	// ���͊Ǘ�
	// �E�ړ�
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// ���ړ�
	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// �W�����v
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE))
	{
		objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->SetJump(true);

		/*Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
		objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/

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
	
	// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
	if (Input::GetInstance().GetKeyPress(VK_F))
	{
		Vector3 p_pos = objectmanager.GetGameObject<Player>(PLAYER, "Player").lock()->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->GetPosition();
		//Suction(gion_pos, p_pos);
		if (gion_pos.x - p_pos.x <= 300 && gion_pos.x - p_pos.x >= 0)/*Player�Ƌ[���̋��������ɗ�����A�[�������X�ɋ߂Â�*/
		{
			//�����ɁA�߂Â��X�s�[�h������
			gion_pos.x -= 14;
			std::cout << "�z������ł܂�" << std::endl;
			objectmanager.GetGameObject<GameObject>(OBJECT, "Gion").lock()->SetPosition(gion_pos);
		}
		std::cout << "�[�����W�F" << gion_pos.x << std::endl;
	}
	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���


	//----------------�����蔻��-----------------------
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObject<GameObject>(OBJECT, "Ground");
	ColliderPlayer_Ground(playerShared, groundShared);
	Collider_toGround(objectmanager.GetGameObject<Magazine>(OBJECT, "Magazine"), objectmanager.GetGameObject<GameObject>(OBJECT, "Ground"));

	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
