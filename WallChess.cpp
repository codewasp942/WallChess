/*
https://github.com/codewasp942/
*/


#include <iostream>
#include"position.h"
#include <windows.h>
using namespace std;

bool mp[3][109][109];
int xw = 7, yw = 7;

int main(){

	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	if (hout == INVALID_HANDLE_VALUE) {
		MessageBox(HWND_DESKTOP, TEXT("Error"), TEXT("The consle can be only black-white."));
	}

	pos p1(1, 1),p2(xw, yw);
}