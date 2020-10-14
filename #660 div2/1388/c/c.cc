#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;
using ll = long long;
ll T;
ll n, m, p[maxn], h[maxn], u, v;
std::vector<ll> t[maxn];
ll passby[maxn], positive[maxn];
bool yes;

void init(ll n) {
	for (ll i = 0; i <= n; i++) {
		t[i].clear();
	}
}

ll calpass(ll root, ll fa) {
	passby[root] = p[root];
	for (auto it: t[root]) {
		if (it != fa) {
			passby[root] += calpass(it, root);
		}
	}
	return passby[root];
}

ll check(ll root, ll fa) {
	ll maxx = positive[root];
	for (auto it: t[root]) {
		if (it != fa) {
			maxx = std::max(maxx, check(it, root));
		}
	}
	if (maxx > positive[root] || positive[root] < 0 || passby[root]-positive[root] < 0) {
		yes = 0;
	}
	return maxx;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		init(n);
		for (ll i = 1; i <= n; i++) {
			std::cin >> p[i];
		}
		for (ll i = 1; i <= n; i++) {
			std::cin >> h[i];
		}
		for (ll i = 0; i < n-1; i++) {
			std::cin >> u >> v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		calpass(1, -1);
//		for (ll i = 1; i <= n; i++) {
//			std::cout << passby[i] << " \n"[i==n];
//		}
		yes = 1;
		for (ll i = 1; i <= n; i++) {
			positive[i] = (passby[i] + h[i])/2;
			if ((passby[i] + h[i])%2==1 || positive[i] < 0 || positive[i] - h[i] < 0) {
//				std::cout << i << ' ' <<  passby[i] << ' ' << h[i] << '\n';
				yes = 0;
			}
		}
		if (yes) {
			check(1, -1);
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}