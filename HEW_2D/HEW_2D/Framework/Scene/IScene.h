#pragma once
#include "../../Game/ObjectManager/ObjectManager.h"


//! -----------�݌v�����FIScene���������̘b-----------------
//! �V�[���N���X�̓e���v���[�g�ɂ��āA���N���X�Ƃ���IScene���������Ƃ��ׂ�����Ȃ��H�H

/**
 * @brief �V�[���̒��ۃN���X
 *
 * �S�ẴV�[����������p������̂Ń|�����[�t�B�Y���ŃV�[�����Ǘ��ł���
 * 
 * �����ɃI�u�W�F�N�g�}�l�[�W���u���Ƃ��ׂ��H
 * 
 * �V�[�����̃I�u�W�F�N�g�}�l�[�W�����I�u�W�F�N�g��������d3d�̎Q�Ƃ�n��
 */
class IScene
{
public:
	IScene(D3D11& _D3d11) :objectmanager(_D3d11) {};

	virtual ~IScene() {};

	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void Uninit(void) = 0;

	void SetChangeScene(bool _Flg);
	bool GetChangeScene(void);

protected:
	ObjectManager objectmanager;
	bool ChangeScene = false;
};
