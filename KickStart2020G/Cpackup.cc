#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
using ll = long long;

ll T, w, n, x[maxn];

ll gao(ll val) {
	ll ret = 0;
	for (int i = 0; i < w; i++) {
		ret += std::min(std::min(x[i], val)+n - std::max(x[i], val), std::max(x[i], val)-std::min(x[i], val));
	}
	return ret;
}

ll midmod(ll x, ll y) {
	if ((x+n-y)%n > (y+n-x)%n) {
		std::swap(x, y);
	}
	ll res;
	if (y < x) {
		y += n;
	}
	res = ((x+y)/2)%n;
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (ll CAS = 1; CAS <= T; CAS++) {
		std::cin >> w >> n;
		for (ll i = 0; i < w; i++) {
			std::cin >> x[i];
			x[i]--;
		}
		ll x1 = 0, x2 = (n+1)/3, x3 = n*2/3;
		ll res1 = gao(x1), res2 = gao(x2), res3 = gao(x3);
		if (res1 > res2) {
			std::swap(x1, x2);
		}
		if (res3 > res2) {
			std::swap(x2, x3);
		}
		int cnt = 100;
		while (std::abs(x1-x3) > 3 && cnt) {
			cnt--;
			std::cout << x1 << ' ' << x2 << ' ' << x3 << '\n';
			x2 = midmod(x1, x3);
			res2 = gao(x2);
			if (res1 > res2) {
				std::swap(x1, x2);
			}
			if (res3 > res2) {
				std::swap(x2, x3);
			}
		}
		ll ans = 1e15;
		if (x3 < x1) {
			x3 += n;
		}
		std::cout << x1 << ' ' << x3 << '\n';
		for (ll i = std::min(x1, x3); i <= std::max(x1, x3); i++) {
			std::cout << i << ' ' << gao(i%n) << '\n';
			ans = std::min(ans, gao(i%n));
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}