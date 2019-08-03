#include <iostream>

using ll = unsigned long long;
const ll mod = 998244353;
const ll maxn = 100007;

ll pow(ll n) {
	ll ans = 1;
	for (ll i = 1; i < n; i++) {
		ans *= 10ll;
	}
	return ans%mod;
}

int main(int argc, char *argv[]) {  
	ll ans = 0;
	ll n;
	ll a[maxn];
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
		ll x = a[i];
		ll cnt = 1LL;
		ll y;
		while (x) {
			y = x%10;
			x /= 10;
			ans += (y*pow(cnt))%mod*n;
			ans %= mod;
			ans += (y*pow(cnt+1))%mod*n;
			ans %= mod;
			cnt += 2;
		}
	}
	std::cout << ans << '\n';
}