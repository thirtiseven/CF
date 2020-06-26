#include <iostream>
#include <algorithm>

int n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	if (k >= 2*n) {
		std::cout << "YES\n";
		for (int i = 0; i < n-1; i++) {
			std::cout << "2 ";
		}
		std::cout << k-2*(n-1) << '\n';
		std::cout << "1\n";
	} else {
		std::cout << "NO\n";
	}
}