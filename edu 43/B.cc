#include <iostream>

using ll = unsigned long long;

int main(int argc, char *argv[]) {  
	ll n, m, k;
	std::cin >> n >> m >> k;
	if (k < n) {
		std::cout << k+1 << ' ' << 1;
	} else {
		k -= n;
		int r = k/(m-1);
		int c = k%(m-1);
		if (r % 2 == 0) {
			std::cout << n-r << " " << c+2;
		} else {
			std::cout << n-r << " " << m-c;
		}
	}
}