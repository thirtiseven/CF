#include <iostream>
#include <algorithm>

using ll = long long;

ll t, a, b, q, l, r;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll x;

ll gao(ll i) {
	ll res = 0;
	res += (i/x)*a;
	if (i%x != 0) {
		res += std::min((i)%x+1, a);	
	} else {
		res++;
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> q;
		if (a < b) {
			std::swap(a, b);
		}
		ll c = a-b;
		x = lcm(a, b);
//		for (ll i = 0; i <= 100; i++) {
//			std::cout << i << ' ' << gao(i) << '\n';
//		}
		while (q--) {
			std::cin >> l >> r;
//			std::cout << gao(l-1) <<' '<< l-1 << '\n';
//			std::cout << gao(r) <<' '<< r << '\n';
			std::cout << (r-l+1)-(gao(r)-gao(l-1)) << ' ';
		}
		std::cout << '\n';
	}
}