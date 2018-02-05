#ifndef MAPVIEW_H
#define MAPVIEW_H

//map에서 쓰이는 View
class Mapview{

private:

public:
	void View_Level_Step(int a, int b);									// 레벨
	void View_Collect_Color(int _Score);								// 선택 블록색상 출력
	void View_Map_Print(int _stage[][14], int max_x, int max_y);		//맵 출력
	void View_Block_Key(int block_N);									// 블록 키 보여주기
	void _XYPutStr(int x, int y, char* str);							
};

#endif