#include <iostream>
#include <vector>

const int maxn = 2e5+7;
int T;
std::vector<int> g[maxn];
int a, b, n, m;
int u, v;
int col[maxn], vis[maxn];
long long num[8];
bool yes;

void dfs(int cur, int cc, int cf) {
	if (vis[cur]) {
		return;
	}
	vis[cur] = 1;
	if (col[cur] == 0) {
		col[cur] = cc;
		num[cc]++;
	}
	if (col[cur] == 6) {
		if (cf == 1) {
			for (auto it: g[cur]) {
				if (!vis[it]) {
					dfs(it, 3, 6);
				}
			}
		} else if (cf == 2 || cf == 7) {
			for (auto it: g[cur]) {
				if (!vis[it]) {
					dfs(it, 4, 6);
				}
			}
		}
	} else if (col[cur] == 7) {
		if (cf == 1) {
			for (auto it: g[cur]) {
				if (!vis[it]) {
					dfs(it, 2, 7);
				}
			}
		} else if (cf == 3 || cf == 6) {
			for (auto it: g[cur]) {
				if (!vis[it]) {
					dfs(it, 5, 7);
				}
			}
		}
	} else {
		for (auto it: g[cur]) {
//			std::cout << cur << ' ' <<  it  << ' ' << col[it] << ' ' << col[cur] << '\n';
			if (col[it] == 0) {
				dfs(it, col[cur], col[cur]);
			} else if (col[it] == 6 || col[it] == 7) {
				if ((col[it] == 6 && col[cur] == 5) || (col[it] == 7 && col[cur] == 4) || (col[it] == 6 && col[cur] == 2 && num[3] > 0) || (col[it] == 7 && col[cur] == 3 && num[2] > 0)) {
//					std::cout << "!!!" << cur << ' ' << it << '\n';
					yes = 0;
				}
				dfs(it, col[it], col[cur]);
			} else if (col[it] != col[cur]) { 
				yes = 0;
			}
		}
	}
}

int main(int argc, char *argv[]) { 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> a >> b;
		yes = 1;
		std::fill(col, col + n + 1, 0);
		std::fill(vis, vis + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int start = 1;
		while (start == a || start == b) {
			start++;
		}
		col[a] = 6, col[b] = 7;
		std::fill(num, num+8, 0);
		dfs(start, 1, 0);
		for (int i = 1; i <= n; i++) {
//			std::cout << col[i] << ' ';
		}
//		std::cout << '\n';
		long long ans = 0;
		if (yes == 0) {
			ans = 0;
		} else if (num[5] > 0) {
			ans = num[1]*num[5];
		} else if (num[4] > 0) {
			ans = num[1]*num[4];
		} else {
			ans = num[2]*num[3];
		}
		std::cout << ans << '\n';
	}
}