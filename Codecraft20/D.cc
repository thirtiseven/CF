#include <iostream>

const int maxn = 1003;

int n;
std::pair<int, int> dir[4] = {std::make_pair(-1, 0), std::make_pair(1, 0), std::make_pair(0, -1), std::make_pair(0, 1)};
char dc[4] = {'D', 'U', 'R', 'L'};
char dx[4] = {'U', 'D', 'L', 'R'};
std::pair<int, int> m[maxn][maxn];
char ans[maxn][maxn];

void dfs(int x, int y, int dd) {
	ans[x][y] = dc[dd];
	int xx, yy;
	for (int k = 0; k < 4; k++) {
		xx = x+dir[k].first, yy = y+dir[k].second;
		if (xx > 0 && xx <= n && yy > 0 && yy <= n && ans[xx][yy] == '0' && m[xx][yy] == m[x][y]) {
			dfs(xx, yy, k);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> m[i][j].first >> m[i][j].second;
			ans[i][j] = '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (m[i][j].first == i && m[i][j].second == j) {
				ans[i][j] = 'X';
				for (int k = 0; k < 4; k++) {
					int xx = i+dir[k].first, yy = j+dir[k].second;
					if (xx > 0 && xx <= n && yy > 0 && yy <= n && ans[xx][yy] == '0' && m[xx][yy] == m[i][j]) {
						dfs(xx, yy, k);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (m[i][j].first == -1 && m[i][j].second == -1 && ans[i][j] == '0') {
				bool yes = 0;
				for (int k = 0; k < 4; k++) {
					int xx = i+dir[k].first, yy = j+dir[k].second;
					if (xx > 0 && xx <= n && yy > 0 && yy <= n && ans[xx][yy] == '0' && m[xx][yy] == m[i][j]) {
						if (yes == 0) {
							ans[i][j] = dx[k];
							yes = 1;
						}
						dfs(xx, yy, k);
					}
				}
				if (yes == 0) {
					std::cout << "INVALID\n";
					exit(0);
				}
			}
		}
	}
//	std::cout << "!!!!\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == '0') {
				std::cout << "INVALID\n";
				exit(0);
			}
		}
	}	
	std::cout << "VALID\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << ans[i][j];
		}
		std::cout << '\n';
	}
}