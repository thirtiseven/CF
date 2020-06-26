#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1e6+7;

int t, n, k;
std::string s;
int ans = 0;
int dp[3][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k >> s;
		ans = 1000000;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				cnt++;
			}
		}
		for (int i = 0; i < k; i++) {
			int tot = 0;
			if (s[i] == '1') {
				tot++;
			}
			dp[0][i] = int(s[i] == '1');
			dp[1][i] = (s[i] == '1'?0:1000000);
			dp[2][i] = 10000000;
			int j;
			for (j = k+i; j < n; j+=k) {
				if (s[j] == '1') {
					tot++;
				}
				dp[0][j] = dp[0][j-k] + int(s[j] == '1');
				dp[1][j] = std::min(dp[0][j-k], dp[1][j-k]) + int(s[j] == '0');
				dp[2][j] = std::min(dp[1][j-k], dp[2][j-k]) + int(s[j] == '1');
			}
			j -= k;
			int cur = std::min(dp[0][j], std::min(dp[1][j], dp[2][j]));
			ans = std::min(ans, cnt-tot+cur);
		}
		std::cout << ans << '\n';
	}
}