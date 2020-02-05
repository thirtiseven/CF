#include <iostream>
#include <cstring>

using ll = long long;

const ll mod = 1e9+7;

ll n, m;
ll dp[12][1007];

ll PowMod(ll a, ll b, const ll &Mod) { 
	a %= Mod;
	ll ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}


ll Inv(ll a, ll n){
	return PowMod(a, n-2, n); 
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		std::cout << dp[m][i] << ' ';
//	}
//	std::cout << '\n';
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j+i <= n+1; j++) {
//			std::cout << i << ' ' << j << '\n';
			ans += dp[m][i]*dp[m][j];
			ans %= mod;
		}
	}
	std::cout << ans << '\n';
}