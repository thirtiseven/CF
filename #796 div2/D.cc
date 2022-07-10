#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 2e5+7;

ll t, n, k, a[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		ll ans = 0;
		if (k < n) {
			ll cur = 0;
			for (int i = 0; i < k; i++) {
				cur += a[i];
				ans = std::max(ans, cur);
			}
			for (int i = k; i < n; i++) {
				cur -= a[i-k];
				cur += a[i];
				ans = std::max(ans, cur);
			}
			ans += (k-1)*k/2;
		} else {
			for (int i = 0; i < n; i++) {
				ans += a[i];
			}
			ans += (k-n)*n+(n-1)*n/2;
		}
		std::cout << ans << '\n';
	}
}

/*
0000000

*/