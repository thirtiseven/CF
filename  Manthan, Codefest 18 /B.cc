#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int main(int argc, char *argv[]) {  
	int n;
	long long s, a[maxn];
	std::cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	a[0] = 0, a[n+1] = 1e9;
	std::sort(a, a+n+2);
	int pos = std::lower_bound(a, a+n+2, s) - a;
	if (pos == n+1) {
		pos--;
	}
//	std::cout << pos << '\n';
	long long ans = 0;
	for (int i = std::min(pos, n/2+1); i <= std::max(pos, n/2+1); i++) {
		ans += std::abs(a[i]-s);
	}
	std::cout << ans;
}