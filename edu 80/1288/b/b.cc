#include <iostream>
#include <string>

using ll = long long;

ll T, A, B;

ll conc(ll a, ll b) {
	return std::stoll(std::to_string(a)+std::to_string(b));
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> A >> B;
		ll ans = 0;
//		for (ll i = 1; i <= A; i++) {
//			for (ll j = 1; j <= B; j++) {
//				if (i*j+i+j==conc(i, j)) {
//					std::cout << i << ' ' << j << '\n';
//					ans++;
//				}
//			}
//		}
//		std::cout << ans << '\n';
		std::string bs = std::to_string(B);
		int yes = 0;
		for (int i = 0; i < bs.length(); i++) {
			if (bs[i] != '9') {
				yes = 1;
				break;
			}
		}
		ans = A*(bs.length()-yes);
		std::cout << ans << '\n';
	}
}