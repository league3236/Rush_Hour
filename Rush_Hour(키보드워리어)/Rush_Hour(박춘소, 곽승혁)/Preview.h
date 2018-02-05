#ifndef PREVIEW_H
#define PREVIEW_H
#include <iostream>
#include <conio.h>
#include <Windows.h>

//기본적인 view class
class Preview{

private:

public:
	void XYPutStr(int x, int y, char str[]);
	void Basic();		//기본 화면
	void View_StartPage();												//첫페이지
	void View_SelectPage();													//선택화면
	void View_EXIT();								//원하는 곳에 str넣기
	void View_Help();															//도움말 화면
	void View_BG();				//배경
	void View_Loading();
	void View_NextStage(int _stage);
	void View_SuccessPage(int _stage,int _selectC);	//스테이지 끝날때 화면 출력
	void View_Score(int score);
	void View_Image(int _image);
	void View_SelectC(int _x, int _y);				//캐릭터 선택 이미지 출력
	void View_ImageBlock(int block_N);				//선택된 블록의 이미지 출력
	void View_ImageTold(int block_N);				//선택된 이미지 대화체 출력
};

#endif