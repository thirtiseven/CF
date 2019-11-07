#include <iostream>
#include <algorithm>

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

const int maxn = 2e5+7;

ll p[maxn], x, a, y, b, n;
ll k;

bool check(ll bob) {
	ll abm = bob/lcm(a, b);
	ll am = bob/a - abm;
	ll bm = bob/b - abm;
	ll res = 0;
	for (int i = 0; i < abm; i++) {
		res += (x+y)*p[n-i-1];
	}
	for (int i = abm; i < abm+am; i++) {
		res += x*p[n-i-1];
	}
	for (int i = abm+am; i < abm+am+bm; i++) {
		res += y*p[n-i-1];
	}
//	std::cout << bob << ' ' << res << '\n';
	if (res < k) {
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
			p[i] /= 100;
		}
		std::sort(p, p+n);
		std::cin >> x >> a >> y >> b;
		if (x < y) {
			std::swap(x, y);
			std::swap(a, b);
		}
		std::cin >> k;
		if (!check(n)) {
			std::cout << "-1" << '\n';
		} else {
			int l = 1, r = n, mid;
			while (l <= r) {
				mid = (l+r)/2;
				if (!check(mid)) {
					l = mid+1;
				} else {
					r = mid-1;
				}
			}
			std::cout << l << '\n';
		}
 	}
}