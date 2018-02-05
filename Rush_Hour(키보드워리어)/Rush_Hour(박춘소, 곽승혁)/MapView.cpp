#include "Mapview.h"
#include "consola.h"
#include "Model.h"
#include <iostream>
#include <conio.h>
using namespace std;



void Mapview::View_Level_Step(int _stage, int _step)
{
	textcolor(WHITE);
	_XYPutStr(40, 3, "┏━━━━━━━━┓");
	_XYPutStr(40, 4, "┃ Stage :	 ┃");
	gotoxy(52, 4);
	cout << _stage+1;
	_XYPutStr(40, 5, "┃		 ┃");
	_XYPutStr(40, 6, "┃ Step  :        ┃");
	gotoxy(52, 6);
	cout << _step;
	_XYPutStr(40, 7, "┗━━━━━━━━┛");
}
void Mapview::View_Collect_Color(int _Score)
{
	Model model;
	textcolor(WHITE);					//텍스트 색상 WHITE
	_XYPutStr(40, 9, "┏━━━━━━━━┓");
	_XYPutStr(40, 10, "┃ Please Choose  ┃");
	_XYPutStr(40, 11, "┃   Number       ┃");
	_XYPutStr(40, 12, "┃Move : ↑↓←→ ┃");
	_XYPutStr(40, 13, "┃Your Score :    ┃");
	gotoxy(54, 13);
	cout << _Score;				//score 출력
	_XYPutStr(40, 14, "┃                ┃");
	_XYPutStr(40, 15, "┃                ┃");
	_XYPutStr(40, 16, "┃                ┃");
	_XYPutStr(40, 17, "┃                ┃");
	_XYPutStr(40, 18, "┗━━━━━━━━┛");

	gotoxy(42, 15);
	textcolor(RED); cout << "■=1 ";		//각 블록 색상과 넘버 표시
	textcolor(BLUE); cout << "■=2 ";
	textcolor(GREEN); cout << "■=3";
	gotoxy(42, 16);
	textcolor(CYAN); cout << "■=4 ";
	textcolor(MAGENTA); cout << "■=5 ";
	textcolor(BROWN); cout << "■=6";
	gotoxy(42, 17);
	textcolor(LIGHTBLUE); cout << "■=7 ";
	textcolor(LIGHTGREEN); cout << "■=8 ";
}



void Mapview::View_Map_Print(int _stage[][14], int max_x, int max_y)
{
	gotoxy(12, 4);
	for (int j = 0; j<=max_x; j++) {
		gotoxy(12, 5 + j);
		for (int k = 0; k<max_y; k++) {
			if (_stage[j][k] == 9) {
				textcolor(WHITE); cout << "■";
			}
			else if (_stage[j][k] == 0) {
				textcolor(WHITE); cout << "  ";
			}
			else if (_stage[j][k] == 1) {
				textcolor(RED); cout << "■";
			}
			else if (_stage[j][k] == 2) {
				textcolor(BLUE); cout << "■";
			}
			else if (_stage[j][k] == 3) {
				textcolor(GREEN); cout << "■";
			}
			else if (_stage[j][k] == 4) {
				textcolor(CYAN); cout << "■";
			}
			else if (_stage[j][k] == 5) {
				textcolor(MAGENTA); cout << "■";
			}
			else if (_stage[j][k] == 6) {
				textcolor(BROWN); cout << "■";
			}
			else if (_stage[j][k] == 7) {
				textcolor(LIGHTBLUE); cout << "■";
			}
			else if (_stage[j][k] == 8) {
				textcolor(LIGHTGREEN); cout << "■";
			}
		}
	}
}
void Mapview::View_Block_Key(int block_N)
{
	textcolor(WHITE);
	gotoxy(42, 8);
	if (block_N >= '1' && block_N <= '9')
	{
		cout << "Collect:";
		switch (block_N)								//key에 따라 블록의 색깔을 뿌려줌
		{
		case '1':
			textcolor(RED);
			break;
		case '2':
			textcolor(BLUE);
			break;
		case '3':
			textcolor(GREEN);
			break;
		case '4':
			textcolor(CYAN);
			break;
		case '5':
			textcolor(MAGENTA);
			break;
		case '6':
			textcolor(BROWN);
			break;
		case '7':
			textcolor(LIGHTBLUE);
			break;
		case '8':
			textcolor(LIGHTGREEN);
			break;
		}
		cout << "■";
		
	}
}


void Mapview::_XYPutStr(int x, int y, char * str)
{
	gotoxy(x, y);
	cout << str;
}
