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
		for (int i = 0; i < s.length(); i++) {
			if (i % 2 == 0) {
				if (s[i] == 'a') {
					s[i] = 'b';
				} else {
					s[i] = 'a';
				}
			} else {
				if (s[i] == 'z') {
					s[i] = 'y';
				} else {
					s[i] = 'z';
				}
			}
		}
		std::cout << s << '\n';
	}
}