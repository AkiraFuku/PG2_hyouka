#pragma once
#include"Obj.h"

class Bullet:public Obj {

private:
	int GraphHandle_;

public:
	Bullet();	
	~Bullet();
	bool isShot_;
	void Update ();
	float GetRadius() { return radius_; };
	void Draw ()override;
	void reset();
	void Move ()override;
};
