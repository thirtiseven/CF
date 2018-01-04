#include <iostream>
#include <algorithm>
#define ll int

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

void Gcd(ll a,ll b,ll &d,ll &x,ll &y){ 
	if(!b) {
		d=a; 
		x=1; 
		y=0;
	} else {
		Gcd(b,a%b,d,y,x);
		y-=x*(a/b); 
	}
}

int main(int argc, char *argv[]) {  
	ll x, y, a, b, n, d;
	std::cin >> n >> a >> b;
	Gcd(a, b, d, x, y);
	std::cout << a << " " << b << ' ' << d << '\n';
	//int m = std::__gcd(a, b);
	d = gcd(std::max(a, b), std::min(a, b));
	if(n % d == 0) {
		x = n/d*x;
		y = n/d*y;
		std::cout << x << " " << y << "MM\n";
		int bd = b/d, ad = a/d;
		if(x<0) {
			while(x<0) {
				x += bd;
				y -= ad;
				std::cout << x << " " << y << "MMM\n";
			}
		} else if(y<0) {
			while(y<0) {
				x -= bd;
				y += ad;
				std::cout << x << " " << y << "MMM\n";
			}
		}
		if(y < 0 || x < 0) {
			std::cout << "NO\n";
			return 0;
		}
		std::cout << "YES\n" << x << " " << (n-x*a)/b << '\n';
	} else {
		std::cout << "NO\n";
	}
	return 0;
}