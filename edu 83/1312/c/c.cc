#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 32;

ll T, n, k, a[maxn], tot[100];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::fill(tot, tot+100, 0);
		std::cin >> n >> k;
		ll x = 0, y = 0;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			while (a[i] > 0) {
				if (a[i]%k > 1ll) {
					yes = 0;
					break;
				}
				if (a[i]%k == 1ll) {
					tot[cnt]++;
//					std::cout << cnt << '\n';
				}
				if (tot[cnt] > 1ll) {
					yes = 0;
					break;
				}
				a[i] /= k;
				cnt++;
			}
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}