#include "TitleScene.h"
#include "../../Game/Objcet/Player/Player.h"


TitleScene(D3D11& _D3d11) :IScene(_D3d11) {

}




/**
 * @brief �^�C�g��������
*/
void TitleScene::Init(void) {
	// �I�u�W�F�N�g�}�l�[�W��������
	objectmanager.Init();

	// �I�u�W�F�N�g�ǉ�		objectmanager.AddObject<GameObject>(OBJECT);

	// �w�i
	objectmanager.AddObject<GameObject>(OBJECT);

	// �v���C���[
	objectmanager.AddObject<Player>(PLAYER);
}

void TitleScene::Update(void){

}

void TitleScene::Draw(void){

}

void TitleScene::Uninit(void){

}
