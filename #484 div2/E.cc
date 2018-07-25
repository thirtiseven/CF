#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
	if (b==0) {
		x=1;y=0;
		return a;
	} else {
		ll r=extend_gcd(b, a%b, y, x);
		y -= x*(a/b);
		return r;
	}
}

bool linear_equation(int a,int b,int c,int &x,int &y) {
	ll d = extend_gcd(a,b,x,y);
	if(c%d)
		return false;
	ll k=c/d;
	x*=k; y*=k;    //求得的只是其中一组解
	return true;
}

int main(int argc, char *argv[]) {  
	ll n, m, x, y, vx, vy;
	std::cin >> n >> m >> x >> y >> vx >> vy;
	if (vx == 0 || vy == 0) {
		std::cout << -1 << '\n';
		exit(0);
	}
	ll un, um;
	if (vx == 1 && vy == -1) {
		
	} else if (vx == 1 && vy == 1) {
		
	} else if (vx == -1 && vy == 1) {
		
	} else if (vx == -1 && vy == -1) {
		
	}
}