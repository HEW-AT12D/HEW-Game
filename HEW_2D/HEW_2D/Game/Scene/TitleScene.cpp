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

	// �I�u�W�F�N�g�ǉ�		


	// �w�i
	objectmanager.AddObject<GameObject>(OBJECT);
	objectmanager.

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void){

}

void TitleScene::Draw(void){

}

void TitleScene::Uninit(void){

}
