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
		ll y = k-3;
		n -= y;
		ll x = 1, nn = n;
		while (nn%2==0) {
			nn /= 2;
			x *= 2;
		}
		for (int i = 0; i < y; i++) {
			std::cout << "1 ";
		}
		if (nn == 1) {
			std::cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
		} else {
			std::cout << x << ' ' << (nn-1)/2*x << ' ' << (nn-1)/2*x << '\n';
		}
	}
}