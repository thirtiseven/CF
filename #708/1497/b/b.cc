#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
int t, n, m, a[maxn], mod[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		std::fill(mod, mod+m, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			mod[a[i]%m]++;
		}
//		for (int i = 0; i < m; i++) {
//			std::cerr << mod[i] << ' ';
//		}
//		std::cerr << '\n';
		int ans = 0;
		if (mod[0] > 0) {
			ans++;
		}
		if (m % 2 == 0 && mod[m/2] > 0) {
			ans++;
		}
		for (int i = 1; i+i < m; i++) {
			int minn = std::min(mod[i], mod[m-i]);
			int maxx = std::max(mod[i], mod[m-i]);
			if (maxx == 0) {
				continue;
			}
			if (maxx - minn <= 1) {
				ans++;
			} else {
				ans += maxx - (minn+1) + 1;
			}
		}
		std::cout << ans << '\n';
	}
}