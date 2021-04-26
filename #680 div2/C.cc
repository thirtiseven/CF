#include <iostream>
#include <algorithm>

using ll = long long;

ll T, p, q;

ll gao(ll a, ll b) {
	ll ans = 0;
	for (ll i = 2; i * i <= b; i++) {
		if (b % i == 0) {
			ll temp = a;
			while (temp % b == 0) {
				temp /= i;
			}
			ans = std::max(ans, temp);
			temp = a;
			ll temp2 = b/i;
			while (temp % b == 0) {
				temp /= temp2;
			}
			ans = std::max(ans, temp);
		}
	}
	ll temp = a;
	while (temp % b == 0) {
		temp /= b;
	}
	ans = std::max(ans, temp);
	return (ans);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> p >> q;
		if (p % q != 0) {
			std::cout << p << '\n';
		} else {
			ll x = gao(p, q);
			std::cout << x << '\n'; 
		}
	}
}