#include "omokData.h"

omokData::omokData() : MyArray(15,15){
	//omokPanData = new MyArray(15, 15);
}

omokData::~omokData() {
	//delete omokPanData;
}

bool omokData::isOkPush(int x, int y) {
	if (retrieve(x, y) == 0) { //���� ������ ���� ���� ���
		return true;  //�� �ڸ��� ���� �� ������ �˸�
	}
	else {
		return false;
	}
}

void omokData::pushStone(int x, int y, int dol) { //�� ���� ��� �Լ�
	store(x, y, dol); //�迭�� ����
}

bool omokData::isWin(int x, int y, int turn) {

	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, start1, start2, start3, start4;

	for (start1 = x, start2 = y; start1 < 14 && start2 > 0; start1++, start2--) {  //�밢�� ���� Ž���� ���� �ʱ���ġ ��������
	}
	for (start3 = x, start4 = y; start3 > 0 && start4 > 0; start3--, start4--) {	//�밢�� ���� Ž���� ���� �ʱ���ġ ��������
	}

	if (turn == 1) { //�� �����ϰ��
		for (int i = 0; i < 15; i++) {     //���� ���� ���� �������� ���ο�, ���� Ž��
			if (retrieve(i, y) == 0 || retrieve(i, y) == 2) {  //(���ι���)Ž������ ���� ������ ���� �ʰų� �鵹�� ������ �������
				cnt1 = 0; //ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt1++;
			}
			if (retrieve(x, i) == 0 || retrieve(x, i) == 2) { //(���ι���)Ž������ ���� ������ ���� �ʰų� �鵹�� ������ �������
				cnt2 = 0; //ī��Ʈ�� �ʱ�ȭ��
			}
			else {
				cnt2++;
			}
			if (cnt1 == 5 || cnt2 == 5) {      //����, ���ι��� Ž���� �� 5���� �������� ���� ��
				return true;  //1�� ��ȯ�ϰ� �Լ��� ����
			}
		}
		for (int i = start1, j = start2; i > -1 && j < 15; i--, j++) {//�밢�� ���� Ž�� 1
			if (retrieve(i, j) == 0 || retrieve(i, j) == 2) { //(�밢������1)Ž������ ���� ������ ���� �ʰų� �鵹�� ������ �������
				cnt3 = 0; //ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt3++;
			}
			if (cnt3 == 5) {    //�� 5���� �������� �������
				return true;   //1��ȯ�� ����
			}
		}
		for (int i = start3, j = start4; i < 15 && j < 15; i++, j++) {//�밢�� ���� Ž�� 2
			if (retrieve(i, j) == 0 || retrieve(i, j) == 2) { //(�밢������2)Ž������ ���� ������ ���� �ʰų� �鵹�� ������ �������
				cnt4 = 0; //ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt4++;
			}
			if (cnt4 == 5) {    //�� 5���� �������� �������
				return true;   //1��ȯ�� ����
			}
		}
	}
	else if (turn == 2) {  //�� �����ϰ��
		for (int i = 0; i < 15; i++) {     //���� ���� ���� �������� ���ο�, ���� Ž��
			if (retrieve(i, y) == 0 || retrieve(i, y) == 1) {       //(���ι���)Ž������ ���� ������ ���� �ʰų� �浹�� ������ �������
				cnt1 = 0;	//ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt1++;
			}
			if (retrieve(x, i) == 0 || retrieve(x, i) == 1) { //(���ι���)Ž������ ���� ������ ���� �ʰų� �浹�� ������ �������
				cnt2 = 0; //ī��Ʈ�� �ʱ�ȭ��
			}
			else {
				cnt2++;
			}
			if (cnt1 == 5 || cnt2 == 5) {       //����, ���ι��� Ž���� �� 5���� �������� ���� ��
				return true;						//1�� ��ȯ�ϰ� �Լ��� ����
			}
		}
		for (int i = start1, j = start2; i > -1 && j < 15; i--, j++) {//�밢�� ���� Ž�� 1
			if (retrieve(i, j) == 0 || retrieve(i, j) == 1) { //(�밢������1)Ž������ ���� ������ ���� �ʰų� �浹�� ������ �������
				cnt3 = 0; //ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt3++;
			}
			if (cnt3 == 5) {    //�� 5���� �������� �������
				return true;   //1��ȯ�� ����
			}
		}
		for (int i = start3, j = start4; i < 15 && j < 15; i++, j++) {//�밢�� ���� Ž�� 2
			if (retrieve(i, j) == 0 || retrieve(i, j) == 1) { //(�밢������2)Ž������ ���� ������ ���� �ʰų� �浹�� ������ �������
				cnt4 = 0; //ī��Ʈ�� �ʱ�ȭ��.
			}
			else {
				cnt4++;
			}
			if (cnt4 == 5) {    //�� 5���� �������� �������
				return true;   //1��ȯ�� ����
			}
		}
	}
	return false;
}