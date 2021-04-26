#include <iostream>
#include <algorithm>
#include <cmath>

const int maxn = 123;
int t, n, u, v, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> u >> v;
		int minn = 1e6+1, maxx = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			minn = std::min(a[i], minn);
			maxx = std::max(a[i], maxx);
		}
		int ans = 2e9+1;
		for (int i = 1; i < n; i++) {
			if (std::abs(a[i-1]-a[i]) > 1) {
				ans = 0;
				break;
			} else if (std::abs(a[i-1]-a[i]) == 1) {
				ans = std::min(ans, std::min(u, v));
			} else {
				ans = std::min(ans, std::min(v+v, u+v));
			}
		}
		std::cout << ans << '\n';
	}
}