#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

using ll = long long;

ll n, k, a[maxn], pre[maxn], shu[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a+1, a+n+1);
	pre[0] = shu[n+1] = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		shu[i] = shu[i+1] + a[i];
	}
	ll ans = 1e18;
	for (ll i = 1; i <= n; i++) {
		if (i >= k) {
//			std::cout << "1 " << a[i]*i-pre[i] << '\n';
			ans = std::min(ans, a[i]*i-pre[i]);
		}
		if (n-i+1 >= k) {
//			std::cout << "2 " << (n-i+1)*a[i]-shu[i] << '\n';
			ans = std::min(ans, shu[i]-(n-i+1)*a[i]);
		}
//		std::cout << "3 " << a[i]*i-pre[i]+shu[i]-(n-i+1)*a[i] << '\n';
		ans = std::min(ans, a[i]*i-pre[i]+shu[i]-(n-i+1)*a[i]);
	}
	std::cout << ans << '\n';
}