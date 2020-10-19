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
			case	STAGE_OPENING:		//	�I�[�v�j���O
				break;
			case	STAGE_GAME:			//	�v���C
				stage = Game( );
				break;
			case	STAGE_GAMEOVER:		//	�Q�[���I�[�o�[
				break;
			case	STAGE_GAMECLEAR:	//	�Q�[���N���A
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
	//	Player�̏�����
	if ( !InitGame( ) ) {
		return false;
	}
	//
	InitGame( );
	//
	return true;
}


