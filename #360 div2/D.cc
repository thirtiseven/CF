#include <iostream>
#include <algorithm>
#include <string>

#define ll long long
#define maxn 1000009

ll gcd(ll a, ll b) { 
	int t;
	while(b != 0) { 
		t = a % b;
		a = b;
		b = t; 
	}
	return a; 
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

bool quick_in(ll &x) { 
	char c;
	while((c = getchar()) != EOF && !isdigit(c)); 
	if(c == EOF) {
		return false;
	}
	x = 0;
	do {
		x *= 10;
		x += c - '0'; 
	} while((c = getchar()) != EOF && isdigit(c)); 
	return true;
}

int main(int argc, char *argv[]) {
	ll n, k, a[maxn], ans = 1;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		quick_in(a[i]);
	}
	for (int i = 0; i < n; i++) {
		ans = lcm(ans, a[i]) % k;
		if (!ans) {
			std::cout << "Yes";
			return 0;
		}
	}
	std::cout << "No";
	return 0;
}