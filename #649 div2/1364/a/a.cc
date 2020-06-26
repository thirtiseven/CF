#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 1e5;

ll T, n, x, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		if (sum % x == 0) {
			ll ans = -1;
			for (ll i = 0; i < n; i++) {
				if (a[i] % x != 0) {
					ans = std::max(ans, n-i-1);
					break;
				}
			}
			for (ll i = n-1; i >= 0; i--) {
				if (a[i] % x != 0) {
					ans = std::max(ans, i);
					break;
				}
			}
			std::cout << ans << '\n';
		} else {
			std::cout << n << '\n';
		}
	}
}