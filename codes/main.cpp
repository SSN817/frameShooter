#include"main.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{

	ChangeWindowMode( TRUE ) ;//�|�b�v�A�b�v�E�C���h�E�ŕ\��
	setWindowSize(1000,640);

	if( DxLib_Init() == -1 )	// �c�w���C�u��������������
	{
		return -1 ;	// �G���[���N�����璼���ɏI��
	}

	/*
	subjectSet s;

	basicEnemy* eshooter = new basicEnemy(&s);
	s.setObserver(eshooter);

	defaultShooter* shooter = new defaultShooter(&s);
	s.setObserver(shooter);
	*/

	game test;

	SetDrawScreen( DX_SCREEN_BACK ); //�`���𗠉�ʂɐݒ�
	while(ProcessMessage()!=-1)
	{
		
		ClearDrawScreen(); // ��ʂ�����
		ioUpdate();
		//s.update();
		

		test.run();

		ScreenFlip();//����ʔ��f
	}

	WaitKey() ;// �L�[���͑҂�
	DxLib_End() ;// �c�w���C�u�����g�p�̏I������
	return 0 ;	// �\�t�g�̏I�� 
}