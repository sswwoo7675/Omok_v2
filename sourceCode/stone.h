#include <string>
#include <iostream>
using namespace std;

#ifndef STONE_H
#define STONE_H
class stone {

public:
	int x; //돌 x좌표
	int y; //돌 y좌표
	int state; //돌 상태 (흑or백)
	string shape; //돌 모양
	stone(int x, int y, int state, string shape);
};
#endif