#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
const int maxn = 2e5+7;

ll n, a[maxn];
ll dp[maxn];
std::vector<ll> t[maxn];
ll val, ans;

void init() {
	std::fill(dp, dp+maxn, 0);
	val = 0;
}

ll dfs(ll now, ll root, ll dis) {
	val += dis*a[now];
	dp[now] = a[now];
	for (auto it: t[now]) {
		if (it != root) {
			dp[now] += dfs(it, now, dis+1);
		}
	}
	return dp[now];
}

void solve(ll now, ll root) {
	ll backup;
	for (auto it: t[now]) if (it != root) {
		backup = val;
		val -= dp[it];
		dp[now] -= dp[it];
		dp[it] += dp[now];
		val += dp[now];
		ans = std::max(ans, val);
		solve(it, now);
		dp[it] -= dp[now];
		dp[now] += dp[it];
		val = backup;
	}
}

int main(int argc, char *argv[]) {  
	init();
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	ll u, v;
	for (ll i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u-1].push_back(v-1);
		t[v-1].push_back(u-1);
	}
	dfs(0, -1, 0);
	ans = val;
	solve(0, -1);
	std::cout << ans << '\n';
}