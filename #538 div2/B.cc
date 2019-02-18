#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

using ll = long long;

std::pair<ll, ll> a[maxn];
bool yes[maxn];

int main(int argc, char *argv[]) {  
	ll n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::fill(yes, yes+maxn, 0);
	std::sort(a+1, a+n+1);
	std::reverse(a+1, a+1+n);
	ll sum = 0;
	for (int i = 1; i <= m*k; i++) {
		yes[a[i].second] = 1;
		sum += a[i].first;
	}
	std::cout << sum << '\n';
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (yes[i]) {
			cnt++;
		}
		if (cnt == m) {
			cnt=0;
			std::cout << i << ' ';
		}
	}
}