#include <iostream>
#include <algorithm>

using ll = long long;

ll a, b, c, d;
ll x[4];

ll gao(ll z) {
	ll rec = (c-b+1)*(b-a+1);
	ll res = 0;
	if (z < x[0]) {
		return rec;
	}
	if (z < x[1]) {
		rec -= (z-x[0])*(z-x[0]+1)/2;
		return rec;
	} else {
		rec -= (x[1]-x[0])*(x[1]-x[0]+1)/2;
	}
	if (z <= x[2]) {
		rec -= (z-x[1]-1)*(std::min(b-a+1, c-b+1));
		return rec;
	} else {
		rec -= (x[2]-x[1]-1)*(std::min(b-a+1, c-b+1));
	}
	if (z < x[3]) {
		rec = 0;
		ll n = (b+c-z);
		rec = n*(n+1)/2;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> a >> b >> c >> d;
	x[0] = a+b;
	x[1] = a+c;
	x[2] = b+b;
	x[3] = b+c;
	std::sort(x, x+4);
//	std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << '\n';
	ll ans = 0;
	for (ll i = c; i <= d; i++) {
//		std::cout << i << ' ' << gao(i) << ' ' << ans << '\n';
		ans += gao(i);
	}
	std::cout << ans << '\n';
}