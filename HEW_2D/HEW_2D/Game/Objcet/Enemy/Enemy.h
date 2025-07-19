#pragma once
#include"../Character/Character.h"

class Enemy :public Character
{
public:
	Enemy(D3D11& _D3d11, Sound* _sound = nullptr) :Character(_D3d11, _sound) {
		m_Velocity = { 0.0f };
		m_MoveSpeed = 1.0f;
		m_JumpPower = 7.0f;
	}
	~Enemy();//デストラクタ
	void Update();//エネミーの動作
	float m_Timer = 0.0f;
	float m_ChangeDirInterval = 5.0f; // 2秒ごとに反転
	bool m_FacingLeft = true;
	DirectX::XMINT2 uv;
	Enemy* enemy;

};