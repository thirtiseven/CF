#include <iostream>
#include <algorithm>

using ll = long long;
const ll mod = 1e9+7;
const int maxn = 2e6+7;

ll ans[maxn];
ll t, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll left0, left1, left3, right0, right1, right3;
	left0 = left1 = left3 = right0 = right1 = right3 = 0;
	ll addleft0, addleft1, addleft3, addright0, addright1, addright3;
	left0 = 1;
	ans[1] = 0;
	for (int i = 2; i <= 200000; i++) {
		addright0 = 2*left1+left0;
		addleft3 = left1;
		addleft1 = left0;
		addleft0 = 2*right1+right0;
		addright3 = right1;
		addright1 = right0;
		left0 = addleft0 % mod;
		left1 = addleft1 % mod;
		left3 += addleft3;
		left3 %= mod;
		right0 = addright0 % mod;
		right1 = addright1 % mod;
		right3 += addright3;
		right3 %= mod;
//		std::cout << left0+right0 << ' ' << left1+right1 << ' ' << left3+right3 << '\n';
		ans[i] = (left3+right3)*4;
		std::cout << i << ' ' <<  left3*4%mod << ' ' << right3*4%mod << '\n';
		ans[i] %= mod;
//		std::cout << i << ' ' << ans[i] << '\n';
 	}
 	std::cin >> t;
 	while (t--) {
		std::cin >> n;
		std::cout << ans[n] << '\n';
	}
}