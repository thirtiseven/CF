#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 2e5+7;
using ll = long long;

ll t, n;
ll a[maxn], b[maxn];
std::pair<ll, ll> c[maxn];
std::map<ll, ll> x, y;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		x.clear();
		y.clear();
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i] >> b[i];
			c[i] = std::make_pair(a[i], b[i]);
			x[a[i]]++;
			y[b[i]]++;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (x[a[i]]-1) * (y[b[i]]-1);
		}
		ll all = n*(n-1)*(n-2)/6;
		std::cout << all - ans << '\n';
	}
}