#include <iostream>
#include <algorithm>
#include <map>
 
using ll = long long;
const int maxn = 1e5+7;
 
ll t, n, a[maxn];
std::map<ll, ll> mp;
 
int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		if (n == 1) {
			std::cout << "0\n";
			continue;
		}
		mp.clear();
		for (int i = 1; i < n; i++) {
			mp[a[i]-a[i-1]]++;
		}
		std::pair<ll, ll> x1, x2;
		if (mp.size() == 2) {
			auto it = mp.begin();
			x1 = *it;
			it++;
			x2 = *it;
		}
//		std::cerr << mp.size() << '\n';
//		std::cout << x1.first << ' ' << x1.first << '\n';
		if (mp.size() == 1) {
			std::cout << "0\n";
		} else if (mp.size() == 2 && (x1.first == 0 || x2.first == 0)) {
			std::cout << "-1\n";
		} else if (mp.size() > 2) {
			std::cout << "-1\n";
		} else {
			ll s = std::abs(x1.first-x2.first);
			ll c = (a[1]+s-a[0])%s;
			if (a[0] >= s) {
				std::cout << "-1\n";
				goto end;
			}
//			std::cout << "!!!" << s << ' ' << c << '\n';
			for (int i = 1; i < n; i++) {
				if (a[i] != (a[i-1]+c)%s) {
					std::cout << "-1\n";
					goto end;
				}
			}
			std::cout << s << ' ' << c << '\n';
			end:;
		}
	}
}