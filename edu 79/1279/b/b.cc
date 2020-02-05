#include <iostream>

using ll = long long;
const int maxn = 1e5+7;

ll T, n, s;
ll a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		ll sum = 0, maxx = 0;
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (ll i = 0; i < n; i++) {
			sum += a[i];
			ll temp = ans;
			if (a[i] > maxx) {
				maxx = a[i];
				ans = i+1;
//				std::cout << ans << "!!\n";
			}
			if (sum - maxx > s) {
				ans = temp;
				break;
			}
		}
		if (sum <= s) {
			ans = 0;
		}
		std::cout << ans << '\n';
	}
}