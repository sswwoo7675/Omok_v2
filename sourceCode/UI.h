#define RED            (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define GREEN         (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define BLUE         (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PURPLE         (RED | BLUE)
#define WHITE         (RED | GREEN | BLUE)
#define YELLOW         (RED | GREEN)
#define SKYBLUE         (GREEN | BLUE)

#define BG_RED         (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_GREEN      (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_BLUE         (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_PURPLE      (BG_RED | BG_BLUE)
#define BG_WHITE      (BG_RED | BG_GREEN | BG_BLUE)
#define BG_YELLOW      (BG_RED | BG_GREEN)
#define BG_SKYBLUE      (BG_GREEN | BG_BLUE)

#include "omokData.h"
#include "Player.h"
#include "Replay.h"

#ifndef UI_H
#define UI_H

class UI {
private:
	omokData* data;
	Player* Players;
	Replay* replays;
	int whoTurn;
public:
	UI(); //������
	~UI(); //�Ҹ���
	void gotoxy(int x, int y); //Ŀ���̵��Լ�
	template <class T> void gotoxyPrint(int x, int y, T text); //���� ��ǥ�� text���� ��� �Լ�
	void printManual();//�޴��� ���
	template <class T> void printBox(int x, int y, int width, int height, int color, T text);//�ڽ� ����� Ʋ ���
	void clearLine(int x, int y, int n); //���� Ŭ����
	void run(); //���α׷� �������� �Լ�
	void drawPan(); //�ٵ����� �׸��� �Լ�
	void feildPrint(); //���� �ʵ� ���
	void nameSettingPrint();//�̸� ������ ���
	void gameClear();//���� �ٽý����� ���� Ŭ���� �Լ�.
	void playGibo(); //�⺸�÷��� �Լ�.
	void removePrintStone(int x, int y); //���� ����� �Լ�
};

#endif