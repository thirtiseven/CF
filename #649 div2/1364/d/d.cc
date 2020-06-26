#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

const int maxn = 1e5+7;

int n, m, k, u, v;

std::vector<int> g[maxn];
int deg[maxn], fa[maxn];
std::vector<int> cir, ans;
std::queue<std::pair<int, int>> q;
std::set<int> s;

bool dfs(int now, int par) {
//	std::cout << now << ' ' << par << '\n';
	if (s.count(now)) {
		int cur = par;
		while (cur != now) {
//			std::cout << cur << ' ';
			cir.push_back(cur);
			cur = fa[cur];
		}
		cir.push_back(now);
		return true;
	}
	s.insert(now);
	fa[now] = par;
	for (auto it: g[now]) {
		if (it != par) {
			if (s.count(it)) {
				return dfs(it, now);
			}
		}
	}
	for (auto it: g[now]) {
		if (it != par) {
			if (dfs(it, now)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> k;
	std::fill(deg, deg+maxn, 0);
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	std::fill(fa, fa+maxn, 0);
	if (dfs(1, -1)) {
//		std::cout << "CIR " << cir.size() << '\n';
		if (cir.size() <= k) {
//			std::cout << "1!!!!!\n";
			std::cout << "2\n";
			std::cout << cir.size() << '\n';
			for (auto it: cir) {
				std::cout << it << ' ';
			}
			std::cout << '\n';
		} else {
//			std::cout << "2!!!!!\n";
			std::cout << "1\n";
			for (int i = 0; i < (k+1); i+=2) {
				std::cout << cir[i] << ' ';
			}
			std::cout << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				ans.push_back(i);
			}
		}
//		std::cout << "3!!!!!\n";
		std::cout << "1\n";
		for (int i = 0; i < (k+1)/2; i++) {
			std::cout << ans[i] << ' ';
		}
		std::cout << '\n';
	}
}