#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
int t, n, k, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int ans1 = 0, ans2 = 1, cur = 0;
		for (int i = 2; i <= k-1; i++) {
			if (a[i] > a[i-1] && a[i] > a[i+1]) {
				cur++;
			}
		}
		ans1 = cur;
		for (int i = 2; i <= n-k+1; i++) {
			if (a[i] > a[i-1] && a[i] > a[i+1]) {
				cur--;
			}
			if (a[i+k-2] > a[i+k-3] && a[i+k-2] > a[i+k-1]) {
				cur++;
			}
			if (cur > ans1) {
				ans1 = cur;
				ans2 = i;
			}
		}
		std::cout << ans1+1 << ' ' << ans2 << '\n';
	}
}