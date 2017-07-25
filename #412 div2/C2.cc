#include <iostream>
#include <algorithm>
#define ll long long

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	while(t--) {
		ll x, y, p, q;
		std::cin >> x >> y >> p >> q;
		if((p == 0 && x != 0) || (p == q && x != y)) {
			std::cout << "-1";
			continue;
		}  
		if((p == 0 && x == 0) || (p == q && x == y)) {
			std::cout << "0";
			continue;
		} 
		ll n = std::max(std::max((x + p - 1) / p, ( y + q - 1) / q), (q - p + y - x - 1) / (q - p));
		std::cout << n * q - y << std::endl;
	}
	return 0;
}