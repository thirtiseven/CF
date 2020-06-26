#include <iostream>

using ll = long long;

ll t, n, k;

ll check(ll a) {
	if (a - a/n >= k) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		ll l = 1, r = 2e9, mid;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		std::cout << l << '\n';
	}
}