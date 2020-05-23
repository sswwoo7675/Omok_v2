#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
private:
	int** mdata;
	int sizeX;
	int sizeY;
public:
	MyArray(int x, int y);
	~MyArray();
	int retrieve(int x, int y);
	void store(int x, int y, int item);
};

#endif // !