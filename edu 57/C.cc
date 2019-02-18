#include <iostream>

using ll = int;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	int T, ang;
	std::cin >> T;
	while (T--) {
		std::cin >> ang;
		ang *= 2;
		ll x = gcd(360,ang);
		ll ans = 360/gcd(360,ang);
		if (ang/x + 1 == 360/x) {
			ans*=2;
		}
		std::cout << ans << '\n';
	}
}