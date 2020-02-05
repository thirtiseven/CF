#include <iostream>
#include <algorithm>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int len = s.length(), x = int(s[0]-'0');
		for (int i = 1; i < len; i++) {
			if (s[i] > s[0]) {
				break;
			}
			if (s[i] < s[0]) {
				x--;
				break;
			}
		}
		std::cout << (len-1)*9+x << '\n';
	}
}