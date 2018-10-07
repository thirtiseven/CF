#include <iostream>
#include <algorithm>

const int maxn = 500009;

using ll = long long;

ll a[maxn], n, minn[maxn], maxx[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	ll ans = -1e18;
	minn[1] = maxx[1] = a[1];
	for (int i = 2; i <= n; i++) {
		minn[i] = std::min(a[i] - maxx[i-1], minn[i-1]-a[i]);
		maxx[i] = std::max(a[i] - minn[i-1], maxx[i-1]-a[i]);
	}
	ans = std::max(maxx[n], ans);
	minn[n] = maxx[n] = a[n];
	for (int i = n-1; i >= 1; i--) {
		minn[i] = std::min(a[i] - maxx[i+1], minn[i+1]-a[i]);
		maxx[i] = std::max(a[i] - minn[i+1], maxx[i+1]-a[i]);
	}
	ans = std::max(maxx[1], ans);
	std::cout << ans;
}