#include <iostream>
#include <algorithm>
#include <string>

int T;
std::string s;

const int maxn = 200000+7;

int dp[4];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		for (int i = 1; i < 4; i++) {
			dp[i] = -10000000;
		}
		int ans = 100000000;
		for (int i = 0; i < s.length(); i++) {
			dp[int(s[i]-'0')] = i;
			ans = std::min(ans, i-std::min(dp[1], std::min(dp[2], dp[3]))+1);
		}
		if (ans > s.length()) {
			ans = 0;
		}
		std::cout << ans << '\n';
	}
}