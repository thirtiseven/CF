#include <iostream>
#include <algorithm>

using ll = long long;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

ll T, r, b, k;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> r >> b >> k;
		ll x = gcd(r, b);
		r /= x;
		b /= x;
		if (r < b) {
			std::swap(r, b);
		}
		ll ans = 1;
		ans = std::max((r-2)/b+1LL, ans);
		if (k > ans) {
			std::cout << "OBEY\n";
		} else {
			std::cout << "REBEL\n";
		}
	}
}