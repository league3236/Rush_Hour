#include<stdio.h>
#include<Windows.h>
#include "Bgm.h"

#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

int dwID;

void Bgm::Bgm_Sound(int x)
{
	switch (x)
	{
	case 1:
		mciOpen.lpstrElementName = "Bgm/SELECT.wav"; // 파일 경로 입력
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // 반복 시작
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(250);				//0.1초 기다렸다가 취소하기 위하여
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // 취소
		break;
	case 2:
		mciOpen.lpstrElementName = "Bgm/NEXT.wav"; // 파일 경로 입력
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // 반복 시작
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(1500);				//0.5초 기다렸다가 취소하기 위하여
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // 취소
		break;
	case 3:
		mciOpen.lpstrElementName = "Bgm/BLOCK.wav"; // 파일 경로 입력
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // 반복 시작
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(600);				//0.5초 기다렸다가 취소하기 위하여
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // 취소
		break;
	case 4:
		mciOpen.lpstrElementName = "Bgm/BLOCK2.wav"; // 파일 경로 입력
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // 반복 시작
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(1000);				//0.5초 기다렸다가 취소하기 위하여
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // 취소
		break;


	}
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	
	

	/*mciSendCommandW(dwID, MCI_RESUME, 0, NULL);       // 반환

	/* mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);        */// stop

}