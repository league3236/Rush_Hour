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
	PV.View_BG();							// ��� ȭ�� ���
	PV.View_StartPage();					// ���� ��ŸƮ ������
	PV.View_SelectPage();					// 1.���ӽ��� 2.���� ���
	Select_Num();							// ���ӽ����� �Ұ��� ������ ������ ����
	PV.View_BG();							// ��� ȭ�� ���
	PV.View_Image(model.GetselectC());		// �ɸ��� ���� �̹��� ���
	Select_Character();						// �ɸ��� ����
	PV.View_Loading();						// �ε�ȭ�� ���
	PV.View_BG();							// ��� ȭ�� ���
	Map_Control();							//�� ��Ʈ�� �Լ�
	PV.View_BG();							// ��� ȭ�� ���
	PV.View_Score(model.Getscore());		//���ھ���ֱ�
	_getch();
}
void Control::Map_Control()
{
	while (model.Getstage() < 4)
	{
		PV.View_NextStage(model.Getstage());		//�������� ���
		PV.View_BG();								//��� ���
		S.CallMap(model.Getstage(),model.GetselectC());			//�ʺҷ�����
		MV.View_Collect_Color(model.Getscore());				//�Է��� ��� ���� Ȯ��
		MV.View_Level_Step(model.Getstage(), model.Getstep());			//���� Ȯ��
		MV.View_Map_Print(S.GetMap(), S.GetMapMax_x(), S.GetMapMax_y());			//�� ���
		do {
			model.SetKey(Get_Key());						//�Է� Ű �ޱ� 
			switch (Sort_out_Key(model.GetKey()))			//Ű ������ ����
			{

			case 1:							//�Է� ���� Ű�� �����̸�
			{
				MV.View_Block_Key(model.GetKey());//	��ϻ��� �Է�
				PV.View_ImageTold(model.GetKey());		//��Ͽ� ���� �̹����� ��ȭ
				PV.View_ImageBlock(model.GetKey());//	��Ͽ� ���� �̹��� ���
				model.Setblock_K(model.GetKey());//	���� �ֱٿ� �Է��ߴ� Block Number Set�ϱ�
				break;

			}

			case 2:
			{
				int x = Find_x(S.GetMap(), model.Getblock_K(), S.GetMapMax_x(), S.GetMapMax_y());		//x��ǥ ã��
				int y = Find_y(S.GetMap(), model.Getblock_K(), S.GetMapMax_x(), S.GetMapMax_y());		//y��ǥ ã��
				Trans_Matrix(S.GetMap(), model.GetKey(), model.Getblock_K(), x, y);				//Ű �޾ƿ���
				MV.View_Level_Step(model.Getstage(), model.Getstep());				

			}
			}
		} while (End_Block(S.GetMap(), model.Getch()));
		//PV.Basic();
		Score(model.Getstep());				//���ھ� �����ֱ�
		model.Setstage();					//�������� ++
		model.Setstep(0);					//���� ����
		PV.View_SuccessPage(model.Getstage(), model.GetselectC());// SuccessPage ���
	
	}
}

int Control::Get_Key()			//Ű �޾ƿ���
{
	int ch;
	ch = _getch();
	if (ch == M_ESCKEY)			
		exit(0);
	return (ch == 0xe0) ? (0xe000 | _getch()) : ch;
}

int Control::Get_BlockKey()				//��� �޾ƿ���
{
	int ch;
	ch = _getch();

	return ch;				//���ڸ� �� ch����
}

int Control::EXIT()						//��Ʈ�� ������
{
	PV.View_EXIT();
	char ch = _getch();
	if (ch == 'Y' || ch == 'y')
		exit(0);
	/*else if (ch == 'N' || ch == 'n')
	{
		PV.View_BG();
		MV.View_Block_Key				//���� ��

	}*/
}

void Control::Select_Num()				//������ ��������? �ƴϸ� �ٷ� ������ ��
{
	PV.XYPutStr(14, 9, "��");
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
			PV.XYPutStr(14, 9, "��");
			PV.XYPutStr(14, 12, " ");
			break;
		}
		case M_DOWNKEY:
		{
			if (i == 1)
				i++;
			PV.XYPutStr(14, 12, "��");
			PV.XYPutStr(14, 9, " ");
			break;
		}
		}
	} while (ch != M_ENTER);
	if (i == 2)
		PV.View_Help();
}

void Control::Select_Character()			//ĳ���� ����
{
	int _x = 8, _y = 10;
	int key;
	int _Select = 0;

	while (_Select != 1)
	{
		key = Get_Key();					//����Ű�� �޾ƿ�
		
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
				textcolor(WHITE);	      	//��� �ؽ�Ʈ�� �ʱ�ȭ
				if (_x == 8 && _y == 10)
					model.SetselectC(1);			//�ɸ��� ����
				else if (_x == 58 && _y == 10)
					model.SetselectC(2);			//�ɸ��� ���
				else if (_x == 8 && _y == 17)
					model.SetselectC(3);			//�ɸ��� ����
				else if (_x == 58 && _y == 17)
					model.SetselectC(4);			//�ɸ��� �׸�
			}

		}
	}
	system("cls");					//��üȭ�� �����
}

int Control::Sort_out_Key(int key)
{
	if (key >= '1' && key <= '9')					//1���� 9���� Ű�� ������
	{
		Bg.Bgm_Sound(3);
		return 1;
	}
	else if (key == M_UPKEY || key == M_DOWNKEY || key == M_LEFTKEY || key == M_RIGHTKEY || key == M_ESCKEY)
		return 2;							//�Է¹��� ���� ��Ʈ���̸�
	else
		return 3;								//�ٸ��Ÿ�
}

bool Control::End_Block(int map[][14], int stage)			// ����� ���������� ���� �Լ� ��������� ���Ͽ�
{
	switch (model.GetselectC())				//�� �ɸ��͸��� ���� �ɸ��� ��ġ�� �ٸ�����
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
	int _step = model.Getstep();//�� �Լ��� ���Դٴ°� ������ ����Ű�� ������ ������ step++����
	switch (Block_N)				//���õ� ��Ͽ� ����
	{
	case '1':
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//������ �����̸� �������� ��ĭ�̵�
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
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//�Ʒ����� �����̸� �Ʒ��� ��ĭ�̵�
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
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//�Ʒ����� �����̸� �Ʒ��� ��ĭ�̵�
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
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//������ �����̸� �������� ��ĭ�̵�
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
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//������ �����̸� �������� ��ĭ�̵�
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
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//�Ʒ����� �����̸� �Ʒ��� ��ĭ�̵�
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
		if ((key == M_LEFTKEY) && (map[x][y - 1] == 0))				//������ �����̸� �������� ��ĭ�̵�
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
		if ((key == M_UPKEY) && (map[x - 1][y] == 0))				//�Ʒ����� �����̸� �Ʒ��� ��ĭ�̵�
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

int Control::Find_x(int map[][14], int Block_N, int max_x, int max_y)			//x�� ã��
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

int Control::Find_y(int map[][14], int Block_N, int max_x, int max_y)			//y�� ã��
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

void Control::Score(int step)								//���ھ� ���
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