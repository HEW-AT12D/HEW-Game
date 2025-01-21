#include "Player.h"
#include "../../../Framework/Input/Input.h"


/**
 * @brief 更新
*/
void Player::Update(void) 
{
	// 方向ベクトル初期化
	m_Direction = { 0.0f };

	// 方向ベクトルを合成
	// ジャンプした場合
	if (Jump)
	{
		Jumping = true;					// ジャンプ中に設定(これステートでもいいかも)
		m_Velocity.y += m_JumpPower;	// 速度のY成分にジャンプ力を代入
		m_Direction.y += 1.0f;			// 上向きの方向ベクトルを加算
		Jump = false;
		Animation(JUMP);
	}
	// 下降している場合(ジャンプ中でベクトルのY成分が負(-)の時)
	if (Jumping && m_Velocity.y < 0.0f)
	{
		Animation(JUMP);
		// 地面に足がついた場合は方向ベクトルをリセット
		if (m_Velocity.y == 0.0f)
		{
			Jumping = false;
		}
		else
		{
			// そうでない場合(下降中の場合)
			m_Direction.y -= 1.0f;	// 下向きの方向ベクトルを加算
		}
	}
	// 左移動しようとしている場合
	if (MoveLeft)
	{
		m_Direction.x -= 1.0f;	// 左向きの方向ベクトルを加算
		Animation(RUN);
		MoveLeft = false;
	}
	// 右移動しようとしている場合
	if (MoveRight)
	{
		m_Direction.x += 1.0f;	// 右向きの方向ベクトルを加算
		Animation(RUN);
		MoveRight = false;
	}

	// 正規化(長さを１に揃える)
	if (m_Direction.Length() > 0.0f)
	{
		m_Direction.Normalize();
	}
	else
	{
		m_Direction = { 0.0f, 0.0f, 0.0f };  // 明示的に方向ベクトルをリセット
	}

	// X成分の移動速度を方向ベクトルと移動速度から計算
	m_Velocity.x = m_Direction.x * m_MoveSpeed;

	// 地面の上にいない場合、重力分速度を減算
	if (!OnGround)
	{
		m_Velocity.y -= 0.5f;	// 重力加速度実装の場合ここを変更
	}

	// 移動処理
	Vector3 newpos = transform.GetPosition();
	newpos += m_Velocity;		// 方向ベクトルとX成分の移動速度を掛けた値の分だけ毎フレーム進む
	// 新しい座標を代入
	transform.SetPosition(newpos);
	
}

/**
 * @brief アニメーション関数
 * @param どのアニメーションを再生するかの列挙型
 * ジャンプ中に移動しちゃうと移動アニメーションが優先されてしまうのでそこ直したい
 * 接地したときに左右移動キー押さないと通常時に戻らないのでそこも直す
*/
void Player::Animation(STATE _Anim_Name)
{
	// 一番初めはアニメーション加算なのでCountUpをtrueに設定
	static bool CountUp = true;
	static bool CountDown = false;
	// ディレイ用フレームカウント変数
	static int framecount = 0;

	// UV番号最大値で割る→余りがあればまだ加算できる
	// 余りなし→アニメーション最終フレームなので減算開始
	// →行いたいアニメーションの種類だけ引数で送る→関数内で計算して加算中か減算中かを判断させればいい
	switch (_Anim_Name)
	{
	case NORMAL:
		// 通常時は何もしない(小刻みな縦揺れアニメーションとかあればここに書く)
		break;
	case RUN:
		// 通常移動時
		//TODO:2025/01/21 左向きに移動したときの処理がまだ！！！！！！！！！！！！！！
		this->m_Number.y = 0;	// 一番上の段を使う

		// フレーム数加算
		framecount++;
		if (framecount == 3)
		{
			// 加算中は
			if (CountUp)
			{
				// アニメーション番号加算(アニメーションごとに分割数が違う場合はswitchで条件分けしてここに分割数を入れればおｋ)
				m_Number.x += 1;
				// アニメーション番号余りなし→アニメーション最終フレームなので減算開始
				if (m_Number.x % m_Split.x == 0)
				{
					CountDown = true;
					CountUp = false;
				}
			}
			// 減算中は
			if (CountDown)
			{
				// アニメーション番号加算
				m_Number.x -= 1;
				// アニメーション番号が0より小さい→アニメーションの開始フレームなので番号を0に戻して加算開始
				if (m_Number.x < 0)
				{
					m_Number.x = 0;
					CountUp = true;
					CountDown = false;
				}
			}
			framecount = 0;
		}
		break;
	case JUMP:
		// ここがややこしい
		// ・ジャンプしたとき→ジャンプ中ではなくジャンプフラグが立った時
		// ・上昇中のとき→ジャンプ中でベクトルのY成分が正(+)の時
		// ・下降中のとき→ジャンプ中でベクトルのY成分が負(-)の時
		// ・着地したとき→ジャンプ中で下向きのベクトルが0になった時(プレイヤーが地面に接触したとき)

		// ジャンプ時
		// ・ジャンプしたとき→ジャンプ中ではなくジャンプフラグが立った時
		if (!Jumping && Jump)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・上昇中のとき→ジャンプ中でベクトルのY成分が正(+)の時
		if (Jumping && m_Velocity.y > 0.0f)
		{
			// 別画像がないので同じものを使う
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 0;	// 左を使う
		}
		// ・下降中のとき→ジャンプ中でベクトルのY成分が負(-)の時
		if (Jumping && m_Velocity.y < 0.0f)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}
		// ・着地したとき→ジャンプ中で下向きのベクトルが0になった時(プレイヤーが地面に接触したとき)
		if (Jumping && m_Velocity.y == 0)
		{
			this->m_Number.y = 1;	// 二番目の段の
			this->m_Number.x = 1;	// 右を使う
		}

		break;

	// ↓は画像内ので今のところ実装予定なし
	case DAMAGED:
		break;
	case ATTACKED:
		break;
	default:
		break;
	}
}
