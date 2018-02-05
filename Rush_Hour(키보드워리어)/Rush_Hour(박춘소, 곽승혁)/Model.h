#ifndef MODEL_H
#define MODEL_H

//data를 저장하고 return해주는 class
class Model{
private:
	int stage, step, score, selectC;
	int block_K, Key, oldch,ch;
public:
	Model();
	int Getstage();
	int GetselectC();
	int Getstep();
	int Getblock_K();
	int GetKey();
	int Getoldch();
	int Getch();
	int Getscore();
	void Setscore(int x);
	void SetselectC(int x);
	void Setstage();//stage는 --될 필요가없음, 그러므로 ++해주는 함수
	void Setstep(int x);
	void Setblock_K(int x);
	void SetKey(int x);
	void Setoldch(int x);
	void Setch(int x);
};

#endif