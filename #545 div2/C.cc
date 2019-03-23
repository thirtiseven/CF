#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

const int maxn = 1024;

int m, n;
std::vector<int> x[maxn], y[maxn];
std::map<int, int> xx[maxn];
std::map<int, int> yy[maxn];
int mp[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> mp[i][j];
			x[i].push_back(mp[i][j]);
			y[j].push_back(mp[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		std::sort(x[i].begin(), x[i].end());
		x[i].erase(std::unique(x[i].begin(), x[i].end()));
		int cnt = 1;
		for (auto it: x[i]) {
			xx[i][it] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < m; i++) {
		std::sort(y[i].begin(), y[i].end());
		y[i].erase(std::unique(y[i].begin(), y[i].end()));
		int cnt = 1;
		for (auto it: y[i]) {
			yy[i][it] = cnt;
			cnt++;
		}
	}
	int aa, bb;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			aa = xx[i][mp[i][j]];
			bb = yy[j][mp[i][j]];
			std::cout << std::max(aa, bb) + std::max(x[i].size()-aa, y[j].size()-bb) << " ";
		}
		std::cout << '\n';
	}
}
