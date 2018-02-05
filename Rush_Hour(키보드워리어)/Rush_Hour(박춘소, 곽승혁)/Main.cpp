#include "Control.h"
#include <WIndows.h>
#pragma comment(lib,"winmm.lib")

int main()
{
	system("mode con: cols=80 lines=30");				// 콘솔 이미지 제어
	PlaySound(TEXT("Bgm/BGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP);		//Bgm출력
	Control control;
	control.Run();					//게임 시작
	return 0;
}