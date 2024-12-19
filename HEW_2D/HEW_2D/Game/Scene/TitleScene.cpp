#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"



/**
 * @brief �^�C�g���V�[���̏�����
 *
 * �V�[�����Ƃɏ������͍ŏ��̈�x�̂�
 * ��
*/
void TitleScene::Init(void) {
	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();

	//-----------------------
	//-----�I�u�W�F�N�g�ǉ�-----
	//-----------------------
	// TODO:1218�����܂� �I�u�W�F�N�g�̊Ǘ���enum����ύX��tag�Ɩ��O�ɂ�����
	
	// �w�i
	objectmanager.AddObject<GameObject>(BACKGROUND, "Background1");
	objectmanager.GetGameObject(BACKGROUND, "Background1")->Init("")
	// �^�C�g��
	objectmanager.AddObject<GameObject>(IMAGE, "TitleImage");
	// UI1(�{�^��)
	objectmanager.AddObject<GameObject>(UI, "StartButton");
	// UI2(�{�^��)
	objectmanager.AddObject<GameObject>(UI, "ExitButton");
	// �v���C���[
	//objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void) {

}

void TitleScene::Draw(void) {

}

void TitleScene::Uninit(void) {

}
