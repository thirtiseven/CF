#include <iostream>
#include <cmath>

using ll = long long;

ll T, n, l, r;

ll A002260(ll n) {
	return (2*n + round(sqrt(2*n)) - round(sqrt(2*n))*round(sqrt(2*n)))/2;
}

ll A002024(ll n) {
	return floor(sqrt(2*n) + 0.5);
} 

ll gao(ll x) {
	if (x % 2 == 1) {
		if (x == n*(n-1)+1) {
			return 1;
		}
		x ++;
		x /= 2;
		return n-A002024(n*(n-1)/2-x+1);
	} else {
		x /= 2;
		return n+1-A002260(n*(n-1)/2-x+1);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> l >> r;
		for (ll i = l; i <= r; i++) {
//			std::cout << A002260(i) << " \n"[i==r];
//			gao(i);
			std::cout << gao(i) << " \n"[i==r];
		}
	}
}