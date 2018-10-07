#include <iostream>
#include <vector>
using ll = long long;
const int maxn = 1e6+9;
ll n, siz[maxn], ans, s;
std::vector<ll> g[maxn];

void dfs(int fa, int u, int dep) {
	siz[u] = 1;
	s += dep&1;
	for (auto it: g[u]) {
		if(it == fa) continue;
		dfs(u, it, dep+1);	
		siz[u] += siz[it];
	}
	ans += siz[u] * (n - siz[u]);
}

int main(int argc, char *argv[]) {
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,1,0);
	ans += s * (n - s);
	std::cout << ans/2 << std::endl;
}