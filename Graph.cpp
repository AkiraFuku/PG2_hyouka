#include "Graph.h"

// グローバル変数の宣言
int playerGraphHandle;
int enemyGraphHandle;
int bulletGraphHandle;
int backGroundGraphHandle;
int titleGraphHandle;
int endGraphHandle;
int numberGraphs[10];
int bomEfectGraph[10];
int lifeGraphHandle;
int daikonGraphHandle;
int akaDaikonGraphHandle;

void LoadTextures() {
    // テクスチャのロード
    playerGraphHandle = Novice::LoadTexture("./Resources/images/player.png");
    enemyGraphHandle = Novice::LoadTexture("./Resources/images/enemy.png");
    bulletGraphHandle = Novice::LoadTexture("./Resources/images/daikon.png");
    backGroundGraphHandle = Novice::LoadTexture("./Resources/images/background.png");
    titleGraphHandle = Novice::LoadTexture("./Resources/images/title.png");
    endGraphHandle = Novice::LoadTexture("./Resources/images/end.png");
    numberGraphs[0] = Novice::LoadTexture("./Resources/images/nungrph/0.png");
    numberGraphs[1] = Novice::LoadTexture("./Resources/images/nungrph/1.png");
    numberGraphs[2] = Novice::LoadTexture("./Resources/images/nungrph/2.png");
    numberGraphs[3] = Novice::LoadTexture("./Resources/images/nungrph/3.png");
    numberGraphs[4] = Novice::LoadTexture("./Resources/images/nungrph/4.png");
    numberGraphs[5] = Novice::LoadTexture("./Resources/images/nungrph/5.png");
    numberGraphs[6] = Novice::LoadTexture("./Resources/images/nungrph/6.png");
    numberGraphs[7] = Novice::LoadTexture("./Resources/images/nungrph/7.png");
    numberGraphs[8] = Novice::LoadTexture("./Resources/images/nungrph/8.png");
    numberGraphs[9] = Novice::LoadTexture("./Resources/images/nungrph/9.png");
    bomEfectGraph[0] = Novice::LoadTexture("./Resources/images/bomEfect/0.png");
    bomEfectGraph[1] = Novice::LoadTexture("./Resources/images/bomEfect/1.png");
    bomEfectGraph[2] = Novice::LoadTexture("./Resources/images/bomEfect/2.png");
    bomEfectGraph[3] = Novice::LoadTexture("./Resources/images/bomEfect/3.png");
    bomEfectGraph[4] = Novice::LoadTexture("./Resources/images/bomEfect/4.png");
    bomEfectGraph[5] = Novice::LoadTexture("./Resources/images/bomEfect/5.png");
    bomEfectGraph[6] = Novice::LoadTexture("./Resources/images/bomEfect/6.png");
    bomEfectGraph[7] = Novice::LoadTexture("./Resources/images/bomEfect/7.png");
    bomEfectGraph[8] = Novice::LoadTexture("./Resources/images/bomEfect/8.png");
    bomEfectGraph[9] = Novice::LoadTexture("./Resources/images/bomEfect/9.png");
    lifeGraphHandle = Novice::LoadTexture("./Resources/images/lifedaikon.png");
    daikonGraphHandle = Novice::LoadTexture("./Resources/images/daikon.png");
    akaDaikonGraphHandle = Novice::LoadTexture("./Resources/images/akadaikon.png");
}

// メイン関数または適切な場所でLoadTextures関数を呼び出す
// LoadTextures();