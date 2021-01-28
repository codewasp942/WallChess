#include"outex.h"
#include<windows.h>
#include<cstdio>

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