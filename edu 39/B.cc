#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll a, b;
	std::cin >> a >> b;
	while (1) {
		if (!a||!b) {
			std::cout << a << " " << b;
			break;
		} else if (a >= 2*b) {
			a %= 2*b;
		} else if (b >= 2*a) {
			b %= 2*a;
		} else {
			std::cout << a << " " << b;
			break;
		}
	}
}