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
	objectmanager.AddObject<GameObject>(OBJECT);
	// �^�C�g��
	objectmanager.AddObject<GameObject>(OBJECT);
	// UI1(�{�^��)
	objectmanager.AddObject<GameObject>(OBJECT);
	// UI2(�{�^��)
	objectmanager.AddObject<GameObject>(OBJECT);
	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void) {

}

void TitleScene::Draw(void) {

}

void TitleScene::Uninit(void) {

}
