#include <iostream>
#include <string>

int t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n == 1) {
			std::cout << "-1\n";
		} else {
			std::cout << "2";
			for (int i = 0; i < n-1; i++) {
				std::cout << "3";
			}
			std::cout << "\n";
		}
	}
}