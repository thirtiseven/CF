#include <iostream>

int t, n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		if (n*m%2==0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (n*m%2==0 && i==0 && j==0) {
						std::cout << "B";
					} else if ((i+j)%2==0) {
						std::cout << "W";
					} else {
						std::cout << "B";
					}
				}
				std::cout << '\n';
			}
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if ((i+j)%2==0) {
						std::cout << "B";
					} else {
						std::cout << "W";
					}
				}
				std::cout << '\n';
			}
		}
	}
}