#include <iostream>

const int maxn = 2e5+7;

int a[maxn];
int dp[maxn][3];

int k1, k2, k3, x, n;

int main(int argc, char *argv[]) {  
	std::cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;
	for (int i = 0; i < k1; i++) {
		std::cin >> x;
		a[x] = 1;
	}
	for (int i = 0; i < k2; i++) {
		std::cin >> x;
		a[x] = 2;
	}
	for (int i = 0; i < k3; i++) {
		std::cin >> x;
		a[x] = 3;
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + int(a[i]!=1); 
		dp[i][1] = std::min(dp[i-1][0], dp[i-1][1]) + int(a[i]!=2);
		dp[i][2] = std::min(std::min(dp[i-1][1], dp[i-1][0]), dp[i-1][2]) + int(a[i]!=3);
	}
	std::cout << std::min(dp[n][0], std::min(dp[n][1], dp[n][2])) << '\n';
}