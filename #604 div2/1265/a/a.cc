#include <iostream>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		bool yes = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i-1] && s[i] != '?') {
				yes = 0;
				break;
			}
		}
		if (!yes) {
			std::cout << "-1\n";
			continue;
		}
		if (s[0] == '?') {
			if (s[1] == 'a') {
				s[0] = 'b';
			} else if (s[1] == 'b') {
				s[0] = 'c';
			} else {
				s[0] = 'a';
			}
		}
		if (s[s.length()-1] == '?') {
			if (s[s.length()-2] == 'a') {
				s[s.length()-1] = 'b';
			} else if (s[s.length()-1] == 'b') {
				s[s.length()-2] = 'c';
			} else {
				s[s.length()-1] = 'a';
			}
		}
		for (int i = 1; i < s.length()-1; i++) {
			if (s[i] == '?') {
				if (s[i-1] == 'a') {
					if (s[i+1] == 'b') {
						s[i] = 'c';
					} else  {
						s[i] = 'b';
					}
				} else if (s[i-1] == 'b') {
					if (s[i+1] == 'a') {
						s[i] = 'c';
					} else {
						s[i] = 'a';
					}
				} else {
					if (s[i+1] == 'a') {
						s[i] = 'b';
					} else {
						s[i] = 'a';
					}
				}
			}
		}
		std::cout << s << '\n';
	}
}