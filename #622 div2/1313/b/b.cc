#include <iostream>

using ll = long long;

ll T, n, x, y;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x >> y;
		ll sum = x+y;
		ll lsm = x+y+1;
		ll ans1, ans2;
		if (sum-1 >= n) {
			ans2 = n;
		} else {
			ans2 = sum-1;
		}
		if (lsm-1 > n) {
			ans1 = std::min(n, (lsm-1)-n+1);
		} else {
			ans1 = 1;
		}
		std::cout << ans1 << ' ' << ans2 << '\n';
	}
}