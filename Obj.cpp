#include "Obj.h"

void Obj::Draw() {}

void Obj::Move() {}

Obj::Obj() {
	pos_ = {0.0f, 0.0f};
	velocity_ = {0.0f, 0.0f};
	speed_ = {0.0f, 0.0f};
	size_ = {0.0f, 0.0f};
	radius_ = 0.0f;
	ishit_ = false;
	
}



/// <summary>
/// pos_のセッター
/// </summary>
/// <param name="vector"></param>
void Obj::SetPos(Vector2 vector) {pos_=vector;};
/// <summary>
/// lengethの取得
/// </summary>
/// <param name="vector2"></param>
/// <returns></returns>
float Lengeth(Vector2 vector2) {
	float lengeth_ = sqrtf(static_cast<float>(
				pow(vector2.x, 2) +
				pow(vector2.y, 2)));
	return lengeth_; 
}

float Lengeth(Vector2 posA, Vector2 posB) { 
	
	float lengeth_ = sqrtf(static_cast<float>(
				pow(posA.x-posB.x, 2) +
				pow(posA.y-posB.y, 2)));
	return lengeth_; 

}
/// <summary>
/// 正規化
/// </summary>
/// <param name="vector2"></param>
/// <returns></returns>
Vector2 Normarize(Vector2 vector2) {
	Vector2 vector;
	
	if (Lengeth(vector2) != 0.0f){
		return vector	={ vector2.x / Lengeth(vector2),vector2.y / Lengeth(vector2)};
	}else {
		return vector2;
	}
	
}
