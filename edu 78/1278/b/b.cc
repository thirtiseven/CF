#include <iostream>
#include <algorithm>

using ll = long long;
ll T, a, b;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		ll x = std::abs(a-b);
		if (x == 0) {
			std::cout << "0\n";
			continue;
		}
		for (ll i = 1; i <= 50000; i++) {
			if (i*(i+1)/2 >= x && (i*(i+1)/2)%2 == x%2) {
				std::cout << i << '\n';
				break;
			}
		}
	}
}