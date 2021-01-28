/*
https://github.com/codewasp942/WallChess
Visual Studio 2019 on windows
*/


#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cmath>
#include <conio.h>
#include "position.h"
#include "outex.h"

using namespace std;

bool mp[3][109][109];		//某位置是否有墙
bool cmove[109][109];		//是否可达
bool keys[300];				//键盘状态
int xw = 7, yw = 7;			//棋盘宽度、高度

int main(){

	if (!hinit()) {
		MessageBox(HWND_DESKTOP, TEXT("无法获取标准输出句柄"), TEXT("运行错误"),MB_OK);
		return 5201314;
	}

	pos p1(1, 1),p2(xw, yw);
	char ch;
	
	while (1) {
		ch = getchar();
		printf("\033[2J");
		cout << (int)ch;
	}

	return 0;
}