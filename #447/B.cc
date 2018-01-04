#include <iostream>

const unsigned long long mod = 1e9+7;
typedef unsigned long long LL;

LL PowMod(LL a, LL b) { 
	a %= mod;
	LL ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % mod; 
		} 
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans; 
}

int main(int argc, char *argv[]) {  
	LL n, m, k;
	std::cin >> n >> m >> k;
	if(n%2==m%2||k==1) 
	std::cout << PowMod(PowMod(2, n-1), m-1) << '\n';
	else 
	std::cout << 0 << '\n';
	return 0;
}