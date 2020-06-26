#include <iostream>

int a, b, T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		int x = b-a;
		if (x == 0) {
			std::cout << "0\n";
		} else if (x < 0) {
			if (x % 2 == 0) {
				std::cout << "1\n";
			} else {
				std::cout << "2\n";
			}
		} else {
			if (x % 2 == 1) {
				std::cout << "1\n";
			} else {
				std::cout << "2\n";
			}
		}
	}
}