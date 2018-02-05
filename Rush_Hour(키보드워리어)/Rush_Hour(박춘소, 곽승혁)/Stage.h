#ifndef STAGE_H
#define STAGE_H

class Stage{

private:
	int map[14][14];
	int Mapmax_x, Mapmax_y;
public:
	void CallMap(int stage, int num);		//맵불러오기
	void Setmap(int* map);			//아직 구현하지 못함
	int(*GetMap())[14];		//맵 호출하기
	int GetMapMax_x();		//맵의 x값
	int GetMapMax_y();		//맵의 y값
};
#endif