#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using ll = unsigned long long;

ll t, n, a, b;
ll bit[1000];

ll gao(ll x) {
	std::fill(bit, bit+1000, 0);
	ll pos=0;
	while(x) {
		bit[pos++]=x%2ll;
		x/=2ll;
	}
	return pos;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		n--;
		a = n/3ll+1ll;
		b = n%3ll;
//		std::cout << a << ' ' << b << '\n';
		ll len = gao(a);
//		std::cout << len << '\n';
		std::string ans = "";
		for (ll i = 0; i < 2ll*len; i++) {
			ans += "0";
		}
		if (b == 0 || b == 2) {
			for (ll i = 0; i < len; i++) {
				if (bit[i]) {
					ans[i*2] = '1';
				}
			}
		}
		if (b == 1 || b == 2) {
			for (ll i = 0; i < len; i++) {
				if (bit[i]) {
					ans[i*2+1] = '1';
				}
			}
		}
		std::reverse(ans.begin(), ans.end());
//		std::cout << ans << '\n';
		std::bitset<1000> b(ans);
		std::cout << b.to_ullong() << '\n';
	}
}