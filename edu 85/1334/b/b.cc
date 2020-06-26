#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 1e5+7;

ll T, n, x, a[maxn], sum;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x;
		sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		std::sort(a, a+n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if ((n-i)*x <= sum) {
//				std::cout << ((n-i)*x) << ' ' << sum << '\n';
				ans = n-i;
				break;
			}
			sum -= a[i];
		}
		std::cout << ans << '\n';
	}
}