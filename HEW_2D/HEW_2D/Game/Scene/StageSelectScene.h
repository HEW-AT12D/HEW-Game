#pragma once
#include "../../Framework/Scene/IScene.h"


/**
 * @brief �X�e�[�W�I���V�[��
 * ���̃V�[���̓Q�[������ɕێ����Ă���
 * 
 * ���ԂɃX�e�[�W���J���Ă����݌v�ɂ���Ȃ炻����Ǘ�����d�g�݂��K�v
*/
class StageSelectScene :public IScene
{
public:
	StageSelectScene(D3D11& _D3d11) :IScene(_D3d11) {
		ChangeScene = false;
	}
	~StageSelectScene() {};

	void Init(void) override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;


private:
	
};

