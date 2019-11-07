#include <iostream>
#include <set>
#include <vector>

const int maxn = 1e5+7;

using ll = long long;

ll q, n, r, t;
std::set<ll> s;
std::vector<ll> x;

int main(int argc, char *argv[]) {  
	std::cin >> q;
	while (q--) {
		x.clear();
		s.clear();
		std::cin >> n >> r;
		for (ll i = 0; i < n; i++) {
			std::cin >> t;
			s.insert(t);
		}
		for (auto it: s) {
			x.push_back(it);
		}
		
		ll ans = 0;
		for (ll i = x.size()-1; i >= 0; i--) {
			if (x[i] <= ans*r) {
				break;
			} else {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}