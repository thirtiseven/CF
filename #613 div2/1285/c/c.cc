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

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll x;
	std::cin >> x;
	ll a, b, minn = 1000000000000;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0 && gcd(i, x/i) == 1) {
			if (std::max(i, x/i) < minn) {
				minn = std::max(i, x/i);
				a = i;
				b = x/i;
			}
		}
	}
	std::cout << a << ' ' << b << '\n';
}