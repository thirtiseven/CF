#include <iostream>
#include <algorithm>

const int maxn = 100000+7;
using ll = long long;

ll n, m, a[maxn];

ll minn[maxn], maxx[maxn], yes[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> m;
		maxx[i] = 0, minn[i] = 1000000, yes[i] = 0;
		for (ll j = 0; j < m; j++) {
			std::cin >> a[j];
			if (a[j] > minn[i]) {
				yes[i] = 1;
 			}
 			maxx[i] = std::max(a[j], maxx[i]);
			minn[i] = std::min(a[j], minn[i]);
		}	
		if (yes[i]) {
			maxx[i] = 1000000;
		}
//		std::cout << maxx[i] << ' ' << minn[i] << '\n';	
	}
	std::sort(maxx, maxx+n);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (yes[i]) {
			ans += n;
		} else {
			int x = std::upper_bound(maxx, maxx+n, minn[i]) - maxx;
//			std::cout << x << '\n';
			ans += (n - x);
		}
	}
	std::cout << ans << '\n';
}