#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll gao(ll n) {
	return n*(n+1ll)/2ll*3ll-n;
}

const ll upp = 1e9+7;

std::vector<ll> x;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll cur = 1;
	while (1) {
		ll xx = gao(cur);
		std::cerr << xx << ' ';
		if (xx > upp) {
			break;
		}
		x.push_back(xx);
		cur++;
	}
	std::cerr << '\n';
	int t, n;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		int pos = std::upper_bound(x.begin(), x.end(), n) - x.begin() - 1;
		int ans = 0;
//		std::cout << pos << ' ' << x[pos] << '\n';
		while (n > 1 && pos >= 0) {
			if (n >= x[pos]) {
				std::cout << x[pos] << " + ";
				n -= x[pos];
				ans++;
			}
			pos--;
		}
		std::cout << ans << '\n';
	}
}