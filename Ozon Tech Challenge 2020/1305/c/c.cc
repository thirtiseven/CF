#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

using ll = long long;

ll n, m, a[maxn], c[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if (n > m) {
		std::cout << "0\n";
		exit(0);
	}
	ll ans = 1;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			ans *= std::abs(a[i]-a[j]);
			ans %= m;
		}
	}	
	std::cout << ans << '\n';
}