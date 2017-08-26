//
//  main.cpp
//  usaco test
//
//  Created by li haoyang on 11/08/2017.
//  Copyright © 2017 li haoyang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 60

bool vis[maxn][maxn];
int colour;
int m, n;
int castle[maxn][maxn];
int roomid[maxn][maxn];
int roomsize[maxn * maxn];

void floodfill(int l, int c, int id) {
	if(vis[l][c] || l < 0 || l >= n || c < 0 || c >= m) {
		return;
	}
	vis[l][c] = 1;
	roomid[l][c] = id;
	roomsize[id]++;
	int tmp = castle[l][c];
	if (tmp >= 8) {
		floodfill(l+1, c, id);
		tmp -= 8;
	}
	if (tmp >= 4) {
		floodfill(l, c+1, id);
		tmp -= 4;
	}
	if (tmp >= 2) {
		floodfill(l-1, c, id);
		tmp -= 2;
	}
	if (tmp >= 1) {
		floodfill(l, c-1, id);
	}
}

int main(int argc, const char * argv[]) {
	std::cin >> m >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> castle[n][m];
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(roomsize, 0, sizeof(roomsize));
	colour = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!vis[i][j]) {
				colour++;
				floodfill(i, j, colour);
			}
		}
	}
	int maxsize = -1;
	for(int i = 0; i <= colour; i++) {
		maxsize = std::max(roomsize[i], maxsize);
	}
	std::cout << colour << "\n" << maxsize;
	return 0;
}