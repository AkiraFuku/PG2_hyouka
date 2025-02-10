#pragma once
#include "Obj.h"    
class Enemy:public Obj {
   
private:
    int hitCoolTime_;
    int sound_;
    int playHandle_;
    bool isAlive_;
    int respawnTimer_;
	int bombGraphHandle_[9];
    int GraphHandle_;

public:
    Enemy();

    void reset();
    bool GetIsAlive() ;
	void SetIsAlive(bool isAlive);  
    float GetRadius() { return radius_; };
    void Update ();
	int GetSound() { return sound_; };
    void Draw ()override;
    void Move ()override;
};
