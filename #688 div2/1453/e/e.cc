#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;

int T, n, u, v;
std::vector<int> G[maxn], sp;
int dep[maxn], dfn[maxn], len[maxn];

std::pair<int, int> dp[21][maxn << 1];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		G[i].clear();
		len[i] = 0;
	}
	sp.clear();
}

int dfslca(int u, int fa) {
	dep[u] = dep[fa] + 1;
	dfn[u] = sp.size();
	sp.push_back(u);
	for (auto& v : G[u]) {
		if (v == fa) continue;
		len[u] = std::max(len[u], dfslca(v, u));
		sp.push_back(u);
	}
	len[u] = std::max(len[u], dep[u]);
	return len[u];
}

void initrmq() {
	int x = sp.size();
	for (int i = 0; i < x; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
	for (int i = 1; (1 << i) <= x; i++)
		for (int j = 0; j + (1 << i) - 1 < n; j++)
			dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v) {
	int l = dfn[u], r = dfn[v];
	if (l > r) std::swap(l, r);
	int k = 31 - __builtin_clz(r - l + 1);
	return std::min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
}

int ans = 1;

void dfs(int u, int fa, int bro) {
	if (G[u].size() == 1) {
		if (bro == -1) {
			ans = std::max(ans, dep[u]);
			return;
		}
		int lcanow = lca(u, bro);
		ans = std::max(ans, dep[u]+dep[bro]-2*dep[lcanow]);
	}
	if (G[u].size() == 2) {
		for (auto it: G[u]) {
			if (it != fa) {
				dfs(it, u, bro);
			}
		}
	}
	std::vector<std::pair<int, int>> ve;
	for (auto it: G[u]) {
		if (it != fa) {
			ve.push_back(std::make_pair(len[it], it));
		}
	}
	std::sort(ve.begin(), ve.end());
	for (int i = 0; i < ve.size()-1; i++) {
		dfs(ve[i].second, u, ve[i+1].second);
	}
	dfs(ve[ve.size()-1].second, u, -1);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		init(n);
		for (int i = 0; i < n-1; i++) {
			std::cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dep[0] = 0;
		dfslca(1, 0);
		initrmq();
		dfs(1, 0, -1);
		std::cout << ans << '\n';
	}
}