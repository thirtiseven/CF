#include <iostream>

const int maxn = 2e5+7;
const int upper = 2e5+1;

int m, n, k, t;
int a[maxn], dis[maxn], tot[maxn], left[maxn];
int l, r, d;

int main(int argc, char *argv[]) { 
	std::cin >> m >> n >> k >> t;
	std::fill(tot, tot+maxn, 0);
	std::fill(dis, dis+maxn, 0); 
	std::fill(left, left+maxn, n+1);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
		tot[a[i]]++;
	}
	for (int i = 0; i < k; i++) {
		std::cin >> l >> r >> d;
		dis[d-1] = std::max(dis[d-1], r);
		left[d-1] = std::min(left[d-1], l-1);
	}
	for (int i = upper; i >= 0; i--) {
		tot[i] = tot[i] + tot[i+1];
		dis[i] = std::max(dis[i], dis[i+1]);
		left[i] = std::min(left[i+1], left[i]);
	}
	int ans = 0;
	for (int i = 0; i <= upper; i++) {
		if (tot[i] == 0) break;
		int cost;
		if (dis[i] >= left[i]) {
			cost = dis[i] + (dis[i] - left[i]) + (n + 1 - left[i]);
		} else {
			cost = n+1;
		}
//		std::cout << cost << ' ' << tot[i] << ' ' << left[i] << ' ' << dis[i] << ' ' << i << '\n';
		if (cost <= t) {
			ans = std::max(ans, tot[i]);
		}
	}
	std::cout << ans << '\n';
}