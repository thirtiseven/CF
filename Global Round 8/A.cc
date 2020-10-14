#include <iostream>
#include <algorithm>

int t, n, a;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			if (i % 2 == 0 && a != 0) {
				std::cout << "-";
			}
			std::cout << std::abs(a) << ' ';
		}
		std::cout << '\n';
	}
}