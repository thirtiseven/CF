#include <iostream>
#include <algorithm>
#include <string>

int T, x, y;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int C = 1; C <= T; C++) {
		std::cin >> x >> y >> s;
		int ans = 0;
		char last = '0';
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '?') {
				if (i == s.length()-1) {
					break;
				}
				if (last == 'C' && s[i+1] == 'J') {
					ans += x;
					last = 'J';
				} else if (last == 'J' && s[i+1] == 'C') {
					ans += y;
					last = 'C';
				}
			} else {
				if (s[i] == 'J' && last == 'C') {
					ans += x;
				}
				if (s[i] == 'C' && last == 'J') {
					ans += y;
				}
				last = s[i];
			}
		}
		std::cout << "Case #" << C << ": " << ans << '\n';
	}
}