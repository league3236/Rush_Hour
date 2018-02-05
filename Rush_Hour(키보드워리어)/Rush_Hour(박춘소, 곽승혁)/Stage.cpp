#include "Stage.h"
#include <fstream>
using namespace std;

void Stage::CallMap(int stage, int num)			//�ؽ�Ʈ ���Ͽ��� �ʺθ���
{
	ifstream fin;						//��Ʈ��
	int i = 0, j = 0;
	char ch;
	char mapfile[16][150] = { "map(red)/stage1.txt", "map(red)/stage2.txt", "map(red)/stage3.txt", "map(red)/stage4.txt", "map(blue)/stage1.txt", "map(blue)/stage2.txt", "map(blue)/stage3.txt", "map(blue)/stage4.txt", "map(magenda)/stage1.txt", "map(magenda)/stage2.txt", "map(magenda)/stage3.txt", "map(magenda)/stage4.txt", "map(green)/stage1.txt", "map(green)/stage2.txt", "map(green)/stage3.txt", "map(green)/stage4.txt" };
	
	if (num == 2)
		stage += 4;						//ĳ���Ͱ� 2���Ͻ�
	else if (num == 3)
		stage += 8;
	else if (num == 4)
		stage += 12;


	fin.open(mapfile[stage], ios::in);					//�� ����

	while (!fin.eof())							//���ư��鼭 �� �����ϱ�
	{
		fin.get(ch);
		ch = ch - '0';
		map[i][j] = ch;
		if (map[i][j] == -38)
		{
			i++;
			j = -1;
		}
		j++;
	}
	Mapmax_x = i;
	Mapmax_y = j - 1;
	fin.close();
}

int(*Stage::GetMap())[14]
{
	return map;
}

int Stage::GetMapMax_x()
{
	return Mapmax_x;
}

int Stage::GetMapMax_y()
{
	return Mapmax_y;
}
/*
void Stage::Setmap(int* _map)
{
	int x = GetMapMax_x();
	int y = GetMapMax_y();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			map[i][j] = _map[i][j];
		}
	}
}*/