#include "stone.h"
#include <vector>

using namespace std;

#ifndef REPLAY_H
#define REPLAY_H
class Replay {
	vector<stone> stonelist;
	vector<stone>::iterator it;
public:
	void addStonelist(stone* stone);
	void next();
	bool undo();
	stone get();
	void setit();
};

#endif
