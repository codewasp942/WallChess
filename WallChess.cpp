/*
https://github.com/codewasp942/WallChess
Visual Studio 2019
*/


#include <iostream>
#include"position.h"
#include <windows.h>
using namespace std;

bool mp[3][109][109];		//某位置是否有墙
int xw = 7, yw = 7;			//棋盘宽度、高度

int main(){

	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	if (hout == INVALID_HANDLE_VALUE) {
		MessageBox(HWND_DESKTOP,
			TEXT("尴尬了，无法获取输出句柄。"),
			TEXT("运行错误"),
			MB_ICONWARNING | MB_OK);
		return 5201314;
	}

	pos p1(1, 1),p2(xw, yw);
	return 0;
}