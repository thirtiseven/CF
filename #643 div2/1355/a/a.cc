#include <iostream>
#include <algorithm>

using ll = long long;

ll T, a, k;

//std::pair<ll, ll> dig(ll x) {
//	ll minn = 10, maxx = -1;
//	while (x) {
//		minn = std::min(minn, x%10ll);
//		maxx = std::max(maxx, x%10ll);
//		x /= 10;
//	}
//	return std::make_pair(minn, maxx);
//}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> k;
		k--;
		while (k--) {
			ll minn = 10, maxx = -1, aa = a;
			while (aa) {
				minn = std::min(minn, aa%10ll);
				if (minn == 0) {
					goto end;
				}
				maxx = std::max(maxx, aa%10ll);
				aa /= 10;
			}
			if (minn == 0) {
				break;
			}
			a += minn*maxx;
		}
		end:
		std::cout << a << '\n';
 	}
}