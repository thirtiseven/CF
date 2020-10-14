#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
using ll = long long;

ll T, n, k, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		ll ans = 0;
		for (int i = n-1; i >= n-k-1; i--) {	
			ans += a[i];
		}	
		std::cout << ans << '\n';
	}
}