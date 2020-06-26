#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
using ll = long long;

ll n, a, r, m, h[maxn];

ll gao(ll x) {
	ll lack = 0, add = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] > x) {
			add += (h[i]-x);
		}
		if (h[i] < x) {
			lack += (x-h[i]);
		}
	}
	if (a+r<=m) {
		return add*r+lack*a;
	}
	ll temp = std::min(add, lack);
	add -= temp;
	lack -= temp;
	return lack*a+add*r+temp*m;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> a >> r >> m;
	ll l = 1e9, r = 0, mid1, mid2;
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
		l = std::min(l, h[i]);
		r = std::max(r, h[i]);
	}
	while (l < r) {
		mid1 = l + (r-l)/3;
		mid2 = r - (r-l)/3;
//		std::cout << l << ' ' << mid1 << ' ' << mid2 << ' ' << r << '\n';
//		std::cout << gao(mid1) << ' ' << gao(mid2) << '\n';
 		if (gao(mid1) > gao(mid2)) {
			l = mid1+1;
		} else {
			r = mid2-1;
		}
	}
	std::cout << gao(l) << '\n';
}