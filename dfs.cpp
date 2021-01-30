#include "dfs.h"
#include "position.h"
#include "qipan.h"
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<pos, int> po;

void _bfs(bool(*outmem)[maxyw], bool(*wallarr)[maxxw][maxyw], int xw, int yw, pos stt, pos bik, int maxsize, int stp, int& cnt) {
	queue<po> q;
	q.push(make_pair(stt,0));
	outmem[stt.x][stt.y] = 1;
	cnt = 1;
	while (!q.empty()) {
		po nw = q.front();
		q.pop();
		pos nwp = nw.first;
		for (int i = 0;i < 4;i++) {
			pos nxt = nwp[i];
			if (nxt.x<1 || nxt.x>xw || nxt.y<1 || nxt.y>yw)continue;
			if ((nw.second + 1 > maxsize) && (maxsize > 0))continue;
			if (wallarr[i % 2][max(nwp.x, nxt.x)][max(nwp.y, nxt.y)])continue;
			if (outmem[nxt.x][nxt.y])continue;
			outmem[nxt.x][nxt.y] = 1;
			q.push(make_pair(nxt, nw.second + 1));
		}
	}
	
	
	/*
	
	if (stt == bik)return;
	if (maxsize > 0 && stp > maxsize)return;
	cnt++;
	for (int i = 0;i < 4;i++) {
		pos nxt = stt[i];
		if (nxt.x<1 || nxt.x>xw || nxt.y<1 || nxt.y>yw)continue;
		if (wallarr[i % 2][max(stt.x, nxt.x)][max(stt.y, nxt.y)])continue;
		if (outmem[nxt.x][nxt.y])continue;
		outmem[nxt.x][nxt.y] = 1;
		_dfs(outmem, wallarr, xw, yw, nxt, bik, maxsize, stp + 1, cnt);
	}
	*/
}

int scan(bool(*outmem)[maxyw], bool(*wallarr)[maxxw][maxyw], int xw, int yw, pos stt, pos bik, int maxsize) {
	for (int i = 1;i <= xw;i++) {
		for (int j = 1;j <= yw;j++) {
			outmem[i][j] = 0;
		}
	}
	int cnt = 0;
	outmem[stt.x][stt.y] = 1;
	_bfs(outmem, wallarr, xw, yw, stt, bik, maxsize, 1, cnt);
	return cnt;
}