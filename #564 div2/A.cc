#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;
const int mod = 998244353;
using ll = long long;

std::vector<int> t[maxn];
ll dp[maxn], fac[maxn];

int dfs(int now, int root) {
	for (auto it: t[now]) {
		if (it != root) {
			dp[now] *= dfs(it, now);
			dp[now] %= mod;
 		}
	}
	dp[now] *= fac[t[now].size()];
	dp[now] %= mod;
	return dp[now];
}

int main(int argc, char *argv[]) {  
	std::fill(dp, dp+maxn, 1LL);
	int n, u, v;
	std::cin >> n;
	fac[1] = 1;
	for (int i = 2; i < maxn; i++) {
		fac[i] = i * fac[i-1];
		fac[i] %= mod;
	}
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfs(1, 0);
	dp[1] *= n;
	dp[1] %= mod;
	std::cout << dp[1] << '\n';
}