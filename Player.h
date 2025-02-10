#pragma once

#include"Obj.h"
#include"Bullet.h"

const int bulltNum_=30;

class Player:public Obj {
private:
    int shotCoolTime_;
    int scoer_;
    int lifeGraphHandle_;
    int hitCoolTime_;
    int islife_;
    Bullet* bullet_[bulltNum_];
    int GraphHandle_;
public:

    Player();
    ~Player();
    void reset();
    void Update (const char* keys); 
    void Draw ()override;
    void Move ()override;
    /// <summary>
	/// set scoer
    /// </summary>
    /// <param name="scoer"></param>
    void SetScoer(int scoer) { scoer_ = scoer; };

/// <summary>   
    
	void SetLife(int life) ;
	void SetIsHit(bool ishit) ;
	void SetHitCoolTime(int hitCoolTime) ;
   
    int GetLife() { return islife_; };
    int GetScoer() { return scoer_; };
    Bullet* GetBullets(int i) { return bullet_[i]; };
    bool GetIsHit() { return ishit_; };
	int GetHitCoolTime() { return hitCoolTime_; };
	float GetRadius() { return radius_; };
};
