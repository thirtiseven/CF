#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, k;
	std::cin >> n >> k;
	if (2LL*n-1LL < k) {
		std::cout << "0\n";
	} else if (n >= k-1LL) {
		std::cout << (k-1LL)/2LL << '\n';
	} else {
		std::cout << n-(k-1LL)/2LL << '\n';
	}
}