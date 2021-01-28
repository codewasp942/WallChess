#include "dfs.h"
#include "position.h"
#include "qipan.h"
#include <algorithm>
using namespace std;

void _dfs(bool(*outmem)[maxyw], bool(*wallarr)[maxxw][maxyw], int xw, int yw, pos stt, pos bik, int maxsize, int stp, int& cnt) {
	if (stt == bik)return;
	if (stp > maxsize)return;
	outmem[stt.x][stt.y] = 1;
	cnt++;
	for (int i = 0;i < 4;i++) {
		pos nxt = stt[i];
		if (nxt.x<1 || nxt.x>xw || nxt.y<1 || nxt.y>yw)continue;
		if (wallarr[i % 2][max(stt.x, nxt.x)][max(stt.y, nxt.y)])continue;
		_dfs(outmem, wallarr, xw, yw, nxt, bik, maxsize, stp + 1, cnt);
	}
}

int dfs(bool(*outmem)[maxyw], bool(*wallarr)[maxxw][maxyw], int xw, int yw, pos stt, pos bik, int maxsize) {
	memset(outmem, 0, sizeof(outmem));
	int cnt = 0;
	_dfs(outmem, wallarr, xw, yw, stt, bik, maxsize, 0, cnt);
	return cnt;
}