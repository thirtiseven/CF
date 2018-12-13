#include <iostream>

using ll = long long;

ll sum(ll a) {
	if (a == 0) {
		return 0;
	}
	if (a%2==0) {
		return a/2;
	}
	return -(a+1)/2;
}

int main(int argc, char *argv[]) {  
	ll t, l, r;
	std::cin >> t;
	while (t--) {
		std::cin >> l >> r;
		std::cout << sum(r) - sum(l-1) << '\n';
	}
}