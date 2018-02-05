#include "Model.h"

Model::Model()
{
	stage = 0;
	step = 0;
	score = 0;
	selectC = 0;
}
int Model::Getstage()
{
	return stage;
}
int Model::GetselectC()
{
	return selectC;
}
int Model::Getstep()
{
	return step;
}
int Model::Getblock_K()
{
	return block_K;
}
int Model::GetKey()
{
	return Key;
}
int Model::Getch()
{
	return ch;
}
int Model::Getoldch()
{
	return oldch;
}
int Model::Getscore()
{	return score;
}
void Model::SetselectC(int x)
{
	selectC = x;
}
void Model::Setstage()
{
	stage++;
}
void Model::Setstep(int x)
{
	step = x;
}
void Model::Setblock_K(int x)
{
	block_K = x;
}
void Model::SetKey(int x)
{
	Key = x;
}
void Model::Setoldch(int x)
{
	oldch = x;
}
void Model::Setch(int x)
{
	ch = x;
}
void Model::Setscore(int x)
{
	score = x;
}
