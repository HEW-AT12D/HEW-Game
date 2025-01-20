#include"RigitBody2D.h"

/*!
*	重力を適用させる関数
*	オブジェクトの高さとジャンプor落下し始めてからの時間、初速度が必要
*	
*/
int RigitBody2D::NaturalFall(int position_y,double time,double velocity)
{

	velocity += gravity * time;		//速度の計算
	position_y -= velocity * time;	//速度からｙ座標を算出

	return position_y;
}