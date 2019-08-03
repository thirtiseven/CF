#include <iostream>

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	if (n % 2 == 1) {
		std::cout << "0\n";
	} else {
		std::cout << (1<<(n/2)) << "\n";
	}
}