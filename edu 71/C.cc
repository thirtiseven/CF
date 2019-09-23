#include <iostream>
#include <string>

using ll = long long;

const int maxn = 2e5+7;
const ll inf = 1e17;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		ll n, a, b;
		std::string s;
		std::cin >> n >> a >> b;
		std::cin >> s;
		ll dp[maxn][2];
		dp[0][0] = a + 2 * b;
		dp[0][1] = inf;
		if (s[1] == '1') {
			dp[0][0] = inf;
			dp[0][1] = 2*a+3*b;
		}
		for (int i = 1; i < s.length()-1; i++) {
			if (s[i+1] == '1' || s[i] == '1') {
				dp[i][1] = std::min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);
				dp[i][0] = inf;
			} else {
				dp[i][1] = std::min(dp[i-1][1] + a + 2*b, dp[i-1][0] + 2*a + 2*b);
				dp[i][0] = std::min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b);
			}
//			std::cout << dp[i][0] << ' ' << dp[i][1] << '\n';
		}
		dp[n-1][0] = std::min(dp[n-2][0] + a+b, dp[n-2][1] + 2*a+b);
		std::cout << dp[n-1][0] << '\n';
	}
}