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
	//ù°��
	XYPutStr(8, 3, "      ");
	XYPutStr(38, 3, "  ");
	delay(50);

	//��°��
	XYPutStr(6, 4, "  ");
	XYPutStr(14, 4, "  ");
	XYPutStr(28, 4, "        ");
	XYPutStr(38, 4, "  ");
	delay(50);

	//��°��
	XYPutStr(6, 5, "  ");
	XYPutStr(14, 5, "  ");
	XYPutStr(28, 5, "  ");
	XYPutStr(38, 5, "  ");

	delay(50);

	//��°��
	XYPutStr(6, 6, "        ");
	XYPutStr(18, 6, "  ");
	XYPutStr(24, 6,"  ");
	XYPutStr(28, 6, "        ");
	XYPutStr(38, 6, "        ");
	delay(50);

	//�ټ�°��
	XYPutStr(6, 7, "  ");
	XYPutStr(14, 7, "  ");
	XYPutStr(18, 7,"  ");
	XYPutStr(24, 7,"  ");
	XYPutStr(34, 7, "  ");
	XYPutStr(38, 7,"  ");
	XYPutStr(44, 7, "  ");
	delay(50);

	//����°��
	XYPutStr(6, 8, "  ");
	XYPutStr(14, 8, "  ");
	XYPutStr(18, 8, "  ");
	XYPutStr(24, 8, "  ");
	XYPutStr(34, 8, "  ");
	XYPutStr(38, 8,"  ");
	XYPutStr(44, 8,"  ");
	delay(50);

	//�ϰ�°��
	XYPutStr(6, 9, "  ");
	XYPutStr(14, 9, "  ");
	XYPutStr(18, 9,"        ");
	XYPutStr(28, 9,"        ");
	XYPutStr(38, 9,"  ");
	XYPutStr(44, 9,"  ");
	delay(50);

	//��ȩ��°��
	XYPutStr(28, 11,"  ");
	delay(50);

	//����°��
	XYPutStr(28, 12, "  ");
	delay(50);

	//���ѹ�°��
	XYPutStr(28, 13,"  ");
	delay(50);

	//���ι�°��
	XYPutStr(28, 14,"        ");
	XYPutStr(38, 14,"        ");
	XYPutStr(48, 14,"  ");
	XYPutStr(54, 14,"  ");
	XYPutStr(58, 14,"  ");
	delay(50);

	//������°��
	XYPutStr(28, 15,"  ");
	XYPutStr(34, 15,"  ");
	XYPutStr(38, 15,"  ");
	XYPutStr(44, 15,"  ");
	XYPutStr(48, 15,"  ");
	XYPutStr(54, 15,"  ");
	XYPutStr(58, 15,"  ");
	XYPutStr(60, 15,"    ");
	delay(50);

	//���׹�°��
	XYPutStr(28, 16,"  ");
	XYPutStr(34, 16,"  ");
	XYPutStr(38, 16,"  ");
	XYPutStr(44, 16,"  ");
	XYPutStr(48, 16,"  ");
	XYPutStr(54, 16,"  ");
	XYPutStr(58, 16,"  ");
	delay(50);

	//���ټ���°��
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
	delay(1000);			//1�� ��ٷȴٰ�
	_getch();
	system("cls");			//�ܼ� ȭ�� �����

}
void Preview::Basic()
{

	_setcursortype(_NOCURSOR);			//Ŀ�� ���� 
	textbackground(BLACK); //���� ���� ����
	textcolor(WHITE);			//���ڻ� ����
	textbackground(BLACK);		//���� ���� ����
}
void Preview::View_Help()
{
	clrscr();
	View_BG();						//��� ���			
	textcolor(RED);					//������ �ؽ�Ʈ Į��
	textbackground(WHITE);				//��� ���
	XYPutStr(13, 9, "����������������������������������������������������");
	XYPutStr(13, 10, "��                     <Help>                     ��");
	XYPutStr(13, 11, "��                ����� : Move                 ��");
	XYPutStr(13, 12, "��     1. Press the number you want to choose.    ��");
	XYPutStr(13, 13, "��               2. Press the arrow key.	      ��");
	XYPutStr(13, 14, "��    3. The goal is to get the red block out     ��");
	XYPutStr(13, 15, "��	      of the board buy sliding		      ��");
	XYPutStr(13, 16, "��	   the other blocks out of the way.    	      ��");
	XYPutStr(13, 17, "��			             		      ��");
	XYPutStr(13, 18, "��	          Space: Restart  		      ��");
	XYPutStr(13, 19, "����������������������������������������������������");
	_setcursortype(_NOCURSOR);						//Ŀ�� ���ֱ�
	_getch();
	Basic();
	system("cls");
	textbackground(BLACK);								//��� ����
	textcolor(WHITE);								//������� �ٲٱ�
}

void Preview::View_BG()
{
	gotoxy(1, 1);
	View_Image(10);						//���ȭ�� ���(���� ��µ� �̹��� ���ֱ� ���Ͽ�)
	textbackground(BLACK);			//���� ����
	textcolor(WHITE);				//���ڻ� ����
	system("cls");				//�ܼ������
	/*
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��" << endl;
	*/ //���ۿ���..
}
void Preview::View_Loading()
{
	View_BG();							// ��� ȭ�� ���
	View_Image(11);						// �ε� ȭ�� ���
	Sleep(3000);						// 3�� ���
}

void Preview::View_NextStage(int _stage)
{
	View_BG();						//��� ���
	View_Image(_stage+1);				//���� �������� �̹��� ���
	Sleep(2000);					//2�� ������
}
void Preview::View_SuccessPage(int _stage,int _selectC)					//ĳ���͸��� �ϼ� ȭ�� ���
{
	textcolor(WHITE);						//�ؽ�Ʈ �÷� ���
	View_BG();							//��� ���
	gotoxy(0, 0);							//0,0���� �̵� (Ŀ�� �������Ͽ�)
	
	switch (_selectC)					// ���õ� ĳ���� ����
	{
	case 1:									
		View_Image(6);						//������ �ϼ� ������
		break;
	case 2:
		View_Image(7);						//����� �ϼ� ������
		break;
	case 3:
		View_Image(8);						//����Ÿ�� �ϼ� ������
		break;
	case 4:
		View_Image(9);						//�׸��� �ϼ� ������
		break;
	}
	Sleep(2000);							//2�� ������

	_setcursortype(_NOCURSOR);					//Ŀ�� ����
}

void Preview::XYPutStr(int a, int b, char *str)				//x,y���� ���� string���
{
	gotoxy(a, b);
	cout << str;
}

void Preview::View_SelectPage()										//������ �������� �ٷ� �������� ����������
{
	View_BG();			//���ȭ�� ���
	XYPutStr(16, 9, "1. Game Start");
	XYPutStr(16, 12, "2. Help");
	_setcursortype(_NOCURSOR);
}

void Preview::View_EXIT()					//������ ������
{
	system("cls");
	textcolor(WHITE);
	textbackground(BLACK);
	XYPutStr(18, 12, "EXIT?");
	XYPutStr(18, 14, "Y/N");
	_setcursortype(_NOCURSOR);
}

void Preview::View_Score(int score)						//���ھ ���� �̹��� �����ֱ�
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

void Preview::View_Image(int select)						//�̹��� �����ֱ�
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
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == '1')
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/RED.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
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
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 2)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 3)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 4)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/STAGE4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 6)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(RED).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 7)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(BLUE).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 8)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(MAGENTA).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 9)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(GREEN).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 110, 100, 700, 700, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 10)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/CLEAR(BG).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 0, 0, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 11)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/LOAD.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 100, 0, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 12)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(A).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 13)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(B).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 14)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(C).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 15)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(D).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 16)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/GRADE(F).bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 50, 50, 1000, 1000, hMemDC, 0, 0, SRCCOPY);

	}
	else if (select == 17)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 18)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 19)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	else if (select == 20)
	{
		// �̹��� �ε�
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image/Character_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		// �̹��� ��� �κ�
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		BitBlt(hdc, 90, 160, 628, 350, hMemDC, 0, 0, SRCCOPY);
	}
	// ���� �޸� ���� 
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd, hdc);

	//system("pause");
	
}

void Preview::View_SelectC(int _x, int _y)					//ĳ���� ����ȭ�� ���
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

void Preview::View_ImageTold(int block_N)			//���õ� �ɸ��� ���ϱ�
{
	textcolor(WHITE);
	if (block_N >= '1' && block_N <= '9')
	{
		switch (block_N)								//key�� ���� ����� ������ �ѷ���
		{
		case '1':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� ���̸��� ����  ��");
			XYPutStr(40, 22, "�������� �����λ� ��");
			XYPutStr(40, 23, "�������𸣴´ٴ�  ��");
			XYPutStr(40, 24, "����ø�� �ƴϰ���?��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '2':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� ���� �ְ���    ��");
			XYPutStr(40, 22, "��      ��п��  ��");
			XYPutStr(40, 23, "��   �ű� ��!!!   ��");
			XYPutStr(40, 24, "���� ����� ���Ѷ�");
			XYPutStr(40, 25, "��������������������");
			break;
		case '3':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� �� ���Ѷ�!!    ��");
			XYPutStr(40, 22, "��   �������±��� ��");
			XYPutStr(40, 23, "�� �����ڴ� ����  ��");
			XYPutStr(40, 24, "��  ������������  ��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '4':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� �� �̸�      ��");
			XYPutStr(40, 22, "��   ���ʹٰ�?? ��");
			XYPutStr(40, 23, "�� ������       ��");
			XYPutStr(40, 24, "���ʵ� ������̻� ��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '5':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� ��..������     ��");
			XYPutStr(40, 22, "�� ��п����     ��");
			XYPutStr(40, 23, "�� ���ظ԰ڱ�     ��");
			XYPutStr(40, 24, "�� ��Ż�ϰ� �ʹ�  ��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '6':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� ���� �����ٰ�? ��");
			XYPutStr(40, 22, "�� ��... �����   ��");
			XYPutStr(40, 23, "�� �ؾߵɰž�     ��");
			XYPutStr(40, 24, "�� ��û ��ΰŵ�  ��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '7':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� �츮�� ���ο�  ��");
			XYPutStr(40, 22, "�� �̼��� �ʿ���  ��");
			XYPutStr(40, 23, "�� ��û ���ָ�    ��");
			XYPutStr(40, 24, "��  �߻������!!  ��");
			XYPutStr(40, 25, "��������������������");
			break;
		case '8':
			XYPutStr(40, 20, "��������������������");
			XYPutStr(40, 21, "�� ���� ŭ ������ ��");
			XYPutStr(40, 22, "�� ������ ���ͺ�  ��");
			XYPutStr(40, 23, "�� ���ٸ� �ٵ�    ��");
			XYPutStr(40, 24, "�� ������ �߾ı��ڦ�");
			XYPutStr(40, 25, "��������������������");
			break;
		}
	}
}

void Preview::View_ImageBlock(int block_N)				//���õ� ��ϵ��� ĳ���� ������
{
	gotoxy(0, 0);
		switch (block_N)								//key�� ���� ����� ������ �ѷ���
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
