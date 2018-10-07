#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 2018;
const ll inf = 10000000000000;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, m, x, a[maxn], b[maxn], pa[maxn], pb[maxn], ma[maxn], mb[maxn];
	std::cin >> n >> m;
	pa[0] = pb[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pa[i] = pa[i-1] + a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
		pb[i] = pb[i-1] + b[i];
	}
	std::cin >> x;
	std::fill(ma, ma+maxn, inf);
	std::fill(mb, mb+maxn, inf);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			ma[j-i] = std::min(pa[j] - pa[i], ma[j-i]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j <= m; j++) {
			mb[j-i] = std::min(pb[j] - pb[i], mb[j-i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ma[i]*mb[j] <= x) {
				ans = std::max(i*j, ans);
			}
		}
	}
	std::cout << ans << '\n';
}