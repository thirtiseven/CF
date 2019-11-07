#include <iostream>

using ll = long long;

const ll mod = 1e9+7;

ll x, n;

ll PowMod(ll a, ll b, const ll &Mod) { 
	a %= Mod;
	ll ans = 1LL; 
	while(b) {
		if (b & 1LL){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1LL;
	}
	return ans; 
}

ll ans = 1;

int main(int argc, char *argv[]) {  
	std::cin >> x >> n;
	ll tmp = x;
	ll powi, tot, pre;
	for (ll i = 2ll; i * i <= x; i++) {
		if (tmp % i == 0) {
			powi = i;
			tot = 0;
			pre = powi;
			while (powi <= n && powi >= pre) {
				tot += n / powi;
				pre = powi;
				powi *= i;
			}
//			std::cerr << PowMod(i, tot, mod) << '\n';
			ans *= PowMod(i, tot, mod);
			ans %= mod;
		}
		while (tmp % i == 0) {
			tmp /= i;
		}
	}
	if (tmp > 1) {
		powi = tmp;
		tot = 0;
		pre = 0;
		while (powi <= n && powi >= pre) {
			tot += n / powi;
			pre = powi;
			powi *= tmp;
		}
//		std::cerr << PowMod(tmp, tot, mod) << '\n';
		ans *= PowMod(tmp, tot, mod);
		ans %= mod;
	}
	std::cout << ans << '\n';
}