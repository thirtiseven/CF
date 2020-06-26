#include <iostream>
#include <algorithm>

int T, n;

bool is_prime(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		if (n == 1) {
			std::cout << "FastestFinger\n";
		} else if (n == 2) {
			std::cout << "Ashishgup\n";
		} else if (n % 2 == 1) {
			std::cout << "Ashishgup\n";
		} else {
			n /= 2;
//			>1的奇数 * 质数 * 2 => Ash 
			if (n % 2 == 0) {
				while (n % 2 == 0) {
					n /= 2;
				}
				if (n > 1) {
					std::cout << "Ashishgup\n";
					continue;
				} else {
					std::cout << "FastestFinger\n";	
					continue;
				}
			}
			if (!is_prime(n)) {
				std::cout << "Ashishgup\n";
				continue;
			}
			std::cout << "FastestFinger\n";	
		}
	}
}

