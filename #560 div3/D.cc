#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

const int maxn = 321;

using ll = long long;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll t, n, d[maxn];
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		ll ans = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> d[i];
		}
		std::sort(d, d+n);
		ans = d[n-1]*d[0];
		int x = 0;
		for (ll i = 2; i <= d[n-1]; i++) {
			if (ans % i == 0) {
				if (i != d[x]) {
					ans = -1;
					break;
				}
				x++;
//				std::cout << "yes!\n";
			}
		}
		if (ans != -1) {
			ll test = ans;
			for (int i = 0; i < n; i++) {
				while (test % d[i] == 0) {
					test /= d[i];
				}
			}
			if (test != 1) ans = -1;
		}
		std::cout << ans << '\n';
	}
}