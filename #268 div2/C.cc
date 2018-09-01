#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if (n < 4) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		if (n % 2 == 0) {
			std::cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
			for (int i = 5; i < n; i+=2) {
				std::cout << i+1 << " - " << i << " = 1\n 1 * 24 = 24\n";
			}
		} else {
			std::cout << "3 + 4 = 7\n7 + 5 = 12\n2 * 12 = 24\n24 * 1 = 24\n";
			for (int i = 6; i < n; i+=2) {
				std::cout << i+1 << " - " << i << " = 1\n 1 * 24 = 24\n";
			}
		}
	}
}