#pragma once
#include "../../Framework/Scene/IScene.h"
#include "../../Framework/ObjectManager/ObjectManager.h"


class ResultScene :public IScene
{
public:
	ResultScene();
	~ResultScene();
	
	void Init(void) override;		//! ‰Šú‰»
	void Update(void) override;		//! XV
	void Draw(void) override;		//! •`‰æ
	void Uninit(void) override;		//! I—¹

private:
	ObjectManager objectmanager;
};
