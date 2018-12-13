#include <iostream>
#include <string>

const int maxn = 2e5+7;
const int mod = 998244353;

using ll = long long;
int n, m;

ll PowMod(ll a, ll b) { 
	a %= mod;
	ll ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % mod; 
		} 
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans; 
}


int tree[maxn];

void add(int i, int x) {
	for(;i <= m; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	for (int i = 0; i < b.length(); i++) {
		add(i+1, int(b[i]-'0'));
	}
	ll ans = 0;
	int x = m;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] == '1') {
			ans += sum(x)*PowMod(2, n-i-1)%mod;
			ans %= mod;
//			std::cout << ans << '\n';
		}
		x--;
		if (x < 0) break;
	}
	std::cout << ans%mod << '\n';
}