#include <iostream>
#include <cstring>

using ll = long long;
const ll maxn = 3e5+7;
ll n, m, k;
ll a[maxn], dp[maxn][11], num[maxn][11];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	memset(dp, sizeof(dp), 0);
	memset(num, sizeof(num), 0);
	dp[0][0] = a[0];
	num[0][0] = 1;
	if (dp[0][0] < 0) {
		dp[0][0] = 0;
		num[0][0] = 0;
	}
	for (int i = 1; i < n; i++) {
			for (int j = 0; j <= num[i][j]; j++) {
				if (dp[i-1][j] > 0) {
					dp[i][j] = dp[i-1][j] + a[i];
					num[i][j] = num[i-1][j] + 1;
					if (num[i][j] % m == 1 || m==1) {
						dp[i][j] -= k;
					}
					num[i][j] %= m;
				} else {
					dp[i][j] = a[i] - k;
					num[i][j] = 1;
				}
				if (dp[i][j] < 0) {
					dp[i][j] = 0;
					num[i][j] = 0;
				}
			}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			ans = std::max(dp[i][j], ans);
		}
	}
	std::cout << ans << '\n';
}