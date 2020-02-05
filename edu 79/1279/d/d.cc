#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

const ll mod = 998244353;
const int maxn = 1e6+8;

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

ll Inv(ll a, ll m){
	return PowMod(a, m-2, m); //n为素数
}

ll wanted[maxn];
ll n, k;
std::vector<ll> a[maxn]; 

int main(int argc, char *argv[]) {  
	std::fill(wanted, wanted+maxn, 0);
	std::cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> k;
		for (int j = 0; j < k; j++) {
			std::cin >> temp;
			wanted[temp]++;
			a[i].push_back(temp);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll wsum = 0;
		for (auto it: a[i]) {
			wsum += wanted[it];
		}
		ll d = a[i].size()*n;
		ans += wsum * Inv(d, mod);
		ans %= mod;
	}
	ans *= Inv(n, mod);
	ans %= mod;
	std::cout << ans << '\n';
}