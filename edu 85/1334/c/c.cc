#include <iostream>
#include <algorithm>

using ll = long long;
const ll maxn = 300000;

ll T, n;
ll a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (ll i = 0; i < n; i++) {
			std::cin >> a[i] >> b[i];
		}
		ll minn = -1;
		ll now = 1e12;
		for (ll i = 0; i < n; i++) {
			if (std::min(b[(i+n-1)%n], a[i]) < now) {
				minn = i;
				now = std::min(b[(i+n-1)%n], a[i]);
			}
		}
		ll ans = now;
		for (ll i = 0; i < n; i++) {
			if (a[(minn+i)%n] > b[(minn+n+i-1)%n]) {
				ans += a[(minn+i)%n] - b[(minn+n+i-1)%n];
			}
		}
		std::cout << ans << '\n';
	}
}