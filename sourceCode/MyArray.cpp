/**********************************************
���� �̸� : MyArray.cpp
���� ��� : 2���� �迭�� ��Ÿ���� Ŭ����
**********************************************/

#include "MyArray.h"


MyArray::MyArray(int x, int y) {
	mdata = new int*[y];
	for (int i = 0; i < y; i++) {
		mdata[i] = new int[x];
		for (int j = 0; j < x; j++) {
			mdata[i][j] = 0;
		}
	}
	sizeX = x;
	sizeY = y;
}

MyArray::~MyArray()
{
	for (int i = 0; i < sizeY; i++) {
		delete[]mdata[i];
	}
	delete[]mdata;
}

int MyArray::retrieve(int x, int y)
{
	return mdata[x][y];
}

void MyArray::store(int x, int y, int item) {
	mdata[x][y] = item;
}