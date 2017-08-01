#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

int main(int argc, char *argv[]) {  
	int k2, k3, k5, k6;
	std::cin >> k2 >> k3 >> k5 >> k6;
	int sum = 0;
	int minus256 = std::min(k2, std::min(k5, k6));
	k2 -= minus256;
	int minus32 = std::min(k2, k3);
	sum = minus256 * 256 + minus32 * 32;
	std::cout << sum;
	return 0;
}