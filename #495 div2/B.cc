#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		if (i%2==0) {
			std::cout << '1';
		} else {
			std::cout << '0';
		}
	}
}