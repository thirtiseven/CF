#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
using ll = long long;
ll n, m, a[maxn], c[maxn], b[maxn];

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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for (int i = 1; i < n; i++) {
		c[i] = a[i] - a[i-1];
	}
	ll g = c[1];
	for (int i = 2; i < n; i++) {
		g = gcd(g, c[i]);
	}
//	std::cerr << g << '\n';
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
		std::cout << gcd(g, a[0]+b[i]) << ' ';
	}
}