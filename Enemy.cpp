#include "Enemy.h"

Enemy::Enemy() {

	pos_ = {static_cast<float>(rand() % 300 + 200),-static_cast<float>(rand() % 20 + 30) };
	size_ = {32.0f, 32.0f};
	speed_ = {0.0f, 4.0f};
	radius_ = 16.0f;
	isAlive_ = true;
	respawnTimer_ = 120;
	GraphHandle_ =Novice::LoadTexture("./Resources/images/enemy.png");
	sound_ = Novice::LoadAudio("./Resources/Sounds/maou_se_battle18.wav");
	playHandle_ = -1;
	hitCoolTime_ = 0;
	
	bombGraphHandle_[0] = Novice::LoadTexture("./Resources/images/BomEfect/bmef1.png");
	bombGraphHandle_[1] = Novice::LoadTexture("./Resources/images/BomEfect/bmef2.png");
	bombGraphHandle_[2] = Novice::LoadTexture("./Resources/images/BomEfect/bmef3.png");
	bombGraphHandle_[3] = Novice::LoadTexture("./Resources/images/BomEfect/bmef4.png");
	bombGraphHandle_[4] = Novice::LoadTexture("./Resources/images/BomEfect/bmef5.png");
	bombGraphHandle_[5] = Novice::LoadTexture("./Resources/images/BomEfect/bmef6.png");
	bombGraphHandle_[6] = Novice::LoadTexture("./Resources/images/BomEfect/bmef7.png");
	bombGraphHandle_[7] = Novice::LoadTexture("./Resources/images/BomEfect/bmef8.png");
	bombGraphHandle_[8] = Novice::LoadTexture("./Resources/images/BomEfect/bmef9.png");
	


}
void Enemy::reset() {
	pos_ = {static_cast<float>(rand() % 300 + 200), -static_cast<float>(rand() % 20 + 30)};
	isAlive_ = true;
	respawnTimer_ = 120;
}

bool Enemy::GetIsAlive() { return isAlive_; }

void Enemy::Update( ) {
	if (isAlive_) {
					

		velocity_ = speed_;
		Move();

		if (pos_.y > kStageHeight+64){
			isAlive_ = false;
		}
	}else {
		if (respawnTimer_ > 0) {
			respawnTimer_--;
		} else {
			respawnTimer_ = 120;
			isAlive_ = true;
			Novice::StopAudio(playHandle_);
			pos_ = {static_cast<float> (rand() % 300 + 200),0};
		}
	}

	/*if (isAlive_) {
		GraphHandle_=enemyGraphHandle_;
	} else {
		if (respawnTimer_ >= 90) {

			
			
			GraphHandle_ = bombGraphHandle_[8 - (respawnTimer_ / 15)];
		}
	}*/
		
	
	
}





void Enemy::Draw() {
	if (isAlive_) {
	/*	Novice::DrawBox(
		    static_cast<int>(pos_.x - size_.x / 2.0f),
			static_cast<int>(pos_.y - size_.y / 2.0f), 
			static_cast<int>( size_.x ), 
			static_cast<int>( size_.y ),
			0.0f, 0xFF0000FF,
		    kFillModeSolid);*/

		Novice::DrawSprite(static_cast<int>(pos_.x - size_.x / 2.0f),
							static_cast<int>(pos_.y - size_.y / 2.0f),
							GraphHandle_,
							1.0f,
							1.0f,
							0.0f,
							0xFFFFFFFF
							);
	} else {
		if (respawnTimer_ >= 90) {
			/*Novice::DrawBox(
			    static_cast<int>(pos_.x - size_.x / 2.0f),
				static_cast<int>(pos_.y - size_.y / 2.0f),
				static_cast<int>(size_.x ),
				static_cast<int>(size_.y ),
				0.0f,
			    0x00FF00FF, kFillModeSolid);*/

			Novice::DrawSprite(
			static_cast<int>(pos_.x - size_.x / 2.0f),
			static_cast<int>(pos_.y - size_.y / 2.0f),
			bombGraphHandle_[8 - (respawnTimer_ / 15)],
			1.5f, 1.5f, 0.0f, 0xFFFFFFFF);
		}
	}
}

void Enemy::Move() {
	pos_.y +=Normarize(velocity_).y *speed_.y;
	pos_.x +=Normarize(velocity_).x * speed_.x;
}
void Enemy::SetIsAlive(bool isAlive) { isAlive_ = isAlive; };


