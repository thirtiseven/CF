#include <iostream>
#include <cmath>
#define ll long long

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
	int n, k;
	std::cin >> n >> k;
	std::cout << lcm(n, (ll)pow(10, k));
	return 0;
}