#include "Control.h"
#include <WIndows.h>
#pragma comment(lib,"winmm.lib")

int main()
{
	system("mode con: cols=80 lines=30");				// �ܼ� �̹��� ����
	PlaySound(TEXT("Bgm/BGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP);		//Bgm���
	Control control;
	control.Run();					//���� ����
	return 0;
}