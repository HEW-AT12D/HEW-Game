#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../ObjectManager/ObjectManager.h"
#include "../../Framework/Sound/sound.h"

/**
 * @brief �^�C�g���V�[���N���X
 * 
 * �T�E���h�A�w�i�Ȃǂ̃Q�[���I�u�W�F�N�g��z��iarray�j�Ŏ���
*/
class TitleScene :public IScene
{
public:
	TitleScene();
	~TitleScene();
	void Init(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Uninit(void)override;

private:
	//Sound sound;
	ObjectManager objectmanager;
};



