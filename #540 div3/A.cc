#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		ll n, a, b;
		std::cin >> n >> a >> b;
		if (2*a <= b) {
			std::cout << n*a << '\n';
		} else {
			std::cout << n/2*b+(n%2)*a << '\n';
		}
	}
}