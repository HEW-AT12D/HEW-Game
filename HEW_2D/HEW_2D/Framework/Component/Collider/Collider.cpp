#include"Collider.h"
#include"../../../Game/Objcet/BaseObject/Object.h"


//PlayerとGroundの当たり判定
bool ColliderPlayer_Ground(GameObject* player, GameObject* ground)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Up_Collider, Player_Bottom_Collider;//playerの当たり判定変数
	float Ground_Right_Collider, Ground_Left_Collider, Ground_Up_Collider, Ground_Bottom_Collider;//groundの当たり判定変数

	Player_Right_Collider = player->GetPosition().x + player->GetScale().x / 2; //プレイヤーの右当たり判定変数
	Player_Left_Collider = player->GetPosition().x - player->GetScale().x / 2;  //プレイヤーの左当たり判定変数
	Player_Up_Collider = player->GetPosition().y + player->GetScale().y / 2;    //プレイヤーの上当たり判定変数
	Player_Bottom_Collider = player->GetPosition().y - player->GetScale().y / 2;//プレイヤーの下当たり判定変数

	Ground_Right_Collider = ground->GetPosition().x + ground->GetScale().x / 2; //グラウンドの右の当たり判定変数
	Ground_Left_Collider = ground->GetPosition().x - ground->GetScale().x / 2;  //グラウンドの左の当たり判定変数
	Ground_Up_Collider = ground->GetPosition().y + ground->GetScale().y / 2;    //グラウンドの上の当たり判定変数
	Ground_Bottom_Collider = ground->GetPosition().y - ground->GetScale().y / 2;//グラウンドの下の当たり判定変数

	//プレイヤーとグラウンドの当たり判定
	if (1.0f > Player_Left_Collider - Ground_Right_Collider && 1.0f > Ground_Left_Collider - Player_Right_Collider && 0.5f > Player_Bottom_Collider - Ground_Up_Collider)
	{
		return true;
	}
	else {
		return false;
	}
}


//PlayerとGionの当たり判定
bool ColliderPlayer_Gion(GameObject* player, GameObject* gion)
{
	float Player_Right_Collider, Player_Left_Collider, Player_Up_Collider, Player_Bottom_Collider;//playerの当たり判定変数
	float Gion_Right_Collider, Gion_Left_Collider, Gion_Up_Collider, Gion_Bottom_Collider;        //gionの当たり判定変数

	Player_Right_Collider = player->GetPosition().x + player->GetScale().x / 2; //プレイヤーの右当たり判定変数
	Player_Left_Collider = player->GetPosition().x - player->GetScale().x / 2;  //プレイヤーの左当たり判定変数
	Player_Up_Collider = player->GetPosition().y + player->GetScale().y / 2;    //プレイヤーの上当たり判定変数
	Player_Bottom_Collider = player->GetPosition().y - player->GetScale().y / 2;//プレイヤーの下当たり判定変数

	Gion_Right_Collider = gion->GetPosition().x + gion->GetScale().x / 2;   //擬音の右当たり判定
	Gion_Left_Collider = gion->GetPosition().x - gion->GetScale().x / 2;    //擬音の左当たり判定
	Gion_Up_Collider = gion->GetPosition().y + gion->GetScale().y / 2;      //擬音の上当たり判定
	Gion_Bottom_Collider = gion->GetPosition().y - gion->GetScale().y / 2;	//擬音の下当たり判定

	//Playerと擬音の当たり判定
	if (1.0f > Player_Left_Collider - Gion_Right_Collider && 1.0f > Gion_Left_Collider - Player_Right_Collider && 0.5f > Player_Bottom_Collider - Gion_Up_Collider)
	{
		std::cout << "Playerと擬音が衝突しました" << std::endl;
  		return true;
	}
	else {
		return false;
	}
}


//扇型と擬音の当たり判定
bool ColliderFan_Gion(GameObject*fan, GameObject*gion)
{
	float PI = 3.14159265;
	float fanAngle = PI / 6;
	//扇型の情報取得
	float fanCenterX = fan->GetPosition().x-30;   //扇型の中心X座標
	float fanCenterY = fan->GetPosition().y;   //扇型の中心Y座標
	float fanRadius = fan->GetScale().x / 2;   //扇型の半径（スケールのX方向を使用）

	//扇型の方向ベクトルを右方向に固定
	float fanDirX = 1.0f;//右方向の成分
	float fanDirY = 0.0f;//上方向の成分

	//擬音の情報取得
	float Gion_Right_Collider = gion->GetPosition().x + gion->GetScale().x / 2; //擬音の右端
	float Gion_Left_Collider = gion->GetPosition().x - gion->GetScale().x / 2;  //擬音の左端
	float Gion_Up_Collider = gion->GetPosition().y + gion->GetScale().y / 2;    //擬音の上端
	float Gion_Bottom_Collider = gion->GetPosition().y - gion->GetScale().y / 2;//擬音の下端

	//擬音の四つの頂点
	float vertices[4][2] = {
		{Gion_Left_Collider,Gion_Up_Collider},//左上
		{Gion_Right_Collider,Gion_Up_Collider},//右上
		{Gion_Left_Collider,Gion_Bottom_Collider},//左下
		{Gion_Right_Collider,Gion_Bottom_Collider},//右下
	};

	//四角形の各頂点が扇形内に含まれるか確認
	for (int i = 0; i < 4; ++i) {
		float dx = vertices[i][0] - fanCenterX;   //扇型中心から頂点へのベクトルX
		float dy = vertices[i][1] - fanCenterY;   //扇型中心から頂点へのベクトルY
		float distance = sqrtf(dx * dx + dy * dy);//距離を計算

		//距離が半径内か確認
		if (distance <= fanRadius) {
			//ベクトルの角度の計算（内積）
			float dot = (dx * fanDirX + dy * fanDirY) / (distance);//cosθ=内積/(|v1|*|v2|)

			//角度が範囲内か確認
			float cosLimit = cosf(fanAngle);//扇型の角度範囲のcos値
			if (dot >= cosLimit) {
				std::cout << "頂点が扇型内です" << std::endl;
				return true;//頂点が扇型内
			}
		}
	}

	//四角形の辺が扇型の円弧と交差しているか確認
	float edges[4][4] = {
		{Gion_Left_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Up_Collider},        //上辺
		{Gion_Right_Collider,Gion_Up_Collider,Gion_Right_Collider,Gion_Bottom_Collider},   //右辺
		{Gion_Left_Collider,Gion_Bottom_Collider,Gion_Right_Collider,Gion_Bottom_Collider},//下辺
		{Gion_Left_Collider,Gion_Up_Collider,Gion_Left_Collider,Gion_Bottom_Collider}      //左辺
	};
	for (int i = 0; i < 4; ++i) {
		if (LineIntersectsCircle(edges[i][0], edges[i][1], edges[i][2], edges[i][3], fanCenterX, fanCenterY, fanRadius)) {
			std::cout << "四角形の辺が扇型の円弧と交差しています" << std::endl;
			return true;//四角形の辺が扇型の円弧と交差
		}
	}
	//扇型の中心が四角形内にあるか確認
	if (fanCenterX >= Gion_Left_Collider && fanCenterX <= Gion_Right_Collider &&
		fanCenterY >= Gion_Bottom_Collider && fanCenterY <= Gion_Up_Collider) {
		return true;//扇型が中心が四角形内
	}
	return false;//どれにも該当しない場合、当たっていない
}

// 線分と円が交差しているか判定する関数
bool LineIntersectsCircle(float x1, float y1, float x2, float y2, float cx, float cy, float radius)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float fx = x1 - cx;
	float fy = y1 - cy;

	float a = dx * dx + dy * dy;
	float b = 2 * (fx * dx + fy * dy);
	float c = (fx * fx + fy * fy) - radius * radius;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		return false;//交差していない
	}
	else {
		discriminant = sqrtf(discriminant);
		float t1 = (-b - discriminant) / (2 * a);
		float t2 = (-b + discriminant) / (2 * a);

		return (t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1);
	}
}


void DrawFan(GameObject* fan, bool isColliding)
{
	//扇型の情報取得
	float centerX = fan->GetPosition().x;
	float centerY = fan->GetPosition().y;
	float radius = fan->GetScale().x / 2;
	float M_PI = 3.14159265;
	float fanAngle = M_PI / 6;//開き角度（30度）
	float dirX = cosf(fan->GetRotation().z);
	float dirY = sinf(fan->GetRotation().z);

	//色判定
	float r, g, b;
	if (isColliding) {
		r = 1.0f; g = 0.0f; b = 0.0f;//赤
	}
	else {
		r = 0.0f, g = 1.0f, b = 0.0f;//緑
	}
}