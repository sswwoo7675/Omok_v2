#include <string>
#include <iostream>
using namespace std;

#ifndef STONE_H
#define STONE_H
class stone {

public:
	int x; //�� x��ǥ
	int y; //�� y��ǥ
	int state; //�� ���� (��or��)
	string shape; //�� ���
	stone(int x, int y, int state, string shape);
};
#endif