#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
const ll maxn = 2017;

ll n, p, a[maxn];
std::vector<ll> ans;

ll gao(ll x) {
	ll res = 1;
	ll cnt = 0;
	for (ll i = n-1; i >= 0; i--) {
		if ((std::min(x+n-1-a[i]+1, n)-cnt) <= 0) {
			return 0;
		}
		res *= (std::min(x+n-1-a[i]+1, n)-cnt);
		cnt ++;
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> p;
	ll maxx = 1, minn = 2000;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
		maxx = std::max(maxx, a[i]);
		minn = std::min(minn, a[i]);
	}
	std::sort(a, a+n);
	for (ll i = minn; i < maxx; i++) {
//		std::cout << i << ' ' << gao(i) << '\n';
		if (gao(i) > 0 && gao(i) % p != 0) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it << ' ';
	}
}