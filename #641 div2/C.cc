#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 200007;

ll n, a[maxn];

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

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	std::cin >> a[0];
	ll g = a[0], l = a[0], minn = 1000000;
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		l = a[i]*l/gcd(l, a[i]);
		g = gcd(g, a[i]);
		minn = std::min(minn, a[i]);
	}
	std::cout << g << ' ' << l << '\n';
	std::cout << g * g * minn << '\n';
}