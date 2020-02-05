#include <iostream>

const int maxn = 2e5+7;

int n, a[maxn];
int dp[maxn][2];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i-1]) {
			dp[i][0] = dp[i-1][0] + 1;
			if (dp[i-1][1] > 0) {
				dp[i][1] = dp[i-1][1] + 1;
			} else {
				dp[i][1] = dp[i-1][1];
			}
			if (i > 1 && a[i] > a[i-2]) {
				dp[i][1] = std::max(dp[i-2][0] + 1, dp[i][1]);
			}
		} else {
			dp[i][0] = 1;
			if (i > 1 && a[i] > a[i-2]) {
				dp[i][1] = dp[i-2][0] + 1; 
			}
		}
		ans = std::max(ans, dp[i][0]);
		ans = std::max(ans, dp[i][1]);
	}
	std::cout << ans << '\n';
}