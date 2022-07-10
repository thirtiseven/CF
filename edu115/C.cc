#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 2e5+7;
using ll = long long;

ll a[maxn];
ll sum, k;
ll ans;
std::map<ll, ll> mp;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int t, n;
	std::cin >> t;
	while (t--) {
		sum = 0;
		mp.clear();
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
			mp[a[i]]++;
		}
		if (sum * 2 % n != 0) {
			std::cout << "0\n";
			continue;
		}
		k = sum * 2 / n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (k - a[i] == a[i]) {
				ans += mp[k-a[i]] - 1;
			} else {
				ans += mp[k-a[i]];
			}
		}
		std::cout << ans/2 << '\n';
	}
}