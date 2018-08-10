#include <iostream>

using ll = long long;

int n, m, x, y, vx, vy;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int ans = exgcd(b, a%b, y, x);
	y -= (a/b)*x;
	return ans;
}

int main(int argc, char *argv[]) {
	std::cin >> n >> m >> x >> y >> vx >> vy;
	if (vx == 0) {
		if(x%n == 0) {
			if (vy == 1) {
				printf("%d %d\n",x, m);
			} else {
				printf("%d %d\n",x, 0);
			}
		} else {
			puts("-1");
		}
		return 0;
	}
	if (vy == 0) {
		if (y%m == 0) {
			if (vx == 1) {
				std::cout << n << " " << y << '\n';
			} else {
				std::cout << "0 " << y << '\n';
			}
		} else {
			std::cout << "-1\n";
		}
		return 0;
	}
	int fx = 0, fy = 0;
	if (vx == -1) {
		x = n - x;
		fx = 1;
	}
	if (vy == -1) {
		y = m - y;
		fy = 1;
	}
	ll a, b;
	ll gcd = exgcd(n, m, a, b);
	if ((x - y)%gcd!=0) {
		std::cout << "-1\n";
		return 0;
	}
	ll t = (x - y)/gcd;
	a *= t;
	b *= t;
	ll m1 = m/gcd, n1 = n/gcd;
	ll a1 = (a%m1+m1+m1-1)%m1+1;
	ll b1 = -((x - y)-a1*n)/m;
	ll ansx, ansy;
	if (a1&1)
		ansx = n;
	else
		ansx = 0;
	if (b1&1)
		ansy = m;
	else
		ansy = 0;
	if (fx)
		ansx = n-ansx;
	if (fy)
		ansy = m-ansy;
	std::cout << ansx << " " << ansy << '\n';
	return 0;
}