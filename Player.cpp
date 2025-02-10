#include "Player.h"

/// <summary>
/// playerのコンストラクタ
/// </summary>
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
/// <summary>
/// playerのデストラクタ
/// </summary>
Player::~Player() { 
	pos_ = {kStageWidth / 2.0f, kStageHeight / 2.0f + 256.0f};

	for (int i = 0; i < bulltNum_; i++) {
		delete bullet_[i];
	}
	
}
/// <summary>
/// playerのリセット
/// </summary>
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
/// <summary>
/// playerの更新
/// </summary>
/// <param name="keys"></param>
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


/// <summary>
/// playerの描画
/// </summary>
void Player::Draw() {

	for (int i = 0; i < bulltNum_; i++){
		bullet_[i]->Draw();
	}
	if (!ishit_){
		
			Novice::DrawSprite(
					static_cast<int>(pos_.x - size_.x / 2.0f),
					static_cast<int>(pos_.y - size_.y/ 2.0f),
					GraphHandle_, 1.0f, 1.0f,
					0.0f, WHITE);
	} else {
		if (static_cast<int>(hitCoolTime_) % 2 == 0) {
			
			Novice::DrawSprite(
				static_cast<int>(pos_.x - size_.x / 2.0f),
				static_cast<int>(pos_.y - size_.y/ 2.0f),
			GraphHandle_, 1.0f, 1.0f,
			0.0f, WHITE);
		}
	}
	
	
}
/// <summary>
/// playerの移動
/// </summary>
void Player::Move() {
	pos_.y +=Normarize(velocity_).y *speed_.y;
	pos_.x +=Normarize(velocity_).x * speed_.x;
}
/// <summary>
/// lifeのセッター
/// </summary>
/// <param name="life"></param>
void Player::SetLife(int life) { islife_ = life; };
/// <summary>
/// ishitのセッター
/// </summary>
/// <param name="ishit"></param>
void Player::SetIsHit(bool ishit) { ishit_ = ishit; };
/// <summary>/// 
/// hitCoolTimeのセッター
/// </summary>
/// /// <param name="hitCoolTime"></param>
void Player::SetHitCoolTime(int hitCoolTime) { hitCoolTime_ = hitCoolTime; };