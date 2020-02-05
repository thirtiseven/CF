#include <iostream>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int zero = 0;
		int sum = 0;
		int even = 0;
		for (auto it: s) {
			int x = int(it-'0');
			sum += x;
			if ((x != 0 && x % 2 == 0) || (zero == 1 && x == 0)) {
//				std::cout << x << ' ' << x%2 << '\n';
				even = 1;
			}
			if (x == 0) {
				zero = 1;
			}
		}
		if (sum == 0 || (sum % 3 == 0 && even == 1 && zero == 1)) {
			std::cout << "red\n";
		} else {
			std::cout << "cyan\n";
		}
	}
}