#include <iostream>
#include <vector>

const int maxn = 150002;
using ll = unsigned long long;

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
	ll n, a[maxn], b[maxn], t;
	std::cin >> n >> a[0] >> b[0];
	if (n == 1) {
		std::cout << a[0] << '\n';
		exit(0);
	}
	t = a[0]*b[0];
	for (int i = 1; i < n; i++) {
		std::cin >> a[i] >> b[i];
		t = gcd(t, a[i]*b[i]);
	}
	if (t==1) {
		std::cout << "-1\n";
	} else {
		for (int i = 0; i < n; i++) {
			t = std::max(gcd(t, a[i]), gcd(t, b[i]));
		}
		std::cout << t << '\n';
	}
}