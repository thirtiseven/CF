#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e5+7;
using ll = long long;

ll T, n, a[maxn];
std::vector<ll> b, c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i+=2) {
			ans += a[i];
		}
		b.clear();
		c.clear();
		for (int i = 0; i < n/2; i++) {
			b.push_back(a[i*2+1]-a[i*2]);
		}
		for (int i = 0; i < (n-1)/2; i++) {
			c.push_back(a[i*2+1]-a[i*2+2]);
		}
		ll maxb = 0, maxc = 0, curb = 0, curc = 0;
		for (int i = 0; i < b.size(); i++) {
			if (curb > 0) {
				curb += b[i];
			} else {
				curb = b[i];
			}
			maxb = std::max(maxb, curb);
		}
		for (int i = 0; i < c.size(); i++) {
			if (curc > 0) {
				curc += c[i];
			} else {
				curc = c[i];
			}
			maxc = std::max(maxc, curc);
		}
		std::cout << ans + std::max(maxb, maxc) << '\n';
	}
}