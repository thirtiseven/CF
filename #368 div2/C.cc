#include <iostream>
#define ll long long

int main(int argc, char *argv[]) {  
	ll n, alice, bob, p;
	std::cin >> n;
	p = n * n;
	if(n <= 2) {
		std::cout << -1 << '\n';
		return 0;
	}
	if(p % 2 == 1) {
		alice = (p - 1) / 2;
		bob = (p + 1) / 2;
	} else {
		alice = (p / 2 + 2) / 2;
		bob = ((p / 2 - 2)) / 2;
	}
	std::cout << alice << " " << bob << '\n';
	return 0;
}