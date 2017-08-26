#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000007

std::vector<int> g[105];
int dp[105][55];
int f[55];
int n, k;
void dfs(int u, int fa) {
	dp[u][0] = 1;
	dp[u][k+1] = 1;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == fa) {
			continue;
		} 
		dfs(v,u);
		memset(f,0,sizeof(f));
		for(int j = 0; j <= 2 * k; j++) {
			for(int p = 0; p <= 2 * k; p++) {
				if(j + p <= 2 * k) {
					f[std::min(p+1, j)] += (1LL * dp[u][j] * dp[v][p]) % mod;
					f[std::min(p+1, j)] %= mod;
				} else {
					f[std::max(p+1,j)] += (1LL * dp[u][j] * dp[v][p]) % mod;
					f[std::max(p+1,j)] %= mod;
				}
			}
		}
		for(int j = 0; j <= 2 * k; j++)
			dp[u][j] = f[j];
	}
}

int main(int argc, char *argv[]) {
	std::cin >> n >> k;
	for(int i = 1; i < n; i++){
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 1);
	int ans = 0;
	for(int i = 0; i <= k; i++){
		ans=(ans + dp[1][i]) % mod;
	}
	std::cout << ans << std::endl;
	return 0;
}