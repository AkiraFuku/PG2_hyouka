#include "Bullet.h"
/// <summary>
/// bulletのコンストラクタ
/// </summary>
Bullet::Bullet() { 
	Bullet::isShot_ = false;
	pos_ = {-1000.0f, -1000.0f};
	size_ = {8.0f, 16.0f};
	speed_ = {0.0f, 8.0f};
	radius_ = 8.0f;
	GraphHandle_ = Novice::LoadTexture("./Resources/images/daikonn.png");

}
/// <summary>
/// bulletのデストラクタ
/// </summary>
Bullet::~Bullet() {

}
/// <summary>
/// bulletのアップデート
/// </summary>
void Bullet::Update() {
	if (isShot_) {
		///上方向に進ませる///
		velocity_ = speed_;
		Move();
		///画面外に出たら発射フラグをFalseに変更する///
		if (pos_.y <= 0 - size_.y / 2.0f) {
			isShot_ = false;
		}
	}		
}
/// <summary>
/// bulletの描画
/// </summary>
void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawTriangle(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y - size_.y / 2.0f),
			static_cast<int>(pos_.x - size_.x / 2.0f),
			static_cast<int>(pos_.y + size_.y / 2.0f),
			static_cast<int>(pos_.x + size_.x / 2.0f),
			static_cast<int>(pos_.y + size_.y / 2.0f),
			0xFFFFFFFF, kFillModeSolid);
				
		Novice::DrawSprite(
			static_cast<int>(pos_.x - size_.x ),
			static_cast<int>(pos_.y - size_.y / 2.0f),
			GraphHandle_, 1.0f, 1.0f, 0.0f, WHITE
			);

	}
}
/// <summary>
/// bulletのリセット
/// </summary>
void Bullet::reset() {
	pos_ = {-1000.0f, -1000.0f};
	isShot_ = false;

}
/// <summary>
/// bulletの移動
/// </summary>
void Bullet::Move() {
	pos_.y -=Normarize(velocity_).y *speed_.y;
	pos_.x -=Normarize(velocity_).x * speed_.x;
}
