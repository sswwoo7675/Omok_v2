#include "Player.h"

Player::Player() {
	x = 7;
	y = 7; //기본 좌표는 7
	winCnt = 0;
	loseCnt = 0;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

void Player::setX(int n) {
	x = n;
}

void Player::setY(int n) {
	y = n;
}

int Player::getDol()
{
	return dol;
}

string Player::getName()
{
	return name;
}

void Player::setDol(int dol)
{
	this->dol = dol;
}

void Player::setName(string name)
{
	this->name = name;
}

int Player::getWinCnt()
{
	return winCnt;
}

int Player::getLoseCnt()
{
	return loseCnt;
}

void Player::move_xy(char key)
{
	if (key == 75) {    //←키 입력
		if (x != 0) {
			x--;
		}
	}
	else if (key == 77) { //→키 입력
		if (x != 14) {
			x++;
		}
	}
	else if (key == 72) { //↑키 입력
		if (y != 0) {
			y--;
		}
	}
	else if (key == 80) { //↓키 입력
		if (y != 14) {
			y++;
		}
	}
}

Player Player::operator ++() {
	winCnt++;
	if (dol == 1) { //돌을 바꾸는 과정
		dol = 2;
	}
	else {
		dol = 1;
	}
	x = 7;  //좌표 초기화
	y = 7;
	return (*this);
}

Player Player::operator --() {
	loseCnt++;
	if (dol == 1) { //돌을 바꾸는 과정
		dol = 2;
	}
	else {
		dol = 1;
	}
	x = 7;  //좌표 초기화
	y = 7;
	return (*this);
}