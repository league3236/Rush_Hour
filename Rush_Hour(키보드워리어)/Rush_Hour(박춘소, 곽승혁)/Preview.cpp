#include "Preview.h"
#include "consola.h"
#include "Arrow.h"
#include "Bgm.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
//#pragma comment(lib,"Gdiplus.lib")

void Preview::View_StartPage()
{
	int i;
	_setcursortype(_NOCURSOR);
	textbackground(WHITE);
	//첫째줄
	XYPutStr(8, 3, "      ");
	XYPutStr(38, 3, "  ");
	delay(50);

	//둘째줄
	XYPutStr(6, 4, "  ");
	XYPutStr(14, 4, "  ");
	XYPutStr(28, 4, "        ");
	XYPutStr(38, 4, "  ");
	delay(50);

	//셋째줄
	XYPutStr(6, 5, "  ");
	XYPutStr(14, 5, "  ");
	XYPutStr(28, 5, "  ");
	XYPutStr(38, 5, "  ");

	delay(50);

	//넷째줄
	XYPutStr(6, 6, "        ");
	XYPutStr(18, 6, "  ");
	XYPutStr(24, 6,"  ");
	XYPutStr(28, 6, "        ");
	XYPutStr(38, 6, "        ");
	delay(50);

	//다섯째줄
	XYPutStr(6, 7, "  ");
	XYPutStr(14, 7, "  ");
	XYPutStr(18, 7,"  ");
	XYPutStr(24, 7,"  ");
	XYPutStr(34, 7, "  ");
	XYPutStr(38, 7,"  ");
	XYPutStr(44, 7, "  ");
	delay(50);

	//여섯째줄
	XYPutStr(6, 8, "  ");
	XYPutStr(14, 8, "  ");
	XYPutStr(18, 8, "  ");
	XYPutStr(24, 8, "  ");
	XYPutStr(34, 8, "  ");
	XYPutStr(38, 8,"  ");
	XYPutStr(44, 8,"  ");
	delay(50);

	//일곱째줄
	XYPutStr(6, 9, "  ");
	XYPutStr(14, 9, "  ");
	XYPutStr(18, 9,"        ");
	XYPutStr(28, 9,"        ");
	XYPutStr(38, 9,"  ");
	XYPutStr(44, 9,"  ");
	delay(50);

	//아홉번째줄
	XYPutStr(28, 11,"  ");
	delay(50);

	//열번째줄
	XYPutStr(28, 12, "  ");
	delay(50);

	//열한번째줄
	XYPutStr(28, 13,"  ");
	delay(50);

	//열두번째줄
	XYPutStr(28, 14,"        ");
	XYPutStr(38, 14,"        ");
	XYPutStr(48, 14,"  ");
	XYPutStr(54, 14,"  ");
	XYPutStr(58, 14,"  ");
	delay(50);

	//열세번째줄
	XYPutStr(28, 15,"  ");
	XYPutStr(34, 15,"  ");
	XYPutStr(38, 15,"  ");
	XYPutStr(44, 15,"  ");
	XYPutStr(48, 15,"  ");
	XYPutStr(54, 15,"  ");
	XYPutStr(58, 15,"  ");
	XYPutStr(60, 15,"    ");
	delay(50);

	//열네번째줄
	XYPutStr(28, 16,"  ");
	XYPutStr(34, 16,"  ");
	XYPutStr(38, 16,"  ");
	XYPutStr(44, 16,"  ");
	XYPutStr(48, 16,"  ");
	XYPutStr(54, 16,"  ");
	XYPutStr(58, 16,"  ");
	delay(50);

	//열다섯번째줄
	XYPutStr(28, 17,"  ");
	XYPutStr(34, 17,"  ");
	XYPutStr(38, 17,"        ");
	XYPutStr(48, 17,"        ");
	XYPutStr(58, 17, "  ");
	delay(50);

	textbackground(BLACK);
	textcolor(WHITE);
	XYPutStr(20, 21, "Made By Keyboard Warrior");
	textcolor(WHITE);
	XYPutStr(28, 23, "Please press Any Key  ");

	fflush(stdin);
	delay(1000);			//1초 기다렸다가
	_getch();
	system("cls");			//콘솔 화면 지우기

}
void Preview::Basic()
{

	_setcursortype(_NOCURSOR);			//커서 없이 
	textbackground(BLACK); //글자 배경색 지정
	textcolor(WHITE);			//글자색 지정
	textbackground(BLACK);		//글자 배경색 지정
}
void Preview::View_Help()
{
	clrscr();
	View_BG();						//배경 출력			
	textcolor(RED);					//빨간색 텍스트 칼라
	textbackground(WHITE);				//흰색 배경
	XYPutStr(13, 9, "┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	XYPutStr(13, 10, "┃                     <Help>                     ┃");
	XYPutStr(13, 11, "┃                ↑↓←→ : Move                 ┃");
	XYPutStr(13, 12, "┃     1. Press the number you want to choose.    ┃");
	XYPutStr(13, 13, "┃               2. Press the arrow key.	      ┃");
	XYPutStr(13, 14, "┃    3. The goal is to get the red block out     ┃");
	XYPutStr(13, 15, "┃	      of the board buy sliding		      ┃");
	XYPutStr(13, 16, "┃	   the other blocks out of the way.    	      ┃");
	XYPutStr(13, 17, "┃			             		      ┃");
	XYPutStr(13, 18, "┃	          Space: Restart  		      ┃");
	XYPutStr(13, 19, "┗━━━━━━━━━━━━━━━━━━━━━━━━┛");
	_setcursortype(_NOCURSOR);						//커서 없애기
	_getch();
	Basic();
	system("cls");
	textbackground(BLACK);								//배경 지정
	textcolor(WHITE);								//흰색으로 바꾸기
}

void Preview::View_BG()
{
	gotoxy(1, 1);
	View_Image(10);						//까만색화면 출력(전에 출력된 이미지 없애기 위하여)
	textbackground(BLACK);			//배경색 지정
	textcolor(WHITE);				//글자색 지정
	system("cls");				//콘솔지우기
	/*
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚" << endl;
	*/ //버퍼오류..
}
void Preview::View_Loading()
{
	View_BG();							// 배경 화면 출력
	View_Image(11);						// 로딩 화면 출력
	Sleep(3000);						// 3초 대기
}

void Preview::View_NextStage(int _stage)
{
	View_BG();						//배경 출력
	View_Image(_stage+1);				//다음 스테이지 이미지 출력
	Sleep(2000);					//2초 딜레이
}
void Preview::View_SuccessPage(int _stage,int _selectC)					//캐릭터마다 완성 화면 출력
{
	textcolor(WHITE);						//텍스트 컬러 흰색
	View_BG();							//배경 출력
	gotoxy(0, 0);							//0,0으로 이동 (커서 리셋위하여)
	
	switch (_selectC)					// 선택된 캐릭터 마다
	{
	case 1:									
		View_Image(6);						//레드의 완성 페이지
		break;
	case 2:
		View_Image(7);						//블루의 완성 페이지
		break;
	case 3:
		View_Image(8);						//마젠타의 완성 페이지
		break;
	case 4:
		View_Image(9);						//그린의 완성 페이지
		break;
	}
	Sleep(2000);							//2초 딜레이

	_setcursortype(_NOCURSOR);					//커서 없음
}

void Preview::XYPutStr(int a, int b, char *str)				//x,y값에 가서 string출력
{
	gotoxy(a, b);
	cout << str;
}

void Preview::View_SelectPage()										//도움말을 선택할지 바로 시작할지 결정페이지
{
	View_BG();			//배경화면 출력
	XYPutStr(16, 9, "1. Game Start");
	XYPutStr(16, 12, "2. Help");
	_setcursortype(_NOCURSOR);
}

void Preview::View_EXIT()					//나가는 페이지
{
	system("cls");
	textcolor(WHITE);
	textbackground(BLACK);
	XYPutStr(18, 12, "EXIT?");
	XYPutStr(18, 14, "Y/N");
	_setcursortype(_NOCURSOR);
}

void Preview::View_Score(int score)						//스코어에 따른 이미지 보여주기
{
	Bgm Bg;
	textcolor(YELLOW);
	if (score >= 90)
	{
		View_Image(12);
	}
	else if (score<90 && score >= 80)
	{
		View_Image(13);
	}
	else if (score<80 && score >= 70)
	{
		View_Image(14);
	}
	else if (score<70 && score >= 60)
	{
		View_Image(15);
	}
	else if (score<60)
	{
		View_Image(16);
	}
	Bg.Bgm_Sound(2);
	Sleep(5000);
	_getch();
}

void Preview::View_Image(int select)						//이미지 보여주기
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HWND hWnd = FindWindow(TEXT("ConsoleWindowClass"), NULL);
	HBITMAP hImage = NULL, hOldBitmap = NULL;
	HDC hdc = GetDC(hWnd);									
	HDC hMemDC = CreateCompatibleDC(hdc);
	gotoxy(1, 1);
	if (select == 0)
	{
		XYPutStr(15, 5, "Select Car and Press the Space Bar");
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == '1')
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/RED.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}

	else if (select == '2')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/BLUE.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}

	else if (select == '3')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GREEN.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}
	else if (select == '4')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CYAN.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}

	else if (select == '5')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/MAGENTA.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}
	else if (select == '6')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/BROWN.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}

	else if (select == '7')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/RIGHTBLUE.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}
	else if (select == '8')
	{
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/RIGHTGREEN.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 410, 700, 700, hMemDC, 0, 0, SRCCOPY);
		
	}

	else if (select == 1)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 2)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 3)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 4)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 6)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(RED).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 7)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(BLUE).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 8)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(MAGENTA).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 9)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(GREEN).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 10)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(BG).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 0, 0, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 11)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/LOAD.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 0, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 12)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(A).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 13)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(B).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 14)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(C).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 15)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(D).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 16)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(F).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 17)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 18)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 19)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 20)
	{
		// 이미지 로드
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// 이미지 출력 부분
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	// 각종 메모리 해제 
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd, hdc);

	//system("pause");
	
}

void Preview::View_SelectC(int _x, int _y)					//캐릭터 선택화면 출력
{
	if (_x == 58 && _y == 10)
		View_Image(18);
	else if (_x == 58 && _y == 17)
		View_Image(20);
	else if (_x == 8 && _y == 10)
		View_Image(17);
	else if (_x == 8 && _y == 17)
		View_Image(19);
}

void Preview::View_ImageTold(int block_N)			//선택된 케릭터 말하기
{
	textcolor(WHITE);
	if (block_N >= '1' && block_N <= '9')
	{
		switch (block_N)								//key에 따라 블록의 색깔을 뿌려줌
		{
		case '1':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 내이름은 맥퀸  ┃");
			XYPutStr(40, 22, "┃세계의 유명인사 ┃");
			XYPutStr(40, 23, "┃나를모르는다니  ┃");
			XYPutStr(40, 24, "┃간첩은 아니겠지?┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '2':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 나는 최고의    ┃");
			XYPutStr(40, 22, "┃      비밀요원  ┃");
			XYPutStr(40, 23, "┃   거기 너!!!   ┃");
			XYPutStr(40, 24, "┃내 비밀을 지켜라┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '3':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 다 비켜라!!    ┃");
			XYPutStr(40, 22, "┃   내가가는길을 ┃");
			XYPutStr(40, 23, "┃ 막을자는 없다  ┃");
			XYPutStr(40, 24, "┃  우하하하하하  ┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '4':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 내 미모를      ┃");
			XYPutStr(40, 22, "┃   닮고싶다고?? ┃");
			XYPutStr(40, 23, "┃ 고맙지만       ┃");
			XYPutStr(40, 24, "┃너도 충분히이뻐 ┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '5':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 하..정말로     ┃");
			XYPutStr(40, 22, "┃ 비밀요원도     ┃");
			XYPutStr(40, 23, "┃ 모해먹겠군     ┃");
			XYPutStr(40, 24, "┃ 일탈하고 싶다  ┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '6':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 나를 가진다고? ┃");
			XYPutStr(40, 22, "┃ 흠... 노력좀   ┃");
			XYPutStr(40, 23, "┃ 해야될거야     ┃");
			XYPutStr(40, 24, "┃ 엄청 비싸거든  ┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '7':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 우리는 새로운  ┃");
			XYPutStr(40, 22, "┃ 미션이 필요해  ┃");
			XYPutStr(40, 23, "┃ 엄청 굶주린    ┃");
			XYPutStr(40, 24, "┃  야생마라고!!  ┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		case '8':
			XYPutStr(40, 20, "┏━━━━━━━━┓");
			XYPutStr(40, 21, "┃ 나만 큼 빠른애 ┃");
			XYPutStr(40, 22, "┃ 있으면 나와봐  ┃");
			XYPutStr(40, 23, "┃ 없다면 다들    ┃");
			XYPutStr(40, 24, "┃ 집에서 발씻구자┃");
			XYPutStr(40, 25, "┗━━━━━━━━┛");
			break;
		}
	}
}

void Preview::View_ImageBlock(int block_N)				//선택된 블록들의 캐릭터 보여줌
{
	gotoxy(0, 0);
		switch (block_N)								//key에 따라 블록의 색깔을 뿌려줌
		{
		case '1':
			View_Image(block_N);
			break;
		case '2':
			View_Image(block_N);
			break;
		case '3':
			View_Image(block_N);
			break;
		case '4':
			View_Image(block_N);
			break;
		case '5':
			View_Image(block_N);
			break;
		case '6':
			View_Image(block_N);
			break;
		case '7':
			View_Image(block_N);
			break;
		case '8':
			View_Image(block_N);
			break;
		}
}
