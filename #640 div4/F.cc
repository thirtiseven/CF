#include <iostream>
#include <string>

int t, n0, n1, n2;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n0 >> n1 >> n2;
		if (n1 > 0 || n0 > 0) {
			std::cout << "0";
		}
		for (int i = 0; i < n0; i++) {
			std::cout << "0";
		}
		if (n1 > 0) {
			std::cout << "1";
			n1--;
		} else if (n2 > 0) {
			std::cout << "1";
		}
		for (int i = 0; i < n2; i++) {
			std::cout << "1";
		}
		for (int i = 0; i < n1; i++) {
			if (i%2==0) {
				std::cout << "0";
			} else {
				std::cout << "1";
			}
		}
		std::cout << '\n';
	}
}