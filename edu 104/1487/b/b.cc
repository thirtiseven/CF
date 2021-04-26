#include <iostream>
#include <algorithm>

using ll = long long;

ll t, n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		if (n % 2 == 0) {
			std::cout << ((k-1) % n) + 1 << '\n';
		} else {
			std::cout << ((k-1+((k-1)/(n/2))) % n) + 1 << '\n';
		}
	}
}