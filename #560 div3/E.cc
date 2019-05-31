#include <iostream>
#include <algorithm>

const int mod =  998244353;
const int maxn = 2e5+7;

using ll = unsigned long long;
ll a[maxn], b[maxn];
int n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] *= (i*(n+1LL-i));
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	std::sort(a+1, a+n+1);
	std::sort(b+1, b+n+1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] %= mod;
		a[i] *= b[n+1-i];
		a[i] %= mod;
		ans += a[i];
		ans %= mod;
	}
	std::cout << ans << '\n';
}