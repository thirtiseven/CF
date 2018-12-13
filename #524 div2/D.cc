#include <iostream>

using ll = unsigned long long;

int main(int argc, char *argv[]) {  
	ll t, n, k;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		if (n == 2ll && k == 3ll) {
			std::cout << "NO\n";
			continue;
		} else if ((n <= 31) && (1LL<<(n*2))/3 < k) {
			std::cout << "NO\n";
			continue;
		} else {
			ll cnt = 0;
			for (; cnt <= std::min(n, ll(64)); cnt++) {
				if ((1LL<<(cnt+1))-2ll-cnt > k) {
					break;
				}
			}
			cnt--;
//			std::cout << cnt << '\n';
			std::cout << "YES " << n-cnt << '\n';
			continue;
		}
	}
}