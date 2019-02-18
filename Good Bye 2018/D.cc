#include <iostream>

using ll = long long;

const int maxn = 1e6+7;
const ll mod = 998244353;

ll fac[maxn], inv[maxn];

void init(ll n) {
	fac[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fac[i] = fac[i-1]*i%mod;
	}
	inv[n] = n;
	for (ll i = n-1; i >= 1; i--) {
		inv[i] = inv[i+1]*i%mod;
	}
}

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	ll ans = 0;
	init(n);
	for (int i = 0; i < n-1; i++) {
		ans += inv[n-i]*(fac[n-i-1]-1);
		ans %= mod;
	}
	ans += fac[n];
	std::cout << ans%mod << '\n';
}