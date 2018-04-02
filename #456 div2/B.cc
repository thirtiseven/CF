#include <iostream>

int main(int argc, char *argv[]) {  
	unsigned long long n, k;
	std::cin >> n >> k;
	unsigned long long x = 1;
	while(x <= n) {
		x *= 2;
	}
	std::cout << (k>1?(x-1):n);
}