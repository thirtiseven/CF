#include <iostream>

int n, m, k, x, y;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> k;
	for (int i = 0; i < k*2; i++) {
		std::cin >> x >> y;
	}
	std::cout << n+m+n*m-3 << '\n';
	for (int i = 0; i < n-1; i++) {
		std::cout << "U";
	}
	for (int i = 0; i < m-1; i++) {
		std::cout << "L";
	}
	for (int i = 0; i < n; i++) {
		if (i%2==0) {
			for (int j = 0; j < m-1; j++) {
				std::cout << "R";
			}
			if (i != n-1) {
				std::cout << "D";
			}
		} else {
			for (int j = 0; j < m-1; j++) {
				std::cout << "L";
			}
			if (i != n-1) {
				std::cout << "D";
			}
		}
	}
	std::cout << '\n';
}