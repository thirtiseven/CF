#include <iostream>
#include <algorithm>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int ans = 0, B = 0;
		for (int i = s.length()-1; i >= 0; i--) {
			if (s[i] == 'A') {
				if (B > 0) {
					B--;
				} else {
					ans++;
				}
			} else {
				B++;
			}
		}
		ans += B%2;
		std::cout << ans << '\n';
	}
}