#include "ioex.h"
#include <windows.h>
#include <cstdio>
#include <conio.h>

HANDLE hout;

bool hinit() {
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    return hout != INVALID_HANDLE_VALUE;
}

void outch(char ch, int x, int y, int textcol, int bgcol) {
    COORD coord = { y, x };
    SetConsoleCursorPosition(hout, coord);
    char buffer[1009];
    sprintf(buffer, "\033[%d;%dm%c\033[0m", 30 + textcol, 40 + bgcol, ch);
    printf("%s", buffer);
}

int getk() {
	char ch = _getch();
	switch (ch) {
		case 119:case 72: { //ÉÏ¼ü
			return 0;
			break;
		}
		case 97:case 75: { //×ó¼ü
			return 1;
			break;
		}
		case 115:case 80: { //ÏÂ¼ü
			return 2;
			break;
		}
		case 100:case 77: { // ÓÒ¼ü
			return 3;
			break;
		}
		case 32: {
			return 50;
			break;
		}
		default: {
			return -1;
			break;
		}
	}
}