#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int n;
int a[maxn], dp[maxn][2], x = 0, y = 0, xx = 0, yy = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	dp[0][0] = dp[0][1] = 1;
	x = a[0];
	yy = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] == x) {
			dp[i][0] = dp[i-1][0];
		} else {
			if (a[i] != y) {
				y = a[i];
				dp[i][0] = dp[i-1][0]+1;
			} else {
				dp[i][0] = dp[i-1][0];
				x = a[i];
			}
		}
		if (a[i] == xx) {
			dp[i][1] = dp[i-1][1];
		} else {
			if (a[i] != yy) {
				dp[i][1] = dp[i-1][1]+1;
				yy = a[i];
			} else {
				dp[i][1] = dp[i-1][1]
			}
		}
		dp[i][0] = std::max(dp[i][0], dp[i][1]);
	}
	std::cout << ans << '\n';
}