#include <iostream>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int zero = 0, one = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				zero++;
			} else {
				one++;
			}
		}
		if (zero == s.length() || one == s.length()) {
			std::cout << s << '\n';
		} else {
			for (int i = 0; i < s.length(); i++) {
				std::cout << "10";
			}
			std::cout << '\n';
		}
	}
}