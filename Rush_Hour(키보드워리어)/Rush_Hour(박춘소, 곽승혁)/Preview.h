#ifndef PREVIEW_H
#define PREVIEW_H
#include <iostream>
#include <conio.h>
#include <Windows.h>

//�⺻���� view class
class Preview{

private:

public:
	void XYPutStr(int x, int y, char str[]);
	void Basic();		//�⺻ ȭ��
	void View_StartPage();												//ù������
	void View_SelectPage();													//����ȭ��
	void View_EXIT();								//���ϴ� ���� str�ֱ�
	void View_Help();															//���� ȭ��
	void View_BG();				//���
	void View_Loading();
	void View_NextStage(int _stage);
	void View_SuccessPage(int _stage,int _selectC);	//�������� ������ ȭ�� ���
	void View_Score(int score);
	void View_Image(int _image);
	void View_SelectC(int _x, int _y);				//ĳ���� ���� �̹��� ���
	void View_ImageBlock(int block_N);				//���õ� ����� �̹��� ���
	void View_ImageTold(int block_N);				//���õ� �̹��� ��ȭü ���
};

#endif