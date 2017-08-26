#include <iostream>
#define ll long long
#define maxn 10000

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	ll a[maxn];
	a[1] = 2, a[2] = 3;
	for(int i = 3; i <= 90; i++) {
		a[i] = a[i-1] + a[i-2];
	}
	int l = 1, r = 90;
	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] <= n) {
			l = m + 1;
		} else {
			r = m - 1;
		} 
	}
	std::cout << r << std::endl;
	return 0;
}