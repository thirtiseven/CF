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
	ll a, b, x, y;
	std::cin >> a >> b >> x >> y;
	ll xy = gcd(x, y);
	x /= xy, y /= xy;
	std::cout << std::min(a/x, b/y) << '\n';
}