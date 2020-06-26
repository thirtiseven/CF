#include <iostream>

using ll = long long;

ll t, n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		if (k % 2 == 0 && n % 2 == 1) {
			std::cout << "NO\n";
		} else if (k % 2 == 0 && n % 2 == 0) {
			if (n < k) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
				for (int i = 0; i < k-1; i++) {
					std::cout << 1 << ' ';
				}
				std::cout << n-k+1 << '\n';
			}
		} else if (n % 2 == 0 && k % 2 == 1) {
			if (n < 2*k) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
				for (int i = 0; i < k-1; i++) {
					std::cout << 2 << ' ';
				}
				std::cout << n-(k-1)*2 << '\n';
			}
		} else {
			if (n < k) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
				for (int i = 0; i < k-1; i++) {
					std::cout << 1 << ' ';
				}
				std::cout << n-k+1 << '\n';
			}
		}
	}
}