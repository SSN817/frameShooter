#include"main.h"


// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{

	ChangeWindowMode( TRUE ) ;//ポップアップウインドウで表示
	setWindowSize(1000,640);

	if( DxLib_Init() == -1 )	// ＤＸライブラリ初期化処理
	{
		return -1 ;	// エラーが起きたら直ちに終了
	}

	/*
	subjectSet s;

	basicEnemy* eshooter = new basicEnemy(&s);
	s.setObserver(eshooter);

	defaultShooter* shooter = new defaultShooter(&s);
	s.setObserver(shooter);
	*/

	game test;

	SetDrawScreen( DX_SCREEN_BACK ); //描画先を裏画面に設定
	while(ProcessMessage()!=-1)
	{
		
		ClearDrawScreen(); // 画面を消す
		ioUpdate();
		//s.update();
		

		test.run();

		ScreenFlip();//裏画面反映
	}

	WaitKey() ;// キー入力待ち
	DxLib_End() ;// ＤＸライブラリ使用の終了処理
	return 0 ;	// ソフトの終了 
}