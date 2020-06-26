#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using ll = long long;
const ll maxn = 200000+7;
const ll mod = 998244353;
 
ll n, k, p[maxn], s[maxn];
std::vector<ll> v;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
		s[i] = p[i];
	}
	std::sort(s, s+n);
	ll lower = s[n-k];
	ll now = 0;
	ll ans1 = 0;
	ll l = 0, r = n-1;
	while (p[l] < lower) {
		l++;
	}
	while (p[r] < lower) {
		r--;
	}
	assert(l<=r);
	for (int i = l; i <= r; i++) {
		if (p[i] < lower) {
			now++;
		} else {
			ans1 += p[i];
			if (now > 0) {
				v.push_back(now);
			}
			now=0;
		}
	}
	if (now > 0) {
		v.push_back(now);
	}
	ll ans2 = 1;
	for (auto it: v) {
		ans2 *= (it+1);
		ans2 %= mod;
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
}