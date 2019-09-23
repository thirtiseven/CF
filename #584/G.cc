#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

const int maxn = 200000+7;

int a[maxn], tot[maxn], app[maxn], dis[maxn];

int main(int argc, char *argv[]) {  
	std::fill(tot, tot+maxn, 0);
	std::fill(app, app+maxn, maxn);
	std::fill(dis, dis+maxn, 0);
	int n, q;
	std::cin >> n >> q;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		tot[a[i]]++;
		if (app[a[i]] == maxn) {
			app[a[i]] = i;
		}
		dis[a[i]] = i;
	}
	int ans = 0;
	for (int i = 0; i < n;) {
		int right = dis[a[i]];
		int maxx = 0;
		for (int j = i; app[a[j]] <= right; j++) {
			maxx = std::max(tot[a[j]], maxx);
			right = std::max(dis[a[j]], right);
		}
		ans += right-i+1-maxx;
		i = right+1;
	}
	std::cout << ans << '\n';
}