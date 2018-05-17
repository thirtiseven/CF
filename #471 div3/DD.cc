#include <iostream>
#include <cmath>
#include <algorithm>

using ll = long long;
const int maxn = 100005;
const int inf = 1e9;

int main() {
	ll n, d, x, s, mn = inf, a[maxn];
	std::cin >> n;
	for(int i=0; i<n; i++) {
		std::cin>>a[i];
	}
	for(int i=-1; i<=1; i++) {
		for(int j=-1; j<=1; j++) {
			d = a[1] + j - a[0] - i;
			s = std::abs(i);
			int k;
			for (k=1; k<n; k++) {
				x = std::abs(a[k] - (a[0]+i + k*d));
				if(x>1) break;
				s += x;
			}
			if(k==n) {
				mn = std::min(mn, s);
			}
		}
	}
	std::cout << (mn<1e9 ? mn:-1);
	return 0;
}