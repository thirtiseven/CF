#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll T, l, r;
	std::cin >> T;
	while (T--) {
		std::cin >> l >> r;
		std::cout << l << " " << l*2 << '\n';
	}
}