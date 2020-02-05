#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	long long x;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		if (x >= 15 && x % 14 >= 1 && x % 14 <= 6) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}