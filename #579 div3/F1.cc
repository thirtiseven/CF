#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first+a.second < b.first+b.second;
}

int main(int argc, char *argv[]) {  
	int n, r;
	std::pair<int, int> a[302];
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
	std::cerr << r << " " << ans << '\n';
	std::vector<std::pair<int, int>> rest;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			rest.push_back(a[i]);
		}
	}
	std::sort(rest.begin(), rest.end(), cmp);
	for (auto it: rest) {
		if (r <= it.first) {
			r += it.second;
			ans++;
		}
	}
	std::cout << ans << '\n';
}