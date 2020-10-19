#pragma once

typedef enum {
	STAGE_INIT,			//	初期化
	STAGE_OPENING,		//	オープニング
	STAGE_GAME,			//	プレイ
	STAGE_GAMEOVER,		//	ゲームオーバー
	STAGE_GAMECLEAR,	//	ゲームクリア
} Stage;
