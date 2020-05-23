#include "Replay.h"

void Replay::addStonelist(stone* stone) {
	stonelist.push_back(*stone);
	it = stonelist.begin();
}

void Replay::next() {
	it++;
}

bool Replay::undo() {
	if (it == stonelist.begin()) {
		return false;
	}
	else {
		it--;
		return true;
	}

}

void Replay::setit()
{
	it = stonelist.begin();
}

stone Replay::get() {
	if (it == stonelist.end())
	{
		stone retstone(0,0,0,"x");
		return retstone;
	}
	else
	{
		return *it;
	}
}