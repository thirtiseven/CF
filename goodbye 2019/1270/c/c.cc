#include <iostream>

using ll = long long;

const int maxn = 1e5+7;

int T;
ll n, a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		ll x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			x += a[i];
			y ^= a[i];
		}
		ll a = 0, b = 0, c = 1LL<<58;
		if (x % 2ll == 1LL) {
			c++;
		}
		a = (y*2-x+c)/2ll;
		b = a;
		if (x % 2ll == 1LL) {
			a -= 2ll;
			b -= 2ll;
		}
//		if (x+a+b+c == 2ll*(y^a^b^c)) {
//			std::cout << "YES\n";
//		} else {
//			std::cout << x << ' ' << y << '\n';
//			std::cout c<< x+a+b+c << '\n';
//			std::cout << 2ll*(y^a^b^c) << ' ' << 2ll*(y^c) << ' ' << 2ll*(y+c) << '\n';
//			std::cout << "NO\n";
//		}
		std::cout << 3 << '\n' << a << ' ' << b << ' ' << c << '\n';
	}
}