#include <iostream>
#include <algorithm>

using ll = long long;
ll t, n, r;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> r;
		ll ans = 0;
		ll x;
		if (r >= n) {
			x = 1;
		} else {
			x = 0;
		}
		ll y = std::min(n-1, r);
		ans += (y+1LL)*y/2ll;
		ans += x;
//		std::cerr << n << ' ' << r << ' ' << x << ' ' << y << '\n';
 		std::cout << ans << '\n';
	}
}