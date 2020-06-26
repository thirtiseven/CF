#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
using ll = long long;

std::pair<ll, ll> x[maxn];
ll n, vv[maxn], tree[maxn], tot[maxn];

void add(ll i, ll x) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

ll sum(ll i) {
	ll ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

void add2(ll i, ll x) {
	for(;i <= n; i += i & -i)
		tot[i] += x;
}

ll cal(ll i) {
	ll ret = 0;
	for(; i; i -= i & -i) ret += tot[i];
	return ret;
}

int main() {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		std::cin >> x[i].first;
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> x[i].second;
	}
	std::sort(x+1, x+n+1);
	for (ll i = 1; i <= n; i++) {
		vv[i] = x[i].second;
	}
	std::sort(vv+1, vv+n+1);
	ll size = std::unique(vv+1, vv+n+1) - vv - 1;
	for (int i = 1; i <= n; i++) {
		x[i].second = std::lower_bound(vv+1, vv+size+1, x[i].second) - vv;
	}
	ll ans = 0;
	for (ll i = n; i >= 1; i--) {
		ans += sum(n)-sum(x[i].second-1)-(cal(n)-cal(x[i].second-1))*x[i].first;
		add(x[i].second, x[i].first);
		add2(x[i].second, 1);
	}
	std::cout << ans << '\n';
}