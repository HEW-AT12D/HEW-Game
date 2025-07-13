#include "Stage2Scene.h"
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

void Stage2Scene::Frame1() {
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->Init(L"Game/Asset/BackGround/TitleBack.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Background").lock()->SetScale(Vector3(1920.0f, 1080.0f, 0.0f));

	//�`���[�g���A���Ŕ�(�z����)
	objectmanager.AddObject<GameObject>(BACKGROUND, "board1");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->Init(L"Game/Asset/GameObject/board.png");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "board1").lock()->SetScale(Vector3(500.0f, 500.0f, 0.0f));

	// �v���C���[(�Ŕp)
	objectmanager.AddObject<GameObject>(BACKGROUND, "Playerboard");
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->Init(L"Game/Asset/Character/Player_Sprite.png", 2, 3);
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->SetPosition(Vector3(-500.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(BACKGROUND, "Playerboard").lock()->SetScale(Vector3(100.0f, 100.0f, 0.0f));

	// �X���C��(�Ŕp)
	objectmanager.AddObject<GameObject>(ENEMY, "Slimeboard");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->Init(L"Game/Asset/GameObject/Slime.png");
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->SetPosition(Vector3(-350.0f, -180.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ENEMY, "Slimeboard").lock()->SetScale(Vector3(60.0f, 30.0f, 0.0f));

	//�e�̃G�t�F�N�g(�Ŕp)
	objectmanager.AddObject<GameObject>(UI, "SoundGunboard");
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->SetPosition(Vector3(-430.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(UI, "SoundGunboard").lock()->SetScale(Vector3(70.0f, 60.0f, 0.0f));

	// �|������t�^���邽�߂̃I�u�W�F�N�g
	objectmanager.AddObject<GameObject>(OBJECT, "baneboard");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetPosition(Vector3(-350.0f, -200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetScale(Vector3(50.0f, 20.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));

	//�|����(�Ŕp)
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "Poyonboard");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetPosition(Vector3(-400.0f, -150.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetScale(Vector3(150.0f, 75.0f, 0.0f));

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER, "Player");
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->Init(L"Game/Asset/Character/Completion_Player_Sprite.png", 2, 6);
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));

	// �[���e(�݌v�I�ɂ͏e��ʉ摜�ŗp�ӂ��ăv���C���[�Ɏ�����������ǂ��������A)
	objectmanager.AddObject<SoundGun>(UI, "SoundGun");
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->Init(L"Game/Asset/Character/CyclonImage.png", 1, 4);
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetPosition(Vector3(0.0f, 600.0f, 0.0f));
	objectmanager.GetGameObjectPtr<SoundGun>(UI, "SoundGun").lock()->SetScale(Vector3(130.0f, 130.0f, 0.0f));
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<SoundGun>(UI, "SoundGun").second);

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
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine1").second); //�h�[��

	// �ύX����ׂ����Ɓ��擾�����}�K�W�����������莩�g�̏��L�I�u�W�F�N�g�Ƃ��Đݒ肷��
	// ��
	//objectmanager.GetGameObject<Player>(PLAYER, "Player").second->Set
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetChild(objectmanager.GetGameObject<Magazine>(UI, "Magazine2").second);

	


	// �O��
	objectmanager.AddObject<Magazine>(OBJECT, "Magazine3");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->Init(L"Game/Asset/GameObject/Magazine.png");
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetPosition(Vector3(400.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Magazine>(OBJECT, "Magazine3").lock()->SetScale(Vector3(90.0f, 90.0f, 0.0f));

	

	// �o�l
	objectmanager.AddObject<GameObject>(OBJECT, "bane");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->Init(L"Game/Asset/GameObject/Bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetPosition(Vector3(0.0f, -415.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// �n��
	objectmanager.AddObject<GameObject>(GROUND, "Ground");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetPosition(Vector3(0.0f, -500.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock()->SetScale(Vector3(1920.0f, 120.0f, 0.0f));


	// �n��2
	objectmanager.AddObject<GameObject>(GROUND, "Ground2");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetPosition(Vector3(600.0f, -40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2").lock()->SetScale(Vector3(900.0f, 130.0f, 0.0f));

	// �n��3
	objectmanager.AddObject<GameObject>(GROUND, "Ground3");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->Init(L"Game/Asset/GameObject/Ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetPosition(Vector3(400.0f, 40.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3").lock()->SetScale(Vector3(300.0f, 50.0f, 0.0f));



	//�[���i�r���r���j
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "Gion");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetPosition(Vector3(450.0f, 60.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

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
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "Poyon");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));


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

	//�S�[��
	objectmanager.AddObject<GameObject>(OBJECT, "door");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->Init(L"Game/Asset/GameObject/door.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetPosition(Vector3(850.0f, -370.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetScale(Vector3(100.0f, 150.0f, 0.0f));

	std::vector<std::shared_ptr<GameObject>> objects = {
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground").lock(),//�n�ʂP
	};

	//�[���i�h�[���j
	objectmanager.AddObject<Poyon>(Doon, "Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->SetPosition(Vector3(800.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(Doon, "Gion2").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

}

void Stage2Scene::Frame2() {
	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2.lock()->GetPosition();
	pos.x = -700.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2.lock()->SetPosition(pos);
	
	/*objectmanager.AddObject<GameObject>(OBJECT, "FRAME2bane");
    objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->Init(L"Game/Asset/GameObject/Bane.png", 3, 1);
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2bane").lock()->SetScale(Vector3(200.0f, 250.0f, 0.0f));*/

	//enemy�[��
	objectmanager.AddObject<Poyon>(ONOMATOPOEIA, "FRAME2Poyon");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->Init(L"Game/Asset/Onomatopoeia/Poyon.png");
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon").lock()->SetScale(Vector3(240.0f, 120.0f, 0.0f));

	//�p�^�p�^�̔�
	objectmanager.AddObject<PataPata>(GROUND, "FRAME2Box");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetPosition(Vector3(200.0f,-400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Ground�̈�ԉE
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground1");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->SetPosition(Vector3(500.0f, -100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1").lock()->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Ground�̐^��
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground2"); // ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetPosition(Vector3(-180.0f, 100.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetScale(Vector3(350.0f, 50.0f, 0.0f));

	//Ground�̈�ԍ�
	objectmanager.AddObject<GameObject>(GROUND, "FRAME2Ground3");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//�[���i�h�[���j
	objectmanager.AddObject<GameObject>(ONOMATOPOEIA, "FRAME2Gion2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->Init(L"Game/Asset/Onomatopoeia/Doon.png");
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "FRAME2Gion2").lock()->SetScale(Vector3(150.0f, 100.0f, 0.0f));

	//��
	objectmanager.AddObject<GameObject>(OBJECT, "FRAME2treasure");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->Init(L"Game/Asset/GameObject/takarabako.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->SetPosition(Vector3(-750.0f, 250.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure").lock()->SetScale(Vector3(150.0f, 100.0f, 0.0f));
}

void Stage2Scene::Frame3() {
	objectmanager.GetGameObject<Enemy>(ENEMY, "Slime").second->SetPosition(Vector3(-700.0f, 200.0f, 0.0f));

	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	Vector3 pos = playerShared2.lock()->GetPosition();
	pos.x = -900.0f; pos.y = -400.0f; pos.z = 0.0f;
	playerShared2.lock()->SetPosition(pos);

	objectmanager.GetGameObject<Player>(PLAYER, "Player").second->SetPosition(Vector3(-700.0f, -400.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetPosition(Vector3(-500.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box").lock()->SetScale(Vector3(300.0f, 30.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2").lock()->SetPosition(Vector3(-180.0f, 0.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door").lock()->SetPosition(Vector3(850.0f, 150.0f, 0.0f));

	//�p�^�p�^�[��
	objectmanager.AddObject<PataPata>(ONOMATOPOEIA, "FRAME3patapata");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->Init(L"Game/Asset/Onomatopoeia/pata.png");
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->SetPosition(Vector3(-500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata").lock()->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//�r���r���G�t�F�N�g
	objectmanager.AddObject<BiriBiri>(UI, "FRAME3biribiriefect");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->Init(L"Game/Asset/Effect/Thunder_Effect.png", 8, 1);
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->SetPosition(Vector3(550.0f, -460.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(UI, "FRAME3biribiriefect").lock()->SetScale(Vector3(400.0f, 800.0f, 0.0f));

	//�r���r���[��
	objectmanager.AddObject<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->Init(L"Game/Asset/Onomatopoeia/BiriBiri.png");
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->SetPosition(Vector3(500.0f, -350.0f, 0.0f));
	objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri").lock()->SetScale(Vector3(180.0f, 70.0f, 0.0f));

	//�p�^�p�^BOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box1");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->SetPosition(Vector3(-330.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box1").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//�p�^�p�^BOX
	objectmanager.AddObject<PataPata>(GROUND, "FRAME3Box2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->Init(L"Game/Asset/GameObject/hako.png");
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->SetPosition(Vector3(50.0f, -410.0f, 0.0f));
	objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME3Box2").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	//Ground�̈�ԉE
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground1");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->SetPosition(Vector3(750.0f, 50.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1").lock()->SetScale(Vector3(450.0f, 50.0f, 0.0f));

	//�r���r���̏�
	objectmanager.AddObject<GameObject>(GROUND, "FRAME3Ground2");	// ���O�v�ύX
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->Init(L"Game/Asset/GameObject/ground.png");
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->SetPosition(Vector3(550.0f, -450.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2").lock()->SetScale(Vector3(200.0f, 50.0f, 0.0f));

	// �o�l
	objectmanager.AddObject<GameObject>(OBJECT, "baneFRAME3");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->Init(L"Game/Asset/GameObject/bane.png");
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->SetPosition(Vector3(300.0f, -420.0f, 0.0f));
	objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3").lock()->SetScale(Vector3(50.0f, 50.0f, 0.0f));

	// �X���C��
	objectmanager.AddObject<Enemy>(ENEMY, "Slime");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->Init(L"Game/Asset/GameObject/SlimeRight.png");
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetPosition(Vector3(-750.0f, 200.0f, 0.0f));
	objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime").lock()->SetScale(Vector3(80.0f, 40.0f, 0.0f));
}

void Stage2Scene::Frame4() {

}

void Stage2Scene::Init(void) {
	// BGM�Đ�
	Sound::GetInstance().Play(BGM_INGAME);


	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();
	Frame1();
	//sound.Init();


	//-----------------------
	//-----�I�u�W�F�N�g�ǉ�-----
	//-----------------------
	// TODO:1218�����܂� �I�u�W�F�N�g�̊Ǘ���enum����ύX��tag�Ɩ��O�ɂ�����


	

	std::cout << "TitleSceneInit" << std::endl;

	std::cout << "GameSceneInit" << std::endl;

	//// UI1(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "StartButton");
	//// UI2(�{�^��)
	//objectmanager.AddObject<GameObject>(UI, "ExitButton");
	//// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER);
}

int count = 0; // ����O���[�o���ϐ�

void Stage2Scene::Update(void)
{
	Input::GetInstance().Update();
	// �X�e�B�b�N���͒l���擾
	Vector2 RightStickInput = Input::GetInstance().GetRightAnalogStick();	// �E�X�e�B�b�N����
	Vector2 LeftStickInput = Input::GetInstance().GetLeftAnalogStick();		// ���X�e�B�b�N����

	//sound.Play(SOUND_LABEL_BGM000);


	// ���͏��̍X�V
	auto playerShared = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	auto grounds = objectmanager.GetObjects<GameObject>(GROUND);	// �n��(�z��)
	auto under_ground = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");
	auto enemyShared = objectmanager.GetGameObjectPtr<Enemy>(ENEMY, "Slime");
	auto enemygion = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "Poyon");
	auto groundShared = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground");
	auto enemygion2 = objectmanager.GetGameObjectPtr<Poyon>(ONOMATOPOEIA, "FRAME2Poyon");
	auto baneShared = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "bane");
	auto poyonShared = objectmanager.GetGameObjectPtr<GameObject>(Doon, "Gion2");
	auto crosshairShared = objectmanager.GetGameObjectPtr<CrossHair>(UI, "CrossHair");
	auto BoxShared = objectmanager.GetGameObjectPtr<PataPata>(GROUND, "FRAME2Box");
	auto Ground2FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground2");
	auto Ground3FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground3");
	auto playerShared2 = objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player");
	auto PataPataFRAME3 = objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata");
	auto Ground1FRAME3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground1");
	auto PataPatagion = objectmanager.GetGameObjectPtr<PataPata>(ONOMATOPOEIA, "FRAME3patapata");
	auto efectThunder = objectmanager.GetGameObjectPtr<GameObject>(UI, "FRAME3biribiriefect");
	auto BriBriFRAME3 = objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "FRAME3biribiri");
	auto Ground2FRAME3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Ground2");
	auto baneFRAME3 = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneFRAME3");
	auto FRAME3Box1 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Box1");
	auto FRAME3Box2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME3Box2");
	auto gionShared = objectmanager.GetGameObjectPtr<BiriBiri>(ONOMATOPOEIA, "Gion");
	auto treasureBox = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "FRAME2treasure");
	auto groundShared2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
	auto GOOL = objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "door");
	auto Ground1FRAME2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "FRAME2Ground1");
	auto Frame_Red = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame");
	auto Magazine1 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine1"); //�h�[��
	auto Magazine2 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine2"); //���Ƃ��Ƃ�����
	auto Magazine3 = objectmanager.GetGameObjectPtr<Magazine>(UI, "Magazine3"); //�����Ă���

	Vector3 pos = playerShared.second->GetPosition();
	Vector3 p_enemy = enemyShared.lock()->GetPosition();


	switch (m_Frame)
	{
	case FRAME1:
		

		break;
	case FRAME2:
		objectmanager.DeleteObject(Doon, "Gion2");
		/*if (ColliderPlayer_Ground(playerShared2.lock(), Ground1FRAME2)) {
			playerShared2.lock()->SetOnGround(true);
			std::cout << "OnGround�̏�ԁF" << playerShared.second->GetOnGround() << std::endl;
		}*/
		

		BoxCollider2(playerShared2.lock(), BoxShared.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground1FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground2FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground3FRAME2.lock(), playerShared2.lock());

		BoxShared.lock()->Action(BoxShared.lock(),playerShared.second);
		
		//std::cout << "OnGround�̏�ԁF" << playerShared.second->GetOnGround() << std::endl;

		//�X���C���W�����v
		if (Collider_toEnemy(enemyShared, groundShared))
		{
			//�X���C���W�����v�t���O
			if (enemygion2.lock())
			{
				if (enemygion2.lock()->Get_gion() == false)
				{

					Vector3 Slim_Position = enemygion2.lock()->GetPosition();
					Slim_Position = p_enemy;
					Slim_Position.y = Slim_Position.y + 100;
					enemygion2.lock()->SetPosition(Slim_Position);
				}
			}
			enemyShared.lock()->SetJump(true);
		}
		else if (enemygion2.lock()) {
			enemyShared.lock()->SetOnGround(false);
			enemygion2.lock()->Fade_in_out();
		}

		//enemygion2��empty�łȂ����`�F�b�N
		if (enemygion2.lock())
		{
			//�|�����̉摜�ƃo�l�̉摜���������Ă��邩
			if (BoxCollider(enemygion2.lock(), baneShared.lock()))
			{
				enemygion2.lock()->Set_gion(true);
				Vector3 _p_poyon = baneShared.lock()->GetPosition(); //�|�����̍��W
				Vector3 _r_poyon = baneShared.lock()->GetRotation();  //�|�����̉�]
				enemygion2.lock()->Set_Onomatope(true); //�������Ă���t���O��true
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2.lock()->SetPosition(_p_poyon); //�|�����̉摜�̍��W���o�l�ɂ�������
				enemygion2.lock()->SetRotation(_r_poyon); //�|�����̉摜�̉�]���X�V
				std::cout << "����܂���" << std::endl;
			}
			else
			{
				//std::cout << "�������Ă��܂���" << std::endl;
			}

			//���ڂ̉��������܂ł͂�����true
			if (enemygion2.lock()->Get_Onomatope())
			{
				enemygion2.lock()->Fade_in_out();
				//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
				if (BoxCollider(playerShared.second, baneShared.lock()))
				{
					enemygion2.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
				}
			}
		}
		else {
			std::cout << "enemygion2��empty�ł�" << std::endl;
		}


		//enemygion2��empty�łȂ����`�F�b�N
		if (gionShared.lock())
		{
			//�|�����̉摜�ƃo�l�̉摜���������Ă��邩
			if (BoxCollider(gionShared.lock(), treasureBox.lock()))
			{
				gionShared.lock()->Set_gion(true);
				Vector3 _p_poyon = treasureBox.lock()->GetPosition(); //�|�����̍��W
				Vector3 _r_poyon = treasureBox.lock()->GetRotation();  //�|�����̉�]
				gionShared.lock()->Set_Onomatope(true); //�������Ă���t���O��true
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				gionShared.lock()->SetPosition(_p_poyon); //�|�����̉摜�̍��W���o�l�ɂ�������
				gionShared.lock()->SetRotation(_r_poyon); //�|�����̉摜�̉�]���X�V
				std::cout << "����܂���" << std::endl;
			}
			else
			{
				//std::cout << "�������Ă��܂���" << std::endl;
			}

			//���ڂ̉��������܂ł͂�����true
			if (gionShared.lock()->Get_Onomatope())
			{
				gionShared.lock()->Fade_in_out();
				//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
				if (BoxCollider(gionShared.lock(), treasureBox.lock()))
				{
					//gionShared.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
					treasureBox.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f));
				}
			}
		}
		else {
			std::cout << "enemygion2��empty�ł�" << std::endl;
		}

		// �t���[���J�ڏ���
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				m_Frame = FRAME3;
				//playerShared.second->SetOnGround(false);
				Frame3();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");
				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1�̃|����
				objectmanager.DeleteObject(GROUND, "FRAME2Ground1");
			}
		}
		objectmanager.Update(); //Player�̕�������

		break;
	case FRAME3:
		objectmanager.DeleteObject(OBJECT, "bane");

		BoxCollider2(playerShared2.lock(), BoxShared.lock(),playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground3FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground2FRAME2.lock(), playerShared2.lock());
		BoxCollider2(playerShared2.lock(), Ground1FRAME3.lock(), playerShared2.lock());

		if (PataPataFRAME3.lock())
		{
			if (BoxCollider(PataPataFRAME3.lock(), BoxShared.lock()))
			{
				Vector3 PaPata_Position = PataPataFRAME3.lock()->GetPosition();
				Vector3 Box_pos = BoxShared.lock()->GetPosition();
				PaPata_Position = Box_pos;
				PaPata_Position.y = PaPata_Position.y + 100;
				PataPataFRAME3.lock()->SetPosition(PaPata_Position);
			}
			BoxShared.lock()->Action(BoxShared.lock(), playerShared.second);
		}

		//�r���r��
		if (BriBriFRAME3.lock())
		{
			if (BoxCollider(BriBriFRAME3.lock(), efectThunder.lock()))
			{
				efectThunder.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				//_p_biribiri.x = _p_biribiri.x - 250;
				//_p_biribiri.y = _p_biribiri.y + 80;
				//_r_biribiri.z = _r_biribiri.z - 15;
				BriBriFRAME3.lock()->Set_Onomatope(true); //�������Ă���t���O��true
				//
				//gionShared.lock()->SetPosition(_p_biribiri); //�|�����̉摜�̍��W���o�l�ɂ�������
				//gionShared.lock()->SetRotation(_r_biribiri); //�|�����̉摜�̉�]���X�V
				std::cout << "����܂���" << std::endl;
			}
			else {
				efectThunder.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 0.0f)); //�r���r���̃G�t�F�N�g��F�ŏ����������ɂ��Ă�
			}

			//BriBriFRAME3.lock()->Fade_in_out();
			//���ڂ̉��������܂ł͂�����true
			if (BriBriFRAME3.lock()->Get_Onomatope())
			{
				//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
				if (BoxCollider(playerShared.second, Ground2FRAME3.lock()))
				{
					playerShared.second->SetOnGround(true);
					BriBriFRAME3.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
				}
				else {
					Vector3 r_player = playerShared.second->GetRotation();
					r_player.z = 0;
					playerShared.second->SetRotation(r_player);
				}
			}
		}
		else {
			std::cout << "enemygion��empty�ł�" << std::endl;
		}
		if (BriBriFRAME3.lock())
		{
			efectThunder.lock()->Animation(EFECT, efectThunder);
		}

		//enemygion2��empty�łȂ����`�F�b�N
		if (enemygion2.lock())
		{
			//�|�����̉摜�ƃo�l�̉摜���������Ă��邩
			if (BoxCollider(enemygion2.lock(), baneFRAME3.lock()))
			{
				enemygion2.lock()->Set_gion(true);
				Vector3 _p_poyon = baneFRAME3.lock()->GetPosition(); //�|�����̍��W
				Vector3 _r_poyon = baneFRAME3.lock()->GetRotation();  //�|�����̉�]
				enemygion2.lock()->Set_Onomatope(true); //�������Ă���t���O��true
				_p_poyon.x = _p_poyon.x + 30;
				_p_poyon.y = _p_poyon.y + 20;
				_r_poyon.z = _r_poyon.z - 15;
				enemygion2.lock()->SetPosition(_p_poyon); //�|�����̉摜�̍��W���o�l�ɂ�������
				enemygion2.lock()->SetRotation(_r_poyon); //�|�����̉摜�̉�]���X�V
				std::cout << "����܂���" << std::endl;
			}
			else
			{
				//std::cout << "�������Ă��܂���" << std::endl;
			}

			//���ڂ̉��������܂ł͂�����true
			if (enemygion2.lock()->Get_Onomatope())
			{
				enemygion2.lock()->Fade_in_out();
				//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
				if (BoxCollider(playerShared.second, baneFRAME3.lock()))
				{
					enemygion2.lock()->Action(playerShared.second); //�������Ă����Action�֐����s
				}
			}
		}
		else {
			std::cout << "enemygion2��empty�ł�" << std::endl;
		}

		////enemygion��empty�łȂ����`�F�b�N
		//if (PataPataFRAME3.lock())
		//{
		//	//�p�^�p�^�̉摜�ƃo�l�̉摜���������Ă��邩
		//	if (BoxCollider(PataPataFRAME3.lock(), FRAME3Box2.lock()))
		//	{

		//		PataPataFRAME3.lock()->Set_gion(true);
		//		Vector3 _p_poyon = FRAME3Box2.lock()->GetPosition(); //�|�����̍��W
		//		Vector3 _r_poyon = FRAME3Box2.lock()->GetRotation();  //�|�����̉�]
		//		PataPataFRAME3.lock()->Set_Onomatope(true); //�������Ă���t���O��true
		//		_p_poyon.x = _p_poyon.x + 30;
		//		_p_poyon.y = _p_poyon.y + 20;
		//		_r_poyon.z = _r_poyon.z - 15;
		//		PataPataFRAME3.lock()->SetPosition(_p_poyon); //�|�����̉摜�̍��W���o�l�ɂ�������
		//		PataPataFRAME3.lock()->SetRotation(_r_poyon); //�|�����̉摜�̉�]���X�V
		//		std::cout << "����܂���" << std::endl;
		//	}
		//	else
		//	{
		//		//std::cout << "�������Ă��܂���" << std::endl;
		//	}

		//	//���ڂ̉��������܂ł͂�����true
		//	if (PataPataFRAME3.lock()->Get_Onomatope())
		//	{
		//		PataPataFRAME3.lock()->Fade_in_out();
		//		//Player�ƕt�^�����I�u�W�F�N�g���������Ă��邩
		//		if (BoxCollider(playerShared.second, FRAME3Box2.lock()))
		//		{
		//			PataPataFRAME3.lock()->Action(PataPataFRAME3.lock(),playerShared.second); //�������Ă����Action�֐����s
		//		}
		//	}
		/*}
		else {
			std::cout << "enemygion��empty�ł�" << std::endl;
		}*/

		// �t���[���J�ڏ���
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				//m_Frame = FRAME_MAX;
				playerShared.second->SetOnGround(false);
				//Frame4();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");
				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1�̃|����
				Sound::GetInstance().Stop(BGM_INGAME);
				//������TITLE�ɖ߂�
				m_RequestNext = RESULT;
				SetChangeScene(true);
			}
		}
		objectmanager.Update(); 
		break;
	case FRAME4:
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}

	//FRAME1�`FRAME3�܂ł̒n�ʂ̓����蔻��
	if (!BoxCollider2(playerShared2.lock(), under_ground.lock(), playerShared2.lock()))
	{
		playerShared.second->SetOnGround(false);
	}

	// �}�K�W���ɋ[���������Ă���΃G�C���̈ʒu�ɔ���
	if (Input::GetInstance().GetKeyPress(VK_W) || Input::GetInstance().GetRightTrigger())
	{
		//poyonShared.lock()->Set_Onomatope(true); //�[�������˒����̃t���O
		// �}�K�W���ɋ[�������U����Ă��邩�`�F�b�N
		if (playerShared.second->GetLoadedBullet())
		{
			//if (BoxCollider(Frame_Red.lock(), Magazine1.lock())) //�h�[����p
			//{
			//	playerShared.second->UseMagNumber = 0;
			//}
			//else if (BoxCollider(Frame_Red.lock(), Magazine2.lock()))
			//{
			//	playerShared.second->UseMagNumber = 1;
			//}
			playerShared.second->SetIsShot(true);


			//--------------------------------------
			//			�[���̃^�O�ύX����
			//--------------------------------------

			// �����I�u�W�F�N�g�}�l�[�W������[���̏�񎝂��Ă����ق����ǂ������H

			// �����ŋ[���̃^�O��UI����[���ɕύX
			// ���[���̃|�C���^�����킩���Ă�̂ɃL�[�̓��肪�X���[�Y�ɂł��Ȃ��̂ł���ς�Ǘ����@�ς����ق�������(�o�^����Ă�^�O�𖈃t���[���m�F���ē���������Ƃ�)

			// �����ł͎����Ă����[�����L���X�g�ł����^�ɂ���Ă��̋[���̃^�O��ς���悤�ɂ���
			auto bullet = playerShared.second->GetLoadedBullet();

			switch (m_Frame)
			{
			case FRAME1:
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
				break;
			case FRAME2:
				// �[����"�p�^�p�^"�̏ꍇ
				if (dynamic_cast<PataPata*>(bullet))
				{
					objectmanager.ChangeTag(UI, "PataPata", ONOMATOPOEIA);
				}
				// "�r���r��"�̏ꍇ
				else if (dynamic_cast<BiriBiri*>(bullet))
				{
					objectmanager.ChangeTag(UI, "Gion", ONOMATOPOEIA);
				}
				// "�|����"�̏ꍇ
				else if (dynamic_cast<Poyon*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME2Poyon", ONOMATOPOEIA);
				}
				// ����ȊO(�s���Ȍ^)�̏ꍇ
				else
				{
					throw std::runtime_error("�[�����L���X�g�ł��܂���ł���");
				}
				break;
			case FRAME3:
				// �[����"�p�^�p�^"�̏ꍇ
				if (dynamic_cast<PataPata*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME3patapata", ONOMATOPOEIA);
				}
				// "�r���r��"�̏ꍇ
				else if (dynamic_cast<BiriBiri*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME3biribiri", ONOMATOPOEIA);
				}
				// "�|����"�̏ꍇ
				else if (dynamic_cast<Poyon*>(bullet))
				{
					objectmanager.ChangeTag(UI, "FRAME2Poyon", ONOMATOPOEIA);
				}
				// ����ȊO(�s���Ȍ^)�̏ꍇ
				else
				{
					throw std::runtime_error("�[�����L���X�g�ł��܂���ł���");
				}
				break;
			case FRAME4:
				break;
			case FRAME_MAX:
				break;
			default:
				break;
			}
			
			// SE�Đ�
			Sound::GetInstance().Play(SE_SHOT);
			playerShared2.lock()->SetMagNumber(1); //0�Ԗڂ̔z��

		}
	}

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


	// ----------------�z�����ݏ����������̓v���C���[�̏����Ɉڂ�-------------------------
		// �v���C���[���̐�^�Ɠ������Ă�[����T����(��ԋ߂���)�������Ă�[�����z������
	if (Input::GetInstance().GetKeyPress(VK_F) || Input::GetInstance().GetLeftTrigger())
	{
		// �z�����߂�[����T��
		// ���̃t���[�����̃^�O���[���̂��̑S�Ď擾������ƃv���C���[����o���^�̓����蔻����擾
		//auto onomatopoeias = objectmanager.GetObjects<IOnomatopoeia>(ONOMATOPOEIA);
		auto onomatopoeias = objectmanager.GetGameObjectPair<IOnomatopoeia>(ONOMATOPOEIA);
		auto Doononomatopeia = objectmanager.GetGameObjectPair2<IOnomatopoeia>(Doon, "Gion2");

		//�o�C�u���[�V�����X�^�[�g
		Input::GetInstance().SetVibration(0.5f, 1.0f);

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
					
					// �z�����ݏ������I��������ɋ[���̃^�O��UI�ɕύX�A�ˌ�����Ƃ��Ƀ^�O���[���ɕύX���鏈�����܂�
					objectmanager.ChangeTag(HitOnomatopoeia.first.first, HitOnomatopoeia.first.second, UI);
					/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
				}
			}
			// �[����0(�z�����ݒ��ɐ�^�͈͂���[�������Ȃ��Ȃ����ꍇ)
			else
			{
				// �v���C���[�̏�Ԃ�ύX
				playerShared.second->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
				if (m_Frame == FRAME1)
				{
					count = 1; //�`���[�g���A���̉摜�؂�ւ��J�E���g
					objectmanager.GetGameObjectPtr<GameObject>(OBJECT, "baneboard").lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
				}
			}
		}
		// �[����0(�t���[�����̋[�����Ȃ��ꍇ)
		else
		{
			// �v���C���[�̏�Ԃ�ύX
			playerShared.second->SetIsSuction(false);		// �u��v�z�����ݒ��ɐݒ�
		}


		// Doon��p
		if (!Doononomatopeia.empty())
		{
			// ��`�Ƃ̓����蔻����擾
			auto HitDoon = ColliderFan_Gion(playerShared.second, Doononomatopeia);

			// �|�C���^�ɒl�������Ă����(��`�͈͓��ɓ��������[���������)
			if (HitDoon.second)
			{
				// �[���̋z�����ݎ��s
				playerShared.second->SetIsSuction(true);			// �v���C���[�̏�Ԃ��z�����ݒ��ɐݒ�

				// �z�����ݏ������I�������
				if (playerShared.second->Suction(HitDoon.second))
				{
					playerShared.second->m_Magazines.resize(2); //�Œ���P�R�m��
					if (HitDoon.second == poyonShared.lock())
					{
						poyonShared.lock()->SetPosition(Vector3(800.0f, 450.0f, 0.0f));
						poyonShared.lock()->SetScale(Vector3(300.0f, 150.0f, 0.0f));
					}
					playerShared.second->m_Magazines[0] = std::static_pointer_cast<Magazine>(poyonShared.lock()); //�L���X�g���Ĕz��̂O�ԖڂɊi�[
					// �z�����ݏ������I��������ɋ[���̃^�O��UI�ɕύX�A�ˌ�����Ƃ��Ƀ^�O���[���ɕύX���鏈�����܂�
					objectmanager.ChangeTag(HitDoon.first.first, HitDoon.first.second, UI);
					/*enemygion.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
					gionShared.lock()->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));*/
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
	else {
		Input::GetInstance().SetVibration(0.0f, 0.0f); //�o�C�u���[�V����������
	}
	//�A�F����
	//�[������������Ƃ��ɁA�I�u�W�F�N�g�������ړ������邾������Ȃ��āA��������I�u�W�F�N�g�̏��ɂ���ĕ\��������UI��ς���

	// ���͊Ǘ�
		// �E�ړ�
	if (Input::GetInstance().GetKeyPress(VK_D) || LeftStickInput.x > 0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveRight(true);
		//sound.Play(SOUND_LABEL_BGM000);
		//�f�o�b�N�p
		//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// ���ړ�
	if (Input::GetInstance().GetKeyPress(VK_A) || LeftStickInput.x < -0.1f)
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetMoveLeft(true);

		//�f�o�b�N�p
		//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}
	// �W�����v
	if (Input::GetInstance().GetKeyTrigger(VK_SPACE) || Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_A))
	{
		objectmanager.GetGameObjectPtr<Player>(PLAYER, "Player").lock()->SetJump(true);
		//�f�o�b�N�p
		//std::cout << "Player�̍��W�ړ����ł��Ă��܂�" << std::endl;
	}

	// �N���X�w�A�̓��͎擾(�{���̓v���C���[�̃t���O�𗧂ĂāA�v���C���[�̍X�V�̒��ŃN���X�w�A�𓮂����ׂ�)XINPUT_GAMEPAD_RIGHT_THUMB
	if (Input::GetInstance().GetKeyPress(VK_UP) || RightStickInput.y > 0.1f)
	{
		crosshairShared.lock()->SetMoveUp(true);
	}
	else
	{
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


	if (m_Frame == FRAME1)
	{
		Vector3 poyon_rotation = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->GetRotation();
		Vector3 poyon_posiiton = objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->GetPosition();

		if (count == 0)
		{
			poyon_rotation.z += 5.0f;
		}
		else if(count == 1){
			poyon_rotation.z = 0.0f;
			objectmanager.DeleteObject(ENEMY, "Slimeboard");
			objectmanager.DeleteObject(UI, "SoundGunboard");
		}
		objectmanager.GetGameObjectPtr<GameObject>(ONOMATOPOEIA, "Poyonboard").lock()->SetRotation(poyon_rotation);

		std::cout << playerShared2.lock()->m_Magazines.size() << std::endl; //�}�K�W�����̃f�o�b�N
		// �V�[���X�V�ɕK�v�ȏ����擾
		auto grounds2 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground2");
		auto effectShared = objectmanager.GetGameObjectPtr<GameObject>(UI, "Thunder_Effect");
		auto groundShared3 = objectmanager.GetGameObjectPtr<GameObject>(GROUND, "Ground3");

		 BoxCollider2(playerShared2.lock(), groundShared2.lock(),playerShared2.lock());
		
		effectShared.lock()->Animation(EFECT, effectShared);

		////�[���̑I��
		//if (Input::GetInstance().GetKeyTrigger(VK_P))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();
		//	p_frame.x = p_frame.x + 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		//}
		//if (Input::GetInstance().GetKeyTrigger(VK_O))
		//{
		//	Vector3 p_frame = objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->GetPosition();
		//	p_frame.x = p_frame.x - 120;
		//	objectmanager.GetGameObjectPtr<GameObject>(UI, "Frame").lock()->SetPosition(p_frame);
		//}


		//�Q�[����ʂɑJ��
		// �V�[���J�ځi�f�o�b�N�p
		/*if (Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			this->ChangeScene = true;
			SetChangeScene(this->ChangeScene);
		}*/


		
		//ColliderPlayer_Ground(playerShared.second, grounds2);



		//�X���C���W�����v
		if (Collider_toEnemy(enemyShared, groundShared))
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
			enemyShared.lock()->SetOnGround(false);
			enemygion.lock()->Fade_in_out();
		}

		if (enemygion.lock() != nullptr)
		{
			Vector4 poyon_color = enemygion.lock()->GetColor(); //�G���[�F�z������u�Ԃ�enemygion���̂��폜�����̂ŃG���[���o��
			Vector3 p_poyon = p_enemy;
			p_poyon.x = p_poyon.x + 50;
			p_poyon.y = p_poyon.y + 150;
		}

		Vector3 enemy_Rotation = enemyShared.lock()->GetRotation();


		if (p_enemy.x <= -300)
		{
			enemyShared.lock()->cb.matrixWorld = DirectX::XMMatrixScaling(-1.0f, 1.0f, 1.0f);
		}
		//std::cout << p_enemy.x << std::endl;

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
					Sound::GetInstance().Play(SE_POYON);
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
					Sound::GetInstance().Play(SE_BIRIBIRI);
				}
				else {
					Vector3 r_player = playerShared.second->GetRotation();
					r_player.z = 0;
					playerShared.second->SetRotation(r_player);
				}
			}
		}
		else {
			playerShared2.lock()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		}


		// �����Ń}�K�W����UI�ɂȂ��Ă��Ȃ���Γ����蔻�����肽��
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
			}

		}
		/////////////////////////////////
		// �J�[�\���ړ����ċ[���̑I��
		/////////////////////////////////

		
		// �}�K�W���Ƃ̓����蔻��𖈃t���[����遨�}�K�W�����擾�����炻�̔���`�F�b�N�͂��Ȃ��Ă���
		//objectmanager.Collider_Player_to_Object();		// �����œ���������}�K�W�������P���炷


		// �t���[���J�ڏ���
		if (Input::GetInstance().GetButtonTrigger(XINPUT_GAMEPAD_B) || Input::GetInstance().GetKeyTrigger(VK_RETURN))
		{
			if (Collider_to_Object(playerShared2.lock(), GOOL.lock()))
			{
				m_Frame = FRAME2;
				//playerShared.second->SetOnGround(false);
				Frame2();
				objectmanager.DeleteObject(ONOMATOPOEIA, "Gion");

				objectmanager.DeleteObject(UI, "Thunder_Effect");
				objectmanager.DeleteObject(GROUND, "Ground3");
				objectmanager.DeleteObject(GROUND, "Ground2");
				//objectmanager.DeleteObject(ONOMATOPOEIA, "Gion2");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyon"); //FRAME1�̃|����
				objectmanager.DeleteObject(BACKGROUND, "board1");
				objectmanager.DeleteObject(BACKGROUND, "Playerboard");
				objectmanager.DeleteObject(ONOMATOPOEIA, "Poyonboard");
				objectmanager.DeleteObject(ENEMY, "Slimeboard");
				objectmanager.DeleteObject(UI, "SoundGunboard");
				objectmanager.DeleteObject(OBJECT, "baneboard");
			}
		}
		objectmanager.Update();
	}
}

void Stage2Scene::Draw(void) {
	switch (m_Frame)
	{
	case FRAME1:
		break;
	case FRAME2:
		break;
	case FRAME3:
		break;
	case FRAME4:
		break;
	case FRAME_MAX:
		break;
	default:
		break;
	}
	objectmanager.Draw();
}

void Stage2Scene::Uninit(void) {
	objectmanager.Uninit();
	//sound.Uninit();
}

void Stage2Scene::ChangeFRAME(void) {
	auto playerSharde = objectmanager.GetGameObject<Player>(PLAYER, "Player");
	Vector3 pos = playerSharde.second->GetPosition();
}