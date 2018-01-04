#include <iostream>

#define ll int
#define maxn 2010

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
	ll n, a[maxn];
	std::cin >> n;
	ll mm = n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) {
			mm--;
		}
	}
	if(mm == 0) {
		std::cout << "0\n";
		return 0;
	}
	ll now = a[0];
	ll cnt = 0;
	int ans = a[0];
	for(int i = 1; i < n; i++) {
		ans = gcd(ans, a[i]);
	}
	if(ans > 1) {std::cout << "-1";
	return 0;
	}
	for(int i = 1; i < n; i++) {
		ll ttt = gcd(now, a[i]);
		cnt ++;
		if(a[i] == ttt) {
			cnt--;
		}
		now = ttt;
		if(now == 1) {
			break;
		}
	}
	std::cout << cnt + mm - 1;
	return 0;
}