#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

const ll mod = 998244353;

ll PowMod(ll a, ll b, const ll &Mod) { 
	a %= Mod;
	ll ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}

ll Inv(ll a, ll mod){ 
	return PowMod(a,mod-2,mod);
}

static std::vector<ll> inverse_table(ll n, ll md) {
	std::vector<ll> inv(n);
	inv[1] = 1;
	for (ll i = 2; i < n; ++i) {
		inv[i] = (int64_t)(md - md / i) * inv[md % i] % md;
	}
	return inv;
}

struct Binomial {
	ll n, md;
	std::vector<ll> factorial, inv_factorial;
	Binomial(ll n, ll mod) : n(n), md(mod) {
		factorial.resize(n + 1);
		inv_factorial = inverse_table(n, md);
		factorial[0] = inv_factorial[0] = 1;
		for (ll i = 1; i <= n; i++) {
			factorial[i] = 1LL * factorial[i - 1] * i % md;
			inv_factorial[i] = 1LL * inv_factorial[i - 1] * inv_factorial[i] % md;
		}
	}
	ll choose(ll n, ll k) {
		if (k > n) return 0;
		return 1LL * factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] %
					 md;
	}
};

Binomial CC(500005, mod);

ll n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (n/i >= k) {
			ans += CC.choose(n/i-1, k-1);
			ans %= mod;
		} else {
			break;
		}
	}
	std::cout << ans << '\n';
}