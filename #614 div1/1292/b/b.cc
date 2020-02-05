#include <iostream>

using ll = long long;
const ll maxi = 60;
ll upper;
ll axi[maxi+7], ayi[maxi+7];
ll x0, y0, ax, ay, bx, by, xs, ys, t;

void init() {
	axi[0] = ayi[0] = 1;
	axi[1] = ax;
	ayi[1] = ay;
	for (ll i = 2; i < maxi; i++) {
		axi[i] = axi[i-1]*ax;
		ayi[i] = ayi[i-1]*ay;
		if (axi[i] >= 10000000000000000 || ayi[i] >= 10000000000000000) {
			upper = i;
			break;
		}
	}
}

ll cal(ll i) {
	if (i == 0) {
//		return std::make_pair(x0, y0);
//		return x0+y0;
		return std::abs(xs-x0)+std::abs(ys-y0);
	}
	ll x = axi[i]*x0+(axi[i]-1)/(ax-1)*bx;
	ll y = ayi[i]*y0+(ayi[i]-1)/(ay-1)*by;
	return std::abs(xs-x)+std::abs(ys-y);
//	return std::make_pair(x, y);
}

ll sum(ll i, ll j) {
	if (i > j) std::swap(i, j);
	ll x = (x0*ax-x0+bx*ax)*(axi[j-i+1]-1)/(ax-1)*axi[i];
	ll y = (y0*ay-y0+by*ay)*(ayi[j-i+1]-1)/(ay-1)*ayi[i];
	return x+y;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
//	std::cout << xs << ' ' << ys << '\n';
	upper = maxi;
	init();
	ll maxx = 0;
	for (ll i = 0; i < maxi; i++) {
		if (cal(i) > 1e16) {
			upper = std::min(upper, i);
			break;
		}
	}
//	std::cout << upper << '\n';
	for (ll i = 0; i < upper; i++) {
		if (cal(i) <= t) {
			for (ll j = i; i < upper; j++) {
				if (sum(i, j)+cal(i) <= t) {
					maxx = std::max(j-i+1, maxx);
				}
			}
			for (ll j = i; i >= 0; j--) {
				if (sum(j, i)+cal(i) <= t) {
					maxx = std::max(i-j+1, maxx);
				}
			}
		}
	}
	std::cout << maxx << '\n';
}