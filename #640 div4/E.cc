#include <iostream>

const int maxn = 8002;

int t, n, a[maxn], cnt[maxn], pre[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::fill(cnt, cnt+n+1, 0);
		pre[0] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			pre[i] = pre[i-1] + a[i];
		}
		for (int i = 1; i <= n-1; i++) {
			for (int j = i+1; j <= n; j++) {
				if (pre[j]-pre[i-1] <= n) {
//					std::cout << pre[j]-pre[i-1] << ' ';
					cnt[pre[j]-pre[i-1]] = 1;
				} else {
					break;
				}
			}
		}
//		std::cout << '\n';
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[a[i]] > 0) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}