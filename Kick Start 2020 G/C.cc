#include <iostream>
#include <algorithm>
#include <map>
#include <set>

const int maxn = 5003;
using ll = int;
const ll inf = 1e8;

ll T, n, k, b[maxn];

std::map<ll, std::multiset<ll>> mpl, mpr;

ll pre[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CA = 1; CA <= T; CA++) {
		pre[0] = 0;
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
			pre[i] = pre[i-1] + b[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (pre[j] - pre[i-1] <= k) mpr[pre[j] - pre[i-1]].insert(j-i+1);
			}
		}
		ll ans = inf;
		if (mpr[k].size() > 0) {
			ans = std::min(ans, *mpr[k].begin());
		}
		for (int pivot = 1; pivot <= n-1; pivot++) {
			for (int i = 1; i <= pivot; i++) {
				if (pre[pivot] - pre[i-1] <= k) mpl[pre[pivot] - pre[i-1]].insert(pivot-i+1);
			}
			for (int i = pivot; i <= n; i++) {
				if (pre[i] - pre[pivot-1] <= k) mpr[pre[i] - pre[pivot-1]].erase(mpr[pre[i] - pre[pivot-1]].find(i-pivot+1));
			}
			for (auto it: mpl) {
				if (mpr[k-it.first].size() > 0) {
					ans = std::min(ans, *(it.second.begin()) + *mpr[k-it.first].begin());
				}
			}
		}
		if (ans == inf) {
			ans = -1;
		}
		std::cout << "Case #" << CA << ": " << ans << '\n';
		mpl.clear();
		mpr.clear();
	}
}