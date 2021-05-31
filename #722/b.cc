#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int T;

int n, a[maxn];

int main(int argc, char *argv[]) {
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		int maxx = 1e9+7;
		int ans = 1;
		for (int i = 1; i < n; i++) {
			maxx = std::min(maxx, a[i] - a[i-1]);
			if (a[i] > 0) {
				if (a[i] <= maxx) {
					ans++;
				}
				break;
			} else {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}