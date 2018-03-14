#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, a[2018];
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int dp[2018][4];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			dp[i][0] = dp[i-1][0] + 1;
			dp[i][1] = dp[i-1][1];
			dp[i][2] = std::max(dp[i-1][1], dp[i-1][2]) + 1;
			dp[i][3] = dp[i-1][3];
		} else if (a[i] == 2) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = std::max(dp[i-1][0], dp[i-1][1]) + 1;
			dp[i][2] = dp[i-1][2];
			dp[i][3] = std::max(dp[i-1][2], dp[i-1][3]) + 1;
		}
	}
	std::cout << std::max(std::max(dp[n][0], dp[n][1]), std::max(dp[n][2], dp[n][3]));
}