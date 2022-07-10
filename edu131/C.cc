#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

using ll = long long;

ll t, n, m, a[maxn], w[maxn];

bool check(ll x) {
	ll tasks = 0;
	for (ll i = 1; i <= n; i++) {
		if (w[i] < x) {
			tasks -= (x-w[i])/2;
		} else {
			tasks += (w[i]-x);
		}
	}
	return tasks <= 0;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		std::fill(w, w+n+1, 0);
		for (ll i = 0; i < m; i++) {
			std::cin >> a[i];
			w[a[i]]++;
		}
		ll l = 1, r = 1e6, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ll ans = l+10;
		while (check(ans)) {
			ans--;
		}
		ans+1;
		std::cout << l << '\n';
	}
}