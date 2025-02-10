#pragma once
#include <Novice.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include<Scoer.h>
#include "Player.h"
#include "Enemy.h"


enum SCENE{
		TITLE,
		GAME,
		GAMEOVER,
	};
typedef struct Background {
	Vector2 pos;
	int graphHandle;
} Background;
class Scene {
private:
	int frameCount_;
	int timer_;
	int hieScoer_;
	int BgHandle_;
	int playHandle_;
	Background backGround_[2];
	int numberGraphs_[10];


	Player* player_;
	Enemy* enemy_[10];
	unsigned int titleGlaph_;
	unsigned int endGraph_;
	unsigned int akaDaikonn_;
	unsigned int uiGlaph_;
	std::vector<int> numberArray_[3];
public:
	Scene();
	~Scene();
	void numberDraw(Vector2 pos,int width,int i);
	void Update(const char* keys,const char*preKeys);
	void Draw();
	int scene_;
};
