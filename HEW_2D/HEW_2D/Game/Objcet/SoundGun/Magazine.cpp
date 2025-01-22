#include"Magazine.h"

void Magazine::SetOnomatopoeia(std::unique_ptr<IOnomatopoeia>&& _onomatopoeia)
{
	// 所有権を移動
	m_Onomatopoeia = std::move(_onomatopoeia);
}

void Magazine::Update(void)
{
	// 重力加速度
	if (!OnGround)
	{
		// 接地していなければ加算
		m_Velocity.y -= 0.5f;
	}
	else {

	}

	// 移動処理
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// 方向ベクトルとX成分の移動速度を掛けた値の分だけ毎フレーム進む
	// 新しい座標を代入
	transform.SetPosition(newpos);
}
