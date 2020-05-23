#include "MyArray.h"

#ifndef OMOKDATA_H
#define OMOKDATA_H

class omokData : public MyArray{
public:
	omokData();
	~omokData();
	bool isOkPush(int x, int y); //돌을 놓을수 있는지 확인하는 함수
	void pushStone(int x, int y, int Dol); //x,y위치에 돌을 놓음
	bool isWin(int x, int y, int turn); //승리판정
};

#endif