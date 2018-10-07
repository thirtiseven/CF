#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

const int maxn = 2e5+7;

struct pp {
	int ff, ss;
};

int ans[maxn];
int b[maxn];
int n, m, k;
pp a[maxn];

bool cmp(pp a, pp b) {
	return a.ff < b.ff;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].ff;
		a[i].ss = i;
	}
	std::sort(a, a+n, cmp);
	int maxx;
	int maxxx = 1;
	for (int i = 0; i < n; i++) {
		maxx = 1;
		while (b[maxx] != 0 && a[i].ff - b[maxx] <= k) {
			maxx++;
		}
		b[maxx] = a[i].ff;
		ans[a[i].ss] = maxx;
		if (maxx >= maxxx) {
			maxxx = maxx;
		}
	}
	std::cout << maxxx << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " ";
	}
}