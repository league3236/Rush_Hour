#ifndef STAGE_H
#define STAGE_H

class Stage{

private:
	int map[14][14];
	int Mapmax_x, Mapmax_y;
public:
	void CallMap(int stage, int num);		//�ʺҷ�����
	void Setmap(int* map);			//���� �������� ����
	int(*GetMap())[14];		//�� ȣ���ϱ�
	int GetMapMax_x();		//���� x��
	int GetMapMax_y();		//���� y��
};
#endif