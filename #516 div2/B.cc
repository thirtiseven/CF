#include <iostream>

int main(int argc, char *argv[]) {  
	long long t;
	std::cin >> t;
	while (t--) {
		unsigned a;
		std::cin >> a;
		int n = __builtin_popcount(a);
		std::cout << (1<<n) << '\n';
	}
}