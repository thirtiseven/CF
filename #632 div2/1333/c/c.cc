#include <iostream>
#include <map>
#include <queue>

using ll = long long;
const ll maxn = 2e5+7;

ll n, a[maxn], p[maxn];
std::map<ll, std::queue<ll>> m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	p[0] = 0;
	for (ll i = 1; i <= n; i++) {
		p[i] = p[i-1] + a[i];
		m[p[i]].push(i);
	}
	ll ans = n*(n+1)/2, sta = 0;
	for (ll i = 1; i <= n; i++) {
//		std::cout << sta << ' ';
		if (a[i]) {
			if (m[sta].empty()) {
				ans += (n-i+1);
			} else {
				ans += (m[sta].front()-i);
			}
		}
		sta += a[i];
		m[p[i]].pop();
	}
	std::cout << ans << '\n';
}