#pragma once

class pos
{
public:
	pos();
	pos(int, int);

	void clp(int, int, int, int);
	pos operator[](int);

	int x, y;
};