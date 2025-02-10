#pragma once
#include<Vector2.h>
#include <Novice.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <Scoer.h>
const int kStageWidth = 700;
const int kStageHeight = 720;
float Lengeth(Vector2 vector2);
float Lengeth(Vector2 posA,Vector2 posB);
Vector2 Normarize(Vector2 vector2);

class Obj {
public:
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();
	/// <summary>
	/// ugoki
	/// </summary>
	virtual void Move();

	Obj();

	void SetPos(Vector2 vector);
	Vector2 GetPos(){return pos_;} 

protected:

	Vector2 pos_;
	Vector2 velocity_;
	Vector2 speed_;
	Vector2 size_;
	float radius_;
	bool ishit_;	
	//int GraphHandle_;
};
