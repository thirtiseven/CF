#include <iostream>
#include <string>
#include <cmath>

const int maxn = 1e5+7;
using ll = long long;

ll n, k;
ll pos11[maxn], pos22[maxn];

ll p1(ll n) {
	return floor(sqrt(2*n) + 0.5);
}

ll p2(ll n) {
	ll m = floor((-1+sqrt(8*n-7))/2);
	return n-m*(m+1)/2;
}

void init() {
	for (ll i = 1; i <= 20; i++) {
		std::cout << p1(i) << " \n"[i==20];
	}
	for (ll i = 1; i <= 20; i++) {
		std::cout << p2(i) << " \n"[i==20];
	}	
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll t;
//	init();
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		ll pos1 = n-p1(k)-1;
		ll pos2 = n-p2(k);
		std::string s = "";
		for (ll i = 0; i < n; i++) {
			s += "a";
		}
		s[pos1] = 'b';
		s[pos2] = 'b';
		std::cout << s << '\n';
	}
}