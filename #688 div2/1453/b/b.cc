#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
using ll = long long;

ll T, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		ll maxx = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			if (i == 1 || i == n-1) {
				maxx = std::max(maxx, std::abs(a[i]-a[i-1]));
			}
			if (i < n-1) {
				maxx = std::max(maxx, std::abs(a[i]-a[i-1]+a[i]-a[i+1])-std::abs(a[i+1]-a[i-1]));
			}
			ans += std::abs(a[i]-a[i-1]);
		}
		ans -= maxx;
		std::cout << ans << '\n';
	}
}