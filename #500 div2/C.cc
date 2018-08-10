#include <iostream>
#include <algorithm>

const int maxn = 200009;
using ll = long long;

int main(int argc, char *argv[]) {  
	ll n, a[maxn];
	std::cin >> n;
	for (int i = 0; i < 2*n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+2*n);
	ll ans = 1e18+7;
	for (int i = 1; i < n; i++) {
		ans = std::min(ans, (a[2*n-1]-a[0]) * (a[i+n-1] - a[i]));
	}
	ans = std::min((a[n-1] - a[0]) * (a[2*n-1] - a[n]), ans);
	std::cout << ans;
}