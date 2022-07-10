#include <iostream>
#include <algorithm>
#include <string>

int T, n;
std::string s;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		int ans1 = -1, ans2 = -1;
		for (int i = 0; i < n-1; i++) {
			if (s[i]!=s[i+1]) {
				ans1 = i+1;
				ans2 = i+2;
			}
		}
		std::cout << ans1 << ' ' << ans2 << '\n';
		
	}
}