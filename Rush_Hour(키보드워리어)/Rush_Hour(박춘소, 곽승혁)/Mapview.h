#ifndef MAPVIEW_H
#define MAPVIEW_H

//map���� ���̴� View
class Mapview{

private:

public:
	void View_Level_Step(int a, int b);									// ����
	void View_Collect_Color(int _Score);								// ���� ��ϻ��� ���
	void View_Map_Print(int _stage[][14], int max_x, int max_y);		//�� ���
	void View_Block_Key(int block_N);									// ��� Ű �����ֱ�
	void _XYPutStr(int x, int y, char* str);							
};

#endif