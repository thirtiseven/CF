#include <iostream>
#include <string>
#include <algorithm>

int t, n;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> s;
		int ans = 1;
		std::string minn = s;
		std::string cur;
		for (int i = 2; i <= n; i++) {
			cur = s.substr(i-1);
			std::string t = s.substr(0, i-1);
			if (i % 2 == n % 2) {
				std::reverse(t.begin(), t.end());
			}
			cur += t;
//			std::cout << cur << '\n';
			if (cur < minn) {
				minn = cur;
				ans = i;
			}
		}
		std::cout << minn << '\n' << ans << '\n';
	}
}