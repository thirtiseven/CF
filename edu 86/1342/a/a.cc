#include <iostream>

long long t, a, b, x, y;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> x >> y >> a >> b;
		long long ans = 0;
		if (b < 2*a) {
			ans = b*std::min(x, y)+a*(std::abs(x-y));
		} else {
			ans = a*(x+y);
		}
		std::cout << ans << '\n';
	}
}