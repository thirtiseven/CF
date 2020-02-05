#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 2e5+7;
using ll = long long;

ll n, q;
ll a[maxn], now[maxn];
ll s, t, u;
ll sum = 0;
std::map<std::pair<ll, ll>, ll> upd;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::fill(now, now+n+1, 0);
	std::cin >> q;
	while (q--) {
		std::cin >> s >> t >> u;
		if (u != 0 && upd[std::make_pair(s, t)] != 0) {
			ll x = upd[std::make_pair(s, t)];
			if (x != 0 && now[x] <= a[x]) {
				sum++;
			}
			now[x]--;
			upd[std::make_pair(s, t)] = u;
			if (now[u] < a[u]) {
				sum--;
			}
			now[u]++;
		} else if (u != 0) {
			upd[std::make_pair(s, t)] = u;
			if (now[u] < a[u]) {
				sum--;
			}
			now[u]++;
		} else {
			ll x = upd[std::make_pair(s, t)];
			upd[std::make_pair(s, t)] = 0;
			if (x != 0 && now[x] <= a[x]) {
				sum++;
			}
			now[x]--;
		}
		std::cout << sum << '\n';		
	}
}