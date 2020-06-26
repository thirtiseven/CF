#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;

ll T, c, h, t;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> h >> c >> t;
		if (t == h) {
			std::cout << "1\n";
		} else if (t*2 <= h+c) {
			std::cout << "2\n";
		} else {
			if ((t-c)%(2*t-h-c)==0) {
				ll xx = (t-c)/(2*t-h-c);
				std::cout << 2*xx-1 << '\n';
				continue;
			}
			double x = (double(t-c)/double(2*t-h-c));
			ll a = floor(x);
			ll b = ceil(x);
//			std::cerr << x << ' ' << a << ' ' << b << '\n';
			if (((2*a-1)*t-a*h-(a-1)*c)*(2*b-1) >= (b*h+(b-1)*c-(2*b-1)*t)*(2*a-1)) {
				std::cout << 2*a-1 << '\n';
			} else {
				std::cout << 2*b-1 << '\n';
			}
		}
	}
}