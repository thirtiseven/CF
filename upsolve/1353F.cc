#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 103;

ll t, n, m, a[maxn][maxn], dp[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> a[i][j];
				a[i][j] -= i+j-2;
			}
		}
		ll ans = 1e18;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				ll init = a[x][y];
				for (int i = 0; i <= n; i++) {
					for (int j = 0; j <= m; j++) {
						dp[i][j] = 1e18;
					}
				}
				dp[0][1] = dp[1][0] = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (a[i][j] >= init) dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + a[i][j] - init;
					}
				}
				ans = std::min(ans, dp[n][m]);
			}
		}
		std::cout << ans << '\n';
	}
}