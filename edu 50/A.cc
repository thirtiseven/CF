#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	long long n, k;
	std::cin >> n >> k;
	std::cout << ((k%n)?(k/n+1):(k / n));
}