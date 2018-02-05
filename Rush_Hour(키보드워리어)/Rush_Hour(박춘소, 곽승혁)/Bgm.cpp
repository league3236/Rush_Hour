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
		mciOpen.lpstrElementName = "Bgm/SELECT.wav"; // ���� ��� �Է�
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // �ݺ� ����
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(250);				//0.1�� ��ٷȴٰ� ����ϱ� ���Ͽ�
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // ���
		break;
	case 2:
		mciOpen.lpstrElementName = "Bgm/NEXT.wav"; // ���� ��� �Է�
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // �ݺ� ����
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(1500);				//0.5�� ��ٷȴٰ� ����ϱ� ���Ͽ�
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // ���
		break;
	case 3:
		mciOpen.lpstrElementName = "Bgm/BLOCK.wav"; // ���� ��� �Է�
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // �ݺ� ����
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(600);				//0.5�� ��ٷȴٰ� ����ϱ� ���Ͽ�
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // ���
		break;
	case 4:
		mciOpen.lpstrElementName = "Bgm/BLOCK2.wav"; // ���� ��� �Է�
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // �ݺ� ����
			(DWORD)(LPVOID)&m_mciPlayParms);
		Sleep(1000);				//0.5�� ��ٷȴٰ� ����ϱ� ���Ͽ�
		mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);    // ���
		break;


	}
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	
	

	/*mciSendCommandW(dwID, MCI_RESUME, 0, NULL);       // ��ȯ

	/* mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);        */// stop

}