#include <Novice.h>
#include<time.h>
#include<Scene.h>



const char kWindowTitle[] = "GC1B_12_フク＿アキラ＿タイトル";
 

	


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

			// ライブラリの初期化
		Novice::Initialize(kWindowTitle, 1280, 720);

			// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	///変数
	srand(unsigned int(time(nullptr)));
	
	
	Scene* scene=new Scene;

	//int whi=Novice::LoadTexture("./NoviceResources/white1x1.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		/// 

		scene->Update(keys, preKeys);
		///
		/// ↑更新処理ここまで
		///
		
		///
		/// ↓描画処理ここから
		///
		scene->Draw();
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	delete scene;
		// ライブラリの終了
		Novice::Finalize();
		return 0;
	}


