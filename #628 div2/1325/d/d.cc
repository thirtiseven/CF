#include <iostream>
#include <bitset>
#include <cassert>

using ll = unsigned long long;

ll u, v;
std::bitset<128> b, c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> u >> v;
	ll rrru = u, rrrv = v;
	std::bitset<128> a(u);
	if (v < u) {
		std::cout << "-1\n";
		exit(0);
	} else if (v == u) {
		if (u == 0) {
			std::cout << "0\n";
			exit(0);
		} else {
			std::cout << "1\n" << u << '\n';
			exit(0);
		}
	} else if (v % 2 != u % 2) {
		std::cout << "-1\n";
		exit(0);
	} else {
		v -= u;
		v /= 2;
		ll now = 0;
		while (v) {
			b[now] = c[now] = v%2;
			v /= 2;
			now++;
		}
		if ((a^b)==(a|b)) {
			ll x = (a|b).to_ullong();
			ll y = b.to_ullong();
			std::cout << "2\n" << x << ' ' << y << '\n';
			exit(0);
		} else {
			ll x = a.to_ullong();
			ll y = b.to_ullong();
			ll z = c.to_ullong();
			std::cout << "3\n";
			std::cout << a.to_ullong() << ' ' << b.to_ullong() << ' ' << c.to_ullong() << '\n';
			exit(0);
		}
	}
}