#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>

const int maxn = 2e5+7;
using ll = long long;

int main(int argc, char *argv[]) {  
	std::pair<ll, ll> hd[maxn];
	ll n, a, b;
	std::cin >> n >> a >> b;
	ll maxi = -1, maxx = 0;
	ll mm[maxn];
	ll aa[maxn];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> hd[i].first >> hd[i].second;
		if (b > 0) {
		mm[i] = hd[i].first * pow(2, a) - hd[i].second;
		if (mm[i] > maxx && mm[i] > (hd[i].first - hd[i].second)) {
			maxx = mm[i];
			maxi = i;
		}
		}
		ans += hd[i].second;
	}
	for (int i = 0; i < n; i++) {
		if (hd[i].first > hd[i].second && i != maxi) {
			aa[i] = hd[i].first - hd[i].second;
		} else {
			aa[i] = 0;
		}
	}
	std::sort(aa, aa+n);
	ans += maxx;
	for (int i = n-1; i >= std::max(n-b+1, (ll)0); i--) {
		ans += aa[i];
	}
	if (maxx == 0 && n-b-1>=0) {
		ans += aa[n-b];
	}
	std::cout << ans;
}