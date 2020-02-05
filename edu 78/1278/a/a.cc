#include <iostream>
#include <string>
#include <algorithm>

int T;
std::string s, h, p;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> s >> h;
		bool yes = 0;
		int len = s.length();
		std::sort(s.begin(), s.end());
		int upp = std::max(int(h.length()-s.length()), 0);
		for (int i = 0; i <= upp; i++) {
			p = h.substr(i, len);
			std::sort(p.begin(), p.end());
//			std::cout << p << '\n';
			if (p == s) {
				yes = 1;
				break;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}