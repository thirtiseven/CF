#include <iostream>
#include <cmath>
#include <iomanip>

using ld = long double;

ld f(double n) {
	return ld(floor(n/2)*ceil(n/2));
}

ld g(double n) {
	return (n-1)*(n)/2.0;
}

int main(int argc, char *argv[]) {  
	ld n;
	int m;
	std::cin >> n >> m;
	ld x, d;
	ld ans = 0;
	
	for (int i = 0; i < m; i++) {
		std::cin >> x >> d;
		ans += x*n;
		if (d > 0) {
			ans += d*g(n);
		} else if (d < 0) {
			ans += d*f(n);
		}
	}
	std::cout << std::fixed << std::setprecision(18) << ans/n;
}