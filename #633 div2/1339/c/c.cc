#include <iostream>

const int maxn = 1e5+7;
using ll = long long;

ll t, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		ll cur = 1ll, k = 1ll;
		bool yes = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i-1]) {
				yes = 1;
				ll d = a[i-1]-a[i];
				if (d <= cur*2ll-1ll) {
					a[i] = a[i-1];
					continue;
				}
				while (d > cur*2ll-1ll) {
					cur *= 2ll;
					k++;
				}
				a[i] = a[i-1];
			}
		}
//		for (int i = 0; i < n; i++) {
//			std::cout << a[i] << " \n"[i==n-1];
//		}
		if (yes) {
			std::cout << k << '\n';
		} else {
			std::cout << 0 << '\n';
		}
	}
}