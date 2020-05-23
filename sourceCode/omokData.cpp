#include "omokData.h"

omokData::omokData() : MyArray(15,15){
	//omokPanData = new MyArray(15, 15);
}

omokData::~omokData() {
	//delete omokPanData;
}

bool omokData::isOkPush(int x, int y) {
	if (retrieve(x, y) == 0) { //돌이 놓여져 있지 않은 경우
		return true;  //이 자리에 놓을 수 있음을 알림
	}
	else {
		return false;
	}
}

void omokData::pushStone(int x, int y, int dol) { //돌 놓는 기능 함수
	store(x, y, dol); //배열에 저장
}

bool omokData::isWin(int x, int y, int turn) {

	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, start1, start2, start3, start4;

	for (start1 = x, start2 = y; start1 < 14 && start2 > 0; start1++, start2--) {  //대각선 방향 탐색을 위한 초기위치 설정과정
	}
	for (start3 = x, start4 = y; start3 > 0 && start4 > 0; start3--, start4--) {	//대각선 방향 탐색을 위한 초기위치 설정과정
	}

	if (turn == 1) { //흑 차례일경우
		for (int i = 0; i < 15; i++) {     //현재 돌이 놓인 기점으로 가로와, 세로 탐색
			if (retrieve(i, y) == 0 || retrieve(i, y) == 2) {  //(가로방향)탐색도중 돌이 놓여져 있지 않거나 백돌이 놓여져 있을경우
				cnt1 = 0; //카운트를 초기화함.
			}
			else {
				cnt1++;
			}
			if (retrieve(x, i) == 0 || retrieve(x, i) == 2) { //(세로방향)탐색도중 돌이 놓여져 있지 않거나 백돌이 놓여져 있을경우
				cnt2 = 0; //카운트를 초기화함
			}
			else {
				cnt2++;
			}
			if (cnt1 == 5 || cnt2 == 5) {      //가로, 세로방향 탐색중 돌 5개가 연속으로 있을 때
				return true;  //1을 반환하고 함수를 종료
			}
		}
		for (int i = start1, j = start2; i > -1 && j < 15; i--, j++) {//대각선 방향 탐색 1
			if (retrieve(i, j) == 0 || retrieve(i, j) == 2) { //(대각선방향1)탐색도중 돌이 놓여져 있지 않거나 백돌이 놓여져 있을경우
				cnt3 = 0; //카운트를 초기화함.
			}
			else {
				cnt3++;
			}
			if (cnt3 == 5) {    //돌 5개가 연속으로 있을경우
				return true;   //1반환후 종료
			}
		}
		for (int i = start3, j = start4; i < 15 && j < 15; i++, j++) {//대각선 방향 탐색 2
			if (retrieve(i, j) == 0 || retrieve(i, j) == 2) { //(대각선방향2)탐색도중 돌이 놓여져 있지 않거나 백돌이 놓여져 있을경우
				cnt4 = 0; //카운트를 초기화함.
			}
			else {
				cnt4++;
			}
			if (cnt4 == 5) {    //돌 5개가 연속으로 있을경우
				return true;   //1반환후 종료
			}
		}
	}
	else if (turn == 2) {  //백 순서일경우
		for (int i = 0; i < 15; i++) {     //현재 돌이 놓인 기점으로 가로와, 세로 탐색
			if (retrieve(i, y) == 0 || retrieve(i, y) == 1) {       //(가로방향)탐색도중 돌이 놓여져 있지 않거나 흑돌이 놓여져 있을경우
				cnt1 = 0;	//카운트를 초기화함.
			}
			else {
				cnt1++;
			}
			if (retrieve(x, i) == 0 || retrieve(x, i) == 1) { //(세로방향)탐색도중 돌이 놓여져 있지 않거나 흑돌이 놓여져 있을경우
				cnt2 = 0; //카운트를 초기화함
			}
			else {
				cnt2++;
			}
			if (cnt1 == 5 || cnt2 == 5) {       //가로, 세로방향 탐색중 돌 5개가 연속으로 있을 때
				return true;						//1을 반환하고 함수를 종료
			}
		}
		for (int i = start1, j = start2; i > -1 && j < 15; i--, j++) {//대각선 방향 탐색 1
			if (retrieve(i, j) == 0 || retrieve(i, j) == 1) { //(대각선방향1)탐색도중 돌이 놓여져 있지 않거나 흑돌이 놓여져 있을경우
				cnt3 = 0; //카운트를 초기화함.
			}
			else {
				cnt3++;
			}
			if (cnt3 == 5) {    //돌 5개가 연속으로 있을경우
				return true;   //1반환후 종료
			}
		}
		for (int i = start3, j = start4; i < 15 && j < 15; i++, j++) {//대각선 방향 탐색 2
			if (retrieve(i, j) == 0 || retrieve(i, j) == 1) { //(대각선방향2)탐색도중 돌이 놓여져 있지 않거나 흑돌이 놓여져 있을경우
				cnt4 = 0; //카운트를 초기화함.
			}
			else {
				cnt4++;
			}
			if (cnt4 == 5) {    //돌 5개가 연속으로 있을경우
				return true;   //1반환후 종료
			}
		}
	}
	return false;
}