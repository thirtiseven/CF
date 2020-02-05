#include <iostream>

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

ll T, a, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> m;
		ll g = gcd(a, m);
//		ll testans = 0;
//		for (int i = 0; i < m; i++) {
//			if (gcd(a+i, m) == g) {
//				testans++;
//			}
//		}
		ll ax = a/g, bx = (a+m)/g-1;
//		std::cout << ax << ' ' << bx << ' ';
		ll tot = m/g;
		ll xxx = m;
		for (ll i = 2; i*i <= xxx; i++) {
			if (xxx % i == 0) tot = tot / i * (i+1);
			while (xxx % i == 0) {
				xxx /= i;
			}
		}
		if (xxx % m == 0) tot = tot / m * (m+1);
//		std::cout << m/g << ' ' << tot << '\n';
		std::cout << tot << '\n';
	}
}