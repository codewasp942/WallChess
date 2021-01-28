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
#include "ioex.h"
#include "dfs.h"
#include "qipan.h"

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
	
	while (1) {
		int akey = getk();
		while (akey != 32) {
			if (0 <= akey && akey <= 3) {
				p1 = akey;
			}
			akey = getk();
		}
	}
	dfs(cmove, mp, xw, yw, p1, p2, 3);
	for (int i = 1;i <= xw;i++) {
		for (int j = 1;j <= yw;j++) {
			printf("%d", cmove[i][j]);
		}
		printf("\n");
	}

	return 0;
}