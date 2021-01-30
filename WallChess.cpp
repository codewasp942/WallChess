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
#define elif(tiaojian) else if(tiaojian)

using namespace std;

bool mp[3][maxxw][maxyw];			//ĳλ���Ƿ���ǽ
bool cmove[maxxw][maxyw];			//�Ƿ�ɴ�
char outm[2*maxxw][2 * maxyw];		//��ͼ���
const int xw = 7, yw = 7;			//���̿�ȡ��߶�
int piy = 2;						//����ǰ�տ�����
pos p1, p2;							//����λ��
HANDLE hout;						//��׼������
FILE* fp;							//C�����ļ��������
int s1, s2;							//��¼������
int wins = 0;						//��¼Ӯ�ң�3��ʾƽ��

inline void outto(pos ps, char(*outm)[218], char ch);
void drawqi(int x,int y);
void draw();
void printhelp();
bool judge();

int main(){

	if ((fp = fopen("help.txt", "r")) == NULL) {
		MessageBox(HWND_DESKTOP, TEXT("�޷��򿪰����ļ�����ȷ��help.txt�ڳ���Ŀ¼��"),
			TEXT("���д���"), MB_OK | MB_ICONERROR);
		return 5201314;
	}
	if (!hinit(hout)) {
		MessageBox(HWND_DESKTOP, TEXT("�޷���ȡ��׼������"),
			TEXT("���д���"),MB_OK | MB_ICONERROR);
		return 5201314;
	}

	while (1) {
		memset(mp, 0, sizeof(mp));
		for (int j = 1;j <= yw;j++) {
			mp[0][1][j] = mp[0][xw + 1][j] = 1;
		}
		for (int i = 1;i <= xw;i++) {
			mp[1][i][1] = mp[1][i][yw + 1] = 1;
		}
		p1.x = p1.y = 1;
		p2.x = xw;p2.y = yw;
		int akey;
		while (1) {
			scan(0, cmove, mp, xw, yw, p1, p2, 3);
			draw();
			akey = getk();
			while (akey != 32) {
				if (0 <= akey && akey <= 3) {
					outto(p1, outm, ' ');
					pos tmp = p1[akey];
					if (!(tmp.x<1 || tmp.x>xw || tmp.y<1 || tmp.y>yw || tmp == p2 || !cmove[tmp.x][tmp.y] || mp[akey % 2][max(tmp.x, p1.x)][max(tmp.y, p1.y)])) {
						p1 = tmp;
					}
					draw();
					Sleep(100);
				}elif(akey == 'i') {
					printhelp();
				}
				akey = getk();
			}
			panduan_p1:
			do { akey = getk(); } while (0 > akey || akey > 3);
			if (akey == 0) {
				if (mp[0][p1.x][p1.y])goto panduan_p1;
				mp[0][p1.x][p1.y] = 1;
			}elif(akey == 1) {
				if (mp[1][p1.x][p1.y])goto panduan_p1;
				mp[1][p1.x][p1.y] = 1;
			}elif(akey == 2) {
				if (mp[0][p1.x + 1][p1.y])goto panduan_p1;
				mp[0][p1.x + 1][p1.y] = 1;
			}elif(akey == 3) {
				if (mp[1][p1.x][p1.y + 1])goto panduan_p1;
				mp[1][p1.x][p1.y + 1] = 1;
			}
			scan(0, cmove, mp, xw, yw, p2, p1, 3);
			draw();

			if (!judge()) {
				break;
			}

			scan(0, cmove, mp, xw, yw, p2, p1, 3);
			draw();
			akey = getk();
			while (akey != 32) {
				if (0 <= akey && akey <= 3) {
					outto(p1, outm, ' ');
					pos tmp = p2[akey];
					if (!(tmp.x<1 || tmp.x>xw || tmp.y<1 || tmp.y>yw || tmp == p1 || !cmove[tmp.x][tmp.y] || mp[akey % 2][max(tmp.x, p2.x)][max(tmp.y, p2.y)])) {
						p2 = tmp;
					}
					draw();
					Sleep(100);
				}elif(akey == 'i') {
					printhelp();
				}
				akey = getk();
			}
			panduan_p2:
			do { akey = getk(); } while (0 > akey || akey > 3);
			if (akey == 0) {
				if (mp[0][p2.x][p2.y])goto panduan_p2;
				mp[0][p2.x][p2.y] = 1;
			}elif(akey == 1) {
				if (mp[1][p2.x][p2.y])goto panduan_p2;
				mp[1][p2.x][p2.y] = 1;
			}elif(akey == 2) {
				if (mp[0][p2.x + 1][p2.y])goto panduan_p2;
				mp[0][p2.x + 1][p2.y] = 1;
			}elif(akey == 3) {
				if (mp[1][p2.x][p2.y + 1])goto panduan_p2;
				mp[1][p2.x][p2.y + 1] = 1;
			}
			scan(0, cmove, mp, xw, yw, p2, p1, 3);
			draw();

			if (!judge()) {
				break;
			}
		}
		system("cls");
		if (s1 > s2) {
			puts(">>> >>>  Red wins !!! <<< <<<");
		}elif(s1 < s2) {
			puts(">>> >>> Blue wins !!! <<< <<<");
		}elif(s1 == s2) {
			puts(">>> >>> -+-+ Tie +-+- <<< <<<");
		}
		printf("\n\n");
		printf("          %2d ",s1);
		outch(':', COL_RED, COL_BLACK);
		printf(" %2d\n\n\n\n",s2);
		system("pause");
	}

	CloseHandle(hout);
	return 0;
}

inline void outto(pos ps, char(*outm)[218], char ch) {
	outm[calx(ps.x) + 1][caly(ps.y) + 1] = ch;
	outm[calx(ps.x) + 1][caly(ps.y) + 2] = ch;
}

void drawqi() {
	for (int i = 1;i <= xw + 1;i++) {
		for (int j = 1;j <= yw + 1;j++) {
			outm[calx(i)][caly(j)] = '#';
		}
	}
	for (int i = 1;i <= xw; i++){
		for (int j = 1;j <= yw; j++) {
			if (cmove[i][j]) {
				outto(pos(i, j), outm, '-');
			}
		}
	}
	for (int i = 1;i <= xw + 1; i++) {
		for (int j = 1;j <= yw + 1; j++) {
			if (mp[0][i][j]) {
				outm[calx(i)][caly(j) + 1] = '=';
				outm[calx(i)][caly(j) + 2] = '=';
			}
			if (mp[1][i][j]) {
				outm[calx(i) + 1][caly(j)] = '=';
			}
		}
	}
	outto(p1, outm, '1');
	outto(p2, outm, '2');
}

void draw() {
	system("cls");
	puts(">->-> The WallChess <-<-<");
	puts("$ press i to find help...");
	for (int i = 1;i <= calx(xw + 1);i++) {
		for (int j = 1;j <= caly(yw + 1);j++) {
			outm[i][j] = ' ';
		}
	}
	drawqi();
	for (int i = 1;i <= calx(xw+1);i++){
		for (int j = 1;j <= piy;j++) {
			printf(" ");
		}
		for (int j = 1;j <= caly(yw+1);j++) {
			if (outm[i][j] == ' ')	putchar(' ');
			elif(outm[i][j] == '1')	outch(' ', COL_RED, COL_RED);
			elif(outm[i][j] == '2')	outch(' ', COL_BLUE, COL_BLUE);
			elif(outm[i][j] == '#')	outch('#', COL_WHITE, COL_PURPLE);
			elif(outm[i][j] == '-')	outch('.', COL_CYAN, COL_BLACK);
			elif(outm[i][j] == '=')	outch('+', COL_PURPLE, COL_PURPLE);
			else					putchar(' ');
		}
		printf("\n");
	}
}

void printhelp() {
	system("cls");
	char buffer[509];
	while (fgets(buffer,509,fp) != NULL) {
		puts(buffer);
	}
	while (_getch() != 'i') {};
	draw();
}

bool judge() {
	s1 = scan(1, cmove, mp, xw, yw, p1, p2, 0);
	s2 = scan(1, cmove, mp, xw, yw, p2, p1, 0);
	return cmove[p1.x][p1.y];
}