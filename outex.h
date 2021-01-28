#pragma once

bool hinit();

enum {COL_BLACK=0,COL_RED,COL_GREEN,COL_YELLOW,
	  COL_BLUE,COL_PURPLE,COL_CYAN,COL_WHITE};
#define cls printf("\033[2J")

void outch(char ch, int x, int y, int textcol=7, int bgcol=0);
