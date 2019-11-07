#include <iostream>
#include <vector>
#include <map>

using ll = long long;

std::vector<std::pair<ll, ll>> a, b;
std::map<std::vector<std::pair<ll, ll>>,ll> mp;
ll n, k, t;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		for (ll j=2; j*j<=t; j++) {
			ll cnt = 0;
			while (t % j == 0) {
				cnt++;
				t /= j;
			}
			if (cnt % k) {
				a.push_back(std::make_pair(j, cnt % k));
			}
		}
		if (t > 1) {
			a.push_back(std::make_pair(t, 1));
		}
		for (auto it: a) {
			b.push_back(std::make_pair(it.first, k-it.second));
		}
		ans += mp[b];
		mp[a]++;
		a.clear();
		b.clear();
	}
	std::cout << ans << '\n';
}