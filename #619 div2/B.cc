#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int T, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int minn = 1e9, maxx = 0, diff = 0;
		for (int i = 0; i < n-1; i++) {
			if (a[i] == -1 && a[i+1] >= 0) {
				minn = std::min(minn, a[i+1]);
				maxx = std::max(maxx, a[i+1]);
			}
			if (a[i]>=0 && a[i+1]>=0) {
				diff = std::max(diff, std::abs(a[i]-a[i+1]));
			}
		}
		for (int i = n-1; i > 0; i--) {
			if (a[i] == -1 && a[i-1] >= 0) {
				minn = std::min(minn, a[i-1]);
				maxx = std::max(maxx, a[i-1]);
			}
		}
		int ans = (minn+maxx)/2;
		int ans2 = std::max(maxx-ans, ans-minn);
		std::cout << std::max(ans2, diff) << ' ' << ans << '\n';
	}
}