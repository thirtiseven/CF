#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, r;
	std::pair<int, int> a[103];
	std::cin >> n >> r;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	int ans = 0;
	int vis[302];
	std::fill(vis, vis+301, 0);
	while (ans < n) {
		int maxx = 0;
		int x = -1;
		for (int i = 0; i < n; i++) {
			if (a[i].first <= r && !vis[i]) {
				if (a[i].second > maxx) {
					x = i;
					maxx = a[i].second;
				}
			}
		}
		if (x == -1) {
			break;
		}
		r += maxx;
		std::cerr << r << ' ' << maxx << '\n';
		vis[x] = 1;
		if (r < 0) {
			r -= maxx;
			vis[x] = 0;
			break;
		}
		ans ++;
	}
	while (ans < n) {
		int maxx = 0;
		int x = -1;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && a[i].first <= r) {
				if (a[i].first > maxx) {
					maxx = a[i].first;
					x = a[i].second;
					pos = i;
				}
			}
		}
		if (pos == -1) {
			break;
		}
		r += x;
		std::cerr << r << ' ' << x << '\n';
		vis[pos] = 1;
		if (r < 0) {
			break;
		}
		ans ++;
	}
	std::cout << ans << '\n';
}