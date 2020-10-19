#include	"./Shooting.h"

static Stage stage = STAGE_GAME;

bool	Init( );
void	Render( );

int	WINAPI WinMain( HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow )
{
	if ( !Init( ) ) {
		return 0;
	}

	while ( !CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		long deltaTime = GetNowCount( );
		ClearDrawScreen( );
		switch ( stage ) {
			case	STAGE_OPENING:		//	オープニング
				break;
			case	STAGE_GAME:			//	プレイ
				stage = Game( );
				break;
			case	STAGE_GAMEOVER:		//	ゲームオーバー
				break;
			case	STAGE_GAMECLEAR:	//	ゲームクリア
				break;
		}
		ScreenFlip( );
		//
		if ( ProcessMessage( ) == -1 ) {
			break;
		}
		deltaTime = GetNowCount( ) - deltaTime;
		if ( deltaTime < FRAME_TIME ) {
			Sleep( FRAME_TIME - deltaTime );
		}
	}
	DxLib_End( );
	return 1;
}

bool	Init( )
{
	if ( DxLib_Init( ) == -1 ) {
		return false;
	}
	ChangeWindowMode( TRUE );
	SetDrawScreen( DX_SCREEN_BACK );
	//	Playerの初期化
	if ( !InitGame( ) ) {
		return false;
	}
	//
	InitGame( );
	//
	return true;
}


