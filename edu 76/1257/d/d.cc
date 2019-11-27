#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int T, n, m, a[maxn], p[maxn], s[maxn];
int best[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::fill(best, best+n+1, 0);
		int maxa = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			maxa = std::max(maxa, a[i]);
		}
		std::cin >> m;
		int maxx = 0;
		for (int i = 0; i < m; i++) {
			std::cin >> p[i] >> s[i];
			best[s[i]] = std::max(best[s[i]], p[i]);
			maxx = std::max(maxx, p[i]);
		}
		if (maxx < maxa) {
			std::cout << "-1\n";
			continue;
		}
		for (int i = n-1; i > 0; i--) {
			best[i] = std::max(best[i], best[i+1]);
		}
		int ans = 0, cur = 1, maxnow = 0;
		for (int i = 0; i < n; i++) {
			maxnow = std::max(a[i], maxnow);
			if (best[cur] < maxnow) {
				cur = 1;
				maxnow = a[i];
				ans++;
			}
			cur++;
		}
		if (cur > 0) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}