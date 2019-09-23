#include <iostream>
#include <algorithm>

int q, n, s[103];

int main(int argc, char *argv[]) {  
	std::cin >> q;
	while (q--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		std::sort(s, s+n);
		bool yes = 0;
		int cur = s[0];
		for (int i = 1; i < n; i++) {
			if (cur > 2048) {
				break;
			}
			if (cur == s[i]) {
				cur += s[i];
				if (cur == 2048) {
					yes = 1;
					break;
				}
			} else {
				break;
			}
		}
		if (yes) {
			std::cout << "yes\n";
		} else {
			std::cout << "no\n";
		}
	}
}