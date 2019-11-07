#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int t, n, sum0;
	std::string s;
	bool yes = 0;
	std::cin >> t;
	while (t--) {
		yes = 0;
		sum0 = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> s;
			if (s.length() % 2 == 1) {
				yes = 1;
			}
			for (auto it: s) {
				if (it == '0') {
					sum0++;
				}
			}
		}
		if (!yes && sum0 % 2 == 1) {
			std::cout << n-1 << '\n';
		} else {
			std::cout << n << '\n';
		}
	}
}