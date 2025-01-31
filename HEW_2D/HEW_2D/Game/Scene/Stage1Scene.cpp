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
	
	//// �w�i
	//objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	//objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	//objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
	//
	//// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER, "Player");
	//objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	//objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	//// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	//objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	//objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	//objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(260.0f, 130.0f, 0.0f));
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

	////�[���i�|�����j
	//objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// ���O�v�ύX
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Wiin.png");
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));
	//
	//// �}�K�W��(���������ԂŃX�^�[�g�A�����Ă�͈̂����)
	//// 1��(�h�H����p)
	//objectmanager.AddObject<Magazine>(UI, "SpecialMagazine");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "SpecialMagazine").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	//// 2��
	//objectmanager.AddObject<Magazine>(UI, "Magazine1");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));
	//// 3��
	//objectmanager.AddObject<Magazine>(UI, "Magazine2");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	//// 3�͎q�I�u�W�F�N�g�ɐݒ肵��UI�ɕύX���Ă���
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "SpecialMagazine").second);
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second);
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	//// 3��(�t�B�[���h�ɗ����Ă�}�K�W��)
	//objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	//// �n��
	//objectmanager.AddObject<GameObject>(GROUND, "Ground");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));

	//// �n��2
	//objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(700.0f, -350.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	//// �X���C��
	//objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	//objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	//objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(120.0f, 120.0f, 0.0f));

	//// �N���X�w�A
	//objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	//objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	//objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(30.0f, 30.0f, 0.0f));
	//// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	////�}�K�W���̊O�g(�����ʒu�͈�ԍ���̃}�K�W��)
	//objectmanager.AddObject<GameObject>(UI, "Frame");    // ���O�v�ύX
	//objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	//objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

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
















	switch (CurrentFrame)
	{
	case FRAME1:
		// �w�i
		objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

		// �v���C���[
		objectmanager.AddObject<Player>(PLAYER, "Player");
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(500.0f, 600.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

		// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
		objectmanager.AddObject<SoundGun>(UI, "SoundGun");
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


		//�[���i�r���r���j
		objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

		//�[���i�h�[���j
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(800.0f, 50.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

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
		objectmanager.AddObject<GameObject>(GROUND, "Ground");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


		// �n��2
		objectmanager.AddObject<GameObject>(GROUND, "Ground2");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(600.0f, -50.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(900.0f, 120.0f, 0.0f));

		// �n��3
		objectmanager.AddObject<GameObject>(GROUND, "Ground3");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(400.0f, 40.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));

		// �X���C��
		objectmanager.AddObject<Enemy>(ENEMY, "Slime");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(200.0f, -300.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));

		// �N���X�w�A
		objectmanager.AddObject<CrossHair>(UI, "CrossHair");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
		// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

		//enemy�[��
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

		// �o�l
		objectmanager.AddObject<GameObject>(OBJECT, "bane");
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(0.0f, -360.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));

		//�T���_�[�G�t�F�N�g
		objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
		objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
		objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

		//�}�K�W���̊O�g
		objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

		break;

	case FRAME2:
		// �w�i
		objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

		// �v���C���[
		objectmanager.AddObject<Player>(PLAYER, "Player");
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

		// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
		objectmanager.AddObject<SoundGun>(UI, "SoundGun");
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


		//�[���i�r���r���j
		objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(-650.0f, -330.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(60.0f, 30.0f, 0.0f));


		// �r���r���ł������
		objectmanager.AddObject<GameObject>(GROUND, "Ground6");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(-800.0f, 250.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(250.0f, 250.0f, 0.0f));

		//�[���i�h�[���j
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(-800.0f, 220.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

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
		objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


		// �n��
		objectmanager.AddObject<GameObject>(GROUND, "Ground");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


		// 3�i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground2");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-700.0f, 100.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(600.0f, 50.0f, 0.0f));

		// 1�i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground3");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(545.0f, -180.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(400.0f, 50.0f, 0.0f));

		// �p�^�p�^��
		objectmanager.AddObject<GameObject>(GROUND, "Ground4");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(145.0f, -80.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(150.0f, 50.0f, 0.0f));

		// �X���C��
		objectmanager.AddObject<Enemy>(ENEMY, "Slime");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-150.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


		//��i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground5");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-130.0f, 20.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(400.0f, 50.0f, 0.0f));


		// �N���X�w�A
		objectmanager.AddObject<CrossHair>(UI, "CrossHair");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
		// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

		//enemy�[��
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

		// �o�l
		objectmanager.AddObject<GameObject>(OBJECT, "bane");
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(300.0f, -360.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));

		//�T���_�[�G�t�F�N�g
		//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

		//�}�K�W���̊O�g
		objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

		break;

	case FRAME3:
		// �w�i
		objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

		// �v���C���[
		objectmanager.AddObject<Player>(PLAYER, "Player");
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

		// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
		objectmanager.AddObject<SoundGun>(UI, "SoundGun");
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


		//�[���i�r���r���j
		objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(650.0f, -400.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

		//�[���i�h�[���j
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(800.0f, -400.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

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
		objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


		// �n��
		objectmanager.AddObject<GameObject>(GROUND, "Ground");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


		// 3�i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground2");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-700.0f, 100.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(600.0f, 50.0f, 0.0f));

		// 1�i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground3");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(750.0f, -80.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

		// �p�^�p�^��
		objectmanager.AddObject<GameObject>(GROUND, "Ground4");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(-645.0f, -120.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));

		// �X���C��
		objectmanager.AddObject<Enemy>(ENEMY, "Slime");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-650.0f, 250.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


		//��i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground5");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-130.0f, -240.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));

		// �p�^�p�^��
		objectmanager.AddObject<GameObject>(GROUND, "Ground7");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetPosition(Vector3(200.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetScale(Vector3(100.0f, 50.0f, 0.0f));

		// ��ɂ���p�^�p�^��
		objectmanager.AddObject<GameObject>(GROUND, "Ground6");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(-230.0f, -80.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));


		// �N���X�w�A
		objectmanager.AddObject<CrossHair>(UI, "CrossHair");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
		// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

		//enemy�[��
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

		// �o�l
		objectmanager.AddObject<GameObject>(OBJECT, "bane");
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(400.0f, -360.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));

		//�T���_�[�G�t�F�N�g
		//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

		//�}�K�W���̊O�g
		objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));

		break;


	case FRAME4:
		objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

		// �v���C���[
		objectmanager.AddObject<Player>(PLAYER, "Player");
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

		// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
		objectmanager.AddObject<SoundGun>(UI, "SoundGun");
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
		objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


		//�[���i�r���r���j
		objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(-670.0f, -400.0f, 0.0f));
		objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

		//�[���i�h�[���j
		objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(-850.0f, -420.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

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

		//// �O��
		//objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
		//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
		//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


		// �n�ʍ�
		objectmanager.AddObject<GameObject>(GROUND, "Ground");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(-700.0f, -500.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(600.0f, 100.0f, 0.0f));

		//�n�ʉE
		objectmanager.AddObject<GameObject>(GROUND, "Ground3");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(350.0f, -500.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(1300.0f, 100.0f, 0.0f));

		// 3�i��
		objectmanager.AddObject<GameObject>(GROUND, "Ground2");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-650.0f, -80.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(700.0f, 50.0f, 0.0f));

		// �p�^�p�^��
		objectmanager.AddObject<GameObject>(GROUND, "Ground4");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(-350.0f, -250.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

		// �p�^�p�^��2
		objectmanager.AddObject<GameObject>(GROUND, "Ground5");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-350.0f, -150.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

		// �p�^�p�^��3
		objectmanager.AddObject<GameObject>(GROUND, "Ground7");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetPosition(Vector3(-350.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

		// �X���C��
		objectmanager.AddObject<Enemy>(ENEMY, "Slime");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-450.0f, -350.0f, 0.0f));
		objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


		//�Ō�̏�Q��
		objectmanager.AddObject<GameObject>(GROUND, "Ground8");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->SetPosition(Vector3(450.0f, -280.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->SetScale(Vector3(100.0f, 350.0f, 0.0f));

		// �r���r���ł������
		objectmanager.AddObject<GameObject>(GROUND, "Ground6");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(170.0f, -330.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(250.0f, 250.0f, 0.0f));


		// �o�l
		objectmanager.AddObject<GameObject>(OBJECT, "bane");
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(200.0f, -360.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));


		// �N���X�w�A
		objectmanager.AddObject<CrossHair>(UI, "CrossHair");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
		objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
		// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
		objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

		////enemy�[��
		//objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
		//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
		//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

		//�T���_�[�G�t�F�N�g
		//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
		//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

		//�}�K�W���̊O�g
		objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
		objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}

	objectmanager.AddObject<Camera>(CAMERA, "Camera");    // ���O�v�ύX
	objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->Init(L"Game/Asset/UI/BlackImage.png");
	objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Camera>(CAMERA, "Camera").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));
}



void Stage1Scene::Update(void)
{
	// �t���[��1�`2�֑J��
	if (OldFrame == FRAME1 && CurrentFrame == FRAME2)
	{

		Frame2Init();
	}
	// �t���[��2�`3�֑J��
	else if (OldFrame == FRAME2 && CurrentFrame == FRAME3)
	{
		Frame3Init();
	}
	// �t���[��3�`4�֑J��
	else if (OldFrame == FRAME3 && CurrentFrame == FRAME4)
	{
		Frame4Init();
	}


	// ���͏��̍X�V
	Input::GetInstance().Update();
	// �X�e�B�b�N���͒l���擾
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// �E�X�e�B�b�N����
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// ���X�e�B�b�N����

	// �V�[���X�V�ɕK�v�ȏ����擾
	//auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");		// �v���C���[
	//auto grounds = objectmanager.GetObjects<GameObject>(GROUND);						// �n��(�z��)
	//auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");	// �n��1(��)
	//auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");	// �n��2
	//auto onopatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);			// �[��(�z��)
	//auto gionShared = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");		// �[��(��)
	//auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");			// �G(��)
	//auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");	// �N���X�w�A


	auto grounds = objectmanager.GetObjects<GameObject>(GROUND);	// �n��(�z��)
	auto grounds2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");
	auto gionShared = objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion");
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");
	auto enemygion = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");
	auto effectShared = objectmanager.GetGameObjectPtr<GameObject>(UI, "Thunder_Effect");
	auto baneShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane");
	auto poyonShared = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2");
	auto groundShared3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3");
	auto cameraShared= objectmanager.GetGameObject<Camera>(CAMERA, "Camera");



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


	// �t���[���J�ڏ���
	if (Input::GetInstance().GetButtonPress(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		Vector3 pos = playerShared.second->GetPosition();
		if (CurrentFrame == FRAME1 || CurrentFrame == FRAME2)
		{

			if (pos.x >= 850.0f)
			{
				if (pos.y <= 0.0f)
				{
					cameraShared.second->SetIsMoving(true);
					CurrentFrame = FRAME2;
				}
			}
		}
		else if (CurrentFrame == FRAME3)
		{

		}
		else if (CurrentFrame == FRAME4)
		{

		}
	}
	
	



	//�Q�[����ʂɑJ��
	// �V�[���J�ځi�f�o�b�N�p
	if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
	{
		SetChangeScene(true);
	}


	//----------------�����蔻��-----------------------

	//ColliderPlayer_Ground(playerShared.second, grounds);			// �v���C���[�ƒn��
	//Collider_Objects_Objects(onopatopoeias,grounds);		// �[���ƒn��
	//ColliderPlayer_Ground(playerShared, groundShared2);

	if (ColliderPlayer_Ground(playerShared.second, grounds))
	{
		Collider_to_Object(playerShared.second, baneShared.lock());

	}
	else {
		Collider_toGround(playerShared2, grounds2.lock());

	}


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


	//////////////////////////////////////////////
	/// �X���C������
	////////////////////////////////////////////////
	Vector3 p_enemy = enemyShared.lock()->GetPosition();
	//�X���C���W�����v
	if (Collider_toGround(enemyShared, groundShared))
	{
		//�X���C���W�����v�t���O
		if (enemygion.lock())
		{
			if (enemygion.lock()->Get_gion() == false)
			{

				Vector3 Slim_Position = enemygion.lock()->GetPosition();
				Slim_Position = p_enemy;
				Slim_Position.y = Slim_Position.y + 100;
				enemygion.lock()->SetPosition(Slim_Position);
			}
			else {
				Vector3 pos_bane = baneShared.lock()->GetPosition();
				baneShared.lock()->SetPosition(pos_bane);
			}

		}
		enemyShared.lock()->SetJump(true);
	}
	else if (enemygion.lock()) {

		enemygion.lock()->Fade_in_out();
	}


	//////////////////////////////////////////////////
	/// �[���̋���(�t�^��)
	//////////////////////////////////////////////////
	
	Vector3 _p_biribiri = effectShared.lock()->GetPosition(); //�|�����̍��W
	Vector3 _r_biribiri = effectShared.lock()->GetRotation();  //�|�����̉�]
	//enemygion��empty�łȂ����`�F�b�N
	if (enemygion.lock())
	{
		//�|�����̉摜�ƃo�l�̉摜���������Ă��邩
		if (BoxCollider(enemygion.lock(), baneShared.lock()))
		{

			enemygion.lock()->Set_gion(true);
			Vector3 _p_poyon = baneShared.lock()->GetPosition(); //�|�����̍��W
			Vector3 _r_poyon = baneShared.lock()->GetRotation();  //�|�����̉�]
			enemygion.lock()->Set_Onomatope(true); //�������Ă���t���O��true
			_p_poyon.x = _p_poyon.x + 30;
			_p_poyon.y = _p_poyon.y + 20;
			_r_poyon.z = _r_poyon.z - 15;
			enemygion.lock()->SetPosition(_p_poyon); //�|�����̉摜�̍��W���o�l�ɂ�������
			enemygion.lock()->SetRotation(_r_poyon); //�|�����̉摜�̉�]���X�V
			std::cout << "����܂���" << std::endl;
		}
		else
		{
			//std::cout << "�������Ă��܂���" << std::endl;
		}

		//���ڂ̉��������܂ł͂�����true
		if (enemygion.lock()->Get_Onomatope())
		{
			enemygion.lock()->Fade_in_out();
			//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
			if (BoxCollider(playerShared.second, baneShared.lock()))
			{
				enemygion.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
			}
		}
	}
	else {
		std::cout << "enemygion��empty�ł�" << std::endl;
	}

	//�r���r��
	if (gionShared.lock())
	{
		if (BoxCollider(gionShared.lock(), effectShared.lock()))
		{
			effectShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
			//_p_biribiri.x = _p_biribiri.x - 250;
			//_p_biribiri.y = _p_biribiri.y + 80;
			//_r_biribiri.z = _r_biribiri.z - 15;
			gionShared.lock()->Set_Onomatope(true); //�������Ă���t���O��true
			//
			//gionShared.lock()->SetPosition(_p_biribiri); //�|�����̉摜�̍��W���o�l�ɂ�������
			//gionShared.lock()->SetRotation(_r_biribiri); //�|�����̉摜�̉�]���X�V
			std::cout << "����܂���" << std::endl;
		}
		else {
			effectShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //�r���r���̃G�t�F�N�g��F�ŏ����������ɂ��Ă�
		}

		gionShared.lock()->Fade_in_out();
		//���ڂ̉��������܂ł͂�����true
		if (gionShared.lock()->Get_Onomatope())
		{
			//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
			if (BoxCollider(playerShared.second, groundShared3.lock()))
			{
				playerShared.second->SetOnGround(true);
				gionShared.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
			}
			else {
				Vector3 r_player = playerShared.second->GetRotation();
				r_player.z = 0;
				playerShared.second->SetRotation(r_player);
			}
		}
	}



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
	

	// �t���[����Ԃ��X�V
	CurrentFrame = OldFrame;
}

void Stage1Scene::Draw(void) {
	objectmanager.Draw();
}

void Stage1Scene::Uninit(void) {
	// BGM��~
	Sound::GetInstance().Stop(BGM_INGAME);
	objectmanager.Uninit();
}



// �t�F�[�h�A�E�g����t���[���O�̃I�u�W�F�N�g�J�����t�F�[�h�C��
void Stage1Scene::Frame2Init(void)
{
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


	//�[���i�r���r���j
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(-650.0f, -330.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(60.0f, 30.0f, 0.0f));


	// �r���r���ł������
	objectmanager.AddObject<GameObject>(GROUND, "Ground6");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(-800.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(250.0f, 250.0f, 0.0f));

	//�[���i�h�[���j
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(-800.0f, 220.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

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
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


	// �n��
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


	// 3�i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-700.0f, 100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(600.0f, 50.0f, 0.0f));

	// 1�i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(545.0f, -180.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(400.0f, 50.0f, 0.0f));

	// �p�^�p�^��
	objectmanager.AddObject<GameObject>(GROUND, "Ground4");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(145.0f, -80.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(150.0f, 50.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-150.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


	//��i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground5");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-130.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(400.0f, 50.0f, 0.0f));


	// �N���X�w�A
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
	// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//enemy�[��
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	// �o�l
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(300.0f, -360.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));

	//�T���_�[�G�t�F�N�g
	//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

	//�}�K�W���̊O�g
	objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));
}


void Stage1Scene::Frame3Init(void)
{
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


	//�[���i�r���r���j
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(650.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

	//�[���i�h�[���j
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(800.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

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
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


	// �n��
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


	// 3�i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-700.0f, 100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(600.0f, 50.0f, 0.0f));

	// 1�i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(750.0f, -80.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	// �p�^�p�^��
	objectmanager.AddObject<GameObject>(GROUND, "Ground4");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(-645.0f, -120.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-650.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


	//��i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground5");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-130.0f, -240.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));

	// �p�^�p�^��
	objectmanager.AddObject<GameObject>(GROUND, "Ground7");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetPosition(Vector3(200.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetScale(Vector3(100.0f, 50.0f, 0.0f));

	// ��ɂ���p�^�p�^��
	objectmanager.AddObject<GameObject>(GROUND, "Ground6");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(-230.0f, -80.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));


	// �N���X�w�A
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
	// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	//enemy�[��
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	// �o�l
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(400.0f, -360.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));

	//�T���_�[�G�t�F�N�g
	//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

	//�}�K�W���̊O�g
	objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));
}


void Stage1Scene::Frame4Init(void)
{
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/ResultBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-800.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);


	//�[���i�r���r���j
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(-670.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

	//�[���i�h�[���j
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetPosition(Vector3(-850.0f, -420.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Gion2").lock()->SetScale(Vector3(120.0f, 60.0f, 0.0f));

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

	//// �O��
	//objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(-600.0f, -400.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));


	// �n�ʍ�
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(-700.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(600.0f, 100.0f, 0.0f));

	//�n�ʉE
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(350.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(1300.0f, 100.0f, 0.0f));

	// 3�i��
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(-650.0f, -80.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(700.0f, 50.0f, 0.0f));

	// �p�^�p�^��
	objectmanager.AddObject<GameObject>(GROUND, "Ground4");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetPosition(Vector3(-350.0f, -250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground4").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// �p�^�p�^��2
	objectmanager.AddObject<GameObject>(GROUND, "Ground5");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetPosition(Vector3(-350.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground5").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// �p�^�p�^��3
	objectmanager.AddObject<GameObject>(GROUND, "Ground7");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetPosition(Vector3(-350.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground7").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-450.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));


	//�Ō�̏�Q��
	objectmanager.AddObject<GameObject>(GROUND, "Ground8");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->SetPosition(Vector3(450.0f, -280.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground8").lock()->SetScale(Vector3(100.0f, 350.0f, 0.0f));

	// �r���r���ł������
	objectmanager.AddObject<GameObject>(GROUND, "Ground6");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetPosition(Vector3(170.0f, -330.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground6").lock()->SetScale(Vector3(250.0f, 250.0f, 0.0f));


	// �o�l
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(200.0f, -360.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(330.0f, 330.0f, 0.0f));


	// �N���X�w�A
	objectmanager.AddObject<CrossHair>(UI, "CrossHair");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->Init(L"Game/Asset/UI/CrossHair.png");
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetPosition(Vector3(200.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));
	// �N���X�w�A���v���C���[�̎q�I�u�W�F�N�g�Ƃ��Đݒ�
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<CrossHair>(UI, "CrossHair").second);

	////enemy�[��
	//objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "_Gion2");	// ���O�v�ύX
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "_Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//�T���_�[�G�t�F�N�g
	//objectmanager.AddObject<BiriBiri>(UI, "Thunder_Effect");
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetPosition(Vector3(500.0f, 20.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetScale(Vector3(600.0f, 1200.0f, 0.0f));
	//objectmanager.GetGameObjectPtr<BiriBiri>(UI, "Thunder_Effect").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));

	//�}�K�W���̊O�g
	objectmanager.AddObject<GameObject>(UI, "Frame");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->Init(L"Game/Asset/UI/Frame.png");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(Vector3(-900.0f, 495.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetScale(Vector3(120.0f, 80.0f, 0.0f));
}
