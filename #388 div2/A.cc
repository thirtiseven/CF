#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if(n%2==0) {
		std::cout << n/2 << "\n";
		for(int i = 0; i < n / 2; i++) {
			std::cout << "2 ";
		}
	} else {
		std::cout << n/2 << "\n";
		for(int i = 0; i < n / 2 - 1; i++) {
			std::cout << "2 ";
		}
		std::cout << "3";
	}
	return 0;
}