#include <iostream>
#include <cstring>

using ll = long long;
const int maxn = 1e3+7;
const ll mod = 1e9+7;
bool vis[1000005];
int prime[1000005];
int tot;

ll PowMod(ll a, ll b) { 
	a %= mod;
	ll ans = 1; 
	while (b) {
		if (b & 1){
			ans = (ans * a) % mod; 
		} 
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans; 
}

ll Inv(ll a, ll n) {
	return PowMod(a, n-2);
}

int main(int argc, char *argv[]) {  
	tot=0;
	memset(vis, 0, sizeof(vis));
	for(int i=2; i<=1000000; i++){
		if (!vis[i]) {
			prime[++tot] = i;
			for(int j=2; j*i<=1000000; j++) vis[j*i] = 1;
		}
	}
	ll n, k;
	std::cin >> n >> k;
	ll up = 1, down = 1;
	ll temp;
	for (int i = 1; prime[i] <= n && n > 1; i++) {
		if (n%prime[i]==0) {
			up *= (prime[i]+PowMod(2, k) - 1LL);
			up %= mod;
			down *= PowMod(4, k);
			down %= mod;
			n /= prime[i];
		}
	}
	std::cout << up*PowMod(down, mod-2)%mod;
}