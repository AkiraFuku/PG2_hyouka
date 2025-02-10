#include "Scene.h"
#include "Enemy.h"
/// <summary>
/// シーンのコンストラクタ
/// </summary>
Scene::Scene() {
	player_ = new Player();
	for (int i = 0; i < 10; i++) {
		enemy_[i] = new Enemy();
	}
	uiGlaph_ = Novice::LoadTexture("./Resources/images/reseet.png");
	titleGlaph_ = Novice::LoadTexture("./Resources/images/RRtitle.png");
	endGraph_ = Novice::LoadTexture("./Resources/images/end.png");
	akaDaikonn_ = Novice::LoadTexture("./Resources/images/lifedaikonn.png");
	
    numberGraphs_[0] = Novice::LoadTexture("./Resources/images/nungrph/0.png");
    numberGraphs_[1] = Novice::LoadTexture("./Resources/images/nungrph/1.png");
    numberGraphs_[2] = Novice::LoadTexture("./Resources/images/nungrph/2.png");
    numberGraphs_[3] = Novice::LoadTexture("./Resources/images/nungrph/3.png");
    numberGraphs_[4] = Novice::LoadTexture("./Resources/images/nungrph/4.png");
    numberGraphs_[5] = Novice::LoadTexture("./Resources/images/nungrph/5.png");
    numberGraphs_[6] = Novice::LoadTexture("./Resources/images/nungrph/6.png");
    numberGraphs_[7] = Novice::LoadTexture("./Resources/images/nungrph/7.png");
    numberGraphs_[8] = Novice::LoadTexture("./Resources/images/nungrph/8.png");
    numberGraphs_[9] = Novice::LoadTexture("./Resources/images/nungrph/9.png");

	
	//	
	
	
	for (int i = 0; i < 2; i++) {
		backGround_[i].graphHandle = Novice::LoadTexture("./Resources/images/backgraund.png"); 
	}
	
	scene_ = TITLE;
	BgHandle_ = Novice::LoadAudio("./Resources/Sounds/dotabatare-su.mp3");
	playHandle_ = -1;
	hieScoer_ = 0;
	timer_ = 60;
	frameCount_ = 0;
	
	
}

/// <summary>
/// シーンのデストラクタ
/// </summary>
Scene::~Scene() { 
	delete player_;
	for (int i = 0; i < 10; i++) {
		delete enemy_[i];
	}
	
}
/// <summary>
/// numberDraw
/// </summary>
/// <param name="pos">ポジション </param>
/// <param name="width">幅</param>
/// <param name="i">リスト番号</param>
void Scene::numberDraw(Vector2 pos,int width,int i ) {
	int digit=static_cast<int>( numberArray_[i].size());
	for (int j = 0; j < digit; j++) {
		Novice::DrawSprite(
			static_cast<int>(pos.x)+j*width,static_cast<int>(pos.y), numberGraphs_[numberArray_[i][j]], 1.0f, 1.0f, 0.0f, WHITE
		);
	}
	
};




/// <summary>
/// key入力によるシーンの更新
/// </summary>
/// <param name="keys"></param>
/// <param name="preKeys"></param>
void Scene::Update(const char* keys, const char* preKeys) {
	switch (scene_){
		case TITLE:
			
			timer_ = 60;
			frameCount_ = 0;

			backGround_[0].pos.x = 0.0f;
			backGround_[0].pos.y = 0.0f;
			backGround_[1].pos.x = 0.0f;
			backGround_[1].pos.y = -720.0f;
		   player_->reset();
			
			
			for (int i = 0; i < 10; i++) {
			     enemy_[i] ->reset();
			}
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]){
				scene_ = GAME;
			}
			break;
		case GAME:
			if (!Novice::IsPlayingAudio(playHandle_))
			{
				playHandle_ = Novice::PlayAudio(BgHandle_, true, 0.5f);
			}
			if (player_->GetLife() <= 0||timer_<=0)
			{
				Novice::StopAudio(playHandle_);
				scene_ = GAMEOVER;
			}
			frameCount_++;
			if (frameCount_ >= 60){
				frameCount_= 0;
				timer_--;
			}
			///プレイヤーの移動///
			player_->Update(keys);
			
			
			//================================================================
			// 敵の更新処理
			//================================================================

			for (int i = 0; i < 10; i++) {
			    enemy_[i]->Update();
			}

			//================================================================
			// 当たり判定
			//================================================================

			for (int i = 0; i < 10; i++) {
			    
				
				if (enemy_[i]->GetIsAlive()) {
					//弾丸//
					for (int j = 0; j < bulltNum_; j++) {
						if (player_->GetBullets(j)->isShot_) {
							if (enemy_[i]->GetRadius() + player_->GetBullets(j)->GetRadius() >=
								Lengeth(enemy_[i]->GetPos(), player_->GetBullets(j)->GetPos())) {
								enemy_[i]->SetIsAlive(false)  ;
								player_->GetBullets(j)->isShot_ = false;
								player_->SetScoer( player_->GetScoer() + 100);
								if (!Novice::IsPlayingAudio(playHandle_)){
									playHandle_ = Novice::PlayAudio(enemy_[i]->GetSound(), false, 0.5f);
								}
							}
						}
					}
			
					
				}
             
			    
			}



			//プレイヤーの当たり判定
			for (int i = 0; i < 10; i++) {
			   if (player_->GetHitCoolTime() <= 0){
					if (enemy_[i]->GetIsAlive()) {
						if (player_->GetLife() > 0) {
							if (!player_->GetIsHit()) {
								if (player_->GetRadius() + enemy_[i]->GetRadius() >= 
									Lengeth(player_->GetPos() , enemy_[i]->GetPos())) {			
									player_->SetIsHit(true) ;
									player_->SetLife(player_->GetLife()-1);
									player_->SetHitCoolTime(180);	
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < 2; i++){
				
				backGround_[i].pos.y += 5.0f;
				
				if (backGround_[i].pos.y == kStageHeight)
				{
					backGround_[i].pos.y = -kStageHeight;
				}
			}
		
			
				
			
			break;
		case GAMEOVER:
			if ( player_->GetScoer() > hieScoer_){
				hieScoer_ = player_->GetScoer();
			}
			numberArray_[0]=NumberArray(hieScoer_);
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]){
				scene_ = TITLE;
			}
		
		
		break;

	}
	numberArray_[1]=NumberArray(timer_);
	numberArray_[2]=NumberArray(player_->GetScoer());
}
/// <summary>
/// sceneの描画
/// </summary>
void Scene::Draw() {

	switch (scene_){
		case TITLE:

			Novice::DrawSprite(0, 0, titleGlaph_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			break;
		case GAME:
			//背景///
			for (int i = 0; i < 2; i++){
				
				Novice::DrawSprite(
					static_cast<int>(backGround_[i].pos.x),
					static_cast<int>(backGround_[i].pos.y),
					backGround_[i].graphHandle,
					1.0f,
					1.0f,
					0.0f,
					0xFFFFFFFF
				);
			}

			//================================================================
			// 敵の描画処理
			//================================================================
			for (int i = 0; i < 10; i++) {
			    enemy_[i]->Draw();
			}

		
			
			///プレイヤー描画///
			player_->Draw();
			
			//UI
			Novice::DrawSprite(kStageWidth, 0, uiGlaph_, 1.0f, 1.0f, 0.0f, WHITE);
		
			numberDraw({890.0f  , 350.0f},40, 2);
		
			numberDraw({890.0f  , 250.0f},40, 1);
			for (int i = 0; i < player_->GetLife(); i++){
				Novice::DrawSprite(i * 40 + 900, 400, akaDaikonn_,
								   1.0f,
								   1.0f,
								   0.0f,
								   0xFFFFFFFF
				);
			}
			break;
		case GAMEOVER:
			Novice::DrawSprite(0, 0, endGraph_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			 numberDraw({300.0f  , 500.0f},40, 2);
			 numberDraw({300.0f  , 300.0f},40, 0);
			
			break;
	}
}
