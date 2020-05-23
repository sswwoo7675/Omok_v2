#include <string>
#include <iostream>

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
	string name; //�÷��̾� �̸�
	int x; //���� ��ǥ
	int y;
	int winCnt; //�̱�Ƚ��
	int loseCnt; //��Ƚ��
	int dol; //��(1) or ��(2)
public:
	Player(); //������
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
	Player operator ++(); //�̰����� ����ϱ� ���� ������ ����
	Player operator --(); //������ ����ϱ� ���� ������ ����
};

#endif