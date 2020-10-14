#include <iostream>
#include <algorithm>

int T, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		if (n == 2) {
			std::cout << "2\n1 2\n";
			continue;
		}
		std::cout << "2\n";
		std::cout << n << ' ' << n-2 << '\n';
		std::cout << n-1 << ' ' << n-1 << '\n';
		for (int i = 0; i < n-3; i++) {
			std::cout << n-1-i << ' ' << n-1-i-2 << '\n';
		}
	}
}