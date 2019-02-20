#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 2e5+7;
ll n, m, a[maxn];
ll sum = 0;

bool check(ll mid) {
	int cnt = 0, tot = 0, k = 0;
	for (int i = 0; i < n; i++) {
		cnt += std::max(a[i]-k, 0ll);
		tot++;
		if (tot == mid) {
			tot = 0;
			k++;
		}
		if (cnt >= m) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if (sum < m) {
		std::cout << "-1\n";
		exit(0);
	}
	std::sort(a, a+n);
	std::reverse(a, a+n);
	ll l = 1, r = n, mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	std::cout << l;
}