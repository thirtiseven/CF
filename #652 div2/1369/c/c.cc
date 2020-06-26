#include <iostream>
#include <algorithm>
#include <cassert>

const int maxn = 2e5+7;
using ll = long long;

ll T, n, k, a[maxn], w[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < k; i++) {
			std::cin >> w[i];
		}
		std::sort(a, a+n);
		std::sort(w, w+k);
		std::reverse(w, w+k);
		ll ans = 0;
		int tot = 0;
		for (int i = 0; i < k; i++) {
			ans += a[n-1-i];
			if (w[k-1-i] == 1) {
				ans += a[n-1-i];
			}
		}
		for (int i = 0; i < k; i++) {
			if (w[i] == 1) {
				break;
			}
			ans += a[tot];
			tot += w[i]-1;
		}
		std::cout << ans << '\n';
	}
}