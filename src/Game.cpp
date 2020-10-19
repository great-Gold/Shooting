#include "./Shooting.h"

Stage Game( )
{
	RenderGame( );
	return STAGE_GAME;
}

bool	InitGame( )
{
	return true;
}
void 	RenderGame( )
{
	DrawBox( 100, 100, 150, 200, GetColor( 255, 255, 0 ), TRUE );
}