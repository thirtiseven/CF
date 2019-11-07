#include <iostream>

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		int n;
		std::cin >> n;
		if (n < 4) {
			std::cout << 4-n << '\n';
		} else if (n % 2 == 0) {
			std::cout << "0\n";
		} else {
			std::cout << "1\n";
		}
	}
}