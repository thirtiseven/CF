#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 52;

int T, n, m;
std::string s[maxn];
//int vis[maxn][maxn];

bool set(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return 0;
	}
	if (s[x][y] == 'B') {
		return 0;
	}
	if (s[x][y] == 'G') {
		return 1;
	}
	s[x][y] = '#';
	return 0;
}

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	}
	if (s[x][y] == 'X') {
		return;
	}
//	vis[x][y] = 1;
	if (s[x][y] == '#') {
		return;
	}
	s[x][y] = 'X';
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		if (s[n-1][m-1] == 'B') {
//			std::cout << "1111 ";
			std::cout << "No\n";
			continue;
		}
		bool fail = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
//				vis[i][j] = 0;
				if (s[i][j] == 'B') {
					fail |= set(i-1, j);
					fail |= set(i+1, j);
					fail |= set(i, j-1);
					fail |= set(i, j+1);
				}
			}
		}
		if (fail) {
//			std::cout << "2222 ";
			std::cout << "No\n";
			continue;
		}
		dfs(n-1, m-1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'G') {
					fail = 1;
				}
			}
		}
		if (fail) {
//			std::cout << "3333 ";
			std::cout << "No\n";
			continue;
		}
		std::cout << "Yes\n";
	}
}