#include <iostream>

using ll = long long;
const ll mod = 998244353;
const int maxn = 2e5+20;
ll ans[maxn];
ll ten[maxn];

void gao(int n) {
	ten[0] = 1;
	for (int i = 1; i <= n; i++) {
		ten[i] = ten[i-1] * 10;
		ten[i] %= mod;
	}
	ans[1] = 10;
	for (int i = 2; i <= n; i++) {
		ans[i] = (180+81*(i-2))*ten[i-2];
		ans[i] %= mod;
	}
}


int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n;
	std::cin >> n;
 	gao(n);
	for (int i = n; i >= 1; i--) {
		std::cout << ans[i] << " \n"[i==1];
	}
}