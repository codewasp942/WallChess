#include"position.h"
using namespace std;

pos::pos(int _x, int _y) {
	x = _x;y = _y;
}

pos::pos() {
	x = y = 1;
}

void pos::clp(int minx, int maxx, int miny, int maxy) {
	if (x < minx)x = minx;
	if (x > maxx)x = maxx;
	if (y < miny)y = miny;
	if (y > maxy)y = maxy;
}

pos pos::operator[](int d) {
	pos ot;
	switch (d) {
	case 0: {
		ot.x--;
	}
	case 1: {
		ot.y--;
	}
	case 2: {
		ot.x++;
	}
	case 3: {
		ot.y++;
	}
	}
	return ot;
}