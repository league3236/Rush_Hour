#ifndef MODEL_H
#define MODEL_H

//data�� �����ϰ� return���ִ� class
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
	void Setstage();//stage�� --�� �ʿ䰡����, �׷��Ƿ� ++���ִ� �Լ�
	void Setstep(int x);
	void Setblock_K(int x);
	void SetKey(int x);
	void Setoldch(int x);
	void Setch(int x);
};

#endif