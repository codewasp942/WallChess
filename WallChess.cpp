/*
https://github.com/codewasp942/WallChess
Visual Studio 2019 on windows
*/


#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cmath>
#include "position.h"
#include "outex.h"

using namespace std;

bool mp[3][109][109];		//某位置是否有墙
int xw = 7, yw = 7;			//棋盘宽度、高度

int main(){

	if (!hinit()) {
		MessageBox(HWND_DESKTOP, TEXT("无法获取标准输出句柄"), TEXT("运行错误"),MB_OK);
		return 5201314;
	}

	pos p1(1, 1),p2(xw, yw);
	for(int i=1;i<=60;i++)outch('o',i,sin(i/5.0)*10+10,COL_BLACK,COL_BLUE);
	return 0;
}