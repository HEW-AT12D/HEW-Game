#pragma once
#include "../../../Game/SceneManager/SceneManager.h"
#include "../../../Framework/D3D11/D3D11.h"
#include"../../../Game/Scene/Stage1Scene.h"
#include "../../../Framework/Sound/sound.h"



//class D3D11;

/**
 * @brief �Q�[���N���X
 * �A�v���P�[�V�����N���X���ێ�����Q�[���N���X
 * �����̃N���X��؂�ւ���Α��̃Q�[���ł����̊O���̃N���X�͎g���܂킹��
*/
class Game
{
public:
	Game(D3D11& _D3d11) :scenemanager(_D3d11) {};
	~Game() {};

	void Init(void);
	void Update(void);
	void Draw(void);
	void Uninit(void);

private:
	SceneManager scenemanager;	// �V�[���Ǘ��N���X

};
