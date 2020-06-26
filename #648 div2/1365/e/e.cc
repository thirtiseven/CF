#include <iostream>
#include <algorithm>

using ll = unsigned long long;
const ll maxn = 502;

ll n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
	}
//	std::sort(a, a+n);
//	ll ans = a[n-1];
//	n--;
//	if (n > 0) {
//		for (ll i = 0; i < n; i++) {
//			a[i] = (a[i]|ans)-ans;
////			std::cerr << a[i] << " \n"[i==n-1];
//		}
//		std::sort(a, a+n);
//		ans |= a[n-1];
//		n--;
//		if (n > 0) {
//			for (ll i = 0; i < n; i++) {
//				a[i] = (a[i]|ans)-ans;
////				std::cerr << a[i] << " \n"[i==n-1];
//			}
//			std::sort(a, a+n);
//			ans |= a[n-1];
//		}
//	}
//	std::cout << ans << '\n';
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans = std::max(ans, a[i] | a[j] | a[k]);
			}
		}
	}
	std::cout << ans << '\n';
}