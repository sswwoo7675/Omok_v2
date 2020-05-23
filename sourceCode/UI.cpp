
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
	Players[0].setDol(rnd);	Players[1].setDol(3 - rnd); //��� ���� �������� ������
	for (int i = 0; i < 2; i++) { //���񿡼� �浹�� ������� �����ϹǷ� �浹�� �÷��̾ ã�� ����
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

template <class T> void UI::printBox(int x, int y, int width, int height, int color, T text) { //���� ����� �׷��ִ� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //������ ����
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
	printBox(10, 10, 39, 11, BG_WHITE, "��");
	gotoxyPrint(23, 12, "������� (made by seo)");
	gotoxyPrint(17, 14, "���۹�� : ��(�����������̵�)\t ��(���������̵�)");
	gotoxyPrint(22, 15, "��(�����̵�)\t��(�Ʒ����̵�)\n");
	gotoxyPrint(22, 16, "�����̽�(�ٵϵ�����)\n");
	gotoxyPrint(19, 18, "EnterŰ�� �Է��Ͻø� ������ ���۵˴ϴ�..");
	gotoxy(1, 29);
}

void UI::clearLine(int x, int y, int n) {
	gotoxy(x, y);
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}
}

void UI::drawPan() {
	cout << "��";
	for (int i = 0; i < 13; i++) {
		cout << "��";
	}
	cout << "��\n";
	for (int i = 0; i < 13; i++) {
		cout << "��";
		for (int j = 0; j < 13; j++) {
			cout << "��";
		}
		cout << "��\n";
	}
	cout << "��";
	for (int i = 0; i < 13; i++) {
		cout << "��";
	}
	cout << "��\n";
}

void UI::feildPrint() {
	system("mode con:cols=85 lines=30");
	drawPan(); //�ٵ����� �׸�.
	printBox(1, 20, 41, 9, BG_WHITE, "��");  //���� �ý��� �ڽ�
	printBox(18, 1, 20, 8, BG_WHITE, "  ");  // P1 �ڽ�
	printBox(18, 11, 20, 8, BG_WHITE, "  "); // P2 �ڽ�
	gotoxyPrint(3, 20, " Omok System ");
	gotoxyPrint(21, 1, " Player1 ");
	gotoxyPrint(21, 11, " Player2 ");
	gotoxyPrint(3, 22, "���� ������ ");
	gotoxyPrint(3, 24, "System Notice : ");
	gotoxyPrint(3, 26, "Control : ");
	gotoxyPrint(8, 26, "(SPACE) ������, (����Ű) ��ġ����, (esc) ��������");
	gotoxyPrint(20, 3, "USER NAME :");
	cout << Players[0].getName();

	gotoxyPrint(20, 4, "�¸� Ƚ�� : ");
	cout << Players[0].getWinCnt();

	gotoxyPrint(20, 5, "�й� Ƚ�� : ");
	cout << Players[0].getLoseCnt();

	gotoxyPrint(20, 6, "Stone :");
	if (Players[0].getDol() == 1)
		cout << "��";
	else
		cout << "��";

	gotoxyPrint(20, 13, "USER NAME :");
	cout << Players[1].getName();

	gotoxyPrint(20, 14, "�¸� Ƚ�� : ");
	cout << Players[1].getWinCnt();

	gotoxyPrint(20, 15, "�й� Ƚ�� : ");
	cout << Players[1].getLoseCnt();

	gotoxyPrint(20, 16, "Stone :");
	if (Players[1].getDol() == 1)
		cout << "��";
	else
		cout << "��";
}

void UI::nameSettingPrint() {
	system("mode con:cols=73 lines=30");
	string name;
	system("cls");  //ȭ�� �ʱ�ȭ��
	gotoxyPrint(8, 11, "�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
	gotoxyPrint(8, 15, "�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
	gotoxyPrint(11, 12, "Player1�� �̸��� �����ϼ���.");
	gotoxy(15, 14);
	cin >> name;
	Players[0].setName(name);

	system("cls");  //ȭ�� �ʱ�ȭ��
	gotoxyPrint(8, 11, "�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
	gotoxyPrint(8, 15, "�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
	gotoxyPrint(11, 12, "Player2�� �̸��� �����ϼ���.");
	gotoxy(15, 14);
	cin >> name;
	Players[1].setName(name);
}

void UI::gameClear()
{
	system("cls");  //ȭ�� �ʱ�ȭ
	data = new omokData();
	replays = new Replay();
	++Players[whoTurn];
	int oth = whoTurn + 1;
	oth = oth % 2;
	--Players[oth];
	for (int i = 0; i < 2; i++) { //���񿡼� �浹�� ������� �����ϹǷ� �浹�� �÷��̾ ã�� ����
		if (Players[i].getDol() == 1) {
			whoTurn = i;
			break;
		}
	}
	feildPrint(); //�ʵ带 ���� �׸�

}

void UI::removePrintStone(int x, int y)
{
	if (x == 0 && y == 0) {
		gotoxyPrint(0, 0, "��");
	}
	else if (x == 14 && y == 0) {
		gotoxyPrint(14, 0, "��");
	}
	else if (x == 0 && y == 14) {
		gotoxyPrint(0, 14, "��");
	}
	else if (x == 14 && y == 14) {
		gotoxyPrint(14, 14, "��");
	}
	else if ((x > 0 || x < 14) && y == 0) {
		gotoxyPrint(x, y, "��");
	}
	else if ((x > 0 || x < 14) && y == 14) {
		gotoxyPrint(x, y, "��");
	}
	else if ((y > 0 || y < 14) && x == 0) {
		gotoxyPrint(x, y, "��");
	}
	else if ((y > 0 || y < 14) && x == 14) {
		gotoxyPrint(x, y, "��");
	}
	else {
		gotoxyPrint(x, y, "��");
	}
}

void UI::playGibo()
{
	replays->setit();
	system("cls");  //ȭ�� �ʱ�ȭ
	feildPrint();
	clearLine(8, 26, 29);	gotoxyPrint(8, 26, "(��) undo, (��) next, (esc) replay����");
	clearLine(3, 22, 29);	gotoxyPrint(3, 22, "REPLAY ����Դϴ�.");
	while (1)
	{
		char key = getch();
		if (key == 77) { 
			stone tmp = replays->get();
			if (tmp.state == 0) { //�����Ͱ� ������
				clearLine(11, 24, 29);
				gotoxyPrint(11, 24, "�� �̻��� �����Ͱ� �����ϴ�.");
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
				gotoxyPrint(11, 24, "�� �̻��� �����Ͱ� �����ϴ�.");
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
	printManual(); //�޴��� ���
	char ch = getch();
	if (ch == 13)    //���͸� �Է½�
	{
		nameSettingPrint(); //�̸� ����
		system("cls");  //ȭ�� �ʱ�ȭ��
		feildPrint();     //���� �ʵ带 �׸��� �Լ�.
		while (1)
		{
			gotoxyPrint(9, 22, Players[whoTurn].getName());
			cout << " ���� �Դϴ�.             ";
			gotoxy(Players[whoTurn].getX(), Players[whoTurn].getY());
			char key = getch();
			if (key == 75 || key == 77 || key == 72 || key == 80) //����Ű �Է½�
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
				{ //�� ���� ���� ������ �ִ��� �˻�.
					data->pushStone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol()); //���� ����.

					if (Players[whoTurn].getDol() == 1)
					{ //�� �����̸�
						gotoxyPrint(Players[whoTurn].getX(), Players[whoTurn].getY(), "��"); //�浹 ���
						replays->addStonelist(new stone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol(), "��")); //���÷��̸� ���� ������ ����
					}
					else
					{
						gotoxyPrint(Players[whoTurn].getX(), Players[whoTurn].getY(), "��"); //�鵹 ���
						replays->addStonelist(new stone(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol(), "��")); //���÷��̸� ���� ������ ����
					}

					if (data->isWin(Players[whoTurn].getX(), Players[whoTurn].getY(), Players[whoTurn].getDol())) //���࿡ �¸��� ��������
					{
						
						clearLine(11, 24, 29);	gotoxyPrint(11, 24, Players[whoTurn].getName() + " �¸�!!. ������ �Ͻðڽ��ϱ�?");
						clearLine(8, 26, 29);	gotoxyPrint(8, 26, "(y) �ٽ��ϱ�, (esc) ���� (a) Replay");
						bool token = false;
						do
						{
							key = getch();
							switch (key)
							{
							case 89:
							case 121: //yŰ
								delete data;
								delete replays;
								gameClear();
								token = true;
								break;

							case 27://eseŰ
								return;

							case 65:
							case 97://�⺸����
								token = false;
								playGibo();
								clearLine(11, 24, 29);
								clearLine(8, 26, 29);
								gotoxyPrint(11, 24, Players[whoTurn].getName() + " �¸�!!. ������ �Ͻðڽ��ϱ�?");
								gotoxyPrint(8, 26, "(y) �ٽ��ϱ�, (esc) ���� (a) Replay");
								break;

							default:
								clearLine(11, 24, 29);
								gotoxyPrint(11, 24, "�߸� �������ϴ�. �ٽ� �����ֽʽÿ�.");
								break;
							}
						} while (token == false);

					}
					else {
						whoTurn++;	whoTurn = whoTurn % 2; //���� ���ʷ� ����
						clearLine(11, 24, 29);
					}
				}
				else
				{
					gotoxyPrint(11, 24, "[ERROR]�� ���� ���� ���� �� �����ϴ� �ٸ����� �����ʽÿ�.");
				}
			}
		}
	}
}