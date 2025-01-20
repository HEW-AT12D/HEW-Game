#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"
#include "../../Framework/Input/Input.h"
#include"../../Game/Objcet/SoundGun/SoundGun.h"
#include"../../Framework/Component/Collider/Collider.h"
#include"../../Framework/Component/Gravity/Gravity.h"



/**
 * @brief �^�C�g���V�[���̏�����
 *
 * �V�[�����Ƃɏ������͍ŏ��̈�x�̂�
 * ��
*/

bool isMoving = false;//�ړ������ǂ����̃t���O
Vector3 targetPosition;                // �ڕW�ʒu
const float moveSpeed = 10.0f;          // 1�t���[��������̈ړ����x

void TitleScene::Init(void) {
	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();
	

	//-----------------------
	//-----�I�u�W�F�N�g�ǉ�-----
	//-----------------------
	// TODO:1218�����܂� �I�u�W�F�N�g�̊Ǘ���enum����ύX��tag�Ɩ��O�ɂ�����
	
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background1");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject(BACKGROUND, "Background1")->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	// �v���C���[
	objectmanager.AddObject<GameObject>(PLAYER, "Player");
	objectmanager.GetGameObject(PLAYER, "Player")->Init(L"Game/Asset/Character/Character_sprit.png",2,1);
	objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(Vector3(0.0f, 100.0f, 0.0f));
	objectmanager.GetGameObject(PLAYER, "Player")->SetScale(Vector3(130.0f, 130.0f, 0.0f));


	//�[���i�ǂ���j
	objectmanager.AddObject<GameObject>(OBJECT, "Gion");
	objectmanager.GetGameObject(OBJECT, "Gion")->Init(L"Game/Asset/Gion/Gion.png");
	objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(Vector3(300.0f, -100.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Gion")->SetScale(Vector3(120.0f, 60.0f, 0.0f));
	

	//����
	objectmanager.AddObject<GameObject>(OBJECT, "Ground");
	objectmanager.GetGameObject(OBJECT, "Ground")->Init(L"Game/Asset/BackGround/ground.png");
	objectmanager.GetGameObject(OBJECT, "Ground")->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Ground")->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//�z�����݉摜
	objectmanager.AddObject<GameObject>(OBJECT, "Saikuron");
	objectmanager.GetGameObject(OBJECT, "Saikuron")->Init(L"Game/Asset/BackGround/saikuron.png");
	objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(Vector3(100.0f, -100.0f, 0.0f));
	objectmanager.GetGameObject(OBJECT, "Saikuron")->SetScale(Vector3(200.0f, 100.0f, 0.0f));

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
	Vector3 pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
	Vector3 s_pos = objectmanager.GetGameObject(OBJECT, "Saikuron")->GetPosition();
	//pos.y -= 1.0f;
	
	std::cout << "PlayerY���W�F" << pos.y << std::endl;
	
	
	if (ColliderPlayer_Ground(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Ground")))
	{
		//std::cout << "�Փ˂��܂���" << std::endl;
		if (Input::GetInstance().GetKeyPress(VK_Q))
		{
			Jump(objectmanager.GetGameObject(PLAYER, "Player"), pos);
		}
	}
	else {
		//Player�̏d�͉����x
		Gravity(objectmanager.GetGameObject(PLAYER, "Player"), pos);
	}
	// ���͊Ǘ�
	if (Input::GetInstance().GetKeyPress(VK_D))
	{
		pos.x += 5.0f;
		s_pos.x += 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);
		objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(s_pos);

		Vector2 num = objectmanager.GetGameObject(PLAYER, "Player")->GetUV();
	/*	objectmanager.GetGameObject(PLAYER, "Player")->Animation();*/
		
		//�f�o�b�N�p
		std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}

	if (Input::GetInstance().GetKeyPress(VK_A))
	{
		pos.x -= 5.0f;
		s_pos.x -= 5.0f;
		objectmanager.GetGameObject(PLAYER, "Player")->SetPosition(pos);
		objectmanager.GetGameObject(OBJECT, "Saikuron")->SetPosition(s_pos);
	}


	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		this->ChangeScene = true;
		SetChangeScene(this->ChangeScene);
	}
	
	//�z�����ݏ���
	//SPACE��������^�Ƌ[���̓����蔻�肪�쓮���遨(true�Ȃ�)Player�Ƌ[���̓����蔻��쓮
	if (Input::GetInstance().GetKeyPress(VK_SPACE))
	{
		Vector3 p_pos = objectmanager.GetGameObject(PLAYER, "Player")->GetPosition();
		Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();
		

		//Player�Ƌ[���̓����蔻�肪true�ɂȂ������Ƃ�\��if��
		if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
		{
			std::cout << "Player�Ƌ[���̓����蔻�肪true�ɂȂ�܂���" << std::endl;
		}else if (ColliderFan_Gion(objectmanager.GetGameObject(OBJECT, "Saikuron"), objectmanager.GetGameObject(OBJECT, "Gion")))
		{
			//�����ɁA�߂Â��X�s�[�h������
			gion_pos.x -= 14;
			std::cout << "�z������ł܂�" << std::endl;
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(gion_pos);

			//Player�ɓ���������ۑ����鏈���������ɏ���
			/*if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
			{
				std::cout << "Player�Ƌ[�����Փ˂��Ă��܂�" << std::endl;
			}*/

		}
		std::cout << "�[�����W�F" << gion_pos.x << std::endl;
	}


	//!�[���̔���
	//! Player �� Gion �̓����蔻��
	if (ColliderPlayer_Gion(objectmanager.GetGameObject(PLAYER, "Player"), objectmanager.GetGameObject(OBJECT, "Gion")))
	{
		std::cout << "Player�Ƌ[���̓����蔻�肪true�ɂȂ�܂���" << std::endl;

		// X�L�[�������ꂽ��ړ����J�n
		if (Input::GetInstance().GetKeyPress(VK_X) && !isMoving)
		{
			// Gion �̌��݈ʒu���擾
			Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();

			// �ڕW�ʒu��ݒ�iX������300.0f�ړ��j
			targetPosition = gion_pos;
			targetPosition.x += 500.0f;

			// �ړ��t���O��L����
			isMoving = true;
		}
	}

	
	// Gion ���ړ����̏ꍇ
	if (isMoving)
	{
		// Gion �̌��݈ʒu���擾
		Vector3 gion_pos = objectmanager.GetGameObject(OBJECT, "Gion")->GetPosition();

		// �ڕW�ʒu�Ƃ̍����v�Z
		Vector3 direction = targetPosition - gion_pos;

		// ���݈ʒu���ڕW�ʒu�ɋ߂����ǂ����𔻒�
		float distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
		if (distance <= moveSpeed)
		{
			// �ڕW�ʒu�ɓ��B�����ꍇ�A�ʒu��ڕW�ɑ�����
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(targetPosition);
			isMoving = false; // �ړ����~
		}
		else
		{
			// ���K�����ĕ����x�N�g�����v�Z
			direction.x /= distance;
			direction.y /= distance;
			direction.z /= distance;

			// 1�t���[�����̈ړ��ʂ��v�Z
			gion_pos.x += direction.x * moveSpeed;
			gion_pos.y += direction.y * moveSpeed;
			gion_pos.z += direction.z * moveSpeed;

			// Gion �̈ʒu���X�V
			objectmanager.GetGameObject(OBJECT, "Gion")->SetPosition(gion_pos);
		}
	}
	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���


	objectmanager.Update();
	
}

void TitleScene::Draw(void) {
	objectmanager.Draw();
}

void TitleScene::Uninit(void) {
	objectmanager.Uninit();
}
