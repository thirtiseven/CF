#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using ll = long long;

const int maxn = 1e5+8;

ll hold[maxn];

ll n, m, u, v, d;

std::vector<ll> a, b;
std::vector<std::tuple<ll, ll, ll>> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	std::fill(hold, hold+n+1, 0);
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v >> d;
		hold[u] += d;
		hold[v] -= d;
	}
	for (int i = 1; i <= n; i++) {
		if (hold[i] > 0) {
			a.push_back(i);
		} else if (hold[i] < 0) {
			b.push_back(i);
		}
	}
	int x = 0, y = 0;
	ll cur;
	while (x < a.size() && a[x] > 0) {
		cur = std::min(hold[a[x]], -hold[b[y]]);
		ans.push_back(std::make_tuple(a[x], b[y], cur));
//		std::cout << a[x] << ' ' << b[y] << ' ' << cur << '\n'; 
		hold[a[x]] -= cur;
		if (hold[a[x]] == 0) {
			x++;
		}
		hold[b[y]] += cur;
		if (hold[b[y]] == 0) {
			y++;
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << std::get<0>(it) << ' ' << std::get<1>(it) << ' ' << std::get<2>(it) << '\n';
	}
}