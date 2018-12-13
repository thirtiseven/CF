#include <iostream>

int main(int argc, char *argv[]) {  
	long long t, a, b, k;
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> k;
		if (k % 2 == 1) {
			std::cout << (a-b)*(k/2)+a <<'\n';
		} else {
			std::cout << (a-b)*(k/2) <<'\n';
		}
	}
}