#include <iostream>
#include <algorithm>
#include <string>

int T, n;
std::string s;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		std::cin >> n;
		std::cin >> s;
		bool a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] <= 'z' && s[i] >= 'a') {
				a = 1;
			}
			if (s[i] <= 'Z' && s[i] >= 'A') {
				b = 1;
			}
			if (s[i] <= '9' && s[i] >= '0') {
				c = 1;
			}
			if (s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&') {
				d = 1;
			}
		}
		if (a == 0) {
			s.append("a");
		}
		if (b == 0) {
			s.append("A");
		}
		if (c == 0) {
			s.append("0");
		}
		if (d == 0) {
			s.append("&");
		}
		while (s.length() < 7) {
			s.append("a");
		}
		std::cout << "Case #" << cas << ": " << s << '\n';
	}
}