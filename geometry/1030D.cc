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

int main(int argc, char *argv[]) {  
	ll n, m, k;
	std::cin >> n >> m >> k;
	if (2*n*m%k) {
		std::cout << "NO\n";
		exit(0);
	}
	ll area = 2*n*m/k;
	ll x = gcd(k, 2*n);
	if (x == 1) {
		std::cout << "YES\n0 0\n" << n << " 0\n0 " << m*2/k << '\n'; 
	} else {
		std::cout << "YES\n0 0\n" << n * 2 / x << " 0\n0 " << m * x / k << '\n'; 
	}
}