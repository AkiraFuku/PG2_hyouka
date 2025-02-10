#include "Player.h"


Player::Player() { 
	pos_ = {kStageWidth / 2.0f, kStageHeight / 2.0f + 256.0f};
	size_ = {32.0f, 32.0f};
	speed_ = {8.0f, 8.0f};
	shotCoolTime_ = 10;
	hitCoolTime_ = 0;
	velocity_ = {0.0f, 0.0f};
	ishit_ = false;
	islife_ = 5;
	scoer_ = 0;
	GraphHandle_ = Novice::LoadTexture("./Resources/images/player.png");
	for (int i = 0; i < bulltNum_; i++) {
		bullet_[i] = new Bullet();
	}

	lifeGraphHandle_=0;

}

Player::~Player() { 
	pos_ = {kStageWidth / 2.0f, kStageHeight / 2.0f + 256.0f};

	for (int i = 0; i < bulltNum_; i++) {
		delete bullet_[i];
	}
	
}

void Player::reset() {
	pos_ = {kStageWidth / 2.0f, kStageHeight / 2.0f + 256.0f};
	shotCoolTime_ = 10;
	hitCoolTime_ = 0;
	velocity_ = {0.0f, 0.0f};
	ishit_ = false;
	islife_ = 5;
	scoer_ = 0;
	for (int i = 0; i < bulltNum_; i++) {
		bullet_[i]->reset();
	}
}

void Player::Update(const char* keys) {
	if (keys==nullptr) {
		return;
	}
	///プレイヤーの移動///
	velocity_={0.0f,0.0f};
	if (keys[DIK_W]) {
		if (pos_.y > 50 - size_.y / 2.0f){
			velocity_.y = -speed_.y;
		}
	}

	if (keys[DIK_S]) {
		if (pos_.y < kStageHeight){
			velocity_.y =speed_.y;
		}
	}

	if (keys[DIK_A]) {
		if (pos_.x >  size_.x/ 2.0f){
			velocity_.x = -speed_.x;
		}
	}

	if (keys[DIK_D]) {
		if (pos_.x < kStageWidth - size_.x / 2.0f){
			velocity_.x = speed_.x;
		}
	}
	Move();
	//プレイヤーの無敵時価
	if (ishit_){
		if (hitCoolTime_ > 0){
			hitCoolTime_--;
		} else{
			ishit_ = false;
		}


	}
			///
	if (keys[DIK_SPACE]){
		if (shotCoolTime_ > 0) {
			shotCoolTime_--;
		} else {
			shotCoolTime_ = 10;
		}
		if (shotCoolTime_ <= 0){
			for (int i = 0; i < bulltNum_; i++){
				if (!bullet_[i]->isShot_) {
					bullet_[i]->isShot_ = true;
					bullet_[i]->SetPos(pos_);
					break;
				}
			}
		}

	}
	for (int i = 0; i < bulltNum_; i++) {
		bullet_[i]->Update();
	 }
}



void Player::Draw() {

	for (int i = 0; i < bulltNum_; i++){
		bullet_[i]->Draw();
	}
	
	//if (ishit_) {
		if (!ishit_){
			/*Novice::DrawBox(
			    static_cast<int>(pos_.x - size_.x / 2.0f), 
				static_cast<int>(pos_.y - size_.y / 2.0f),
				static_cast<int>(pos_.x + size_.x / 2.0f),
				static_cast<int>(pos_.y + size_.y / 2.0f),
				0.0f,
				0xFF0000FF, kFillModeSolid);*/
			Novice::DrawSprite(
					static_cast<int>(pos_.x - size_.x / 2.0f),
					static_cast<int>(pos_.y - size_.y/ 2.0f),
					GraphHandle_, 1.0f, 1.0f,
					0.0f, WHITE);
		} else {
			if (static_cast<int>(hitCoolTime_) % 2 == 0) {
				/*Novice::DrawBox(
			    static_cast<int>(pos_.x - size_.x / 2.0f), 
				static_cast<int>(pos_.y - size_.y / 2.0f),
				static_cast<int>(pos_.x + size_.x / 2.0f),
				static_cast<int>(pos_.y + size_.y / 2.0f),
				0.0f,
				0x00FF00FF, kFillModeSolid);*/
				Novice::DrawSprite(
					static_cast<int>(pos_.x - size_.x / 2.0f),
					static_cast<int>(pos_.y - size_.y/ 2.0f),
				GraphHandle_, 1.0f, 1.0f,
				0.0f, WHITE);
			}
		}
	//}
	
}

void Player::Move() {
	pos_.y +=Normarize(velocity_).y *speed_.y;
	pos_.x +=Normarize(velocity_).x * speed_.x;
}
void Player::SetLife(int life) { islife_ = life; };
void Player::SetIsHit(bool ishit) { ishit_ = ishit; };
void Player::SetHitCoolTime(int hitCoolTime) { hitCoolTime_ = hitCoolTime; };