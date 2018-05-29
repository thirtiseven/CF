#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::string s;
	char c;
	std::cin >> s;
	std::string ss = s;
	std::reverse(s.begin(), s.end());
	int ok = 1;
	c = s[0];
	for (auto aa: s) {
		if (aa != c) {
			ok = 0;
		}
	}
	if (ok) {
		std::cout << 0;
	} else if (ss == s) {
		std::cout << s.length()-1;
	} else {
		std::cout << s.length();
	}
}