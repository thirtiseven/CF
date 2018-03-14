#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

const int maxn = 123;
int n, m, u, v, dp[maxn][maxn][26];
char c;
std::vector<std::pair<int, int> > edges[maxn];

int solve(int u, int v, int c) {
	if (dp[u][v][c] != -1) {
		return dp[u][v][c];
	}
	for (auto& p: edges[u]) {
		if (p.second >= c) {
			if (!solve(v, p.first, p.second)) {
				return dp[u][v][c] = 1;
			}
		}
	}
	return dp[u][v][c] = 0;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	while (m--) {
		std::cin >> u >> v >> c;
		edges[u].push_back(std::make_pair(v, int(c-'a')));
	}
	memset(dp, -1, sizeof(dp));
	for (u = 1; u <= n; ++u) {
		for (v = 1; v <= n; ++v) {
			if (solve(u, v, 0)) {
				std::cout << 'A';
			} else {
				std::cout << 'B';
			}
		}
		std::cout << '\n';
	}
	return 0;
}