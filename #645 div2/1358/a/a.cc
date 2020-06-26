#include <iostream>
#include <algorithm>

using ll = long long;

ll t, n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		if (n % 2 == 1 && m % 2 == 1) {
			std::cout << (n-1)/2*m+(m+1)/2 << '\n';
		} else {
			std::cout << n*m/2 << '\n';
		}
	}
}