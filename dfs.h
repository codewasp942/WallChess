#pragma once
#include "position.h"
#include "qipan.h"

void _dfs(bool (*outmem)[ maxyw ], bool (*wallarr)[ maxxw ][ maxyw ], int xw, int yw, pos stt, pos bik, int maxsize, int stp, int& cnt);
int scan(bool(*outmem)[maxyw], bool(*wallarr)[maxxw][maxyw], int xw, int yw, pos stt, pos bik, int maxsize = 0);