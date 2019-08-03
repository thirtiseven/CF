#include <iostream>
#include <algorithm>

using ll = unsigned long long;
const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	ll n, h[2][maxn], dp[2][maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> h[0][i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> h[1][i];
	}
	dp[0][0] = h[0][0];
	dp[1][0] = h[1][0];
	dp[0][1] = dp[1][0] + h[0][1];
	dp[1][1] = dp[0][0] + h[1][1];
	for (int i = 2; i < n; i++) {
		dp[0][i] = std::max(dp[1][i-2], dp[1][i-1]) + h[0][i];
		dp[1][i] = std::max(dp[0][i-2], dp[0][i-1]) + h[1][i];
	}
	std::cout << std::max(dp[0][n-1], dp[1][n-1]) << '\n';
}