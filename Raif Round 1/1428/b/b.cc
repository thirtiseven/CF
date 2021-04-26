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
		int all1 = 1, all2 = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] != '<' && s[i] != '-') {
				all1 = 0;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] != '>' && s[i] != '-') {
				all2 = 0;
				break;
			}
		}
		if (all1 || all2) {
			std::cout << n << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '-' || s[(i+n-1)%n] == '-') {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}