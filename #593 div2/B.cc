#include <iostream>

using ll = long long;
const ll mod = 1e9+7;

ll PowMod(ll a, ll b, const ll &Mod) { 
	a %= Mod;
	ll ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}

int main(int argc, char *argv[]) {  
	ll n, m;
	std::cin >> n >> m;
	std::cout << PowMod(PowMod(2, m, mod) - 1, n, mod) << '\n';
}