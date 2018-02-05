#include <iostream>
#include "Control.h"
#include "Mapview.h"
#include "Stage.h"
#include "Preview.h"
#include "Model.h"
#include <conio.h>
#include "Arrow.h"
#include "consola.h"
#include "Bgm.h"

using namespace std;

void Control::Run()
{
	PV.View_BG();							// 배경 화면 출력
	PV.View_StartPage();					// 게임 스타트 페이지
	PV.View_SelectPage();					// 1.게임시작 2.도움말 출력
	Select_Num();							// 게임시작을 할건지 도움말을 볼건지 선택
	PV.View_BG();							// 배경 화면 출력
	PV.View_Image(model.GetselectC());		// 케릭터 선택 이미지 출력
	Select_Character();						// 케릭터 선택
	PV.View_Loading();						// 로딩화면 출력
	PV.View_BG();							// 배경 화면 출력
	Map_Control();							//맵 컨트롤 함수
	PV.View_BG();							// 배경 화면 출력
	PV.View_Score(model.Getscore());		//스코어보여주기
	_getch();
}
void Control::Map_Control()
{
	while (model.Getstage() < 4)
	{
		PV.View_NextStage(model.Getstage());		//스테이지 출력
		PV.View_BG();								//배경 출력
		S.CallMap(model.Getstage(),model.GetselectC());			//맵불러오기
		MV.View_Collect_Color(model.Getscore());				//입력한 블록 색상 확인
		MV.View_Level_Step(model.Getstage(), model.Getstep());			//레벨 확인
		MV.View_Map_Print(S.GetMap(), S.GetMapMax_x(), S.GetMapMax_y());			//맵 출력
		do {
			model.SetKey(Get_Key());						//입력 키 받기 
			switch (Sort_out_Key(model.GetKey()))			//키 종류에 따라
			{

			case 1:							//입력 받은 키가 숫자이면
			{
				MV.View_Block_Key(model.GetKey());//	블록색깔 입력
				PV.View_ImageTold(model.GetKey());		//블록에 따른 이미지의 대화
				PV.View_ImageBlock(model.GetKey());//	블록에 따른 이미지 출력
				model.Setblock_K(model.GetKey());//	가장 최근에 입력했던 Block Number Set하기
				break;

			}

			case 2:
			{
				int x = Find_x(S.GetMap(), model.Getblock_K(), S.GetMapMax_x(), S.GetMapMax_y());		//x좌표 찾기
				int y = Find_y(S.GetMap(), model.Getblock_K(), S.GetMapMax_x(), S.GetMapMax_y());		//y좌표 찾기
				Trans_Matrix(S.GetMap(), model.GetKey(), model.Getblock_K(), x, y);				//키 받아오기
				MV.View_Level_Step(model.Getstage(), model.Getstep());				

			}
			}
		} while (End_Block(S.GetMap(), model.Getch()));
		//PV.Basic();
		Score(model.Getstep());				//스코어 더해주기
		model.Setstage();					//스테이지 ++
		model.Setstep(0);					//스텝 저장
		PV.View_SuccessPage(model.Getstage(), model.GetselectC());// SuccessPage 출력
	
	}
}

int Control::Get_Key()			//키 받아오기
{
	int ch;
	ch = _getch();
	if (ch == M_ESCKEY)			
		exit(0);
	return (ch == 0xe0) ? (0xe000 | _getch()) : ch;
}

int Control::Get_BlockKey()				//블록 받아오기
{
	int ch;
	ch = _getch();

	return ch;				//숫자면 전 ch받음
}

int Control::EXIT()						//컨트롤 나가기
{
	PV.View_EXIT();
	char ch = _getch();
	if (ch == 'Y' || ch == 'y')
		exit(0);
	/*else if (ch == 'N' || ch == 'n')
	{
		PV.View_BG();
		MV.View_Block_Key				//구현 중

	}*/
}

void Control::Select_Num()				//도움말을 선택할지? 아니면 바로 시작할 지
{
	PV.XYPutStr(14, 9, "▶");
	int i=1, ch;
	textcolor(WHITE);
	do
	{
		ch = Get_Key();
		switch (ch)
		{
		case M_UPKEY:
		{
			if (i == 2)
				i--;
			PV.XYPutStr(14, 9, "▶");
			PV.XYPutStr(14, 12, " ");
			break;
		}
		case M_DOWNKEY:
		{
			if (i == 1)
				i++;
			PV.XYPutStr(14, 12, "▶");
			PV.XYPutStr(14, 9, " ");
			break;
		}
		}
	} while (ch != M_ENTER);
	if (i == 2)
		PV.View_Help();
}

void Control::Select_Character()			//캐릭터 선택
{
	int _x = 8, _y = 10;
	int key;
	int _Select = 0;

	while (_Select != 1)
	{
		key = Get_Key();					//방향키를 받아옴
		
		if (key == M_DOWNKEY&&_y<17)
		{
			_y += 7;
			PV.View_SelectC(_x, _y);
			Bg.Bgm_Sound(1);
		}
		else if (key == M_UPKEY&&_y>10)
		{
			_y -= 7;
			PV.View_SelectC(_x, _y);
			Bg.Bgm_Sound(1);
		}
		else if (key == M_RIGHTKEY&&_x<58)
		{
			_x += 50;
			PV.View_SelectC(_x, _y);
			Bg.Bgm_Sound(1);
		}
		else if (key == M_LEFTKEY&&_x>8)
		{
			_x -= 50;
			PV.View_SelectC(_x, _y);
			Bg.Bgm_Sound(1);
		}
		
		else if (key == 32)
		{
			{
				_Select = 1;
				textcolor(WHITE);	      	//흰색 텍스트로 초기화
				if (_x == 8 && _y == 10)
					model.SetselectC(1);			//케릭터 레드
				else if (_x == 58 && _y == 10)
					model.SetselectC(2);			//케릭터 블루
				else if (_x == 8 && _y == 17)
					model.SetselectC(3);			//케릭터 퍼플
				else if (_x == 58 && _y == 17)
					model.SetselectC(4);			//케릭터 그린
			}

		}
	}
	system("cls");					//전체화면 지우기
}

int Control::Sort_out_Key(int key)
{
	if (key >= '1' && key <= '9')					//1에서 9까지 키를 받으면
	{
		Bg.Bgm_Sound(3);
		return 1;
	}
	else if (key == M_UPKEY || key == M_DOWNKEY || key == M_LEFTKEY || key == M_RIGHTKEY || key == M_ESCKEY)
		return 2;							//입력받은 값이 컨트롤이면
	else
		return 3;								//다른거면
}

bool Control::End_Block(int map[][14], int stage)			// 블록이 빠져나가면 다음 함수 수행시작을 위하여
{
	switch (model.GetselectC())				//각 케릭터마다 메인 케릭터 위치가 다름으로
	{

	case 1:
		if (map[5][13] == 0)
			return true;
		else 
			return false;
		break;
	case 2:
		if (map[13][3] == 0)
			return true;
		else 
			return false;
		
		break;
	case 3:
		if (map[5][13] == 0)
			return true;
		else 
			return false;
		break;
	case 4:
		if (map[13][7] == 0)
			return true;
		else 
			return false;
		break;
	}

}

void Control::Trans_Matrix(int map[][14], int key, int Block_N, int x, int y)
{
	int _step = model.Getstep();//이 함수에 들어왔다는건 무조건 방향키를 눌렀기 때문에 step++해줌
	switch (Block_N)				//선택된 블록에 따라서
	{
	case '1':
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//왼쪽이 공백이면 왼쪽으로 한칸이동
		{
			map[x][y + 3] = 0;
			map[x + 1][y + 3] = 0;
			map[x][y - 1] = 1;
			map[x + 1][y - 1] = 1;
			model.Setstep(++_step);
		}
		else if ((key == M_RIGHTKEY) && (map[x][y + 4] == 0))
		{
			map[x][y] = 0;
			map[x + 1][y] = 0;
			map[x][y + 4] = 1;
			map[x + 1][y + 4] = 1;
			model.Setstep(++_step);
		}
		break;
	case '2':
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//아랫쪽이 공백이면 아래로 한칸이동
		{
			map[x - 1][y] = 2;
			map[x - 1][y + 1] = 2;
			map[x + 5][y] = 0;
			map[x + 5][y + 1] = 0;
			model.Setstep(++_step);
		}
		else if ((key == M_DOWNKEY) && (map[x + 6][y] == 0))
		{
			map[x + 6][y] = 2;
			map[x + 6][y + 1] = 2;
			map[x][y] = 0;
			map[x][y + 1] = 0;
			model.Setstep(++_step);
		}
		break;
	case '3':
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//아랫쪽이 공백이면 아래로 한칸이동
		{
			map[x - 1][y] = 3;
			map[x - 1][y + 1] = 3;
			map[x + 3][y] = 0;
			map[x + 3][y + 1] = 0;
			model.Setstep(++_step);
		}
		else if ((key == M_DOWNKEY) && (map[x + 4][y] == 0))
		{
			map[x + 4][y] = 3;
			map[x + 4][y + 1] = 3;
			map[x][y] = 0;
			map[x][y + 1] = 0;
			model.Setstep(++_step);
		}
		break;
	case '4':
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//왼쪽이 공백이면 왼쪽으로 한칸이동
		{
			map[x][y + 5] = 0;
			map[x + 1][y + 5] = 0;
			map[x][y - 1] = 4;
			map[x + 1][y - 1] = 4;
			model.Setstep(++_step);
		}
		else if ((key == M_RIGHTKEY) && (map[x][y + 6] == 0))
		{
			map[x][y] = 0;
			map[x + 1][y] = 0;
			map[x][y + 6] = 4;
			map[x + 1][y + 6] = 4;
			model.Setstep(++_step);
		}
		break;
	case '5':
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//왼쪽이 공백이면 왼쪽으로 한칸이동
		{
			map[x][y + 3] = 0;
			map[x + 1][y + 3] = 0;
			map[x][y - 1] = 5;
			map[x + 1][y - 1] = 5;
			model.Setstep(++_step);
		}
		else if ((key == M_RIGHTKEY) && (map[x][y + 4] == 0))
		{
			map[x][y] = 0;
			map[x + 1][y] = 0;
			map[x][y + 4] = 5;
			map[x + 1][y + 4] = 5;
			model.Setstep(++_step);
		}
		break;
	case '6':
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//아랫쪽이 공백이면 아래로 한칸이동
		{
			map[x - 1][y] = 6;
			map[x - 1][y + 1] = 6;
			map[x + 5][y] = 0;
			map[x + 5][y + 1] = 0;
			model.Setstep(++_step);
		}
		else if ((key == M_DOWNKEY) && (map[x + 6][y] == 0))
		{
			map[x + 6][y] = 6;
			map[x + 6][y + 1] = 6;
			map[x][y] = 0;
			map[x][y + 1] = 0;
			model.Setstep(++_step);
		}
		break;
	case '7':
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//왼쪽이 공백이면 왼쪽으로 한칸이동
		{
			map[x][y + 3] = 0;
			map[x + 1][y + 3] = 0;
			map[x][y - 1] = 7;
			map[x + 1][y - 1] = 7;
			model.Setstep(++_step);
		}
		else if ((key == M_RIGHTKEY) && (map[x][y + 4] == 0))
		{
			map[x][y] = 0;
			map[x + 1][y] = 0;
			map[x][y + 4] = 7;
			map[x + 1][y + 4] = 7;
			model.Setstep(++_step);
		}
		break;
	case '8':
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//아랫쪽이 공백이면 아래로 한칸이동
		{
			map[x - 1][y] = 8;
			map[x - 1][y + 1] = 8;
			map[x + 5][y] = 0;
			map[x + 5][y + 1] = 0;
			model.Setstep(++_step);
		}
		else if ((key == M_DOWNKEY) && (map[x + 6][y] == 0))
		{
			map[x + 6][y] = 8;
			map[x + 6][y + 1] = 8;
			map[x][y] = 0;
			map[x][y + 1] = 0;
			model.Setstep(++_step);
		}
	}
	MV.View_Map_Print(map, S.GetMapMax_x(), S.GetMapMax_y());
}

int Control::Find_x(int map[][14], int Block_N, int max_x, int max_y)			//x값 찾기
{
	for (int i = 0; i < max_x+1; i++)
	{
		for (int j = 0; j < max_y; j++)
		{
			if (map[i][j] == (Block_N-'0'))
				return i;
		}
	}
}

int Control::Find_y(int map[][14], int Block_N, int max_x, int max_y)			//y값 찾기
{
	for (int i = 0; i < max_x+1; i++)
	{
		for (int j = 0; j < max_y; j++)
		{
			if (map[i][j] == (Block_N-'0'))
				return j;
		}
	}
}

void Control::Score(int step)								//스코어 계산
{
	int i = model.Getscore();
	if (model.GetselectC() == 1)
	{
		switch (model.Getstage())
		{
		case 0:
			if (step <= 20)
				i += 25;
			else if (step>20 && step <= 23)
				i += 20;
			else if (step>23 && step <= 25)
				i += 15;
			else if (step>25)
				i += 10;
			break;
		case 1:
			if (step <= 26)
				i += 25;
			else if (step>26 && step <= 28)
				i += 20;
			else if (step>28 && step <= 31)
				i += 15;
			else if (step>31)
				i += 10;
			break;
		case 2:
			if (step <= 34)
				i += 25;
			else if (step>34 && step <= 36)
				i += 20;
			else if (step>36 && step <= 38)
				i += 15;
			else if (step>38)
				i += 10;
			break;
		case 3:
			if (step <= 34)
				i += 25;
			else if (step>34 && step <= 36)
				i += 20;
			else if (step>36 && step <= 38)
				i += 15;
			else if (step>38)
				i += 10;
			break;
		}
	}
	else if (model.GetselectC() == 2)
	{
		switch (model.Getstage())
		{
		case 0:
			if (step <= 21)
				i += 25;
			else if (step>21 && step <= 25)
				i += 20;
			else if (step>25 && step <= 28)
				i += 15;
			else if (step>28)
				i += 10;
			break;
		case 1:
			if (step <= 33)
				i += 25;
			else if (step>33 && step <= 36)
				i += 20;
			else if (step>36 && step <= 39)
				i += 15;
			else if (step>39)
				i += 10;
			break;
		case 2:
			if (step <= 20)
				i += 25;
			else if (step>20 && step <= 23)
				i += 20;
			else if (step>24 && step <= 26)
				i += 15;
			else if (step>26)
				i += 10;
			break;
		case 3:
			if (step <= 34)
				i += 25;
			else if (step>34 && step <= 36)
				i += 20;
			else if (step>36 && step <= 38)
				i += 15;
			else if (step>38)
				i += 10;
			break;
		}
	}
	else if (model.GetselectC() == 3)
	{
		switch (model.Getstage())
		{
		case 0:
			if (step <= 23)
				i += 25;
			else if (step>23 && step <= 26)
				i += 20;
			else if (step>26 && step <= 28)
				i += 15;
			else if (step>28)
				i += 10;
			break;
		case 1:
			if (step <= 36)
				i += 25;
			else if (step>36 && step <= 38)
				i += 20;
			else if (step>38 && step <= 41)
				i += 15;
			else if (step>41)
				i += 10;
			break;
		case 2:
			if (step <= 34)
				i += 25;
			else if (step>34 && step <= 36)
				i += 20;
			else if (step>36 && step <= 38)
				i += 15;
			else if (step>38)
				i += 10;
			break;
		case 3:
			if (step <= 23)
				i += 25;
			else if (step>23 && step <= 25)
				i += 20;
			else if (step>25 && step <= 28)
				i += 15;
			else if (step>28)
				i += 10;
			break;
		}
	}
	else if (model.GetselectC() == 4)
	{
		switch (model.Getstage())
		{
		case 0:
			if (step <= 25)
				i += 25;
			else if (step>25 && step <= 28)
				i += 20;
			else if (step>28 && step <= 31)
				i += 15;
			else if (step>31)
				i += 10;
			break;
		case 1:
			if (step <= 35)
				i += 25;
			else if (step>35 && step <= 38)
				i += 20;
			else if (step>38 && step <= 41)
				i += 15;
			else if (step>41)
				i += 10;
			break;
		case 2:
			if (step <= 23)
				i += 25;
			else if (step>23 && step <= 26)
				i += 20;
			else if (step>26 && step <= 28)
				i += 15;
			else if (step>28)
				i += 10;
			break;
		case 3:
			if (step <= 21)
				i += 25;
			else if (step>21 && step <= 23)
				i += 20;
			else if (step>23 && step <= 26)
				i += 15;
			else if (step>26)
				i += 10;
			break;
		}
	}
	model.Setscore(i);
}