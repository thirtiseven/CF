#include <iostream>
#include <string>

int t, n;
std::string s;

bool check(int a, int b) {
//	std::cout << a << ' ' << b << '\n';
	while (s[a] == s[b] && a <= b) {
		a++, b--;
	}
	if (a < b) {
//		std::cout << " false\n";
		return false;
	}
//	std::cout << "  true\n";
	return true;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> s;
		if (check(0, s.length()-1)) {
			std::cout << s << '\n';
		} else {
			int l = 0, r = s.length()-1, left = s.length();
			while (s[l] == s[r]) {
				l++, r--, left -= 2;
			}
			int maxx1 = 0, maxx2 = 0;
			for (int i = 0; i < left; i++) {
				if (check(l, l+i)) {
					maxx1 = i+1;
				}
			}
			for (int i = 0; i < left; i++) {
				if (check(r-i,r)) {
					maxx2 = i+1;
				}
			}
			if (maxx1 >= maxx2) {
				for (int i = 0; i < l; i++) {
					std::cout << s[i];
				}
				for (int i = l; i < l+maxx1; i++) {
					std::cout << s[i];
				}
				for (int i = r+1; i < s.length(); i++) {
					std::cout << s[i];
				}
				std::cout << '\n';
			} else {
				for (int i = 0; i < l; i++) {
					std::cout << s[i];
				}
				for (int i = r-maxx2+1; i <= r; i++) {
					std::cout << s[i];
				}
				for (int i = r+1; i < s.length(); i++) {
					std::cout << s[i];
				}
				std::cout << '\n';
			}
		}
	}
}