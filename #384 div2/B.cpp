#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	long long n, k;
	std::cin >> n >> k;
	std::cout << log2(k&(-k)) + 1 << std::endl;
	return 0;
}