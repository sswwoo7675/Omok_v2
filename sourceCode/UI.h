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
	UI(); //생성자
	~UI(); //소멸자
	void gotoxy(int x, int y); //커서이동함수
	template <class T> void gotoxyPrint(int x, int y, T text); //지정 좌표에 text문자 출력 함수
	void printManual();//메뉴얼 출력
	template <class T> void printBox(int x, int y, int width, int height, int color, T text);//박스 모양의 틀 출력
	void clearLine(int x, int y, int n); //라인 클리어
	void run(); //프로그램 실행제어 함수
	void drawPan(); //바둑판을 그리는 함수
	void feildPrint(); //게임 필드 출력
	void nameSettingPrint();//이름 설정란 출력
	void gameClear();//게임 다시시작을 위한 클리어 함수.
	void playGibo(); //기보플레이 함수.
	void removePrintStone(int x, int y); //돌을 지우는 함수
};

#endif