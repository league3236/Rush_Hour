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
	void Run();//게임에 앞에 나오는 함수들의 집합
	void Map_Control();//게임을 할때 필요한 함수들의 집합
	int Get_Key();//키를 받는 함수
	int Get_BlockKey();//block의 숫자를 입력받는 함수
	int EXIT();//함수나갈때 할 함수
	void Select_Num();//seleckpage를 도와주는 함수
	void Select_Character();
	void Score(int);
	int Sort_out_Key(int key);//입력받은 키가 숫자인지 방향키인지 분별해주는 함수
	bool End_Block(int map[][14], int stage);//출구에 원하는 블럭이 들어왔는지 확인하는 함수
	void Trans_Matrix(int map[][14], int key, int Block_N, int x, int y);
	int Find_x(int map[][14], int Block_N, int max_x, int max_y);
	int Find_y(int map[][14], int Block_N, int max_x, int max_y);
};

#endif