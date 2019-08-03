#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int maxn = 1e5+7;

std::vector<int> t[maxn];
int son[maxn], val[maxn];
int degree[maxn];
int fa[maxn];
int belong[maxn];
int ans = 100000000, n;

void dfs(int cur, int fa) {
	son[cur] = 1;
	for (auto it: t[cur]) {
		if (it != fa) {
			dfs(it, cur);
			son[cur] += son[it];
			val[cur] = std::max(val[cur], son[it]);
		}
	}
	val[cur] = std::max(val[cur], n - son[cur]);
	ans = std::min(ans, val[cur]);
}

void dfs(int root, int fa, int dis) {
	belong[root] = dis;
	for (auto it: t[root]) {
		if (it != fa) {
			dfs(it, root, dis+1);
		}
	}
}

bool check(int root) {
	dfs(root, -1, 1);
	std::fill(fa, fa+maxn, 0);
	for (int i = 1; i <= n; i++) {
		if (fa[belong[i]] == 0) {
			fa[belong[i]] = degree[i];
		} else if (fa[belong[i]] != degree[i]) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	int u, v;
	std::cin >> n;
	std::fill(son, son+maxn, 0);
	std::fill(val, val+maxn, 0);
	std::fill(degree, degree+maxn, 0);
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	dfs(1, 0);
	std::vector<int> centroids;
	for (int i = 1; i <= n; i++) {
		if (val[i] == ans) {
			centroids.push_back(i);
		}
	}
	for (auto it: centroids) {
		if (check(it)) {
			std::cout << it << '\n';
			exit(0);
		}
	}
	std::cout << "-1\n";
}