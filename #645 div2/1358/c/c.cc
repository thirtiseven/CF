#include <iostream>
#include <algorithm>

using ll = long long;

ll t, x1, x2, y1, y2, x, y;

ll maxx(ll a, ll b) {
	ll n = a + b - 1, nn = b-1;
	return (n*(n+1)*(n+2)/6)-(nn*(nn+1)/2);
}

ll minn(ll a, ll b) {
	ll n = a + b - 1, nn = a-1;
	return (n*(n*n+5)/6)+(nn*(nn+1)/2);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
//	while (t--) {
//		std::cin >> x >> y;
//		std::cout << maxx(x, y) << ' ' << minn(x, y) << '\n';
//	}
	while (t--) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		x = x2 - x1 + 1;
		y = y2 - y1 + 1;
//		std::cout << x << ' ' << y << ' ';
		std::cout << maxx(x, y) - minn(x, y) + 1 << '\n';
	}
}