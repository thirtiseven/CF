#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 2e5+7;
const int maxm = 6e5+7;

ll n, b[maxn];
ll val[maxm];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	std::fill(val, val+maxm, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		val[b[i]-i+n] += b[i];
	}
	ll ans = 0;
	for (int i = 0; i <= 600000; i++) {
		ans = std::max(ans, val[i]);
	}
	std::cout << ans << '\n';
}