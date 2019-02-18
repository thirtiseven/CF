#include <iostream>
#include <cstring>
#include <algorithm>

using ll = long long;
const ll mod = 1e9+7;
const int maxn = 2e5+7;

ll dp[maxn][4];

int main(int argc, char *argv[]) {  
	memset(dp, 0, sizeof(dp));
	ll n, l, r;
	std::cin >> n >> l >> r;
	ll lr0 = 0, lr1 = 0, lr2 = 0;
	if (r-l+1<=6) {
		for (ll i = l; i <= r; i++) {
			if (i%3==0) lr0++;
			else if (i%3==1) lr1++;
			else lr2++;
		}
	} else {
		while (l%3!=1) {
			if (l%3==0) lr0++;
			else if (l%3==1) lr1++;
			else lr2++;
			l++;
		}
		while (r%3!=0) {
			if (r%3==0) lr0++;
			else if (r%3==1) lr1++;
			else lr2++;
			r--;
		}
		lr0 += (r-l+1)/3;
		lr1 += (r-l+1)/3;
		lr2 += (r-l+1)/3;
	}
//	std::cerr << lr0 << " " << lr1 << " " << lr2 << '\n';
	dp[1][0] = lr0, dp[1][1] = lr1, dp[1][2] = lr2;
	for (ll i = 2; i <= n; i++) {
		dp[i][0] += dp[i-1][0]*lr0;
		dp[i][1] += dp[i-1][0]*lr1;
		dp[i][2] += dp[i-1][0]*lr2;
		dp[i][2] += dp[i-1][1]*lr1;
		dp[i][0] += dp[i-1][1]*lr2;
		dp[i][1] += dp[i-1][1]*lr0;
		dp[i][2] += dp[i-1][2]*lr0;
		dp[i][0] += dp[i-1][2]*lr1;
		dp[i][1] += dp[i-1][2]*lr2;
		dp[i][0] %= mod;
		dp[i][1] %= mod;
		dp[i][2] %= mod;
//		std::cout << dp[i][0]%mod << '\n';
	}
	std::cout << dp[n][0]%mod;
}