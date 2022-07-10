#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
const ll mod = 998244353;
const int maxn = 2e5+10;
ll T, n, a[maxn];

static std::vector<ll> inverse_table(ll x, ll md) {
	std::vector<ll> inv(x);
	inv[1] = 1;
	for (ll i = 2; i < x; ++i) {
		inv[i] = (ll)(md - md / i) * inv[md % i] % md;
	}
	return inv;
}

struct Binomial {
	ll n, md;
	std::vector<ll> factorial, inv_factorial;
	Binomial(ll n, ll mod) : n(n), md(mod) {
		factorial.resize(n + 1);
		inv_factorial = inverse_table(n, md);
		factorial[0] = inv_factorial[0] = 1LL;
		for (ll i = 1; i <= n; i++) {
			factorial[i] = 1LL * factorial[i - 1] * i % md;
			inv_factorial[i] = 1LL * inv_factorial[i - 1] * inv_factorial[i] % md;
//			std::cerr << inv_factorial[i] << ' ';
		}
	}
	ll choose(ll x, ll k) {
		if (k > x) return 114514;
//		std::cerr << factorial[x] << ' ' << inv_factorial[k] << ' ' << inv_factorial[x - k] << '\n';
		return 1LL * factorial[x] * inv_factorial[k] % md * inv_factorial[x - k] % md;
	}
};

Binomial B(200003, mod);

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		std::reverse(a, a+n);
		if (a[0]-a[1] > 1) {
			std::cout << "0\n";
			continue;
		}
		ll maxnum = 1;
		while (a[maxnum] == a[0]) {
			maxnum++;
		}
		ll ans;
		if (maxnum > 1) {
			ans = B.factorial[n] % mod;
		} else {
			ll secnum = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == a[0]-1) {
					secnum ++;
				}
			}
			ans = B.factorial[secnum] * (secnum) % mod * B.choose(n, secnum+1) % mod * (B.factorial[n-secnum-1]) % mod;
		}
		std::cout << ans << '\n';
	}
}