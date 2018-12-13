#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

long long p[maxn], h[maxn], n, k, minn = maxn, maxx = 0;

int main(int argc, char *argv[]) {  
	std::fill(p, p+maxn, 0);
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
		minn = std::min(h[i], minn);
		maxx = std::max(maxx, h[i]);
		p[h[i]]++;
	}
	for (int i = maxx-1; i >= 0; i--) {
		p[i] = p[i+1] + p[i];
	}
	long long ans = 0;
	long long cur = 0;
	for (int i = maxx; i > minn; i--) {
		cur += p[i];
		if (cur > k) {
			cur = p[i];
			ans++;
		}
	}
	if (cur > 0) ans++;
	std::cout << ans;
}