#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using ll = long long;
const int maxn = 2e5+7;

ll n, k, u, v, m;
std::pair<ll, int> son[maxn];
ll dis[maxn];
std::vector<int> t[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		t[i].clear();
		son[i] = std::make_pair(0, 0);
		dis[i] = 0;
	}
}

int dfs(int now, int fa, int d) {
//	std::cerr << ">>>" << now << ' ' << d << '\n';
	dis[now] = d;
	if (t[now].size() == 1 && now != 1) {
		son[now].first = 0;
		son[now].second = now;
		return 1;
	}
	int res = 0;
	for (auto it: t[now]) {
		if (it != fa) {
			res += dfs(it, now, d+1);
		}
	}
	son[now].first = res;
	son[now].second = now;
	return res+1;
}

bool cmp(std::pair<ll, ll> a, std::pair<ll, ll> b) {
	return a.first-dis[a.second] > b.first-dis[b.second];
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	m = n-k;
	init(n);
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfs(1, -1, 0);
//	for (int i = 1; i <= n; i++) {
//		std::cout << i << ' ' << son[i].first << ' ' << dis[i] << '\n';
//	}
	std::sort(son+1, son+n+1, cmp);
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += son[i].first;
		ans -= dis[son[i].second];
//		std::cout << "+" << son[i].first << " -" << dis[son[i].second] << '\n';
	}
	std::cout << ans << '\n';
}