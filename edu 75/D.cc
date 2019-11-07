#include <iostream>
#include <algorithm>

using ll = long long;
const ll maxn = 2e5+7;

ll n, s, rest;
std::pair<ll, ll> p[maxn];
ll upp[maxn];

bool check(ll x) {
	ll now = 0;
	ll left = rest;
	for (ll i = n-1; i >= 0; i--) {
		if (p[i].first >= x) {
			now++;
		} else if (p[i].second >= x) {
			left -= (x-p[i].first);
			if (left < 0) {
				if (now < n/2+1) {
					return 0;
				} else {
					return 1;
				}
			}
			now++;
		}
	}
	if (now < n/2+1) {
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	ll T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		rest = s;
		for (ll i = 0; i < n; i++) {
			std::cin >> p[i].first >> p[i].second;
			upp[i] = p[i].second;
			rest -= p[i].first;
		}
		std::sort(p, p+n);
		std::sort(upp, upp+n);
		ll l = p[n/2].first, r = std::min(upp[n/2], s), mid;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		while (!check(l)) {
			l--;
		}
		std::cout << l << '\n';
	}
}