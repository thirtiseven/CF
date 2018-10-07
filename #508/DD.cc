#include <iostream>
#include <algorithm>

const int maxn = 500009;

using ll = long long;

ll a[maxn], n;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	ll minn = 1e9;
	bool yes = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		minn = std::min(a[i], minn);
		if (a[i] <= 0) {
			ans += -a[i];
			yes = 0;
		} else {
			ans += a[i];
		}
	}
	if (yes && n!= 1LL) {
		ans -= 2LL*minn;
	} else if (n == 1LL) {
		ans = a[1];
	}
	std::cout << ans;
}