#include <iostream>

const int maxn = 1e5+7;
using ll = long long;

int T;

ll a[maxn], b[maxn], pos[maxn];
ll n, m;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (ll i = 0; i < n; i++) {
			std::cin >> a[i];
			pos[a[i]] = i;
		}
		ll maxx = 0;
		ll ans = m;
		for (ll i = 0; i < m; i++) {
			std::cin >> b[i];
			if (pos[b[i]] > maxx) {
				maxx = pos[b[i]];
				ans += 2*(pos[b[i]]-i);
			}
		}
		std::cout << ans << '\n';
	}
}