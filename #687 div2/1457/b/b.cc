#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int T, n, k, c[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> c[i];
		}
		int ans = 10000000;
		for (int j = 1; j <= 100; j++) {
			int now = 0;
			for (int i = 1; i <= n;) {
				if (c[i] != j) {
					now++;
					i += k;
				} else {
					i++;
				}
			}
			ans = std::min(ans, now);
		}
		std::cout << ans << '\n';
	}
}