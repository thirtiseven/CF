#include <iostream>
#include <set>

const int maxn = 1e5+7;

int t, n, k, g[maxn], vis[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		int ans1 = 0, ans2 = 0;
		std::fill(vis, vis+n+1, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> k;
			for (int j = 0; j < k; j++) {
				std::cin >> g[j];
			}
			bool yes = 0;
			for (int j = 0; j < k; j++) {
				if (!vis[g[j]]) {
					vis[g[j]] = 1;
					yes = 1;
					break;
				}
			}
			if (yes == 0 && ans1 == 0) {
				ans1 = i;
			}
		}
		if (ans1 != 0) {
			for (int i = 1; i <= n; i++) {
				if (vis[i] == 0) {
					ans2 = i;
					break;
				}
			}
			std::cout << "IMPROVE\n" << ans1 << ' ' << ans2 << '\n';
		} else {
			std::cout << "OPTIMAL\n";
		}
	}
}