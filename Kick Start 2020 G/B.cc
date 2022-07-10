#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 1e5+7;
const ll inf = 1e9;

ll t, n, x1[maxn], y1[maxn], x2[maxn], y2[maxn];
//std::pair<ll, ll> xsort[maxn], ysort[maxn];

ll calx(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (x < x1[i]) {
			res += (x1[i] - x);
		} else if (x > x2[i]) {
			res += (x - x2[i]);
		}
	}
	return res;
}

ll caly(ll y) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (y < y1[i]) {
			res += (y1[i] - y);
		} else if (y > y2[i]) {
			res += (y - y2[i]);
		}
	}
	return res;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CA = 1; CA <= t; CA++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
//			xsort[i] = std::make_pair(x1[i], x2[i]);
//			ysort[i] = std::make_pair(y1[i], y2[i]);
		}
		ll ansx = -1, ansy = -1;
		ll l = -inf, r = inf, mid1, mid2;
		while (l <= r-3) {
			mid1 = l + (r-l)/3, mid2 = l + (r-l)/3*2;
			if (calx(mid1) > calx(mid2)) {
				l = mid1;
			} else {
				r = mid2;
			}
		}
//		std::cerr << l << ' ' << l + 1 << ' ' << l + 2 << ' ' << r << '\n';
		ansx = l+1;
		while (calx(ansx) == calx(ansx-1)) {
			ansx--;
		}
		l = -inf, r = inf;
		while (l <= r-3) {
			mid1 = l + (r-l)/3, mid2 = l + (r-l)/3*2;
			if (caly(mid1) > caly(mid2)) {
				l = mid1;
			} else {
				r = mid2;
			}
		}
//		std::cerr << l << ' ' << l + 1 << ' ' << l + 2 << ' ' << r << '\n';
		ansy = l+1;
		while (caly(ansy) == caly(ansy-1)) {
			ansy--;
		}
		std::cout << "Case #" << CA << ": " << ansx << ' ' << ansy << '\n';
	}
}