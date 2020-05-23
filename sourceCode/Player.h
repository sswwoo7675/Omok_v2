#include <string>
#include <iostream>

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
	string name; //플레이어 이름
	int x; //현재 좌표
	int y;
	int winCnt; //이긴횟수
	int loseCnt; //진횟수
	int dol; //흑(1) or 백(2)
public:
	Player(); //생성자
	int getX();
	int getY();
	void setX(int n);
	void setY(int n);
	int getDol();
	int getWinCnt();
	int getLoseCnt();
	string getName();
	void setDol(int dol);
	void setName(string name);
	void move_xy(char key);
	Player operator ++(); //이겼을때 사용하기 위한 연산자 구현
	Player operator --(); //졌을때 사용하기 위한 연산자 구현
};

#endif