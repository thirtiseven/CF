#include <iostream>

const int maxn = 500+7;

int n, dp[maxn][maxn], ans[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> dp[i][i];
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i+1; j <= n; j++) {
			for (int k = i; k < j; k++) {
				if (dp[i][k] && dp[i][k] == dp[k+1][j]) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
	}
	std::fill(ans, ans+maxn, 1e9);
	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j+1][i] > 0) {
				ans[i] = std::min(ans[j]+1, ans[i]);
			}
		}
	}
	std::cout << ans[n] << '\n';
}