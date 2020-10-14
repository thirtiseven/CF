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
		int ans = 0, owe = 0;
		for (int i = 0; i < n; i++) {
			if (i == n-1) {
				ans++;
				owe++;
				break;
			}
			if (s[i] == s[i+1]) {
				ans++;
				i++;
				while (i < n - 1 && s[i] == s[i+1]) {
					i++;
					if (owe) owe--;
				}
			} else {
				ans++;
				owe++;
			}
		}
		ans -= owe/2;
		std::cout << ans << '\n';
	}
}