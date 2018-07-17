#include <iostream>

using LL = long long int;
const int pr =  998244353;

LL PowMod(LL a, LL b, const LL &Mod) { 
	a %= Mod;
	LL ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}

LL Inv(LL a, LL n){
	return PowMod(a, n-2, n);
}

LL C(const LL &n, const LL &m) {
	LL ans = 1;
	for (int i = 1; i <= m; i++) {
		LL a = (n - m + i) % pr;
		LL b = i % pr;
		ans = (ans * (a * Inv(b, pr)) % pr) % pr;
	}
	return ans;
}

int main(int argc, char *argv[]) {  
	int n;
	int a[123];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && (n-1-i)>=a[i]) {
			std::cout << C(n-1-i, a[i]) << '\n';
			ans += C(n-1-i, a[i]);
			ans %= pr;
		}
	}
	std::cout << ans << '\n';
}