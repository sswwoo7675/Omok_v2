#include "MyArray.h"

#ifndef OMOKDATA_H
#define OMOKDATA_H

class omokData : public MyArray{
public:
	omokData();
	~omokData();
	bool isOkPush(int x, int y); //���� ������ �ִ��� Ȯ���ϴ� �Լ�
	void pushStone(int x, int y, int Dol); //x,y��ġ�� ���� ����
	bool isWin(int x, int y, int turn); //�¸�����
};

#endif