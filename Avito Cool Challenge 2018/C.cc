#include <iostream>
#include <cstring>

const int mod = 998244353;
const int maxn = 2008;

using ll = long long;

ll dp[maxn][maxn];
ll n, m, k;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	memset(dp, sizeof(dp), 0);
	for (ll i = 0; i <= n; i++) {
		dp[i][0] = m;
	}
	for (ll i = 1LL; i <= 2003; i++) {
		for (ll j = 1LL; j < i; j++) {
			dp[i][j] = dp[i-1LL][j-1LL]*(m-1LL) + dp[i-1LL][j];
			dp[i][j] %= mod;
		}
	}
	std::cout << dp[n][k]%mod << '\n';
}