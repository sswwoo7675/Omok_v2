
#include "UI.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

UI::UI()
{
	data = new omokData();
	Players = new Player[2];
	replays = new Replay();
	srand((unsigned)time(0));
	int rnd = rand() % 2 + 1;
	Players[0].setDol(rnd);	Players[1].setDol(3 - rnd); //흑과 백을 랜덤으로 설정함
	for (int i = 0; i < 2; i++) { //오목에서 흑돌이 가장먼저 시작하므로 흑돌인 플레이어를 찾는 과정
		if (Players[i].getDol() == 1) {
			whoTurn = i;
			break;
		}
	}
}

UI::~UI()
{
	delete data;
}

void UI::gotoxy(int x, int y) {
	x = 2 * x;
	COORD Pos = { x ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

template <class T> void UI::gotoxyPrint(int x, int y, T text) {
	gotoxy(x, y);
	cout << text;
}

template <class T> void UI::printBox(int x, int y, int width, int height, int color, T text) { //상자 모양을 그려주는 함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //색상을 지정
	gotoxy(x, y);
	for (int i = 0; i < width; i++) cout << text;
	cout << endl;
	for (int i = 0; i < height - 2; i++) {
		y++;
		gotoxy(x, y);
		cout << text;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		for (int j = 0; j < width - 2; j++) cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << text << endl;
	}
	y++;
	gotoxy(x, y);
	for (int i = 0; i < width; i++) cout << text;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void UI::printManual() {
	system("mode con:cols=120 lines=30");
	printBox(10, 10, 39, 11, BG_WHITE, "●");
	gotoxyPrint(23, 12, "오목게임 (made by seo)");
	gotoxyPrint(17, 14, "조작방법 : →(오른쪽으로이동)\t ←(왼쪽으로이동)");
	gotoxyPrint(22, 15, "↑(위로이동)\t↓(아래로이동)\n");
	gotoxyPrint(22, 16, "스페이스(바둑돌놓기)\n");
	gotoxyPrint(19, 18, "Enter키를 입력하시면 게임이 시작됩니다..");
	gotoxy(1, 29);
}

void UI::clearLine(int x, int y, int n) {
	gotoxy(x, y);
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}
}

void UI::drawPan() {
	cout << "┌";
	for (int i = 0; i < 13; i++) {
		cout << "┬";
	}
	cout << "┐\n";
	for (int i = 0; i < 13; i++) {
		cout << "├";
		for (int j = 0; j < 13; j++) {
			cout << "┼";
		}
		cout << "┤\n";
	}
	cout << "└";
	for (int i = 0; i < 13; i++) {
		cout << "┴";
	}
	cout << "┘\n";
}

void UI::feildPrint() {
	system("mode con:cols=85 lines=30");
	drawPan(); //바둑판을 그림.
	printBox(1, 20, 41, 9, BG_WHITE, "●");  //오목 시스템 박스
	printBox(18, 1, 20, 8, BG_WHITE, "  ");  // P1 박스
	printBox(18, 11, 20, 8, BG_WHITE, "  "); // P2 박스
	gotoxyPrint(3, 20, " Omok System ");
	gotoxyPrint(21, 1, " Player1 ");
	gotoxyPrint(21, 11, " Player2 ");
	gotoxyPrint(3, 22, "현재 순서는 ");
	gotoxyPrint(3, 24, "System Notice : ");
	gotoxyPrint(3, 26, "Control : ");
	gotoxyPrint(8, 26, "(SPACE) 돌놓기, (방향키) 위치조종, (esc) 게임종료");
	gotoxyPrint(20, 3, "USER NAME :");
	cout << Players[0].getName();

	gotoxyPrint(20, 4, "승리 횟수 : ");
	cout << Players[0].getWinCnt();

	gotoxyPrint(20, 5, "패배 횟수 : ");
	cout << Players[0].getLoseCnt();

	gotoxyPrint(20, 6, "Stone :");
	if (Players[0].getDol() == 1)
		cout << "○";
	else
		cout << "●";

	gotoxyPrint(20, 13, "USER NAME :");
	cout << Players[1].getName();

	gotoxyPrint(20, 14, "승리 횟수 : ");
	cout << Players[1].getWinCnt();

	gotoxyPrint(20, 15, "패배 횟수 : ");
	cout << Players[1].getLoseCnt();

	gotoxyPrint(20, 16, "Stone :");
	if (Players[1].getDol() == 1)
		cout << "○";
	else
		cout << "●";
}

void UI::nameSettingPrint() {
	system("mode con:cols=73 lines=30");
	string name;
	system("cls");  //화면 초기화후
	gotoxyPrint(8, 11, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
	gotoxyPrint(8, 15, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
	gotoxyPrint(11, 12, "Player1의 이름을 설정하세요.");
	gotoxy(15, 14);
	cin >> name;
	Players[0].setName(name);

	system("cls");  //화면 초기화후
	gotoxyPrint(8, 11, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
	gotoxyPrint(8, 15, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
	gotoxyPrint(11, 12, "Player2의 이름을 설정하세요.");
	gotoxy(15, 14);
	cin >> name;
	Players[1].setName(name);
}

void UI::gameClear()
{
	system("cls");  //화면 초기화
	data = new omokData();
	replays = new Replay();
	++Players[whoTurn];
	int oth = whoTurn + 1;
	oth = oth % 2;
	--Players[oth];
	for (int i = 0; i < 2; i++) { //오목에서 흑돌이 가장먼저 시작하므로 흑돌인 플레이어를 찾는 과정
		if (Players[i].getDol() == 1) {
			whoTurn = i;
			break;
		}
	}
	feildPrint(); //필드를 새로 그림

}

void UI::removePrintStone(int x, int y)
{
	if (x == 0 && y == 0) {
		gotoxyPrint(0, 0, "┌");
	}
	else if (x == 14 && y == 0) {
		gotoxyPrint(14, 0, "┐");
	}
	else if (x == 0 && y == 14) {
		gotoxyPrint(0, 14, "└");
	}
	else if (x == 14 && y == 14) {
		gotoxyPrint(14, 14, "┘");
	}
	else if ((x > 0 || x < 14) && y == 0) {
		gotoxyPrint(x, y, "┬");
	}
	else if ((x > 0 || x < 14) && y == 14) {
		gotoxyPrint(x, y, "┴");
	}
	else if ((y > 0 || y < 14) && x == 0) {
		gotoxyPrint(x, y, "├");
	}
	else if ((y > 0 || y < 14) && x == 14) {
		gotoxyPrint(x, y, "┤");
	}
	else {
		gotoxyPrint(x, y, "┼");
	}
}

void UI::playGibo()
{
	replays->setit();
	system("cls");  //화면 초기화
	feildPrint();
	clearLine(8, 26, 29);	gotoxyPrint(8, 26, "(←) undo, (→) next, (esc) replay종료");
	clearLine(3, 22, 29);	gotoxyPrint(3, 22, "REPLAY 모드입니다.");
	while (1)
	{
		char key = getch();
		if (key == 77) { 
			stone tmp = replays->get();
			if (tmp.state == 0) { //데이터가 없을시
				clearLine(11, 24, 29);
				gotoxyPrint(11, 24, "더 이상의 데이터가 없습니다.");
			}
			else {
				gotoxyPrint(tmp.x, tmp.y, tmp.shape);
				replays->next();
				clearLine(11, 24, 29);
			}
		}
		else if (key == 75) {
			if (replays->undo()) {
				clearLine(11, 24, 29);
				stone tmp = replays->get();
				removePrintStone(tmp.x, tmp.y);
			}
			else {
				clearLine(11, 24, 29);
				gotoxyPrint(11, 24, "더 이상의 데이터가 없습니다.");
			}
		}
		else if (key == 27) {
			return;
		}
		else {
		}
	}
}

void UI::run() {
	printManual(); //메뉴얼 출력
	char ch = getch();
	if (ch == 13)    //엔터를 입력시
	{
		nameSettingPrint(); //이름 셋팅
		system("cls");  //화면 초기화후
		feildPrint();     //게임 필드를 그리는 함수.
		while (1)
		{
			gotoxyPrint(9, 22, Players[whoTurn].getName());
			cout << " 차례 입니다.             ";
			gotoxy(Players[whoTurn].getX(), Players[whoTurn].getY());
			char key = getch();
			if (key == 75 || key == 77 || key == 72 || key == 80) //방향키 입력시
			{
				Players[whoTurn].move_xy(key);
			}
			else if (key == 27)
			{
				return;
			}
			else if (key == 32)
			{
				if (data->isOkPush(Players[whoTurn].getX(), Players[whoTurn].getY()))
				{ //그 곳에 돌이 놓여져 있는지 검사.
					data->pushStone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol()); //돌을 놓음.

					if (Players[whoTurn].getDol() == 1)
					{ //흑 순서이면
						gotoxyPrint(Players[whoTurn].getX(), Players[whoTurn].getY(), "○"); //흑돌 출력
						replays->addStonelist(new stone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol(), "○")); //리플레이를 위한 데이터 저장
					}
					else
					{
						gotoxyPrint(Players[whoTurn].getX(), Players[whoTurn].getY(), "●"); //백돌 출력
						replays->addStonelist(new stone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol(), "●")); //리플레이를 위한 데이터 저장
					}

					if (data->isWin(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol())) //만약에 승리가 결정나면
					{
						
						clearLine(11, 24, 29);	gotoxyPrint(11, 24, Players[whoTurn].getName() + " 승리!!. 무엇을 하시겠습니까?");
						clearLine(8, 26, 29);	gotoxyPrint(8, 26, "(y) 다시하기, (esc) 종료 (a) Replay");
						bool token = false;
						do
						{
							key = getch();
							switch (key)
							{
							case 89:
							case 121: //y키
								delete data;
								delete replays;
								gameClear();
								token = true;
								break;

							case 27://ese키
								return;

							case 65:
							case 97://기보보기
								token = false;
								playGibo();
								clearLine(11, 24, 29);
								clearLine(8, 26, 29);
								gotoxyPrint(11, 24, Players[whoTurn].getName() + " 승리!!. 무엇을 하시겠습니까?");
								gotoxyPrint(8, 26, "(y) 다시하기, (esc) 종료 (a) Replay");
								break;

							default:
								clearLine(11, 24, 29);
								gotoxyPrint(11, 24, "잘못 눌렀습니다. 다시 눌러주십시오.");
								break;
							}
						} while (token == false);

					}
					else {
						whoTurn++;	whoTurn = whoTurn % 2; //다음 차례로 변경
						clearLine(11, 24, 29);
					}
				}
				else
				{
					gotoxyPrint(11, 24, "[ERROR]그 곳엔 돌을 놓을 수 없습니다 다른곳에 놓으십시오.");
				}
			}
		}
	}
}