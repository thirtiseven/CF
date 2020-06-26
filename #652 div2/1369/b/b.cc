#include <iostream>
#include <algorithm>
#include <string>

int T, n;
std::string s, t;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		t = "";
		t += s.substr(0, 1);
		for (int i = 1; i < n; i++) {
			if (s[i] != s[i-1]) {
				t += s.substr(i, 1);
			}
		}
		int x = t.length();
		if (t[0] == '0') {
			x--;
		}
		if (t[t.length()-1] == '1') {
			x--;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				std::cout << '0';
			} else {
				break;
			}
		}
		for (int i = 0; i < x/2; i++) {
			std::cout << '0';
			break;
		}
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == '1') {
				std::cout << '1';
			} else {
				break;
			}
		}
		std::cout << '\n';
	}
}