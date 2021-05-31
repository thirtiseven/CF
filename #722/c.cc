#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

using ll = long long;

ll T, n, u, v;
std::vector<ll> t[maxn];
std::pair<ll, ll> lr[maxn];
ll sum[maxn][2];

void init(ll n) {
	for (ll i = 0; i <= n; i++) {
		t[i].clear();
	}
}

void dfs(ll cur, ll root) {
	sum[cur][0] = sum[cur][1] = 0;
	for (auto it: t[cur]) {
		if (it != root) {
			dfs(it, cur);
			sum[cur][0] += (std::max(sum[it][1] + std::abs(lr[it].second - lr[cur].first), sum[it][0] + std::abs(lr[it].first - lr[cur].first)));
			sum[cur][1] += (std::max(sum[it][1] + std::abs(lr[it].second - lr[cur].second), sum[it][0] + std::abs(lr[it].first - lr[cur].second)));
		}
	}
	
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		init(n);
		for (ll i = 1; i <= n; i++) {
			std::cin >> u >> v;
			lr[i] = std::make_pair(u, v);
		}
		for (ll i = 0; i < n-1; i++) {
			std::cin >> u >> v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		dfs(1, -1);
		std::cout << std::max(sum[1][0], sum[1][1]) << '\n';
	}
}