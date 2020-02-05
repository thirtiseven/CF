#include <iostream>

using ll = long long;

const int maxn = 250000;

ll n, m;

ll fac[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	fac[1] = 1LL;
	for (ll i = 2; i <= n; i++) {
		fac[i] = fac[i-1]*i;
		fac[i] %= m;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll tem = fac[n-i];
		tem *= fac[i];
		tem %= m;
		tem *= (n-i+1);
		tem %= m;
		tem *= (n-i+1);
		tem %= m;
		ans += tem;
		ans %= m;
	}
	ans += fac[n];
	ans %= m;
	std::cout << ans << '\n';
}