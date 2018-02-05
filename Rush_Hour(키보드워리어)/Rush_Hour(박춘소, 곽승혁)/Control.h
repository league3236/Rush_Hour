#ifndef CONTROL_H
#define CONTROL_H
#include "Mapview.h"
#include "Preview.h"
#include "Model.h"
#include "Stage.h"
#include "Bgm.h"

class Control {
private:
	Mapview MV;
	Preview PV;
	Model model;
	Stage S;
	Bgm Bg;
public:
	void Run();//���ӿ� �տ� ������ �Լ����� ����
	void Map_Control();//������ �Ҷ� �ʿ��� �Լ����� ����
	int Get_Key();//Ű�� �޴� �Լ�
	int Get_BlockKey();//block�� ���ڸ� �Է¹޴� �Լ�
	int EXIT();//�Լ������� �� �Լ�
	void Select_Num();//seleckpage�� �����ִ� �Լ�
	void Select_Character();
	void Score(int);
	int Sort_out_Key(int key);//�Է¹��� Ű�� �������� ����Ű���� �к����ִ� �Լ�
	bool End_Block(int map[][14], int stage);//�ⱸ�� ���ϴ� ���� ���Դ��� Ȯ���ϴ� �Լ�
	void Trans_Matrix(int map[][14], int key, int Block_N, int x, int y);
	int Find_x(int map[][14], int Block_N, int max_x, int max_y);
	int Find_y(int map[][14], int Block_N, int max_x, int max_y);
};

#endif