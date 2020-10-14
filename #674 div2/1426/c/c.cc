#include <iostream>
#include <algorithm>

using ll = long long;

ll t, n, a, ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		a = 1, ans = 0;
		for (ll i = 1; i * i < n; i++) {
			ans = i;
		}
		if (ans == 0) {
			std::cout << "0\n";
			continue;
		}
		ll res = 0;
		res += (ans-1);
		res += (n-ans-1)/ans+1;
		ans ++;
		ll res2 = 0;
		res2 += (ans-1);
		res2 += (n-ans-1)/ans+1;
		std::cout << std::min(res, res2) << '\n';
	}
}